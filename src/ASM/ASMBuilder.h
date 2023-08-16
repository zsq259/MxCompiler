#ifndef ASM_BUILDER_H
#define ASM_BUILDER_H

#include "IRBaseVisitor.h"

class ASMBuilder : public IRBaseVisitor {
private:

public:
    virtual void visitValue(IRValueNode* node) override;
    virtual void visitVar(IRVarNode* node) override;
    virtual void visitGlobalVar(IRGlobalVarNode* node) override;
    virtual void visitBlock(IRBlockNode* node) override;
    virtual void visitLiteral(IRLiteralNode* node) override;
    virtual void visitString(IRStringNode* node) override;
    virtual void visitBrCondStmt(IRBrCondStmtNode* node) override;
    virtual void visitBrStmt(IRBrStmtNode* node) override;
    virtual void visitRetStmt(IRRetStmtNode* node) override;
    virtual void visitBinaryStmt(IRBinaryStmtNode* node) override;
    virtual void visitAllocaStmt(IRAllocaStmtNode* node) override;
    virtual void visitLoadStmt(IRLoadStmtNode* node) override;
    virtual void visitStoreStmt(IRStoreStmtNode* node) override;
    virtual void visitIcmpStmt(IRIcmpStmtNode* node) override;
    virtual void visitTruncStmt(IRTruncStmtNode* node) override;
    virtual void visitZextStmt(IRZextStmtNode* node) override;
    virtual void visitCallStmt(IRCallStmtNode* node) override;
    virtual void visitPhiStmt(IRPhiStmtNode* node) override;
    virtual void visitGetElementPtrStmt(IRGetElementPtrStmtNode* node) override;
    virtual void visitGlobalVarStmt(IRGlobalVarStmtNode* node) override;
    virtual void visitFunction(IRFunctionNode* node) override;
    virtual void visitProgram(IRProgramNode* node) override;
};

#endif