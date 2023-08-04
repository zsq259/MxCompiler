#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include "ASTBaseVisitor.h"
using std::string;
using std::vector;
using std::pair;

class ASTNode {
public:
    ASTNode() = default;
    virtual ~ASTNode() = default;
    virtual std::string NodeType() { return "ASTNode"; }
	virtual void accept(ASTBaseVisitor *visitor) {}
    virtual void print() = 0;
};

class ASTTypeNode: public ASTNode {
public:
    string name;
    // vector<ASTExprNode*> size;
    int dim = 0;
    
    ~ASTTypeNode() override {
        // for (auto s: size) delete s;
    }
    std::string NodeType() override { return "ASTTypeNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitTypeNode(this); }
    void print() override;  
};

class ASTStmtNode: public ASTNode {
public:
    ~ASTStmtNode() override = default;
    std::string NodeType() override { return "ASTStmtNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitStmtNode(this); }
    // void print() override;
};

class ASTBlockNode: public ASTNode {
public:
    vector<ASTStmtNode*> stmts;

    ~ASTBlockNode() override {
        for (auto s: stmts) delete s;
    }
    std::string NodeType() override { return "ASTBlockNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitBlockNode(this); }
    void print() override;  
};

class ASTExprNode: public ASTNode {
public:

    ~ASTExprNode() override = default;
    std::string NodeType() override { return "ASTExprNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitExprNode(this); }
    // void print() override;
};

class ASTExprStmtNode: public ASTStmtNode {
public:
    vector<ASTExprNode*> exprs;

    ~ASTExprStmtNode() override {
        for (auto e: exprs) delete e;
    }
    std::string NodeType() override { return "ASTExprStmtNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitExprStmtNode(this); }
    void print() override;
};

class ASTFuncExprNode: public ASTExprNode {
public:
    ASTExprNode* func;
    vector<ASTExprNode*> args;

    ~ASTFuncExprNode() override {
        delete func;
        for (auto a: args) delete a;
    }
    std::string NodeType() override { return "ASTFuncExprNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitFuncExprNode(this); }
    void print() override;
};

class ASTArrayExprNode: public ASTExprNode {
public:
    ASTExprNode *array, *index;

    ~ASTArrayExprNode() override {
        delete array;
        delete index;
    }
    std::string NodeType() override { return "ASTArrayExprNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitArrayExprNode(this); }
    void print() override;
};

class ASTMemberExprNode: public ASTExprNode {
public:
    ASTExprNode* name;
    std::string member;

    ~ASTMemberExprNode() override {
        delete name;
    }
    std::string NodeType() override { return "ASTMemberExprNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitMemberExprNode(this); }
    void print() override;
};

class ASTSingleExprNode: public ASTExprNode {
public:
    ASTExprNode* expr;
    string op;
    bool right;

    ~ASTSingleExprNode() override {
        delete expr;
    }  
    std::string NodeType() override { return "ASTSingleExprNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitSingleExprNode(this); }
    void print() override;
};

class ASTNewTypeNode: public ASTNode {
public:
    string name;
    vector<ASTExprNode*> size;
    int dim = 0;

    ~ASTNewTypeNode() {
        for (auto s:size) delete s;
    }
    std::string NodeType() override { return "ASTNewTypeNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitNewTypeNode(this); }
    void print() override;
};

class ASTNewExprNode: public ASTExprNode {
public:
    ASTNewTypeNode* type;

    ~ASTNewExprNode() override {
        delete type;
    }
    std::string NodeType() override { return "ASTNewExprNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitNewExprNode(this); }
    void print() override;
};

class ASTBinaryExprNode: public ASTExprNode {
public:
    ASTExprNode *lhs, *rhs;
    string op;

    ~ASTBinaryExprNode() {
        delete lhs, rhs;
    }
    std::string NodeType() override { return "ASTBinaryExprNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitBinaryExprNode(this); }
    void print() override;
};

class ASTTernaryExprNode: public ASTExprNode {
public:
    ASTExprNode *cond, *True, *False;

    ~ASTTernaryExprNode() override {
        delete cond, True, False;
    }
    std::string NodeType() override { return "ASTTernaryExprNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitTernaryExprNode(this); }
    void print() override;
};

class ASTAssignExprNode: public ASTExprNode {
public:
    ASTExprNode *lhs, *rhs;

    ~ASTAssignExprNode() {
        delete lhs, rhs;
    }
    std::string NodeType() override { return "ASTAssignExprNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitAssignExprNode(this); }
    void print() override;
};

class ASTLiterExprNode: public ASTExprNode {
public:
    string value;

