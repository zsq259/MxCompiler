#ifndef ASM_BUILDER_H
#define ASM_BUILDER_H

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <set>
#include "IRBaseVisitor.h"
#include "ASMNode.h"
#include "Register.h"
#include "IRNode.h"
#include "RegisterAllocator.h"

class ASMBuilder : public IRBaseVisitor {
private:
    RegisterAllocator regAllocator;
    ASMProgramNode* program = nullptr;
    IRFunctionNode* currentFunction = nullptr;
    ASMFunctionNode* currentASMFunction = nullptr;
    ASMBlockNode* currentBlock;
    ASMLocalVarNode *raVar = nullptr, *calleeSavedVar[12];
    ASMImmInsNode* spRet = nullptr;
    std::map<std::string, ASMVarNode*> varMap;
    std::set<ASMVarNode*> varSet;
    std::set<IRVarNode*> irVarSet;
    std::map<std::string, int> counter;
    std::map<std::string, std::vector<ASMLaInsNode*>> phiLaMap;
    std::map<std::string, IRBlockNode*> blockMap;
    std::vector<std::pair<ASMLocalVarNode*, ASMLocalVarNode*>> phiVars;

public:
    ASMBuilder() {}
    ~ASMBuilder() { 
        delete program; 
        for (auto v: varSet) delete v;
        for (auto v: irVarSet) delete v;
    }
    void visitValue(IRValueNode* node) override;
    void visitVar(IRVarNode* node) override;
    void visitGlobalVar(IRGlobalVarNode* node) override;
    void visitBlock(IRBlockNode* node) override;
    void visitLiteral(IRLiteralNode* node) override;
    void visitString(IRStringNode* node) override;
    void visitBrCondStmt(IRBrCondStmtNode* node) override;
    void visitBrStmt(IRBrStmtNode* node) override;
    void visitRetStmt(IRRetStmtNode* node) override;
    void visitBinaryStmt(IRBinaryStmtNode* node) override;
    void visitAllocaStmt(IRAllocaStmtNode* node) override;
    void visitLoadStmt(IRLoadStmtNode* node) override;
    void visitStoreStmt(IRStoreStmtNode* node) override;
    void visitIcmpStmt(IRIcmpStmtNode* node) override;
    void visitTruncStmt(IRTruncStmtNode* node) override;
    void visitZextStmt(IRZextStmtNode* node) override;
    void visitCallStmt(IRCallStmtNode* node) override;
    void visitPhiStmt(IRPhiStmtNode* node) override;
    void visitGetElementPtrStmt(IRGetElementPtrStmtNode* node) override;
    void visitGlobalVarStmt(IRGlobalVarStmtNode* node) override;
    void visitFunction(IRFunctionNode* node) override;
    void visitProgram(IRProgramNode* node) override;
    
    void print() { std::cout << program->to_string(); }
    void getPtr(ASMVarNode* var, ASMVarNode* reg);
    void getVar(ASMVarNode* var, ASMVarNode* reg);
    void getValue(IRValueNode* value, ASMVarNode* reg);
    void storeVar(ASMVarNode* var, ASMVarNode* reg);
    void storePtr(ASMVarNode* var, ASMVarNode* reg);
    ASMLocalVarNode* registerLocalVar(IRVarNode* var, bool p_);
    ASMVarNode* getVarNode(IRVarNode* var);
    void setPhiVar(IRBlockNode* node, IRBlockNode* nextBlock);
};

#endif