#ifndef IRNODE_H
#define IRNODE_H
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include "IRType.h"

class IRNode {
public:
    IRNode() = default;
    ~IRNode() = default;
    virtual void print() = 0;
    virtual std::string to_string() = 0;
};

class IRValueNode: public IRNode {
public:
    IRType* type = nullptr;

    explicit IRValueNode(IRType* type_): type(type_) {}
    // void print() { std::cout << to_string(); };
    // std::string to_string() override;
};

class IRGlobalVarNode: public IRValueNode {
public:
    std::string name;

    explicit IRGlobalVarNode(IRType* type_, std::string name_): IRValueNode(type_), name(name_) {}
    void print() { std::cout << to_string(); };
    std::string to_string() override;
};

class IRVarNode: public IRValueNode {
public:
    std::string name;

    explicit IRVarNode(IRType* type_, std::string name_): IRValueNode(type_), name(name_) {}
    void print() { std::cout << to_string(); };
    std::string to_string() override;
};

class IRStmtNode: public IRNode {
public:
    
};

class IRBlockNode: public IRNode {
public:
    std::string label;
    std::vector<IRStmtNode*> stmts;

    explicit IRBlockNode(std::string label_): label(label_) {}
    ~IRBlockNode() { 
        
    }
    void print() { std::cout << to_string(); };
    std::string to_string() override;
};

class IRBrCondStmtNode: public IRStmtNode {
public:
    IRValueNode* cond = nullptr;
    std::string trueLabel, falseLabel;

    explicit IRBrCondStmtNode(IRValueNode* cond_, std::string trueLabel_, std::string falseLabel_): 
        cond(cond_), trueLabel(trueLabel_), falseLabel(falseLabel_) {}
    ~IRBrCondStmtNode() {}
    void print() { std::cout << to_string(); };
    std::string to_string() override;
};

class IRBrStmtNode: public IRStmtNode {
public:
    std::string label;

    explicit IRBrStmtNode(std::string label_): label(label_) {}
    ~IRBrStmtNode() {}
    void print() { std::cout << to_string(); };
    std::string to_string() override;
};

class IRRetStmtNode: public IRStmtNode {
public:
    IRValueNode* value = nullptr;

    explicit IRRetStmtNode(IRValueNode* value_): value(value_) {}
    ~IRRetStmtNode() {}
    void print() { std::cout << to_string(); };
    std::string to_string() override;
};

class IRBinaryStmtNode: public IRStmtNode {
public:
    std::string op;
    IRVarNode* var = nullptr;
    IRValueNode* lhs = nullptr;
    IRValueNode* rhs = nullptr;

    explicit IRBinaryStmtNode(std::string op_, IRVarNode* var_, IRValueNode* lhs_, IRValueNode* rhs_): 
        op(op_), var(var_), lhs(lhs_), rhs(rhs_) {}
    ~IRBinaryStmtNode() {}
    void print() { std::cout << to_string(); };
    std::string to_string() override;
};

class IRAllocaStmtNode: public IRStmtNode {
public:
    IRVarNode* var = nullptr;
    IRType* type = nullptr;
    explicit IRAllocaStmtNode(IRVarNode* var_, IRType* type_): var(var_), type(type_) {}
    ~IRAllocaStmtNode() { 
        
    }
    void print() { std::cout << to_string(); };
    std::string to_string() override;
};

class IRLoadStmtNode: public IRStmtNode {
public:
    IRVarNode *var = nullptr, *ptr = nullptr;

    explicit IRLoadStmtNode(IRVarNode* var_, IRVarNode* ptr_): var(var_), ptr(ptr_) {}
    ~IRLoadStmtNode() {}
    void print() { std::cout << to_string(); };
    std::string to_string() override;
};

class IRStoreStmtNode: public IRStmtNode {
public:
    IRValueNode* value = nullptr;
    IRVarNode* ptr = nullptr;

    explicit IRStoreStmtNode(IRValueNode* value_, IRVarNode* ptr_): value(value_), ptr(ptr_) {}
    ~IRStoreStmtNode() {}
    void print() { std::cout << to_string(); };
    std::string to_string() override;
};

class IRIcmpStmtNode: public IRStmtNode {
public:
    std::string op;
    IRVarNode* var = nullptr;
    IRValueNode* lhs = nullptr;
    IRValueNode* rhs = nullptr;

    explicit IRIcmpStmtNode(std::string op_, IRVarNode* var_, IRValueNode* lhs_, IRValueNode* rhs_): 
        op(op_), var(var_), lhs(lhs_), rhs(rhs_) {}
    ~IRIcmpStmtNode() {}
    void print() { std::cout << to_string(); };
    std::string to_string() override;
};

class IRLiteralNode: public IRValueNode {
public:
    int value;

    explicit IRLiteralNode(IRType* t_,  int value_): IRValueNode(t_), value(value_) {}
    ~IRLiteralNode() { 
        
    }
    void print() { std::cout << to_string(); };
    std::string to_string() override;
};

class IRStringNode: public IRLiteralNode {
public:
    std::string str;

    ~IRStringNode() { 
        
    }
    void print() { std::cout << to_string(); };
    std::string to_string() override;
};

class IRGlobalVarStmtNode: public IRStmtNode {
public:
    IRValueNode* value = nullptr;
    IRVarNode* var = nullptr;

    ~IRGlobalVarStmtNode() { 
        
    }
    explicit IRGlobalVarStmtNode(IRValueNode* value_, IRVarNode* var_): value(value_), var(var_) {}
    void print() { std::cout << to_string(); };
    std::string to_string() override;
};

class IRFunctionNode: public IRNode {
public:
    IRType* retType = nullptr;
    std::string name;
    std::vector<std::pair<IRType*, std::string>> args;
    std::vector<IRBlockNode*> blocks;

    explicit IRFunctionNode(IRType* retType_, std::string name_): retType(retType_), name(name_) {}
    ~IRFunctionNode() { 
        
    }
    void print() { std::cout << to_string(); };
    std::string to_string() override;
};

class IRClassNode: public IRNode {
public:
    std::string name;
    std::vector<IRVarNode*> vars;
    std::vector<IRFunctionNode*> functions;

    explicit IRClassNode(std::string name_): name(name_) {}
    ~IRClassNode() { 
        
    }
    void print() { std::cout << to_string(); };
    std::string to_string() override;
};

class IRProgramNode: public IRNode {
public:
    std::vector<IRClassNode *> classes;
    std::vector<IRFunctionNode *> functions;
    std::vector<IRGlobalVarStmtNode *> global_vars;

    ~IRProgramNode() { 
        
    }
    void print() { std::cout << to_string(); };
    std::string to_string() override;
};

#endif