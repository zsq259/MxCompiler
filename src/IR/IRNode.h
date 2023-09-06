#ifndef IRNODE_H
#define IRNODE_H
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include "IRType.h"
#include "IRBaseVisitor.h"

class IRValueNode: public IRNode {
public:
    IRType* type = nullptr;

    explicit IRValueNode(IRType* type_): type(type_) {}
    void accept(IRBaseVisitor* visitor) { visitor->visitValue(this); }
};

class IRVarNode: public IRValueNode {
public:
    std::string name;
    bool isConst = false;
    explicit IRVarNode(IRType* type_, std::string name_, bool const_): IRValueNode(type_), name(name_), isConst(const_) {}
    void print() { std::cout << to_string(); };
    std::string to_string() override;
    void accept(IRBaseVisitor* visitor) { visitor->visitVar(this); }
};

class IRGlobalVarNode: public IRVarNode {
public:

    explicit IRGlobalVarNode(IRType* type_, std::string name_, bool const_): IRVarNode(type_, name_, const_) {}
    void print() { std::cout << to_string(); };
    std::string to_string() override;
    void accept(IRBaseVisitor* visitor) { visitor->visitGlobalVar(this); }
};

class IRStmtNode: public IRNode {
public:
    virtual void replaceValue(IRValueNode* from, IRValueNode* to) {}
    virtual void getUse(std::map<IRNode*, std::set<IRValueNode*> > &useSet) {}
    virtual void getDef(std::map<IRNode*, std::set<IRValueNode*> > &defSet) {}
};

class IRBlockNode: public IRNode {
public:
    std::string label;
    std::list<IRStmtNode*> stmts;

    explicit IRBlockNode(std::string label_): label(label_) {}
    ~IRBlockNode() { 
        for (auto &s: stmts) delete s;
    }
    void print() { std::cout << to_string(); };
    std::string to_string() override;
    void accept(IRBaseVisitor* visitor) { visitor->visitBlock(this); }
};

class IRLiteralNode: public IRValueNode {
public:
    int value;

    explicit IRLiteralNode(IRType* t_,  int value_): IRValueNode(t_), value(value_) {}
    void print() { std::cout << to_string(); };
    std::string to_string() override;
    void accept(IRBaseVisitor* visitor) { visitor->visitLiteral(this); }
};

class IRStringNode: public IRLiteralNode {
public:
    std::string str;

    explicit IRStringNode(IRType* type_, std::string str_): IRLiteralNode(type_, 0), str(str_) {}
    ~IRStringNode() override { delete type; }
    void print() { std::cout << to_string(); };
    std::string to_string() override;
    void accept(IRBaseVisitor* visitor) { visitor->visitString(this); }
};

class IRBrCondStmtNode: public IRStmtNode {
public:
    IRValueNode* cond = nullptr;
    std::string trueLabel, falseLabel;

    explicit IRBrCondStmtNode(IRValueNode* cond_, std::string trueLabel_, std::string falseLabel_): 
        cond(cond_), trueLabel(trueLabel_), falseLabel(falseLabel_) {}
    void print() { std::cout << to_string(); };
    std::string to_string() override;
    void accept(IRBaseVisitor* visitor) { visitor->visitBrCondStmt(this); }
    void getUse(std::map<IRNode*, std::set<IRValueNode*> > &useSet) override {
        useSet[this].insert(cond);
    }
};

class IRBrStmtNode: public IRStmtNode {
public:
    std::string label;

    explicit IRBrStmtNode(std::string label_): label(label_) {}
    void print() { std::cout << to_string(); };
    std::string to_string() override;
    void accept(IRBaseVisitor* visitor) { visitor->visitBrStmt(this); }
};

class IRRetStmtNode: public IRStmtNode {
public:
    IRValueNode* value = nullptr;

    explicit IRRetStmtNode(IRValueNode* value_): value(value_) {}
    void print() { std::cout << to_string(); };
    std::string to_string() override;
    void accept(IRBaseVisitor* visitor) { visitor->visitRetStmt(this); }
    void replaceValue(IRValueNode* from, IRValueNode* to) override {
        if (value == from) value = to;
    }
    void getUse(std::map<IRNode*, std::set<IRValueNode*> > &useSet) override {
        if (value) useSet[this].insert(value);
    }
};

class IRBinaryStmtNode: public IRStmtNode {
public:
    std::string op;
    IRVarNode* var = nullptr;
    IRValueNode* lhs = nullptr;
    IRValueNode* rhs = nullptr;

    explicit IRBinaryStmtNode(std::string op_, IRVarNode* var_, IRValueNode* lhs_, IRValueNode* rhs_): 
        op(op_), var(var_), lhs(lhs_), rhs(rhs_) {}
    void print() { std::cout << to_string(); };
    std::string to_string() override;
    void accept(IRBaseVisitor* visitor) { visitor->visitBinaryStmt(this); }
    void replaceValue(IRValueNode* from, IRValueNode* to) override {
        if (lhs == from) lhs = to;
        if (rhs == from) rhs = to;
    }
    void getUse(std::map<IRNode*, std::set<IRValueNode*> > &useSet) override {
        useSet[this].insert(lhs);
        useSet[this].insert(rhs);
    }
    void getDef(std::map<IRNode*, std::set<IRValueNode*> > &defSet) override {
        defSet[this].insert(var);
    }
};

