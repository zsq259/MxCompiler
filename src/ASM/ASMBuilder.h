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

class ASMBuilder : public IRBaseVisitor {
private:
    int spSize = 0;
    RegisterAllocator regAllocator;
    ASMProgramNode* program = nullptr;
    IRFunctionNode* currentFunction = nullptr;
    ASMBlockNode* currentBlock;
    ASMImmInsNode *spAddIns = nullptr, *spRetIns = nullptr;
    std::map<std::string, ASMVarNode*> varMap;
    std::set<ASMVarNode*> varSet;
    std::map<std::string, int> counter;
    std::map<std::string, std::vector<ASMLaInsNode*>> phiLaMap;

public:
    ASMBuilder() {}
    ~ASMBuilder() { 
        delete program; 
        for (auto v: varSet) delete v;
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
    void getPtr(ASMVarNode* var, Register* reg);
    void getVar(ASMVarNode* var, Register* reg);
    void getAddr(IRVarNode* var, Register* reg);
    void getValue(IRValueNode* value, Register* reg);
    void storeVar(ASMVarNode* var, Register* reg);
    void storePtr(ASMVarNode* var, Register* reg);
    ASMLocalVarNode* registerLocalVar(IRVarNode* var, bool p_);
    ASMVarNode* getVarNode(IRVarNode* var);
};

#endif