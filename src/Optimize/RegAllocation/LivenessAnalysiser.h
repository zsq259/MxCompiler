#ifndef LivenessAnalysiser_H
#define LivenessAnalysiser_H

#include <set>
#include <map>
#include <vector>
#include "ASMNode.h"


class ASMCFGNode {
public:
    ASMBlockNode* block;
    std::vector<ASMCFGNode*> next;
    std::vector<ASMCFGNode*> prev;
    ASMCFGNode(ASMBlockNode* block_): block(block_) {}
};

class RegisterAllocator;

class LivenessAnalysiser {
private:
    ASMFunctionNode* function;
    ASMCFGNode* entry;
    std::map<ASMNode*, std::set<ASMVarNode*> > useSet, defSet, inSet, outSet;
    std::map<std::string, ASMCFGNode*> blockMap;
    bool changeFlag = false;
    
    friend class RegisterAllocator;
public:
    explicit LivenessAnalysiser(ASMFunctionNode* f_):function(f_) {
        for (auto block: function->blocks) {
            auto node = new ASMCFGNode(block);
            blockMap[block->name] = node;
        }
        entry = blockMap["main"];
        for (auto block: function->blocks) {
            auto now = blockMap[block->name];
            for (auto ins: block->insts) {
                if (auto j = dynamic_cast<ASMJumpInsNode*>(ins)) {
                    auto next = blockMap[j->label];
                    now->next.push_back(next);
                    next->prev.push_back(now);
                    break;
                }
                if (auto b = dynamic_cast<ASMBranchInsNode*>(ins)) {
                    auto next = blockMap[b->label];
                    now->next.push_back(next);
                    next->prev.push_back(now);
                    break;
                }
            }
        }
    }
    ~LivenessAnalysiser() {
        for (auto p: blockMap) delete p.second;
    }
    void getUseDef(ASMCFGNode* node) {
        auto block = node->block;
        for (auto ins: block->insts) {
            ins->getUse(useSet);
            ins->getDef(defSet);
        }
        for (auto ins: block->insts) {
            auto tmpSet = useSet[ins];
            for (auto v: defSet[block]) tmpSet.erase(v);
            for (auto v: tmpSet) useSet[block].insert(v);

            for (auto v: defSet[ins]) defSet[block].insert(v);
        }
        for (auto child: node->next) getUseDef(child);
    }
    void getBlockInOut(ASMCFGNode* node) {
        auto block = node->block;
        for (auto child: node->next) getBlockInOut(child);
        for (auto child: node->next) {
            for (auto v: inSet[child->block]) changeFlag |= outSet[block].insert(v).second;
        }
        inSet[block] = outSet[block];
        for (auto v: defSet[block]) inSet[block].erase(v);
        for (auto v: useSet[block]) changeFlag |= inSet[block].insert(v).second;
    }
    void getStmtInOut(ASMCFGNode* node) {
        auto block = node->block;
        for (auto child: node->next) getStmtInOut(child);
        auto it = block->insts.end();
        auto &tmpSet = outSet[block];
        while (true) {
            it--;
            inSet[*it] = outSet[*it] = tmpSet;
            for (auto v: defSet[*it]) inSet[*it].erase(v);
            for (auto v: useSet[*it]) inSet[*it].insert(v);
            if (it == block->insts.begin()) break;
            tmpSet = inSet[*it];
        }
    }
    void LivenessAnalysis() {
        getUseDef(entry);
        changeFlag = true;
        while (changeFlag) {
            changeFlag = false;
            getBlockInOut(entry);
        }
        getStmtInOut(entry);
    }
};


#endif