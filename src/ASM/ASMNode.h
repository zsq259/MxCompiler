#ifndef ASM_NODE_H
#define ASM_NODE_H
#include <string>
#include <list>
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
    explicit ASMVarNode(std::string name_): name(name_) {}
};

class ASMGlobalVarNode: public ASMVarNode {
public:
    explicit ASMGlobalVarNode(std::string name_): ASMVarNode(name_) {}
    std::string to_string() override;
};

class ASMLocalVarNode: public ASMVarNode {
public:
    Register* reg = nullptr;
    int offset;
    explicit ASMLocalVarNode(std::string name_, int offset_): 
        ASMVarNode(name_), offset(offset_) {}
    std::string to_string() override;
};

class ASMInsNode: public ASMNode {};

class ASMLaInsNode: public ASMInsNode {
public:
    Register *dest = nullptr;
    std::string name;
    explicit ASMLaInsNode(Register* dest_, std::string name_): dest(dest_), name(name_) {}
    std::string to_string() override;
};

class ASMLoadInsNode: public ASMInsNode {
public:
    std::string op;
    Register *dest = nullptr, *src = nullptr;
    int offset = 0;
    explicit ASMLoadInsNode(std::string op_, Register* dest_, Register* src_, int offset_ = 0): 
        op(op_), dest(dest_), src(src_), offset(offset_) {}
    std::string to_string() override;
};

class ASMStoreInsNode: public ASMInsNode {
public:
    std::string op;
    Register *dest = nullptr, *src = nullptr;
    int offset = 0;
    explicit ASMStoreInsNode(std::string op_, Register* dest_, Register* src_, int offset_ = 0): 
        op(op_), dest(dest_), src(src_), offset(offset_) {}
    std::string to_string() override;
};

class ASMBinaryInsNode: public ASMInsNode {
public:
    std::string op;
    Register *dest = nullptr, *src1 = nullptr, *src2 = nullptr;
    explicit ASMBinaryInsNode(std::string op_, Register* dest_, Register* src1_, Register* src2_): 
        op(op_), dest(dest_), src1(src1_), src2(src2_) {}
    std::string to_string() override;
};

class ASMImmInsNode: public ASMInsNode {
public:
    std::string op;
    Register *dest = nullptr, *src = nullptr;
    int imm = 0;
    explicit ASMImmInsNode(std::string op_, Register* dest_, Register* src_, int imm_): 
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
    Register *src1, *src2;
    std::string op, label;
    explicit ASMBranchInsNode(std::string op_, Register* rs1_, Register* rs2_, std::string label_): 
        op(op_), src1(rs1_), src2(rs2_), label(label_) {}
    std::string to_string() override;
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
    std::list<ASMInsNode*> insts;
    explicit ASMBlockNode(std::string name_): name(name_) {}
    std::string to_string() override;
};

class ASMFunctionNode: public ASMNode {
public:
    std::list<ASMBlockNode*> blocks;
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
    std::list<ASMGlobalVarStmtNode*> globalVarStmts;

    std::string to_string() override;
};

class ASMTextSectionNode: public ASMNode {
public:
    std::list<ASMFunctionNode*> functions;
    std::string to_string() override;
};

class ASMProgramNode: public ASMNode {
public:
    ASMDataSectionNode* data = nullptr;
    ASMTextSectionNode* text = nullptr;
    
    ASMProgramNode() = default;
    std::string to_string() override;
};

#endif