class IRAllocaStmtNode: public IRStmtNode {
public:
    IRVarNode* var = nullptr;
    IRType* type = nullptr;
    explicit IRAllocaStmtNode(IRVarNode* var_, IRType* type_): var(var_), type(type_) {}
    void print() { std::cout << to_string(); };
    std::string to_string() override;
    void accept(IRBaseVisitor* visitor) { visitor->visitAllocaStmt(this); }
};

class IRLoadStmtNode: public IRStmtNode {
public:
    IRVarNode *var = nullptr, *ptr = nullptr;

    explicit IRLoadStmtNode(IRVarNode* var_, IRVarNode* ptr_): var(var_), ptr(ptr_) {}
    void print() { std::cout << to_string(); };
    std::string to_string() override;
    void accept(IRBaseVisitor* visitor) { visitor->visitLoadStmt(this); }
    void replaceValue(IRValueNode* from, IRValueNode* to) override {
        if (ptr == dynamic_cast<IRVarNode*>(from)) ptr = dynamic_cast<IRVarNode*>(to);
    }
    void getUse(std::map<IRNode*, std::set<IRValueNode*> > &useSet) override {
        useSet[this].insert(ptr);
    }
    void getDef(std::map<IRNode*, std::set<IRValueNode*> > &defSet) override {
        defSet[this].insert(var);
    }
};

class IRStoreStmtNode: public IRStmtNode {
public:
    IRValueNode* value = nullptr;
    IRVarNode* ptr = nullptr;
    bool is_ptr = false;

    explicit IRStoreStmtNode(IRValueNode* value_, IRVarNode* ptr_, bool p_): value(value_), ptr(ptr_), is_ptr(p_) {}
    void print() { std::cout << to_string(); };
    std::string to_string() override;
    void accept(IRBaseVisitor* visitor) { visitor->visitStoreStmt(this); }
    void replaceValue(IRValueNode* from, IRValueNode* to) override {
        if (value == from) value = to;
    }
    void getUse(std::map<IRNode*, std::set<IRValueNode*> > &useSet) override {
        useSet[this].insert(value);
    }
    void getDef(std::map<IRNode*, std::set<IRValueNode*> > &defSet) override {
        defSet[this].insert(ptr);
    }
};

class IRIcmpStmtNode: public IRStmtNode {
public:
    std::string op;
    IRVarNode* var = nullptr;
    IRValueNode* lhs = nullptr;
    IRValueNode* rhs = nullptr;

    explicit IRIcmpStmtNode(std::string op_, IRVarNode* var_, IRValueNode* lhs_, IRValueNode* rhs_): 
        op(op_), var(var_), lhs(lhs_), rhs(rhs_) {
            if (op.find("icmp") == std::string::npos) op = "icmp " + op;
        }
    void print() { std::cout << to_string(); };
    std::string to_string() override;
    void accept(IRBaseVisitor* visitor) { visitor->visitIcmpStmt(this); }
    void replaceValue(IRValueNode* from, IRValueNode* to) override {
        if (lhs == from) lhs = to;
        if (rhs == from) rhs = to;
    }
    void getUse(std::map<IRNode*, std::set<IRValueNode*> > &useSet) override {
        useSet[this].insert(lhs);
        useSet[this].insert(rhs);
    }
    void getDef(std::map<IRNode*, std::set<IRValueNode*> > &defSet) override {
        defSet[this].insert(var);
    }
};

class IRTruncStmtNode: public IRStmtNode {
public:
    IRVarNode* var = nullptr;
    IRValueNode *value = nullptr;

    explicit IRTruncStmtNode(IRVarNode* var_, IRValueNode* value_): var(var_), value(value_) {}
    void print() { std::cout << to_string(); };
    std::string to_string() override;
    void accept(IRBaseVisitor* visitor) { visitor->visitTruncStmt(this); }
    void replaceValue(IRValueNode* from, IRValueNode* to) override {
        if (value == from) value = to;
    }
    void getUse(std::map<IRNode*, std::set<IRValueNode*> > &useSet) override {
        useSet[this].insert(value);
    }
    void getDef(std::map<IRNode*, std::set<IRValueNode*> > &defSet) override {
        defSet[this].insert(var);
    }
};

class IRZextStmtNode: public IRStmtNode {
public:
    IRVarNode* var = nullptr;
    IRValueNode *value = nullptr;

