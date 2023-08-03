#include <iostream>
#include <cstdio>
#include <cstring>
#include "ASTNode.h"
using std::cout;

void ASTProgramNode::print() {
    for (auto &child: children) child->print(), cout << '\n';
}

void ASTClassNode::print() {
    
}

void ASTConstructNode::print() {}

void ASTFunctionNode::print() {}

void ASTTypeNode::print() {
    cout << name;
    for (int i = 0; i < dim; ++i) cout << "[]";
}

void ASTBlockNode::print() {
    if (!stmts.size()) { cout << "{}"; return; }
    cout << "{\n";
    for (auto stmt: stmts) stmt->print(), cout << '\n';
    cout << "}";
}

void ASTStmtNode::print() {}

void ASTExprStmtNode::print() {}

void ASTExprNode::print() {}

void ASTFuncExprNode::print() {}

void ASTArrayExprNode::print() {
    array->print();
    cout << '[';
    index->print();
    cout << ']';
}

void ASTMemberExprNode::print() {
    name->print();
    cout << '.' << member;
}

void ASTSingleExprNode::print() {}

void ASTNewExprNode::print() {}

void ASTBinaryExprNode::print() {}

void ASTTernaryExprNode::print() {}

void ASTAssignExprNode::print() {}

void ASTLiterExprNode::print() {}

void ASTAtomExprNode::print() {}

void ASTIfStmtNode::print() {}

void ASTWhileStmtNode::print() {}

void ASTForStmtNode::print() {}

void ASTFlowStmtNode::print() {}

void ASTContinueStmtNode::print() {}

void ASTBreakStmtNode::print() {}

void ASTReturnStmtNode::print() {}

void ASTVarStmtNode::print() {
    
}

void ASTNewTypeNode::print() {}
