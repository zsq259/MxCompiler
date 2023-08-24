#ifndef IRBUILDER_H
#define IRBUILDER_H
#include <map>
#include <set>
#include <vector>
#include <string>
#include "ASTBaseVisitor.h"
#include "Type.h"
#include "IRNode.h"

class IRBuilder : public ASTBaseVisitor {
private:
    IRProgramNode *program = nullptr;
    IRClassType* currentClass = nullptr;
    IRFunctionNode* currentFunction = nullptr;
    IRBlockNode *currentBlock = nullptr, *currentNextBlock = nullptr, *currentEndBlock = nullptr;
    IRBlockNode* currentReturnBlock = nullptr;
    IRVarNode* currentReturnVar = nullptr;
    std::map<ASTNode*, IRValueNode*> astValueMap;
    std::map<std::string, IRVarNode*> varMap;
    std::map<std::string, std::string> opcode, stropcode;
    std::map<std::string, int> counter;
    std::map<std::string, int> memberIndex;
    std::map<std::string, IRGlobalVarNode*> stringMap;
    std::map<std::string, IRClassType*> classMap;
    std::map<ASTFunctionNode*, IRFunctionNode*> functionMap;
    std::map<ASTMemberExprNode*, std::string> memberFuncMap;
    std::set<std::string> memberFuncSet;
    std::set<IRValueNode*> valueSet;
    std::vector<std::pair<IRVarNode*, ASTExprNode*>> varInitList;
public:
    IRBuilder() { init(); }
    ~IRBuilder() { 
        delete program; 
        for (auto v: valueSet) delete v;
        for (auto c: classMap) delete c.second;
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
    void visitFunctionNode(ASTFunctionNode *node) override;
    void visitExprStmtNode(ASTExprStmtNode *node) override;
    void visitFuncExprNode(ASTFuncExprNode *node) override;
    void visitVarStmtNode(ASTVarStmtNode *node) override;
    void visitNewExprNode(ASTNewExprNode *node) override;
    void visitForStmtNode(ASTForStmtNode *node) override;
    void visitProgramNode(ASTProgramNode *node) override;
    void visitIfStmtNode(ASTIfStmtNode *node) override;
    void visitClassNode(ASTClassNode *node) override;
    void visitBlockNode(ASTBlockNode *node) override;
    
    void init();
    IRValueNode* defaultValue(IRType *type);
    IRType* toIRType(ASTTypeNode *node);
    IRType* toIRType(Type *type);
    IRType* toIRType(std::string str);
    void print() { program->print(); }
    void setCondition(IRValueNode* cond, IRBlockNode* block1, IRBlockNode* block2);
    IRValueNode* setVariable(IRType* type, IRValueNode* value);
    void registerClass(ASTClassNode *node);
    void registerFunction(ASTFunctionNode* node);
    void initBuiltin();
    void initEmptyString();
    void initGlobalVar();
    IRVarNode* mallocNewArray(ASTNewTypeNode* node, int index);
    IRProgramNode* root() { return program; }
    void elinimate();
};

#endif