    explicit IRZextStmtNode(IRVarNode* var_, IRValueNode* value_): var(var_), value(value_) {}
    void print() { std::cout << to_string(); };
    std::string to_string() override;
    void accept(IRBaseVisitor* visitor) { visitor->visitZextStmt(this); }
    void replaceValue(IRValueNode* from, IRValueNode* to) override {
        if (value == from) value = to;
    }
    void getUse(std::map<IRNode*, std::set<IRValueNode*> > &useSet) override {
        useSet[this].insert(value);
    }
    void getDef(std::map<IRNode*, std::set<IRValueNode*> > &defSet) override {
        defSet[this].insert(var);
    }
};

class IRCallStmtNode: public IRStmtNode {
public:
    IRVarNode* var = nullptr;
    std::string funcName;
    std::vector<IRValueNode*> args;

    explicit IRCallStmtNode(IRVarNode* var_, std::string funcName_): 
        var(var_), funcName(funcName_) {}
    void print() { std::cout << to_string(); };
    std::string to_string() override;
    void accept(IRBaseVisitor* visitor) { visitor->visitCallStmt(this); }
    void replaceValue(IRValueNode* from, IRValueNode* to) override {
        for (auto &arg: args) if (arg == from) arg = to;
    }
    void getUse(std::map<IRNode*, std::set<IRValueNode*> > &useSet) override {
        for (auto arg: args) useSet[this].insert(arg);
    }
    void getDef(std::map<IRNode*, std::set<IRValueNode*> > &defSet) override {
        if (var) defSet[this].insert(var);
    }
};

class IRPhiStmtNode: public IRStmtNode {
public:
    IRVarNode* var = nullptr;
    std::map<std::string, IRValueNode*> values;

    explicit IRPhiStmtNode(IRVarNode* var_): var(var_) {}
    void print() { std::cout << to_string(); };
    std::string to_string() override;
    void accept(IRBaseVisitor* visitor) {  visitor->visitPhiStmt(this); }
    void replaceValue(IRValueNode* from, IRValueNode* to) override {
        for (auto &arg: values) if (arg.second == from) arg.second = to;
    }
    void getUse(std::map<IRNode*, std::set<IRValueNode*> > &useSet) override {
        for (auto &arg: values) useSet[this].insert(arg.second);
    }
    void getDef(std::map<IRNode*, std::set<IRValueNode*> > &defSet) override {
        defSet[this].insert(var);
    }
};

class IRGetElementPtrStmtNode: public IRStmtNode {
public:
    IRVarNode *var = nullptr, *ptr = nullptr;
    IRValueNode* index = nullptr;
    IRType* type;

    explicit IRGetElementPtrStmtNode(IRVarNode* var_, IRVarNode* ptr_, IRValueNode* index_, IRType* type_): 
        var(var_), ptr(ptr_), index(index_), type(type_) {}
    void print() { std::cout << to_string(); };
    std::string to_string() override;
    void accept(IRBaseVisitor* visitor){ visitor->visitGetElementPtrStmt(this); }
    void replaceValue(IRValueNode* from, IRValueNode* to) override {
        if (index == from) index = to;
        if (ptr == dynamic_cast<IRVarNode*>(from)) ptr = dynamic_cast<IRVarNode*>(to);
    }
    void getUse(std::map<IRNode*, std::set<IRValueNode*> > &useSet) override {
        useSet[this].insert(index);
        useSet[this].insert(ptr);
    }
    void getDef(std::map<IRNode*, std::set<IRValueNode*> > &defSet) override {
        defSet[this].insert(var);
    }
};

class IRGlobalVarStmtNode: public IRStmtNode {
public:
    IRValueNode* value = nullptr;
    IRGlobalVarNode* var = nullptr;

    explicit IRGlobalVarStmtNode(IRValueNode* value_, IRGlobalVarNode* var_): value(value_), var(var_) {}
    void print() { std::cout << to_string(); };
    std::string to_string() override;
    void accept(IRBaseVisitor* visitor){ visitor->visitGlobalVarStmt(this); }
};

class IRFunctionNode: public IRNode {
public:
    IRType* retType = nullptr;
    std::string name;
    std::vector<std::pair<IRType*, std::string>> args;
    std::list<IRBlockNode*> blocks;

    explicit IRFunctionNode(IRType* retType_, std::string name_): retType(retType_), name(name_) {}
    ~IRFunctionNode() { 
        for (auto &b: blocks) delete b;
    }
    void print() { std::cout << to_string(); };
    std::string to_string() override;
    void accept(IRBaseVisitor* visitor){ visitor->visitFunction(this); }
};

class IRProgramNode: public IRNode {
public:
    std::vector<IRFunctionNode *> functions;
    std::vector<IRGlobalVarStmtNode *> globalVars;

    ~IRProgramNode() { 
        for (auto &f: functions) delete f;
        for (auto &g: globalVars) delete g;
    }
    void print() { std::cout << to_string(); };
    std::string to_string() override;
    void accept(IRBaseVisitor* visitor){ visitor->visitProgram(this); }
};

#endif