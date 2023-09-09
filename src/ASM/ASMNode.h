#ifndef ASM_NODE_H
#define ASM_NODE_H
#include <set>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include "Register.h"

static std::map<std::string, int> counter;

class ASMNode {
public:
    ASMNode() = default;
    virtual ~ASMNode() = default;
    virtual std::string to_string() = 0;
};

class ASMVarNode: public ASMNode {
public:
    int offset;
    std::string name;
    bool is_ptr = false;
    Register* reg = nullptr;
    explicit ASMVarNode(std::string name_, bool p_, Register* reg_ = nullptr, int offset_ = 0): name(name_), is_ptr(p_), reg(reg_), offset(offset_) {}
};

class ASMGlobalVarNode: public ASMVarNode {
public:
    explicit ASMGlobalVarNode(std::string name_, bool p_, Register* reg_ = nullptr): ASMVarNode(name_, p_, reg_) {}
    std::string to_string() override;
};

class ASMLocalVarNode: public ASMVarNode {
public:
    
    explicit ASMLocalVarNode(std::string name_, bool p_, Register* reg_ = nullptr, int offset_ = 0): 
        ASMVarNode(name_, p_, reg_, offset_) {}
    std::string to_string() override;
};

class ASMInsNode: public ASMNode {
public:
    virtual void getUse(std::map<ASMNode*, std::set<ASMVarNode*> > &useSet) {}
    virtual void getDef(std::map<ASMNode*, std::set<ASMVarNode*> > &defSet) {}
    virtual void rewrite(std::vector<ASMInsNode*> &loadIns, std::vector<ASMInsNode*> &storeIns) {}
    virtual void coalesce(std::map<ASMVarNode*, ASMVarNode*> &dsuMap) {}
};

class ASMLoadInsNode: public ASMInsNode {
public:
    int offset = 0;
    std::string op;
    ASMVarNode *dest = nullptr, *src = nullptr;
    explicit ASMLoadInsNode(std::string op_, ASMVarNode* dest_, ASMVarNode* src_, int offset_): 
        op(op_), dest(dest_), src(src_), offset(offset_) {
            // if (offset < 0) throw std::runtime_error("offset < 0" + dest->name + " " + src->name);
        }
    std::string to_string() override;
    void getUse(std::map<ASMNode*, std::set<ASMVarNode*> > &useSet) override {
        useSet[this].insert(src);
    }
    void getDef(std::map<ASMNode*, std::set<ASMVarNode*> > &defSet) override {
        defSet[this].insert(dest);
    }
    void rewrite(std::vector<ASMInsNode*> &loadIns, std::vector<ASMInsNode*> &storeIns) override;
    void coalesce(std::map<ASMVarNode*, ASMVarNode*> &dsuMap) {
        if (dsuMap.contains(dest)) dest = dsuMap[dest];
        if (dsuMap.contains(src)) src = dsuMap[src];
    }
};

class ASMStoreInsNode: public ASMInsNode {
public:
    int offset = 0;
    std::string op;
    ASMVarNode *dest = nullptr, *src = nullptr;
    explicit ASMStoreInsNode(std::string op_, ASMVarNode* dest_, ASMVarNode* src_, int offset_): 
        op(op_), dest(dest_), src(src_), offset(offset_) {}
    std::string to_string() override;
    void getUse(std::map<ASMNode*, std::set<ASMVarNode*> > &useSet) override {
        useSet[this].insert(dest);
        useSet[this].insert(src);
    }
    void rewrite(std::vector<ASMInsNode*> &loadIns, std::vector<ASMInsNode*> &storeIns) {
        if (src->reg && src->reg->id == 2) {
            auto tmp = new ASMLocalVarNode(".store.tmp" + std::to_string(counter[".store.tmp"]++), false);
            auto load = new ASMLoadInsNode("lw", tmp, src, src->offset);
            loadIns.push_back(load);
            src = tmp;
        }
    }
    void coalesce(std::map<ASMVarNode*, ASMVarNode*> &dsuMap) {
        if (dsuMap.contains(dest)) dest = dsuMap[dest];
        if (dsuMap.contains(src)) src = dsuMap[src];
    }
};

