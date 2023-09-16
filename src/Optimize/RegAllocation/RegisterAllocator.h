#ifndef RegisterAllocator_h
#define RegisterAllocator_h

#include "ASMNode.h"
#include "Register.h"
#include "LivenessAnalysiser.h"
#include "DomTreeBuilder.h"
#include <unordered_map>


class RegisterAllocator {
private:
    const int K = 27;
    int spSize = 0;
    PhysicalRegister x[32];
    std::unordered_map<std::string, PhysicalRegister*> name2reg;
    std::unordered_map<ASMVarNode*, std::set<ASMVarNode*> > interferenceGraph;
    std::unordered_map<ASMVarNode*, std::set<ASMInsNode*>> defMap, setMap;
    std::unordered_map<ASMVarNode*, int> liveBegin, liveEnd;
    std::map<ASMVarNode*, ASMVarNode*> dsuMap;
    std::vector<ASMVarNode*> spilledStack, selectStack, coloredList;
    std::vector<ASMVarNode*> simplifyWorkList, spillWorkList, moveWorkList;
    std::set<ASMVarNode*> simplifyWorkSet, spillWorkSet, freezeWorkSet;
    std::set<ASMLocalVarNode*> usedReg;
    std::vector<ASMLocalVarNode*> regList, unused;
    std::vector<ASMInsNode*> calleeSaveIns, calleeLoadIns;    
    ASMBlockNode* returnBlock;    
    bool selected[32], called;
    LivenessAnalysiser* livenessAnalysiser = nullptr;
public:
    ASMLocalVarNode *zeroReg, *spReg, *aReg[8], *raReg, *sReg[12], *tReg[7];
    RegisterAllocator() {
        x[0].name = "zero";
        x[1].name = "ra";
        x[2].name = "sp";
        x[3].name = "gp";
        x[4].name = "tp";
        x[5].name = "t0";
        x[6].name = "t1";
        x[7].name = "t2";
        x[8].name = "s0";
        x[9].name = "s1";
        for (int i = 10; i <= 17; ++i) x[i].name = "a" + std::to_string(i - 10);
        for (int i = 18; i <= 27; ++i) x[i].name = "s" + std::to_string(i - 18 + 2);
        for (int i = 28; i <= 31; ++i) x[i].name = "t" + std::to_string(i - 28 + 3);
        for (int i = 0; i < 32; ++i) name2reg[x[i].name] = &x[i];
        for (int i = 0; i < 32; ++i) name2reg["x" + std::to_string(i)] = &x[i];
        for (int i = 0; i < 32; ++i) x[i].id = i;
        zeroReg = new ASMLocalVarNode(".zero.tmp", false, getReg("zero"));
        spReg = new ASMLocalVarNode(".sp.tmp", false, getReg("sp"));
        raReg = new ASMLocalVarNode(".ra.tmp", false, getReg("ra"));
        for (int i = 0; i < 8; ++i) {
            aReg[i] = new ASMLocalVarNode(".a" + std::to_string(i) + ".tmp", false, getReg("a" + std::to_string(i)));
        }
        for (int i = 0; i < 12; ++i) {
            sReg[i] = new ASMLocalVarNode(".s" + std::to_string(i) + ".tmp", false, getReg("s" + std::to_string(i)));
        }
        for (int i = 0; i < 7; ++i) {
            tReg[i] = new ASMLocalVarNode(".t" + std::to_string(i) + ".tmp", false, getReg("t" + std::to_string(i)));
        }
        for (int i = 0; i < 7; ++i) regList.push_back(tReg[i]);
        for (int i = 0; i < 8; ++i) regList.push_back(aReg[i]);
        for (int i = 0; i < 12; ++i) regList.push_back(sReg[i]);
    }
    Register* getReg(const std::string &name) {
        return name2reg[name];
    }
    void addCallDef(ASMFunctionNode* function) {
        for (auto block: function->blocks) {
            for (auto ins: block->insts) {
                if (dynamic_cast<ASMCallInsNode*>(ins)) {                   
                    called = true; 
                    for (int i = 0; i < 8; ++i) {
                        livenessAnalysiser->defSet[ins].insert(aReg[i]);
                    }
                    for (int i = 0; i < 7; ++i) {
                        livenessAnalysiser->defSet[ins].insert(tReg[i]);
                    }
                }
                if (auto ret = dynamic_cast<ASMRetInsNode*>(ins)) {
                    returnBlock = block;
                }
            }
        }
    }
    void collectVarLive(ASMFunctionNode* function) {
        int cnt = 0, sum = 0;
        for (auto block: function->blocks) {
            for (auto ins: block->insts) ++sum;            
        }
        for (auto block: function->blocks) {
            for (auto ins: block->insts) {
                for (auto var: livenessAnalysiser->defSet[ins]) {
                    // if (var->reg) continue;
                    if (!liveBegin.count(var)) {
                        auto &tmp = liveBegin[var];
                        tmp = cnt;
                        if (dynamic_cast<ASMLoadInsNode*>(ins) || dynamic_cast<ASMStoreInsNode*>(ins)) tmp += sum * 2;
                        if (dynamic_cast<ASMLaInsNode*>(ins)) tmp += sum;
                        if (var->reg) tmp += sum * 3;
                    }
                    liveEnd[var] = cnt;
                    ++cnt;
                }                
            }
        }
    }
    void build(ASMFunctionNode* function) {
        for (auto block: function->blocks) {
            for (auto ins: block->insts) {
                for (auto def: livenessAnalysiser->defSet[ins]) {          
                    auto name = def->to_string();                    
                    for (auto otherDef: livenessAnalysiser->defSet[ins]) {
                        if (def == otherDef) continue;
                            interferenceGraph[def].insert(otherDef);
                            interferenceGraph[otherDef].insert(def);                              
                    }
                    for (auto out: livenessAnalysiser->outSet[ins]) {
                        if (def == out) continue;
                        interferenceGraph[def].insert(out);
                        interferenceGraph[out].insert(def);                                            
                    }                    
                }
            }
        }            
    }
    ASMVarNode* dsuFind(ASMVarNode* node) {
        if (dsuMap[node] == node) return node;
        return dsuMap[node] = dsuFind(dsuMap[node]);
    }
    void MakeWorkList(ASMFunctionNode* function) {
        dsuMap.clear();
        for (auto block: function->blocks) {
            for (auto ins: block->insts) {
                if (auto mv = dynamic_cast<ASMMoveInsNode*>(ins)) {
                    bool flag = false;
                    auto src = mv->src, dest = mv->dest;                    
                    if (src->reg && dest->reg) continue;                    
                    dsuMap.emplace(src, src);
                    dsuMap.emplace(dest, dest);
                }
            }
        }                        
        
        for (auto block: function->blocks) {
            for (auto ins: block->insts) {
                if (auto mv = dynamic_cast<ASMMoveInsNode*>(ins)) {                
                    if (mv->src->reg && mv->dest->reg) continue;
                    auto a = mv->src, b = mv->dest;
                    
                    
                    auto fa = dsuFind(a), fb = dsuFind(b);
                    if (fa == fb) continue;
                    if (fa->reg) std::swap(fa, fb);                    
                    bool flag = true;
                    auto &neighbors_a = interferenceGraph[fa];
                    auto &neighbors_b = interferenceGraph[fb];                    
                    for (auto v: neighbors_a) {
                        if (v == fb) { flag = false; break; }
                        auto &tmp = interferenceGraph[v];
                        if (tmp.size() >= K && !tmp.contains(fb)) { flag = false; break; }                        
                    }                    
                    if (!flag) { 
                        if (!a->reg) freezeWorkSet.insert(a);
                        if (!b->reg) freezeWorkSet.insert(b);
                        continue; 
                    }  
                    dsuMap[fa] = fb;
                    for (auto v: neighbors_a) neighbors_b.insert(v), interferenceGraph[v].insert(fb), interferenceGraph[v].erase(fa);                                            
                    interferenceGraph.erase(fa);        
                }
            }
        }
        
        for (auto it: dsuMap) {
            auto node = it.first;
            auto fa = dsuFind(node);
            if (fa == node) continue;
            freezeWorkSet.erase(node);
            moveWorkList.push_back(node);
            
        }
        simplifyWorkSet.clear();
        simplifyWorkList.clear();
        for (auto node: interferenceGraph) {
            if (!node.first->reg &&  !freezeWorkSet.contains(node.first)){
                
                if (node.second.size() < K) {
                    if (simplifyWorkSet.insert(node.first).second) simplifyWorkList.push_back(node.first);
                    else throw std::runtime_error("node: " + node.first->name + "in simplifyWorkSet");
                }
                else spillWorkSet.insert(node.first);
            }
        }                
    }
    void simplify() {
        for (int i = 0; i < simplifyWorkList.size(); ++i) {
            auto node = simplifyWorkList[i];
            auto &neighbors = interferenceGraph[node];
            for (auto otherNode: neighbors) {
                auto size = interferenceGraph[otherNode].size();
                auto sum = interferenceGraph[otherNode].erase(node);
                if (sum && size == K && !otherNode->reg) {
                    if (simplifyWorkSet.insert(otherNode).second) simplifyWorkList.push_back(otherNode);
                    else throw std::runtime_error("node: " + otherNode->name + "in simplifyWorkSet");
                    spillWorkSet.erase(otherNode);
                }
            }
            if (node->reg) {
                throw std::runtime_error("simplify node->reg is not null: " + node->reg->name);
            }
            // for (auto v: selectStack) if (v == node) throw std::runtime_error("simplify node in selectStack");
            selectStack.push_back(node); // may be spill or color            
            freezeWorkSet.erase(node);
        }

        simplifyWorkList.clear();
        // simplifyWorkSet.clear();
    }
    void coalesce(ASMFunctionNode* function) {
        for (auto it: dsuMap) dsuFind(it.first);

        for (auto block: function->blocks) {
            for (auto ins: block->insts) ins->coalesce(dsuMap);
        }
        moveWorkList.clear();
    }
    void freeze() {        
        auto it = freezeWorkSet.begin();
        for (auto it_ = freezeWorkSet.begin(); it_ != freezeWorkSet.end(); ++it_) {
            if (interferenceGraph[*it_].size() < interferenceGraph[*it].size()) it = it_;
        }
        auto node = *it;
        freezeWorkSet.erase(it);
        if (interferenceGraph[node].size() < K) {
            if (simplifyWorkSet.insert(node).second) simplifyWorkList.push_back(node);
            else throw std::runtime_error("node: " + node->name + "in simplifyWorkSet");
        }
        else spillWorkSet.insert(node);
    }
    void selectSpill() {
        auto it = spillWorkSet.begin();
        for (auto it_ = spillWorkSet.begin(); it_ != spillWorkSet.end(); ++it_) {

            // if (liveBegin[*it_] < liveBegin[*it]) it = it_;
            // if (interferenceGraph[*it_].size() > interferenceGraph[*it].size()) it = it_;
            if (liveEnd[*it_] - liveBegin[*it_] > liveEnd[*it] - liveBegin[*it]) it = it_;            
            // auto val1 = 1ll * interferenceGraph[*it_].size() * (liveEnd[*it_] - liveBegin[*it_]);
            // auto val2 = 1ll * interferenceGraph[*it].size() * (liveEnd[*it] - liveBegin[*it]);
            // if (val1 > val2) it = it_;
        }
        auto node = *it;        
        spillWorkSet.erase(it);
        if (simplifyWorkSet.insert(node).second) simplifyWorkList.push_back(node);
        else throw std::runtime_error("node: " + node->name + "in simplifyWorkSet");                        
    }
    void assignColors() {
        if (selectStack.empty()) return ;
        for (auto node: selectStack) {
            if (node->reg) {
                throw std::runtime_error("color node: " + node->name + " ->reg is not null: " + node->reg->name + "before color");
            }
        }
        auto it = selectStack.end();
        while (true) {
            --it;
            auto node = *it;
            if (node->reg) {            
                throw std::runtime_error("color node: " + node->name + " ->reg is not null: " + node->reg->name + "when color");
            }
            for (int i = 0; i < 32; ++i) selected[i] = false;            

            for (auto neighbor: interferenceGraph[node]) {
                if (neighbor->reg) {                    
                    selected[neighbor->reg->id] = true;
                }
            }            
            for (int i = 0; i < K; ++i) {
                auto var = regList[i];
                auto reg = var->reg;
                if (!selected[reg->id]) {
                    node->reg = reg;
                    coloredList.push_back(node);
                    usedReg.insert(var);
                    break;
                }
            }
            if (!node->reg) { 
                for (auto n: spilledStack) if (n == node) throw std::runtime_error("spill node in spilledStack");                
                spilledStack.push_back(node);
            }
            else {
                for (int j = 0; j < spilledStack.size(); ++j) if (spilledStack[j] == node) {
                    spilledStack.erase(spilledStack.begin() + j);
                    break;
                }
            }
            if (it == selectStack.begin()) break;
        }
        selectStack.clear();
    }
    void rewrite(ASMFunctionNode* function) {
        std::set<ASMVarNode*> rewriteSet;        
        for (auto node: spilledStack) {
            if (node->reg) throw std::runtime_error("spilledStack node->reg is not null: " + node->reg->name);            
            rewriteSet.insert(node);
            node->reg = getReg("sp");
            node->offset = spSize;
            spSize += 4;
        }
        std::vector<ASMInsNode*> loadIns;
        std::vector<ASMInsNode*> storeIns;
        for (auto block: function->blocks) {
            for (auto it = block->insts.begin(); it != block->insts.end();) {
                auto ins = *it;
                if (ins == function->spAddIns || ins == function->spRetIns) { ++it; continue; }
                loadIns.clear();
                storeIns.clear();
                ins->rewrite(loadIns, storeIns, rewriteSet);
                for (auto load: loadIns) {
                    it = block->insts.insert(it, load);
                    ++it;
                }
                ++it;
                for (auto store: storeIns) {
                    it = block->insts.insert(it, store);
                    ++it;
                }
            }
        }
        spilledStack.clear();        
        for (auto node: coloredList) node->reg = nullptr;        
        coloredList.clear();
    }
    void removeSameMove(ASMFunctionNode* function) {
        for (auto block: function->blocks) {
            for (auto it = block->insts.begin(); it != block->insts.end();) {
                auto ins = *it;
                if (auto mv = dynamic_cast<ASMMoveInsNode*>(ins)) {
                    if (mv->src->reg == mv->dest->reg) {
                        it = block->insts.erase(it);
                        continue;
                    }
                }
                ++it;
            }
        }
    }
    void calleeSave(ASMLocalVarNode* saveReg) {
        if (!called && unused.size()) {
            auto reg = unused.back();
            unused.pop_back();
            auto mv = new ASMMoveInsNode(reg, saveReg);
            calleeSaveIns.push_back(mv);
            auto mv_ = new ASMMoveInsNode(saveReg, reg);
            calleeLoadIns.push_back(mv_);
        }
        else {
            auto var = new ASMLocalVarNode(".saveReg.tmp", false, getReg("sp"), spSize);
            spSize += 4;
            auto store = new ASMStoreInsNode("sw", var, saveReg, var->offset);
            calleeSaveIns.push_back(store);
            auto load = new ASMLoadInsNode("lw", saveReg, var, var->offset);
            calleeLoadIns.push_back(load);
        }
    }
    void work(ASMFunctionNode* function) {        
        spSize = 0;
        called = false;
        while (true) {
            livenessAnalysiser = new LivenessAnalysiser(function);
            livenessAnalysiser->LivenessAnalysis();            
            addCallDef(function);
            collectVarLive(function);
            build(function);            
            MakeWorkList(function);                    
            while (true) {                
                if (!simplifyWorkList.empty() ) simplify();
                else if (!moveWorkList.empty()) coalesce(function);
                else if (!freezeWorkSet.empty()) freeze();
                else if (!spillWorkSet.empty()) selectSpill();
                else break;
            }
            usedReg.clear();
            assignColors();            
            delete livenessAnalysiser;                        
            if (spilledStack.empty()) break;            
            rewrite(function);
        }
        coloredList.clear();
        calleeSaveIns.clear();
        calleeLoadIns.clear();
        unused.clear();
        for (int i = 0, k = 15; i < k; ++i) {
            auto reg = regList[i];
            if (!usedReg.contains(reg)) unused.push_back(reg);
        }
        calleeSave(raReg);        
        for (int i = 0; i < 12; ++i) if (usedReg.contains(sReg[i])) calleeSave(sReg[i]);
        auto &insts = function->blocks.front()->insts;
        int pos = 0;
        auto spAddIns = function->spAddIns;
        auto spRetIns = function->spRetIns;
        for (int i = 0, k = insts.size(); i < k; ++i) if (insts[i] == spAddIns) { pos = i; break; }
        insts.insert(insts.begin() + pos + 1, calleeSaveIns.begin(), calleeSaveIns.end());
        

        auto &insts_ = returnBlock->insts;
        pos = 0;
        for (int i = 0, k = insts_.size(); i < k; ++i) if (insts_[i] == spRetIns) { pos = i; break; }
        insts_.insert(insts_.begin() + pos, calleeLoadIns.begin(), calleeLoadIns.end());

        spSize = (spSize + 15) / 16 * 16;
        spAddIns->imm = -spSize;
        spRetIns->imm = spSize;
        removeSameMove(function);
    }    

};


#endif