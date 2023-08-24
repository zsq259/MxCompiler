#ifndef MEM2REG_BUILDER_H
#define MEM2REG_BUILDER_H

#include <map>
#include <set>
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
    std::map<IRValueNode*, std::vector<IRStmtNode*>> useMap;
    std::map<std::string, std::vector<IRValueNode*>> renameMap;
    std::map<std::string, std::vector<IRPhiStmtNode*>> phiMap;
    std::map<std::string, int> counter;
    std::set<IRPhiStmtNode*> phiRenameSet;
    std::set<CFGNode*> visited;
    std::set<std::string> allocaSet;
public:
    Mem2RegBuilder() { domTreeBuilder = new DomTreeBuilder; }

    void clear() {
        domTreeBuilder->clear();
        useMap.clear();
        renameMap.clear();
        phiMap.clear();
        phiRenameSet.clear();
        visited.clear();
    }
    void setPhiStmt(DomTreeNode* node, IRValueNode* value, IRVarNode* var) {
        for (auto fid: node->frontier) {
            auto fnode = domTreeBuilder->domTree->id2node[fid];
            auto phi = new IRPhiStmtNode(var);
            phiMap[fnode->name].push_back(phi);
            useMap[var].push_back(phi);
            setPhiStmt(fnode, value, var);
        }
    }
    void setPtrDef(DomTreeNode* node) {
        for (std::list<IRStmtNode*>::iterator it = node->block->stmts.begin(); it != node->block->stmts.end();) {
            auto stmt = *it;
            if (auto s = dynamic_cast<IRStoreStmtNode*>(stmt)) {
                if (!allocaSet.count(s->ptr->name)) { ++it; continue; }
                if (dynamic_cast<IRGlobalVarNode*>(s->ptr)) { ++it; continue; }
                auto var = new IRVarNode(s->value->type, s->ptr->name, s->ptr->isConst);
                setPhiStmt(node, s->value, var);
                ++it;
            }
            else if (auto s = dynamic_cast<IRAllocaStmtNode*>(stmt)) allocaSet.insert(s->var->name), it = node->block->stmts.erase(it);
            else ++it;
        }
        for (auto child: node->children) setPtrDef(child);        
    }
    void visitCFG(CFGNode* node, CFGNode* fa) {
        auto copyMap = renameMap;
        for (std::list<IRStmtNode*>::iterator it = node->block->stmts.begin(); it != node->block->stmts.end(); ++it) {
            auto stmt = *it;
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
        for (std::list<IRStmtNode*>::iterator it = node->block->stmts.begin(); it != node->block->stmts.end();) {
            auto stmt = *it;
            if (auto s = dynamic_cast<IRStoreStmtNode*>(stmt)) {
                if (!allocaSet.count(s->ptr->name)) { ++it; continue; }
                if (dynamic_cast<IRGlobalVarNode*>(s->ptr)) { ++it; continue; }
                renameMap[s->ptr->name].push_back(s->value);
                it = node->block->stmts.erase(it);
            }
            else if (auto s = dynamic_cast<IRLoadStmtNode*>(stmt)) {
                if (!allocaSet.count(s->ptr->name)) { ++it; continue; }
                if (dynamic_cast<IRGlobalVarNode*>(s->ptr)) { ++it; continue; }
                if (!renameMap[s->ptr->name].size()) { ++it; continue; }
                for (auto t: useMap[s->var]) t->replaceValue(s->var, renameMap[s->ptr->name].back());
                it = node->block->stmts.erase(it);                
            }
            else ++it;
        }
        for (auto next: node->next) visitCFG(next, node);
        renameMap = copyMap;
    }
    void collectVarUse(IRFunctionNode* node) {
        for (auto block: node->blocks) {
            for (auto stmt: block->stmts) {
                if (auto s = dynamic_cast<IRRetStmtNode*>(stmt)) useMap[s->value].push_back(s);
                else if (auto s = dynamic_cast<IRBinaryStmtNode*>(stmt)) useMap[s->lhs].push_back(s), useMap[s->rhs].push_back(s);
                else if (auto s = dynamic_cast<IRStoreStmtNode*>(stmt)) useMap[s->value].push_back(s);
                else if (auto s = dynamic_cast<IRIcmpStmtNode*>(stmt)) useMap[s->lhs].push_back(s), useMap[s->rhs].push_back(s);
                else if (auto s = dynamic_cast<IRTruncStmtNode*>(stmt)) useMap[s->value].push_back(s);
                else if (auto s = dynamic_cast<IRZextStmtNode*>(stmt)) useMap[s->value].push_back(s);
                else if (auto s = dynamic_cast<IRCallStmtNode*>(stmt)) {
                    for (auto arg: s->args) useMap[arg].push_back(s);
                }
                else if (auto s = dynamic_cast<IRPhiStmtNode*>(stmt)) {
                    for (auto arg: s->values) useMap[arg.second].push_back(s);
                }
                else if (auto s = dynamic_cast<IRGetElementPtrStmtNode*>(stmt)) {
                    useMap[s->ptr].push_back(s);
                    useMap[s->index].push_back(s);
                }
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
            if (node->pred.size() <= 1) continue;
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
    void visitFunction(IRFunctionNode* node) override {
        if (!node->blocks.size()) return;
        currentFunction = node;
        clear();
        domTreeBuilder->visit(node);
        collectVarUse(node);
        setPtrDef(domTreeBuilder->domTree->root);
        
        for (auto block: node->blocks) {
            std::vector<IRPhiStmtNode*> &phis = phiMap[block->label];
            sort(phis.begin(), phis.end(), [](IRPhiStmtNode* a, IRPhiStmtNode* b) { return a->var->name < b->var->name; });
            int pl = 0, pr = 0, len = phis.size();
            while (pl < len) {
                while (pr < len && phis[pl]->var->name == phis[pr]->var->name) ++pr;
                auto var = new IRVarNode(phis[pl]->var->type, phis[pl]->var->name, phis[pl]->var->isConst);
                auto phi = new IRPhiStmtNode(var);
                block->stmts.push_front(phi);
                phiRenameSet.insert(phi);
                pl = pr;            
            }
        }
        visitCFG(domTreeBuilder->cfg->entry, nullptr);
        for (auto phi: phiRenameSet) {
            phi->var->name += ".rename" + std::to_string(counter[phi->var->name + ".rename"]++);
        }
        for (auto it = node->blocks.begin(); it != node->blocks.end();) {
            auto block = *it;
            if (!visited.count(domTreeBuilder->cfg->name2node[block->label])) it = node->blocks.erase(it);
            else ++it;
        }
        visited.clear();
        eliminateCriticalEdge(domTreeBuilder->cfg->entry);
        currentFunction = nullptr;
    }
    void visitProgram(IRProgramNode* node) override {
        for (auto func: node->functions) visitFunction(func);
    }

};

#endif