#ifndef MEM2REG_BUILDER_H
#define MEM2REG_BUILDER_H

#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include "DomTree.h"
#include "DomTreeBuilder.h"
#include "IRBaseVisitor.h"
#include "IRNode.h"

static IRIntType intType(32);
static IRPtrType ptrType;
static IRLiteralNode nullNode(&ptrType, 0);
static IRLiteralNode intZeroNode(&intType, 0);

class Mem2RegBuilder : public IRBaseVisitor {
private:
    IRFunctionNode* currentFunction = nullptr;
    DomTreeBuilder* domTreeBuilder = nullptr;
    std::map<IRValueNode*, std::set<IRStmtNode*>> useMap;    
    std::map<std::string, std::vector<IRValueNode*>> renameMap;
    std::map<std::string, std::vector<IRPhiStmtNode*>> phiMap;
    std::map<std::string, int> counter;
    std::vector<IRPhiStmtNode*> phiRenameList;
    std::set<CFGNode*> visited;
    std::set<std::string> allocaSet;
    std::map<DomTreeNode*, std::set<IRVarNode*>> phiVarMap;
    std::set<IRNode*> irNodeSet;
public:
    Mem2RegBuilder() { domTreeBuilder = new DomTreeBuilder; }
    ~Mem2RegBuilder() { 
        delete domTreeBuilder; 
        for (auto v: irNodeSet) delete v;        
    }
    void clear() {
        domTreeBuilder->clear();
        useMap.clear();
        renameMap.clear();
        phiMap.clear();
        phiRenameList.clear();
        visited.clear();
        phiVarMap.clear();
    }
    void setPhiStmt(DomTreeNode* node, IRValueNode* value, IRVarNode* var) {
        auto &setMap = phiVarMap[node];
        if (!setMap.insert(var).second) return;
        for (auto fnode: node->frontier) {
            auto phi = new IRPhiStmtNode(var);
            irNodeSet.insert(phi);
            phiMap[fnode->name].push_back(phi);
            useMap[var].insert(phi);
            setPhiStmt(fnode, value, var);
        }
    }
    void setPtrDef(DomTreeNode* node) {
        auto &stmts = node->block->stmts;    
        for (int i = 0; i < stmts.size(); ) {
            auto stmt = stmts[i];
            if (auto s = dynamic_cast<IRStoreStmtNode*>(stmt)) {
                if (!allocaSet.count(s->ptr->name)) { ++i; continue; }
                if (dynamic_cast<IRGlobalVarNode*>(s->ptr)) { ++i; continue; }
                auto var = new IRVarNode(s->value->type, s->ptr->name, s->ptr->isConst);
                irNodeSet.insert(var);
                setPhiStmt(node, s->value, var);
                ++i;
            }
            else if (auto s = dynamic_cast<IRAllocaStmtNode*>(stmt)) allocaSet.insert(s->var->name), stmts.erase(stmts.begin() + i), delete s;
            else ++i;
        }        
    }
    void visitCFG(CFGNode* node, CFGNode* fa) {
        auto copyMap = renameMap;
        auto &stmts = node->block->stmts;        
        for (auto stmt: stmts) {            
            if (auto s = dynamic_cast<IRPhiStmtNode*>(stmt)) {
                if (!allocaSet.count(s->var->name)) break;
                if (!renameMap[s->var->name].size()) {
                    s->values[fa->name] = (s->var->type->to_string() == "ptr"? &nullNode: &intZeroNode);
                }
                else s->values[fa->name] = renameMap[s->var->name].back();
                renameMap[s->var->name].push_back(s->var);
            }
            else break;
        }
        if (visited.count(node)) { renameMap = copyMap; return; }
        visited.insert(node);        
        for (int i = 0; i < stmts.size(); ) {
            auto stmt = stmts[i];
            if (auto s = dynamic_cast<IRStoreStmtNode*>(stmt)) {
                if (!allocaSet.count(s->ptr->name)) { ++i; continue; }
                renameMap[s->ptr->name].push_back(s->value);
                stmts.erase(stmts.begin() + i);
                delete s;
            }
            else if (auto s = dynamic_cast<IRLoadStmtNode*>(stmt)) {
                if (!allocaSet.count(s->ptr->name)) { ++i; continue; }                
                for (auto t: useMap[s->var]) t->replaceValue(s->var, renameMap[s->ptr->name].back());
                stmts.erase(stmts.begin() + i);
                delete s;
            }
            else ++i;
        }
        for (auto next: node->next) visitCFG(next, node);
        renameMap = copyMap;
    }
    void collectVarUse(IRFunctionNode* node) {
        for (auto block: node->blocks) {
            for (auto stmt: block->stmts) {
                stmt->collectUse(useMap);            
            }
        }
    }
    void eliminateCriticalEdge(CFGNode* node) {
        if (visited.count(node)) return;
        visited.insert(node);
        if (node->next.size() <= 1) {
            for (auto next: node->next) eliminateCriticalEdge(next);
            return;
        }
        auto nowBlock = node->block;
        for (auto next: node->next) {
            if (next->pred.size() <= 1) continue;
            auto nextBlock = next->block;

            auto block = new IRBlockNode("._eliminateCriticalEdge." + std::to_string(counter["eliminateCriticalEdge"]++));
            block->stmts.push_back(new IRBrStmtNode(nextBlock->label));
            currentFunction->blocks.push_back(block);

            auto stmt = dynamic_cast<IRBrCondStmtNode*>(nowBlock->stmts.back());
            if (!stmt) throw std::runtime_error("eliminateCriticalEdge: not a cond br");
            if (stmt->trueLabel == nextBlock->label) stmt->trueLabel = block->label;
            else stmt->falseLabel = block->label;

            for (auto st: nextBlock->stmts) {
                if (auto s = dynamic_cast<IRPhiStmtNode*>(st)) {
                    if (s->values.count(nowBlock->label)) {
                        s->values.emplace(block->label, s->values[nowBlock->label]);
                        s->values.erase(nowBlock->label);
                    }
                }
                else break;
            }
        }
        for (auto next: node->next) eliminateCriticalEdge(next);
    }
    void eliminateDeadCode(IRFunctionNode* node) {
        useMap.clear();
        std::unordered_map<IRValueNode*, std::vector<IRStmtNode*>> defMap;
        std::map<IRNode*, std::set<IRValueNode*> > useSet, defSet;
        std::map<IRStmtNode*, std::pair<IRBlockNode*, int>> stmtMap;
        std::set<IRValueNode*> varSet, visited;
        std::set<IRStmtNode*> deleted;        
        for (auto block: node->blocks) {
            auto &stmts = block->stmts;            
            for (int i = 0, k = stmts.size(); i < k; ++i) {
                auto stmt = stmts[i];
                stmtMap.emplace(stmt, std::make_pair(block, i));  
                stmt->collectUse(useMap);
                stmt->collectDef(defMap);
                stmt->getUse(useSet);
                stmt->getDef(defSet);
            }            
        }
        for (auto block: node->blocks)
            for (auto stmt: block->stmts) {
                auto &tmpSet = defSet[stmt];
                for (auto var: tmpSet) varSet.insert(var);
            }
        std::queue<IRValueNode*> que;
        for (auto var: varSet) if (useMap[var].empty()) que.push(var);
        while (!que.empty()) {
            auto var = que.front(); que.pop();            
            if (visited.contains(var)) continue;
            visited.insert(var);    
            for (auto stmt: defMap[var]) {
                if (deleted.contains(stmt) || dynamic_cast<IRCallStmtNode*>(stmt)) continue;
                
                
                auto &tmpDefSet = defSet[stmt];
                for (auto v: tmpDefSet) {                    
                    useMap[v].erase(stmt);
                    if (useMap[v].empty() && !visited.contains(v)) que.push(v);
                }
                deleted.insert(stmt);    
                auto p = stmtMap[stmt];
                auto &stmts = p.first->stmts;
                stmts.erase(stmts.begin() + p.second);
            }
        }
    }
    void visitFunction(IRFunctionNode* node) override {
        if (!node->blocks.size()) return;
        currentFunction = node;
        clear();
        domTreeBuilder->visit(node);
        collectVarUse(node);
        for (auto block: node->blocks) {
            auto now = domTreeBuilder->domTree->name2node[block->label];
            setPtrDef(now);
        }
        for (auto block: node->blocks) {
            std::vector<IRPhiStmtNode*> &phis = phiMap[block->label];
            sort(phis.begin(), phis.end(), [](IRPhiStmtNode* a, IRPhiStmtNode* b) { return a->var->name < b->var->name; });
            int pl = 0, pr = 0, len = phis.size();
            while (pl < len) {
                while (pr < len && phis[pl]->var->name == phis[pr]->var->name) ++pr;
                auto var = new IRVarNode(phis[pl]->var->type, phis[pl]->var->name, phis[pl]->var->isConst);
                irNodeSet.insert(var);
                auto phi = new IRPhiStmtNode(var);                
                block->stmts.insert(block->stmts.begin(), phi);
                phiRenameList.push_back(phi);
                pl = pr;
            }
        }
        visitCFG(domTreeBuilder->cfg->entry, nullptr);
        for (auto phi: phiRenameList) {
            phi->var->name += ".rename" + std::to_string(counter[phi->var->name + ".rename"]++);
        }
        auto &blocks = node->blocks;        
        for (int i = 0; i < blocks.size(); ) {
            auto block = blocks[i];
            if (!visited.count(domTreeBuilder->cfg->name2node[block->label])) {
                delete block;
                blocks.erase(blocks.begin() + i);
            }
            else ++i;
        }
        visited.clear();
        eliminateCriticalEdge(domTreeBuilder->cfg->entry);
        eliminateDeadCode(node);
        currentFunction = nullptr;
    }
    void visitProgram(IRProgramNode* node) override {
        for (auto func: node->functions) visitFunction(func);
    }

};

#endif