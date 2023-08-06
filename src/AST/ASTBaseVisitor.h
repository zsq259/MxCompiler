#ifndef AST_BASE_VISITOR_H
#define AST_BASE_VISITOR_H
#include "../Util/Scope.h"

class ASTBaseVisitor;

class ASTNode {
public:
    ASTNode() = default;
    virtual ~ASTNode() = default;
    virtual std::string NodeType() { return "ASTNode"; }
	virtual void accept(ASTBaseVisitor *visitor) {}
    virtual void print() = 0;
};

class ASTProgramNode;
class ASTClassNode;
class ASTConstructNode;
class ASTFunctionNode;
class ASTTypeNode;
class ASTBlockNode;
class ASTStmtNode;
class ASTExprStmtNode;
class ASTExprNode;
class ASTFuncExprNode;
class ASTArrayExprNode;
class ASTMemberExprNode;
class ASTSingleExprNode;
class ASTNewExprNode;
class ASTBinaryExprNode;
class ASTTernaryExprNode;
class ASTAssignExprNode;
class ASTLiterExprNode;
class ASTAtomExprNode;
class ASTIfStmtNode;
class ASTWhileStmtNode;
class ASTForStmtNode;
class ASTFlowStmtNode;
class ASTContinueStmtNode;
class ASTBreakStmtNode;
class ASTReturnStmtNode;
class ASTVarStmtNode;
class ASTNewTypeNode;

class ASTBaseVisitor {
public:
    ASTBaseVisitor() = default;
    virtual ~ASTBaseVisitor() = default;
    virtual void visit(ASTNode *node) { node->accept(this); }
    virtual void visitProgramNode(ASTProgramNode *node) = 0;
    virtual void visitClassNode(ASTClassNode *node) = 0;
    virtual void visitFunctionNode(ASTFunctionNode *node) = 0;
    virtual void visitTypeNode(ASTTypeNode *node) = 0;
    virtual void visitBlockNode(ASTBlockNode *node) = 0;
    virtual void visitStmtNode(ASTStmtNode *node) = 0;
    virtual void visitExprStmtNode(ASTExprStmtNode *node) = 0;
    virtual void visitExprNode(ASTExprNode *node) = 0;
    virtual void visitFuncExprNode(ASTFuncExprNode *node) = 0;
    virtual void visitArrayExprNode(ASTArrayExprNode *node) = 0;
    virtual void visitMemberExprNode(ASTMemberExprNode *node) = 0;
    virtual void visitSingleExprNode(ASTSingleExprNode *node) = 0;
    virtual void visitNewExprNode(ASTNewExprNode *node) = 0;
    virtual void visitBinaryExprNode(ASTBinaryExprNode *node) = 0;
    virtual void visitTernaryExprNode(ASTTernaryExprNode *node) = 0;
    virtual void visitAssignExprNode(ASTAssignExprNode *node) = 0;
    virtual void visitLiterExprNode(ASTLiterExprNode *node) = 0;
    virtual void visitAtomExprNode(ASTAtomExprNode *node) = 0;
    virtual void visitIfStmtNode(ASTIfStmtNode *node) = 0;
    virtual void visitWhileStmtNode(ASTWhileStmtNode *node) = 0;
    virtual void visitForStmtNode(ASTForStmtNode *node) = 0;
    virtual void visitFlowStmtNode(ASTFlowStmtNode *node) = 0;
    virtual void visitContinueStmtNode(ASTContinueStmtNode *node) = 0;
    virtual void visitBreakStmtNode(ASTBreakStmtNode *node) = 0;
    virtual void visitReturnStmtNode(ASTReturnStmtNode *node) = 0;
    virtual void visitVarStmtNode(ASTVarStmtNode *node) = 0;
    virtual void visitNewTypeNode(ASTNewTypeNode *node) = 0;
};
#endif