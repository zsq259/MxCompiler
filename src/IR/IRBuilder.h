#ifndef IRBUILDER_H
#define IRBUILDER_H
#include <map>
#include <vector>
#include <string>
#include "ASTBaseVisitor.h"
#include "Type.h"
#include "IRNode.h"

class IRBuilder : public ASTBaseVisitor {
private:
    int ifthenCnt = 0, ifelseCnt = 0, ifendCnt = 0;
    int forcondCnt = 0, forbodyCnt = 0, forstepCnt = 0, forendCnt = 0;
    IRProgramNode *program = nullptr;
    IRClassNode* currentClass = nullptr;
    IRFunctionNode* currentFunction = nullptr;
    IRBlockNode* currentBlock = nullptr;
    std::map<ASTNode*, IRValueNode*> astValueMap;
    std::vector<std::pair<IRVarNode*, ASTExprNode*>> varInitList;

public:
    void visitContinueStmtNode(ASTContinueStmtNode *node) override;
    void visitTernaryExprNode(ASTTernaryExprNode *node) override;
    void visitAssignExprNode(ASTAssignExprNode *node) override;
    void visitBinaryExprNode(ASTBinaryExprNode *node) override;
    void visitMemberExprNode(ASTMemberExprNode *node) override;
    void visitSingleExprNode(ASTSingleExprNode *node) override;
    void visitReturnStmtNode(ASTReturnStmtNode *node) override;
    void visitLiterExprNode(ASTLiterExprNode *node) override;
    void visitWhileStmtNode(ASTWhileStmtNode *node) override;
    void visitBreakStmtNode(ASTBreakStmtNode *node) override;
    void visitArrayExprNode(ASTArrayExprNode *node) override;
    void visitAtomExprNode(ASTAtomExprNode *node) override;
    void visitFlowStmtNode(ASTFlowStmtNode *node) override;
    void visitFunctionNode(ASTFunctionNode *node) override;
    void visitExprStmtNode(ASTExprStmtNode *node) override;
    void visitFuncExprNode(ASTFuncExprNode *node) override;
    void visitVarStmtNode(ASTVarStmtNode *node) override;
    void visitNewTypeNode(ASTNewTypeNode *node) override;
    void visitNewExprNode(ASTNewExprNode *node) override;
    void visitForStmtNode(ASTForStmtNode *node) override;
    void visitProgramNode(ASTProgramNode *node) override;
    void visitIfStmtNode(ASTIfStmtNode *node) override;
    void visitClassNode(ASTClassNode *node) override;
    void visitBlockNode(ASTBlockNode *node) override;
    void visitTypeNode(ASTTypeNode *node) override;
    void visitStmtNode(ASTStmtNode *node) override;
    void visitExprNode(ASTExprNode *node) override;
    
    IRLiteralNode* defaultValue(IRType *type);
    IRType* toIRType(ASTTypeNode *node);
    IRType* toIRType(Type *type);
    void print() { program->print(); }
    
};

#endif