#ifndef LivenessAnalysiser_H
#define LivenessAnalysiser_H

#include "IRNode.h"

class LivenessAnalysiser {
private:
    std::map<IRNode*, std::set<IRValueNode*> > useSet, defSet, inSet, outSet;
    bool changeFlag = false;
public:
    LivenessAnalysiser() {}
    // void getUseDef(CFGNode* node) {
    //     auto block = node->block;
    //     for (auto stmt: block->stmts) {
    //         stmt->getUse(useSet);
    //         stmt->getDef(defSet);
    //     }
    //     for (auto stmt: block->stmts) {
    //         auto tmpSet = useSet[stmt];
    //         for (auto v: defSet[block]) tmpSet.erase(v);
    //         for (auto v: tmpSet) useSet[block].insert(v);

    //         for (auto v: defSet[stmt]) defSet[block].insert(v);
    //     }
    //     for (auto child: node->next) getUseDef(child);
    // }
    // void getBlockInOut(CFGNode* node) {
    //     auto block = node->block;
    //     for (auto child: node->next) getBlockInOut(child);
    //     for (auto child: node->next) {
    //         for (auto v: inSet[child->block]) changeFlag |= outSet[block].insert(v).second;
    //     }
    //     inSet[block] = outSet[block];
    //     for (auto v: defSet[block]) inSet[block].erase(v);
    //     for (auto v: useSet[block]) changeFlag |= inSet[block].insert(v).second;
    // }
    // void getStmtInout(CFGNode* node) {
    //     auto block = node->block;
    //     for (auto child: node->next) getStmtInout(child);
    //     auto it = block->stmts.end();
    //     auto &tmpSet = outSet[block];
    //     while (true) {
    //         it--;
    //         inSet[*it] = outSet[*it] = tmpSet;
    //         for (auto v: defSet[*it]) inSet[*it].erase(v);
    //         for (auto v: useSet[*it]) inSet[*it].insert(v);
    //         if (it == block->stmts.begin()) break;
    //         tmpSet = inSet[*it];
    //     }
    // }
    // void LivenessAnalysis() {
    //     getUseDef(cfg->entry);
    //     changeFlag = true;
    //     while (changeFlag) {
    //         changeFlag = false;
    //         getBlockInOut(cfg->entry);
    //     }
    //     getStmtInOut(cfg->entry);
    // }
};


#endif