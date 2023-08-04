#include <iostream>
#include <cstdio>
#include <cstring>
#include "ASTNode.h"
using std::cout;

void ASTProgramNode::print() {
    for (auto &child: children) child->print(), cout << '\n';
}

void ASTClassNode::print() {
    cout << name << "{\n";
    for (auto v: variables) v->print(), cout << "\n\n";
    for (auto c: constructors) c->print(), cout << "\n\n";
    for (auto f: functions) f->print(), cout << "\n\n";
    cout << "}";
}

void ASTConstructNode::print() {
    cout << name;
    block->print();
}

void ASTFunctionNode::print() {
    returnType->print();
    cout << ' ' << name << "(";
    for (auto p: paras) p.first->print(), cout << ' ' << p.second << ' ';
    cout << ") \n";
    block->print();
    cout << "\n";
}

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

// void ASTStmtNode::print() {}

void ASTExprStmtNode::print() {
    for (auto e: exprs) { 
        e->print(); 
        if (e != exprs.back()) cout << ',';
    }
    cout << ';';
}

// void ASTExprNode::print() {}

void ASTFuncExprNode::print() {
    func->print();
    cout << '(';
    for (auto a: args) a->print();
    cout << ')';
}

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

void ASTSingleExprNode::print() {
    if(right) {
        expr->print();
        cout << op;
    }
    else {
        cout << op;
        expr->print(); 
    }
}

void ASTNewExprNode::print() {
    cout << "new ";
    type->print();
}

void ASTBinaryExprNode::print() {
    lhs->print();
    cout << ' ' << op << ' ';
    rhs->print();
}

void ASTTernaryExprNode::print() {
    cond->print();
    cout << "? ";
    True->print();
    cout << ": ";
    False->print();
}

void ASTAssignExprNode::print() {
    lhs->print();
    cout << " = ";
    rhs->print();
}

void ASTLiterExprNode::print() {
    cout << value;
}

void ASTAtomExprNode::print() {
    cout << name;
}

void ASTIfStmtNode::print() {
    cout << "if (";
    conds[0]->print(); cout << ") ";
    blocks[0]->print();
    cout << '\n';
    if (conds.size() > 2) {
        for (int i = 1; i < conds.size(); ++i) {
            cout << "else if (";
            conds[i]->print(); cout << ") ";
            blocks[i]->print();
            cout << '\n';
        }
    }
    if (conds.size() < blocks.size()) {
        cout << "else ";
        blocks[blocks.size() - 1]->print();
        cout << '\n';
    }
}

void ASTWhileStmtNode::print() {
    cout << "while ";
    cond->print();
    cout << ' ';
    block->print();
    cout << '\n';
}

void ASTForStmtNode::print() {
    cout << "for ";
    if (init) init->print();
    cout << " ;";
    if (cond) cond->print();
    cout << " ;";
    if (step) step->print();
    cout << "\n";
    block->print();
}

// void ASTFlowStmtNode::print() {}

void ASTContinueStmtNode::print() {
    cout << "continue";
}

void ASTBreakStmtNode::print() {
    cout << "break";
}

void ASTReturnStmtNode::print() {
    cout << "return ";
    if (expr) expr->print();
}

void ASTVarStmtNode::print() {
    type->print();
    for (auto v: vars) {
        cout << ' ' << v.first;
        if (v.second) cout << " = ", v.second->print();
        if (v != vars.back()) cout << ",";
    }
    cout << ";\n";
}

void ASTNewTypeNode::print() {
    cout << name;
    for (auto s: size) {
        cout << "[";
        s->print();
        cout << ']';
    }
    for (int i = size.size(); i < dim; ++i) cout << "[]";
}