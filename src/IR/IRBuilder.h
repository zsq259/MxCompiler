#ifndef IRBUILDER_H
#define IRBUILDER_H
#include "ASTBaseVisitor.h"

class IRBuilder : public ASTBaseVisitor {
    virtual void visitProgramNode(ASTProgramNode *node) override;
    virtual void visitClassNode(ASTClassNode *node) override;
    virtual void visitFunctionNode(ASTFunctionNode *node) override;
    virtual void visitTypeNode(ASTTypeNode *node) override;
    virtual void visitBlockNode(ASTBlockNode *node) override;
    virtual void visitStmtNode(ASTStmtNode *node) override;
    virtual void visitExprStmtNode(ASTExprStmtNode *node) override;
    virtual void visitExprNode(ASTExprNode *node) override;
    virtual void visitFuncExprNode(ASTFuncExprNode *node) override;
    virtual void visitArrayExprNode(ASTArrayExprNode *node) override;
    virtual void visitMemberExprNode(ASTMemberExprNode *node) override;
    virtual void visitSingleExprNode(ASTSingleExprNode *node) override;
    virtual void visitNewExprNode(ASTNewExprNode *node) override;
    virtual void visitBinaryExprNode(ASTBinaryExprNode *node) override;
    virtual void visitTernaryExprNode(ASTTernaryExprNode *node) override;
    virtual void visitAssignExprNode(ASTAssignExprNode *node) override;
    virtual void visitLiterExprNode(ASTLiterExprNode *node) override;
    virtual void visitAtomExprNode(ASTAtomExprNode *node) override;
    virtual void visitIfStmtNode(ASTIfStmtNode *node) override;
    virtual void visitWhileStmtNode(ASTWhileStmtNode *node) override;
    virtual void visitForStmtNode(ASTForStmtNode *node) override;
    virtual void visitFlowStmtNode(ASTFlowStmtNode *node) override;
    virtual void visitContinueStmtNode(ASTContinueStmtNode *node) override;
    virtual void visitBreakStmtNode(ASTBreakStmtNode *node) override;
    virtual void visitReturnStmtNode(ASTReturnStmtNode *node) override;
    virtual void visitVarStmtNode(ASTVarStmtNode *node) override;
    virtual void visitNewTypeNode(ASTNewTypeNode *node) override;
};

#endif