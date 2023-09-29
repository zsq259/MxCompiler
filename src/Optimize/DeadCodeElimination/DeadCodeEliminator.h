#ifndef DEAD_CODE_ELIMINATOR_H
#define DEAD_CODE_ELIMINATOR_H

#include "IRNode.h"
#include "CFGBuilder.h"
#include <unordered_map>
#include <map>
#include <queue>
#include <set>
#include <vector>

class DeadCodeEliminator {
public:
    void EliminateUnReadchable(IRFunctionNode* node) {        
        CFGBuilder cfgBuilder;
        auto cfg = cfgBuilder.buildCFG(node);
        std::queue<CFGNode*> que;
        std::set<IRBlockNode*> deleted;        
        for (int i = 0, k = node->blocks.size(); i < k; ++i) {
            auto block = node->blocks[i];            
            if (dynamic_cast<IRUnReachableStmtNode*>(block->stmts.back())) {                
                que.push(cfg->name2node[block->label]);
            }
        }
        while (!que.empty()) {
            auto blockNode = que.front(); que.pop();
            auto block = blockNode->block;
            if (deleted.contains(block)) continue;
            deleted.insert(block);
            for (auto pred: blockNode->pred) {
                if (pred->next.size() == 1) {
                    que.push(pred);
                    pred->next.clear();
                }
                else {
                    for (int i = 0, n = pred->next.size(); i < n; ++i) {
                        if (pred->next[i] == blockNode) {
                            pred->next.erase(pred->next.begin() + i);
                            break;
                        }
                    }
                    auto &stmts = pred->block->stmts;
                    auto stmt = stmts.back();
                    auto br = dynamic_cast<IRBrCondStmtNode*>(stmt);
                    if (!br) throw std::runtime_error("DeadCodeEliminator: not a cond br");
                    auto label = br->trueLabel == block->label ? br->falseLabel : br->trueLabel;
                    auto newBr = new IRBrStmtNode(label);
                    stmts.pop_back();
                    stmts.push_back(newBr);

                }
            }
        }
        std::vector<IRBlockNode*> newBlocks;
        for (auto block: node->blocks) {
            if (!deleted.contains(block)) newBlocks.push_back(block);
        }
        node->blocks = newBlocks;        
    }
    void EliminatePhi(IRFunctionNode* node) {
        std::map<IRValueNode*, std::set<IRStmtNode*> > useMap;
        std::unordered_map<IRValueNode*, IRStmtNode*> defMap;
        std::map<IRNode*, std::set<IRValueNode*> > useSet, defSet;        
        std::queue<IRStmtNode*> livePhi;
        std::set<IRStmtNode*> deleted, visited;        
        for (auto block: node->blocks) {
            auto &stmts = block->stmts;            
            for (int i = 0, k = stmts.size(); i < k; ++i) {
                auto stmt = stmts[i];                
                stmt->collectUse(useMap);
                stmt->collectDef(defMap);
                stmt->getUse(useSet);
                stmt->getDef(defSet);
            }            
        }
        for (auto block: node->blocks) {
            for (auto stmt: block->stmts) {
                if (auto phi = dynamic_cast<IRPhiStmtNode*>(stmt)) {
                    deleted.insert(phi);
                    auto var = *(defSet[phi].begin());
                    bool flag = false;
                    auto &uses = useMap[var];
                    for (auto s: uses) {
                        flag |= (!dynamic_cast<IRPhiStmtNode*>(s));
                    }
                    if (flag) livePhi.push(phi);
                }
            }
        }
        while (!livePhi.empty()) {
            auto phi = livePhi.front();
            livePhi.pop();
            if (visited.contains(phi)) continue;
            visited.insert(phi);
            deleted.erase(phi);
            auto &uses = useSet[phi];
            for (auto v: uses) livePhi.push(defMap[v]);
        }
        for (auto block: node->blocks) {
            auto &stmts = block->stmts;
            for (int i = 0; i < stmts.size(); ++i) {
                if (deleted.contains(stmts[i])) stmts.erase(stmts.begin() + i);
            }
        }
    }
    void EliminateNoUse(IRFunctionNode* node) {
        std::map<IRValueNode*, std::set<IRStmtNode*> > useMap;
        std::unordered_map<IRValueNode*, IRStmtNode*> defMap;
        std::map<IRNode*, std::set<IRValueNode*> > useSet, defSet;        
        std::set<IRValueNode*> varSet, visited;
        std::set<IRStmtNode*> deleted;        
        for (auto block: node->blocks) {
            auto &stmts = block->stmts;            
            for (int i = 0, k = stmts.size(); i < k; ++i) {
                auto stmt = stmts[i];                
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
        // for (auto var: varSet) std::cerr << var->to_string() << ' ' << useMap[var].size() << '\n';
        while (!que.empty()) {
            auto var = que.front(); que.pop();            
            if (visited.contains(var)) continue;
            visited.insert(var);                
            auto stmt = defMap[var];
            if (deleted.contains(stmt) || dynamic_cast<IRCallStmtNode*>(stmt)) continue;
            
            
            auto &tmpUseSet = useSet[stmt];
            for (auto v: tmpUseSet) {                    
                useMap[v].erase(stmt);
                if (useMap[v].empty() && !visited.contains(v)) que.push(v);
            }
            deleted.insert(stmt);                    
            
        }
        for (auto block: node->blocks) {
            auto &stmts = block->stmts;
            for (int i = 0; i < stmts.size(); ) {
                auto stmt = stmts[i];
                if (deleted.contains(stmt)) {
                    stmts.erase(stmts.begin() + i);
                    delete stmt;
                }
                else ++i;
            }
        }
        EliminatePhi(node);
    }    
    void EliminateStoreLoad(IRFunctionNode* node) {
        std::map<IRVarNode*, IRValueNode*> valueMap;
        std::map<IRValueNode*, std::set<IRStmtNode*>> useMap;
        std::vector<IRStmtNode*> deleted;
        for (auto block: node->blocks) {
            valueMap.clear();
            useMap.clear();
            deleted.clear();
            for (auto stmt: block->stmts) stmt->collectUse(useMap);
            for (auto stmt: block->stmts) {
                if (auto load = dynamic_cast<IRLoadStmtNode*>(stmt)) {
                    if (!valueMap.contains(load->ptr)) continue;
                    auto value = valueMap[load->ptr];
                    for (auto use: useMap[load->var]) use->replaceValue(load->var, value);
                    deleted.push_back(load);
                }
                if (auto store = dynamic_cast<IRStoreStmtNode*>(stmt)) {
                    valueMap[store->ptr] = store->value;
                }
            }
        }
    }
    void visit(IRProgramNode* program) {
        for (auto func: program->functions) EliminateStoreLoad(func);
    }
};

#endif