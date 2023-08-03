#include "ASTDeclaration.h"

class ASTBaseVisitor {
public:
    ASTBaseVisitor() = default;
    virtual ~ASTBaseVisitor() = default;
    virtual void visitProgramNode(ASTProgramNode *node) = 0;
    virtual void visitClassNode(ASTClassNode *node) = 0;
    virtual void visitConstructNode(ASTConstructNode *node) = 0;
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