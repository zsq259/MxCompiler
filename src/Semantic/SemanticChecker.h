#ifndef SEMANTIC_CHECKER_H
#define SEMANTIC_CHECKER_H
#include "../AST/ASTBaseVisitor.h"
#include "../Util/Scope.h"

class SemanticChecker: public ASTBaseVisitor {
private:
    GlobalScope *globalScope = nullptr;
    Scope *scope = nullptr;
    ASTFunctionNode *currentFunction = nullptr;
    int loopDepth = 0;
public:
    explicit SemanticChecker(GlobalScope *globalScope_): globalScope(globalScope_), scope(globalScope_) {}
    void visitProgramNode(ASTProgramNode *node)           override;
    void visitClassNode(ASTClassNode *node)               override;
    void visitFunctionNode(ASTFunctionNode *node)         override;
    void visitTypeNode(ASTTypeNode *node)                 override;
    void visitBlockNode(ASTBlockNode *node)               override;
    // void visitStmtNode(ASTStmtNode *node)                 override;
    void visitExprStmtNode(ASTExprStmtNode *node)         override;
    // void visitExprNode(ASTExprNode *node)                 override;
    void visitFuncExprNode(ASTFuncExprNode *node)         override;
    void visitArrayExprNode(ASTArrayExprNode *node)       override;
    void visitMemberExprNode(ASTMemberExprNode *node)     override;
    void visitSingleExprNode(ASTSingleExprNode *node)     override;
    void visitNewExprNode(ASTNewExprNode *node)           override;
    void visitBinaryExprNode(ASTBinaryExprNode *node)     override;
    void visitTernaryExprNode(ASTTernaryExprNode *node)   override;
    void visitAssignExprNode(ASTAssignExprNode *node)     override;
    void visitLiterExprNode(ASTLiterExprNode *node)       override;
    void visitAtomExprNode(ASTAtomExprNode *node)         override;
    void visitIfStmtNode(ASTIfStmtNode *node)             override;
    void visitWhileStmtNode(ASTWhileStmtNode *node)       override;
    void visitForStmtNode(ASTForStmtNode *node)           override;
    // void visitFlowStmtNode(ASTFlowStmtNode *node)         override;
    void visitContinueStmtNode(ASTContinueStmtNode *node) override;
    void visitBreakStmtNode(ASTBreakStmtNode *node)       override;
    void visitReturnStmtNode(ASTReturnStmtNode *node)     override;
    void visitVarStmtNode(ASTVarStmtNode *node)           override;
    void visitNewTypeNode(ASTNewTypeNode *node)           override;    
};
#endif