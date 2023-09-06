#ifndef ASM_NODE_H
#define ASM_NODE_H
#include <string>
#include <vector>
#include <iostream>
#include "Register.h"

class ASMNode {
public:
    ASMNode() = default;
    virtual ~ASMNode() = default;
    virtual std::string to_string() = 0;
};

class ASMVarNode: public ASMNode {
public:
    std::string name;
    bool is_ptr = false;
    Register* reg = nullptr;
    explicit ASMVarNode(std::string name_, bool p_, Register* reg_ = nullptr): name(name_), is_ptr(p_), reg(reg_) {}
};

class ASMGlobalVarNode: public ASMVarNode {
public:
    explicit ASMGlobalVarNode(std::string name_, bool p_, Register* reg_ = nullptr): ASMVarNode(name_, p_, reg_) {}
    std::string to_string() override;
};

class ASMLocalVarNode: public ASMVarNode {
public:
    int offset;
    explicit ASMLocalVarNode(std::string name_, bool p_, Register* reg_ = nullptr, int offset_ = 0): 
        ASMVarNode(name_, p_, reg_), offset(offset_) {}
    std::string to_string() override;
};

class ASMInsNode: public ASMNode {};

class ASMLaInsNode: public ASMInsNode {
public:
    ASMVarNode *dest = nullptr;
    std::string name;
    explicit ASMLaInsNode(ASMVarNode* dest_, std::string name_): dest(dest_), name(name_) {}
    std::string to_string() override;
};

class ASMLoadInsNode: public ASMInsNode {
public:
    int offset = 0;
    std::string op;
    ASMVarNode *dest = nullptr, *src = nullptr;
    explicit ASMLoadInsNode(std::string op_, ASMVarNode* dest_, ASMVarNode* src_, int offset_ = 0): 
        op(op_), dest(dest_), src(src_), offset(offset_) {}
    std::string to_string() override;
};

class ASMStoreInsNode: public ASMInsNode {
public:
    int offset = 0;
    std::string op;
    ASMVarNode *dest = nullptr, *src = nullptr;
    explicit ASMStoreInsNode(std::string op_, ASMVarNode* dest_, ASMVarNode* src_, int offset_ = 0): 
        op(op_), dest(dest_), src(src_), offset(offset_) {}
    std::string to_string() override;
};

class ASMBinaryInsNode: public ASMInsNode {
public:
    std::string op;
    ASMVarNode *dest = nullptr, *src1 = nullptr, *src2 = nullptr;
    explicit ASMBinaryInsNode(std::string op_, ASMVarNode* dest_, ASMVarNode* src1_, ASMVarNode* src2_): 
        op(op_), dest(dest_), src1(src1_), src2(src2_) {}
    std::string to_string() override;
};

class ASMImmInsNode: public ASMInsNode {
public:
    std::string op;
    ASMVarNode *dest = nullptr, *src = nullptr;
    int imm = 0;
    explicit ASMImmInsNode(std::string op_, ASMVarNode* dest_, ASMVarNode* src_, int imm_): 
        op(op_), dest(dest_), src(src_), imm(imm_) {}
    std::string to_string() override;
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
};

class ASMCallInsNode: public ASMInsNode {
public:
    std::string name;
    explicit ASMCallInsNode(std::string name_): name(name_) {}
    std::string to_string() override;
};

class ASMMoveInsNode: public ASMInsNode {
public:
    ASMVarNode *dest = nullptr, *src = nullptr;
    explicit ASMMoveInsNode(ASMVarNode* dest_, ASMVarNode* src_): dest(dest_), src(src_) {}
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