class ASMMoveInsNode: public ASMInsNode {
public:
    ASMVarNode *dest = nullptr, *src = nullptr;
    explicit ASMMoveInsNode(ASMVarNode* dest_, ASMVarNode* src_): dest(dest_), src(src_) {}
    std::string to_string() override;
    void getUse(std::map<ASMNode*, std::set<ASMVarNode*> > &useSet) override {
        if (!src) std::cerr << "src is nullptr\n";
        useSet[this].insert(src);
    }
    void getDef(std::map<ASMNode*, std::set<ASMVarNode*> > &defSet) override {
        defSet[this].insert(dest);
    }
    void rewrite(std::vector<ASMInsNode*> &loadIns, std::vector<ASMInsNode*> &storeIns) {
        if (src->reg && src->reg->id == 2 && dest->reg && dest->reg->id == 2) {
            auto tmp = new ASMLocalVarNode(".move.tmp" + std::to_string(counter[".move.tmp"]++), false);
            auto load = new ASMLoadInsNode("lw", tmp, src, src->offset);
            loadIns.push_back(load);
            auto store = new ASMStoreInsNode("sw", dest, tmp, dest->offset);
            storeIns.push_back(store);
            dest = src = tmp;
        }
        else if (src->reg && src->reg->id == 2) {            
            auto load = new ASMLoadInsNode("lw", dest, src, src->offset);
            loadIns.push_back(load);
            src = dest;
        }
        else if (dest->reg && dest->reg->id == 2) {
            auto store = new ASMStoreInsNode("sw", dest, src, dest->offset);
            storeIns.push_back(store);
            dest = src;
        }
    }
    void coalesce(std::map<ASMVarNode*, ASMVarNode*> &dsuMap) {
        if (dsuMap.contains(dest)) dest = dsuMap[dest];
        if (dsuMap.contains(src)) src = dsuMap[src];
    }
};

class ASMLaInsNode: public ASMInsNode {
public:
    ASMVarNode *dest = nullptr;
    std::string name;
    explicit ASMLaInsNode(ASMVarNode* dest_, std::string name_): dest(dest_), name(name_) {}
    std::string to_string() override;
    void getDef(std::map<ASMNode*, std::set<ASMVarNode*> > &defSet) override {
        defSet[this].insert(dest);
    }
    void rewrite(std::vector<ASMInsNode*> &loadIns, std::vector<ASMInsNode*> &storeIns) {
        if (dest->reg && dest->reg->id == 2) {
            auto tmp = new ASMLocalVarNode(".la.tmp" + std::to_string(counter[".la.tmp"]++), false);
            auto store = new ASMStoreInsNode("sw", dest, tmp, dest->offset);
            storeIns.push_back(store);
            dest = tmp;
            // throw std::runtime_error("la dest is sp");
        }
    }
    void coalesce(std::map<ASMVarNode*, ASMVarNode*> &dsuMap) {
        if (dsuMap.contains(dest)) dest = dsuMap[dest];
    }
};

class ASMBinaryInsNode: public ASMInsNode {
public:
    std::string op;
    ASMVarNode *dest = nullptr, *src1 = nullptr, *src2 = nullptr;
    explicit ASMBinaryInsNode(std::string op_, ASMVarNode* dest_, ASMVarNode* src1_, ASMVarNode* src2_): 
        op(op_), dest(dest_), src1(src1_), src2(src2_) {}
    std::string to_string() override;
    void getUse(std::map<ASMNode*, std::set<ASMVarNode*> > &useSet) override {
        useSet[this].insert(src1);
        useSet[this].insert(src2);
    }
    void getDef(std::map<ASMNode*, std::set<ASMVarNode*> > &defSet) override {
        defSet[this].insert(dest);
    }
    void rewrite(std::vector<ASMInsNode*> &loadIns, std::vector<ASMInsNode*> &storeIns) {
        if (src1->reg && src1->reg->id == 2) {
            auto tmp = new ASMLocalVarNode(".binary.tmp" + std::to_string(counter[".binary.tmp"]++), false);
            auto load = new ASMLoadInsNode("lw", tmp, src1, src1->offset);
            loadIns.push_back(load);
            src1 = tmp;
        }
        if (src2->reg && src2->reg->id == 2) {
            auto tmp = new ASMLocalVarNode(".binary.tmp" + std::to_string(counter[".binary.tmp"]++), false);
            auto load = new ASMLoadInsNode("lw", tmp, src2, src2->offset);
            loadIns.push_back(load);
            src2 = tmp;
        }
        if (dest->reg && dest->reg->id == 2) {
            auto tmp = new ASMLocalVarNode(".binary.tmp" + std::to_string(counter[".binary.tmp"]++), false);
            auto store = new ASMStoreInsNode("sw", dest, tmp, dest->offset);
            storeIns.push_back(store);
            dest = tmp;
        }
    }
    void coalesce(std::map<ASMVarNode*, ASMVarNode*> &dsuMap) {
        if (dsuMap.contains(dest)) dest = dsuMap[dest];
        if (dsuMap.contains(src1)) src1 = dsuMap[src1];
        if (dsuMap.contains(src2)) src2 = dsuMap[src2];
    }
};

