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
    int count = 0;
    int ifthenCnt = 0, ifelseCnt = 0, ifendCnt = 0;
    int forcondCnt = 0, forbodyCnt = 0, forstepCnt = 0, forendCnt = 0;
    int whilecondCnt = 0, whilebodyCnt = 0, whileendCnt = 0;
    int ternartytrueCnt = 0, ternartyfalseCnt = 0, ternartyendCnt = 0;
    int returnCnt = 0;
    IRProgramNode *program = nullptr;
    IRClassNode* currentClass = nullptr;
    IRFunctionNode* currentFunction = nullptr;
    IRBlockNode *currentBlock = nullptr, *currentCondBlock = nullptr, *currentEndBlock = nullptr;
    IRBlockNode* currentReturnBlock = nullptr;
    IRVarNode* currentReturnVar = nullptr;
    std::map<ASTNode*, IRValueNode*> astValueMap;
    std::map<std::string, IRVarNode*> varMap;
    std::map<std::string, std::string> opcode;
    std::vector<std::pair<IRVarNode*, ASTExprNode*>> varInitList;

public:
    IRBuilder() {
        init();
    }
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
    // void visitFlowStmtNode(ASTFlowStmtNode *node) override;
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
    // void visitStmtNode(ASTStmtNode *node) override;
    // void visitExprNode(ASTExprNode *node) override;
    
    void init();
    IRLiteralNode* defaultValue(IRType *type);
    IRType* toIRType(ASTTypeNode *node);
    IRType* toIRType(Type *type);
    void print() { program->print(); }
    void setCondition(IRValueNode* cond, IRBlockNode* block1, IRBlockNode* block2);
    IRValueNode* setVariable(IRType* type, IRValueNode* value);
};

#endif