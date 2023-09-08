#ifndef RegisterAllocator_h
#define RegisterAllocator_h

#include "ASMNode.h"
#include "Register.h"
#include "LivenessAnalysiser.h"

class RegisterAllocator {
private:
    const int K = 27;
    int spSize = 0;
    PhysicalRegister x[32];
    std::map<std::string, PhysicalRegister*> name2reg;
    std::map<ASMVarNode*, std::set<ASMVarNode*> > interferenceGraph;
    std::map<ASMVarNode*, std::set<ASMInsNode*>> defMap, setMap;
    std::map<ASMVarNode*, int> liveBegin;
    std::vector<ASMVarNode*> spilledStack, selectStack;
    std::vector<ASMVarNode*> simplifyWorkList, moveWorkList, freezeWorkList, spillWorkList;
    std::set<ASMVarNode*> simplifyWorkSet, spillWorkSet;
    bool selected[32];
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
    }
    Register* getReg(const std::string &name) {
        return name2reg[name];
    }
    void addCallDef(ASMFunctionNode* function) {
        for (auto block: function->blocks) {
            for (auto ins: block->insts) {
                if (dynamic_cast<ASMCallInsNode*>(ins)) {                    
                    for (int i = 0; i < 8; ++i) {
                        livenessAnalysiser->defSet[ins].insert(aReg[i]);
                    }
                    for (int i = 0; i < 7; ++i) {
                        livenessAnalysiser->defSet[ins].insert(tReg[i]);
                    }
                }
            }
        }
    }
    void collectVarLive(ASMFunctionNode* function) {
        int cnt = 0;
        for (auto block: function->blocks) {
            for (auto ins: block->insts) {
                for (auto var: livenessAnalysiser->defSet[ins]) {
                    if (var->reg) continue;
                    if (!liveBegin.count(var)) liveBegin[var] = cnt;                    
                }
                ++cnt;
            }
        }
    }
    void build(ASMFunctionNode* function) {
        for (auto block: function->blocks) {
            for (auto ins: block->insts) {
                for (auto def: livenessAnalysiser->defSet[ins]) {                    
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
    void MakeWorkList() {
        for (auto node: interferenceGraph) {
            if (!node.first->reg){            
                if (node.second.size() < K) {
                    if (simplifyWorkSet.insert(node.first).second) simplifyWorkList.push_back(node.first);
                    // else std::cerr << "node: " << node.first->name << '\n';
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
                    spillWorkSet.erase(otherNode);
                }
            }
            if (node->reg) {
                throw std::runtime_error("simplify node->reg is not null: " + node->reg->name);
            }
            for (auto v: selectStack) { if (v == node) throw std::runtime_error("simplify node in selectStack"); }
            selectStack.push_back(node); // may be spill or color            

        }

        simplifyWorkList.clear();
        simplifyWorkSet.clear();
    }
    void selectSpill() {
        auto it = spillWorkSet.begin();
        for (auto it_ = spillWorkSet.begin(); it_ != spillWorkSet.end(); ++it_) {

            if (liveBegin[*it_] > liveBegin[*it]) it = it_;
        }

        auto node = *it;
        spillWorkSet.erase(it);
        if (simplifyWorkSet.insert(node).second) simplifyWorkList.push_back(node);
        spilledStack.push_back(node);
    }
    void assignColors() {
        if (selectStack.empty()) {
            return ;
            throw std::runtime_error("selectStack is empty");
        }
        for (auto node: selectStack) {
            
            if (node->reg) {
                std::cerr << "node: " << node << ' ' << node->reg << '\n';    
                std::cerr << node->to_string() <<'\n';
                throw std::runtime_error("color node->reg is not null: " + node->reg->name);
            }
        }
        auto it = selectStack.end();
        while (true) {
            --it;
            auto node = *it;
            if (node->reg) {            
                std::cerr << node->to_string() <<'\n';                
                throw std::runtime_error("color node: " + node->name + " ->reg is not null: " + node->reg->name);
            }
            for (int i = 0; i < 32; ++i) selected[i] = false;
            for (auto neighbor: interferenceGraph[node]) {
                if (neighbor->reg) selected[neighbor->reg->id] = true;
            }
            for (int i = 8; i < 32; ++i) {                
                if (!selected[i]) { node->reg = &x[i]; break; }
            }
            if (!node->reg) { 
                spilledStack.push_back(node);
            }
            if (it == selectStack.begin()) break;
        }
        selectStack.clear();
    }
    void rewrite(ASMFunctionNode* function) {
        for (auto node: spilledStack) {
            if (node->reg) continue;
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
                ins->rewrite(loadIns, storeIns);
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
    }
    void work(ASMFunctionNode* function) {
        spSize = 0;
        while (true) {
            
            livenessAnalysiser = new LivenessAnalysiser(function);
            // std::cerr << "ojbk\n";
            livenessAnalysiser->LivenessAnalysis();
            // std::cerr << "ojbk1\n";
            addCallDef(function);
            // std::cerr << "ojbk2\n";
            build(function);
            collectVarLive(function);
            // std::cerr << "ojbk3" << std::endl;
            MakeWorkList();
            // std::cerr << "ojbk4" << std::endl;
            while (true) {
                if (!simplifyWorkList.empty() ) simplify();
                else if (!moveWorkList.empty()) {}
                else if (!freezeWorkList.empty()) {}
                else if (!spillWorkSet.empty()) selectSpill();
                else break;
            }
            // std::cerr << "ojbk5\n";
            assignColors();
            // std::cerr << "ojbk6\n";
            delete livenessAnalysiser;
            // std::cerr << "ojbk7\n";
            if (spilledStack.empty()) break;
            rewrite(function);
        }
        spSize = (spSize + 15) / 16 * 16;
        function->spAddIns->imm = -spSize;
        function->spRetIns->imm = spSize;
    }

};


#endif