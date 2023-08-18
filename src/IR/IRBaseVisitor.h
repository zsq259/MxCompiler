#ifndef IR_BASE_VISITOR_H
#define IR_BASE_VISITOR_H
#include <string>

class IRNode {
public:
    IRNode() = default;
    virtual ~IRNode() = default;
    virtual void print() = 0;
    virtual std::string to_string() = 0;
    virtual void accept(class IRBaseVisitor* visitor) {}
};

class IRValueNode;
class IRVarNode;
class IRGlobalVarNode;
class IRStmtNode;
class IRBlockNode;
class IRLiteralNode;
class IRStringNode;
class IRBrCondStmtNode;
class IRBrStmtNode;
class IRRetStmtNode;
class IRBinaryStmtNode;
class IRAllocaStmtNode;
class IRLoadStmtNode;
class IRStoreStmtNode;
class IRIcmpStmtNode;
class IRTruncStmtNode;
class IRZextStmtNode;
class IRCallStmtNode;
class IRPhiStmtNode;
class IRGetElementPtrStmtNode;
class IRGlobalVarStmtNode;
class IRFunctionNode;
class IRProgramNode;

class IRBaseVisitor {
public:
    IRBaseVisitor() = default;
    virtual ~IRBaseVisitor() = default;
    virtual void visit(IRNode* node) { node->accept(this); }
    virtual void visitValue(IRValueNode* node) {}
    virtual void visitVar(IRVarNode* node) {}
    virtual void visitGlobalVar(IRGlobalVarNode* node) {}
    virtual void visitBlock(IRBlockNode* node) {}
    virtual void visitLiteral(IRLiteralNode* node) {}
    virtual void visitString(IRStringNode* node) {}
    virtual void visitBrCondStmt(IRBrCondStmtNode* node) {}
    virtual void visitBrStmt(IRBrStmtNode* node) {}
    virtual void visitRetStmt(IRRetStmtNode* node) {}
    virtual void visitBinaryStmt(IRBinaryStmtNode* node) {}
    virtual void visitAllocaStmt(IRAllocaStmtNode* node) {}
    virtual void visitLoadStmt(IRLoadStmtNode* node) {}
    virtual void visitStoreStmt(IRStoreStmtNode* node) {}
    virtual void visitIcmpStmt(IRIcmpStmtNode* node) {}
    virtual void visitTruncStmt(IRTruncStmtNode* node) {}
    virtual void visitZextStmt(IRZextStmtNode* node) {}
    virtual void visitCallStmt(IRCallStmtNode* node) {}
    virtual void visitPhiStmt(IRPhiStmtNode* node) {}
    virtual void visitGetElementPtrStmt(IRGetElementPtrStmtNode* node) {}
    virtual void visitGlobalVarStmt(IRGlobalVarStmtNode* node) {}
    virtual void visitFunction(IRFunctionNode* node) {}
    virtual void visitProgram(IRProgramNode* node) {}
};

#endif