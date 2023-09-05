#ifndef NAIVE_ASM_NODE_H
#define NAIVE_ASM_NODE_H
#include <string>
#include <vector>
#include <iostream>
#include "Register.h"

class NaiveASMNode {
public:
    NaiveASMNode() = default;
    virtual ~NaiveASMNode() = default;
    virtual std::string to_string() = 0;
};

class NaiveASMVarNode: public NaiveASMNode {
public:
    std::string name;
    bool is_ptr = false;
    explicit NaiveASMVarNode(std::string name_, bool p_): name(name_), is_ptr(p_) {}
};

class NaiveASMGlobalVarNode: public NaiveASMVarNode {
public:
    explicit NaiveASMGlobalVarNode(std::string name_, bool p_): NaiveASMVarNode(name_, p_) {}
    std::string to_string() override;
};

class NaiveASMLocalVarNode: public NaiveASMVarNode {
public:
    Register* reg = nullptr;
    int offset;
    explicit NaiveASMLocalVarNode(std::string name_, int offset_, bool p_): 
        NaiveASMVarNode(name_, p_), offset(offset_) {}
    std::string to_string() override;
};

class NaiveASMInsNode: public NaiveASMNode {};

class NaiveASMLaInsNode: public NaiveASMInsNode {
public:
    Register *dest = nullptr;
    std::string name;
    explicit NaiveASMLaInsNode(Register* dest_, std::string name_): dest(dest_), name(name_) {}
    std::string to_string() override;
};

class NaiveASMLoadInsNode: public NaiveASMInsNode {
public:
    std::string op, label;
    Register *dest = nullptr, *src = nullptr;
    int offset = 0;
    explicit NaiveASMLoadInsNode(std::string op_, Register* dest_, Register* src_, int offset_ = 0): 
        op(op_), dest(dest_), src(src_), offset(offset_) {}
    std::string to_string() override;
};

class NaiveASMStoreInsNode: public NaiveASMInsNode {
public:
    std::string op, label;
    Register *dest = nullptr, *src = nullptr;
    int offset = 0;
    explicit NaiveASMStoreInsNode(std::string op_, Register* dest_, Register* src_, int offset_ = 0): 
        op(op_), dest(dest_), src(src_), offset(offset_) {}
    std::string to_string() override;
};

class NaiveASMBinaryInsNode: public NaiveASMInsNode {
public:
    std::string op;
    Register *dest = nullptr, *src1 = nullptr, *src2 = nullptr;
    explicit NaiveASMBinaryInsNode(std::string op_, Register* dest_, Register* src1_, Register* src2_): 
        op(op_), dest(dest_), src1(src1_), src2(src2_) {}
    std::string to_string() override;
};

class NaiveASMImmInsNode: public NaiveASMInsNode {
public:
    std::string op;
    Register *dest = nullptr, *src = nullptr;
    int imm = 0;
    explicit NaiveASMImmInsNode(std::string op_, Register* dest_, Register* src_, int imm_): 
        op(op_), dest(dest_), src(src_), imm(imm_) {}
    std::string to_string() override;
};

class NaiveASMJumpInsNode: public NaiveASMInsNode {
public:
    std::string label;
    explicit NaiveASMJumpInsNode(std::string label_): label(label_) {}
    std::string to_string() override;
};

class NaiveASMRetInsNode: public NaiveASMInsNode {
public:
    std::string to_string() override;
};

class NaiveASMBranchInsNode: public NaiveASMInsNode {
public:
    Register *src1, *src2;
    std::string op, label;
    explicit NaiveASMBranchInsNode(std::string op_, Register* rs1_, Register* rs2_, std::string label_): 
        op(op_), src1(rs1_), src2(rs2_), label(label_) {}
    std::string to_string() override;
};

class NaiveASMCallInsNode: public NaiveASMInsNode {
public:
    std::string name;
    explicit NaiveASMCallInsNode(std::string name_): name(name_) {}
    std::string to_string() override;
};

class NaiveASMBlockNode: public NaiveASMNode {
public:
    std::string name;
    std::vector<NaiveASMInsNode*> insts;
    explicit NaiveASMBlockNode(std::string name_): name(name_) {}
    ~NaiveASMBlockNode() override {
        for (auto ins: insts) delete ins;
    }
    std::string to_string() override;
};

class NaiveASMFunctionNode: public NaiveASMNode {
public:
    std::vector<NaiveASMBlockNode*> blocks;

    ~NaiveASMFunctionNode() override {
        for (auto b: blocks) delete b;
    }
    std::string to_string() override;
};

class NaiveASMGlobalVarStmtNode: public NaiveASMNode {
public:
    bool is_string = false;
    std::string name, value;
    explicit NaiveASMGlobalVarStmtNode(std::string name_, std::string value_, bool is_string_): 
        name(name_), value(value_), is_string(is_string_) {}
    std::string to_string() override;
};

class NaiveASMDataSectionNode: public NaiveASMNode {
public:
    std::vector<NaiveASMGlobalVarStmtNode*> globalVarStmts;
    ~NaiveASMDataSectionNode() override {
        for (auto g: globalVarStmts) delete g;
    }
    std::string to_string() override;
};

class NaiveASMTextSectionNode: public NaiveASMNode {
public:
    std::vector<NaiveASMFunctionNode*> functions;
    ~NaiveASMTextSectionNode() override {
        for (auto f: functions) delete f;
    }
    std::string to_string() override;
};

class NaiveASMProgramNode: public NaiveASMNode {
public:
    NaiveASMDataSectionNode* data = nullptr;
    NaiveASMTextSectionNode* text = nullptr;
    
    NaiveASMProgramNode() = default;
    ~NaiveASMProgramNode() override {
        delete data;
        delete text;
    }
    std::string to_string() override;
};

#endif