class ASMImmInsNode: public ASMInsNode {
public:
    std::string op;
    ASMVarNode *dest = nullptr, *src = nullptr;
    int imm = 0;
    explicit ASMImmInsNode(std::string op_, ASMVarNode* dest_, ASMVarNode* src_, int imm_): 
        op(op_), dest(dest_), src(src_), imm(imm_) {}
    std::string to_string() override;
    void getUse(std::map<ASMNode*, std::set<ASMVarNode*> > &useSet) override {
        useSet[this].insert(src);
    }
    void getDef(std::map<ASMNode*, std::set<ASMVarNode*> > &defSet) override {
        defSet[this].insert(dest);
    }
    void rewrite(std::vector<ASMInsNode*> &loadIns, std::vector<ASMInsNode*> &storeIns) {
        if (src->reg && src->reg->id == 2) {
            auto tmp = new ASMLocalVarNode(".imm.tmp" + std::to_string(counter[".imm.tmp"]++), false);
            auto load = new ASMLoadInsNode("lw", tmp, src, src->offset);
            loadIns.push_back(load);
            src = tmp;
        }
        if (dest->reg && dest->reg->id == 2) {
            auto tmp = new ASMLocalVarNode(".imm.tmp" + std::to_string(counter[".imm.tmp"]++), false);
            auto store = new ASMStoreInsNode("sw", dest, tmp, dest->offset);
            storeIns.push_back(store);
            dest = tmp;
        }
    }
    void coalesce(std::map<ASMVarNode*, ASMVarNode*> &dsuMap) {
        if (dsuMap.contains(dest)) dest = dsuMap[dest];
        if (dsuMap.contains(src)) src = dsuMap[src];
    }
};

class ASMJumpInsNode: public ASMInsNode {
public:
    std::string label;
    explicit ASMJumpInsNode(std::string label_): label(label_) {}
    std::string to_string() override;
};

class ASMRetInsNode: public ASMInsNode {
public:
    std::string to_string() override;
};

class ASMBranchInsNode: public ASMInsNode {
public:
    ASMVarNode *src1, *src2;
    std::string op, label;
    explicit ASMBranchInsNode(std::string op_, ASMVarNode* rs1_, ASMVarNode* rs2_, std::string label_): 
        op(op_), src1(rs1_), src2(rs2_), label(label_) {}
    std::string to_string() override;
    void getUse(std::map<ASMNode*, std::set<ASMVarNode*> > &useSet) override {
        useSet[this].insert(src1);
        useSet[this].insert(src2);
    }
    void rewrite(std::vector<ASMInsNode*> &loadIns, std::vector<ASMInsNode*> &storeIns) {
        if (src1->reg && src1->reg->id == 2) {
            auto tmp = new ASMLocalVarNode(".branch.tmp" + std::to_string(counter[".branch.tmp"]++), false);
            auto load = new ASMLoadInsNode("lw", tmp, src1, src1->offset);
            loadIns.push_back(load);
            src1 = tmp;
        }
        if (src2->reg && src2->reg->id == 2) {
            auto tmp = new ASMLocalVarNode(".branch.tmp" + std::to_string(counter[".branch.tmp"]++), false);
            auto load = new ASMLoadInsNode("lw", tmp, src2, src2->offset);
            loadIns.push_back(load);
            src2 = tmp;
        }
    }
    void coalesce(std::map<ASMVarNode*, ASMVarNode*> &dsuMap) {
        if (dsuMap.contains(src1)) src1 = dsuMap[src1];
        if (dsuMap.contains(src2)) src2 = dsuMap[src2];
    }
};

class ASMCallInsNode: public ASMInsNode {
public:
    std::string name;
    explicit ASMCallInsNode(std::string name_): name(name_) {}
    std::string to_string() override;

};

class ASMBlockNode: public ASMNode {
public:
    std::string name;
    std::vector<ASMInsNode*> insts;
    explicit ASMBlockNode(std::string name_): name(name_) {}
    ~ASMBlockNode() override {
        for (auto ins: insts) delete ins;
    }
    std::string to_string() override;
};

class ASMFunctionNode: public ASMNode {
public:
    ASMImmInsNode *spAddIns = nullptr, *spRetIns = nullptr;
    std::vector<ASMBlockNode*> blocks;

    ~ASMFunctionNode() override {
        for (auto b: blocks) delete b;
    }
    std::string to_string() override;
};

class ASMGlobalVarStmtNode: public ASMNode {
public:
    bool is_string = false;
    std::string name, value;
    explicit ASMGlobalVarStmtNode(std::string name_, std::string value_, bool is_string_): 
        name(name_), value(value_), is_string(is_string_) {}
    std::string to_string() override;
};

class ASMDataSectionNode: public ASMNode {
public:
    std::vector<ASMGlobalVarStmtNode*> globalVarStmts;
    ~ASMDataSectionNode() override {
        for (auto g: globalVarStmts) delete g;
    }
    std::string to_string() override;
};

class ASMTextSectionNode: public ASMNode {
public:
    std::vector<ASMFunctionNode*> functions;
    ~ASMTextSectionNode() override {
        for (auto f: functions) delete f;
    }
    std::string to_string() override;
};

class ASMProgramNode: public ASMNode {
public:
    ASMDataSectionNode* data = nullptr;
    ASMTextSectionNode* text = nullptr;
    
    ASMProgramNode() = default;
    ~ASMProgramNode() override {
        delete data;
        delete text;
    }
    std::string to_string() override;
};

#endif