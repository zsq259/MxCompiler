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

    IRValueNode() = default;
    IRValueNode(IRType* t_): type(t_) {}
    // void print() { std::cout << to_string(); };
    // std::string to_string() override;
};

class IRVarNode: public IRValueNode {
public:
    std::string name;

    IRVarNode() = default;
    IRVarNode(std::string name_): name(name_) {}
    void print() { std::cout << to_string(); };
    std::string to_string() { return ""; }
};

class IRStmtNode: public IRValueNode {};

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

class IRLiteralNode: public IRValueNode {
public:
    int value;

    IRLiteralNode() = default;
    IRLiteralNode(IRType* t_,  int value_): IRValueNode(t_), value(value_) {}
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
    void print() { std::cout << to_string(); };
    std::string to_string() override;
};

class IRVarStmtNode: public IRStmtNode {
public:
    IRValueNode* value = nullptr;
    IRVarNode* var = nullptr;

    ~IRVarStmtNode() { 
        
    }
    void print() { std::cout << to_string(); };
    std::string to_string() override;
};

class IRFunctionNode: public IRNode {
public:
    IRType* retType = nullptr;
    std::string name;
    std::vector<std::pair<IRType*, std::string>> args;
    std::vector<IRBlockNode*> blocks;

    IRFunctionNode() = default;
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