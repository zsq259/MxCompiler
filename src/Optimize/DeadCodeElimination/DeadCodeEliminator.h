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
    }    
};

#endif