    ~ASTLiterExprNode() override = default;
    std::string NodeType() override { return "ASTLiterExprNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitLiterExprNode(this); }
    void print() override;
};

class ASTAtomExprNode: public ASTExprNode {
public:
    string name;

    ~ASTAtomExprNode() override = default;
    std::string NodeType() override { return "ASTAtomExprNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitAtomExprNode(this); }
    void print() override;
};

class ASTIfStmtNode: public ASTStmtNode {
public:
    vector<ASTExprNode*> conds;
    vector<ASTBlockNode*> blocks;

    ~ASTIfStmtNode() {
        for(auto c: conds) delete c;
        for(auto b: blocks) delete b;
    }
    std::string NodeType() override { return "ASTIfStmtNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitIfStmtNode(this); }
    void print() override;
};

class ASTWhileStmtNode: public ASTStmtNode {
public:
    ASTExprNode* cond;
    ASTBlockNode* block;

    ~ASTWhileStmtNode() {
        delete cond, block;
    }
    std::string NodeType() override { return "ASTWhileStmtNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitWhileStmtNode(this); }
    void print() override;
};

class ASTForStmtNode: public ASTStmtNode {
public:
    ASTStmtNode* init;
    ASTExprNode *cond, *step;
    ASTBlockNode* block;

    ~ASTForStmtNode() {
        delete init, cond, step, block;
    }
    std::string NodeType() override { return "ASTForStmtNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitForStmtNode(this); }
    void print() override;
};

class ASTFlowStmtNode: public ASTStmtNode {
public:
    ~ASTFlowStmtNode() override = default;
    std::string NodeType() override { return "ASTFlowStmtNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitFlowStmtNode(this); }
    // void print() override;
};

class ASTContinueStmtNode: public ASTFlowStmtNode {
public:
    ~ASTContinueStmtNode() override = default;
    std::string NodeType() override { return "ASTContinueStmtNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitContinueStmtNode(this); }
    void print() override;
};

class ASTBreakStmtNode: public ASTFlowStmtNode {
public:
    ~ASTBreakStmtNode() override = default;
    std::string NodeType() override { return "ASTBreakStmtNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitBreakStmtNode(this); }
    void print() override;
};

class ASTReturnStmtNode: public ASTFlowStmtNode {
public:
    ASTExprNode* expr;

    ~ASTReturnStmtNode() override = default;
    std::string NodeType() override { return "ASTReturnStmtNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitReturnStmtNode(this); }
    void print() override;
};

class ASTVarStmtNode: public ASTStmtNode {
public:
    ASTTypeNode *type;
    vector<pair<string, ASTExprNode*>> vars;

    ~ASTVarStmtNode() override {
        delete type;
        for (auto v: vars) delete v.second;
    }
    std::string NodeType() override { return "ASTVarStmtNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitVarStmtNode(this); }
    void print() override;
};

class ASTConstructNode: public ASTNode {
public:
    string name;
    ASTBlockNode* block;

    ~ASTConstructNode() override {
        delete block;
    }
    std::string NodeType() override { return "ASTConstructNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitConstructNode(this); }
    void print() override;  
};

class ASTFunctionNode: public ASTNode {
public:
    string name;
    vector<pair<ASTTypeNode*, string>> paras;
    ASTBlockNode* block;
    ASTTypeNode* returnType;

    ~ASTFunctionNode() override {
        for (auto p: paras) delete p.first;
        delete block;
        delete returnType;
    }
    std::string NodeType() override { return "ASTFunctionNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitFunctionNode(this); }
    void print() override;  
};

class ASTClassNode: public ASTNode {
public:
    string name;
    vector<ASTVarStmtNode*> variables;
    vector<ASTConstructNode*> constructors;
    vector<ASTFunctionNode*> functions;

    ~ASTClassNode() override {
        for (auto v: variables) delete v;
        for (auto c: constructors) delete c;
        for (auto f: functions) delete f;
    }
    std::string NodeType() override { return "ASTClassNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitClassNode(this); }
    void print() override;  
};

class ASTProgramNode: public ASTNode {
public:
    vector<ASTNode*> children;

    ASTProgramNode() = default;
    ~ASTProgramNode() override {
        for (auto child: children) delete child;
    }
    std::string NodeType() override { return "ASTProgramNode"; }
    void accept(ASTBaseVisitor *visitor) override { return visitor->visitProgramNode(this); }
    void print() override;  
};
