#ifndef IRNODE_H
#define IRNODE_H
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include "Type.h"
#include "IRType.h"

class IRNode {
public:
    virtual ~IRNode() = default;
    virtual void print() = 0;
    virtual void to_string() = 0;
};

class IRValueNode: public IRNode {
public:
    IRType* type = nullptr;
    void print() override;
    void to_string() override;
};

class IRVarNode: public IRValueNode {
public:
    std::string name;
    IRVarNode(std::string name_): name(name_) {}
    void print() override;
    void to_string() override;
};

class IRGlobalVarNode: public IRVarNode {
public:
    IRGlobalVarNode(std::string name_): IRVarNode(name_) {}
    void print() override;
    void to_string() override;
};

class IRClassNode: public IRNode {};

class IRFunctionNode: public IRNode {};

class IRStmtNode: public IRNode {};

class IRGlobalVarStmtNode: public IRStmtNode {
    IRGlobalVarNode* var;
    IRValueNode* value;

};

class IRProgramNode: public IRNode {
public:
    std::vector<IRClassNode *> classes;
    std::vector<IRFunctionNode *> functions;
    std::vector<IRGlobalVarStmtNode *> global_vars;

    ~IRProgramNode() { 
        
    }
    void print() override;
    void to_string() override;
};

#endif