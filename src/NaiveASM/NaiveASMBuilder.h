#ifndef NAIVE_ASM_BUILDER_H
#define NAIVE_ASM_BUILDER_H

#include <iostream>
#include <string>
#include <map>
#include <list>
#include <set>
#include "IRBaseVisitor.h"
#include "NaiveASMNode.h"
#include "Register.h"
#include "IRNode.h"
#include "RegisterAllocator.h"

class NaiveASMBuilder : public IRBaseVisitor {
private:
    int spSize = 0;
    RegisterAllocator regAllocator;
    NaiveASMProgramNode* program = nullptr;
    IRFunctionNode* currentFunction = nullptr;
    NaiveASMBlockNode* currentBlock;
    NaiveASMImmInsNode *spAddIns = nullptr, *spRetIns = nullptr;
    std::map<std::string, NaiveASMVarNode*> varMap;
    std::set<NaiveASMVarNode*> varSet;
    std::set<IRVarNode*> irVarSet;
    std::map<std::string, int> counter;
    std::map<std::string, std::vector<NaiveASMLaInsNode*>> phiLaMap;
    std::map<std::string, IRBlockNode*> blockMap;
    std::vector<std::pair<NaiveASMLocalVarNode*, NaiveASMLocalVarNode*>> phiVars;

public:
    NaiveASMBuilder() {}
    ~NaiveASMBuilder() { 
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
    void getPtr(NaiveASMVarNode* var, Register* reg);
    void getVar(NaiveASMVarNode* var, Register* reg);
    void getAddr(IRVarNode* var, Register* reg);
    void getValue(IRValueNode* value, Register* reg);
    void storeVar(NaiveASMVarNode* var, Register* reg);
    void storePtr(NaiveASMVarNode* var, Register* reg);
    NaiveASMLocalVarNode* registerLocalVar(IRVarNode* var, bool p_);
    NaiveASMVarNode* getVarNode(IRVarNode* var);
    void setPhiVar(IRBlockNode* node, IRBlockNode* nextBlock);
};

#endif