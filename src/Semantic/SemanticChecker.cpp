#include "SemanticChecker.h"
#include "../AST/ASTNode.h"
void SemanticChecker::visitProgramNode(ASTProgramNode *node) {
    for (auto c: node->children) c->accept(this);
}

void SemanticChecker::visitClassNode(ASTClassNode *node) {
    auto currentScope = scope;
    scope = node->scope;
    for (auto c: node->constructors) c->accept(this);
    for (auto f: node->functions) f->accept(this);
    scope = currentScope;
}

void visitBlockWithScope(ASTBlockNode *node, ASTBaseVisitor *visitor) {
    for (auto s: node->stmts) s->accept(visitor);
}

void SemanticChecker::visitFunctionNode(ASTFunctionNode *node) {
    scope->addFunction(node->name);
    auto currentScope = scope;
    scope = new Scope(scope);
    currentFunction = node;
    for (auto p: node->paras) {
        p.first->accept(this);
        scope->addVariable(p.second, Type(p.first->name, p.first->dim));
    }
    visitBlockWithScope(node->block, this);
    scope = currentScope;
    currentFunction = nullptr;
}

void SemanticChecker::visitTypeNode(ASTTypeNode *node) {
    if (!globalScope->hasClassType(node->name)) {
        throw semantic_error("type " + node->name + " not defined");
    }
    return ;
}

void SemanticChecker::visitBlockNode(ASTBlockNode *node) {
    auto currentScope = scope;
    scope = new Scope(scope);
    for (auto s: node->stmts) s->accept(this);
    scope = currentScope;
}

// void SemanticChecker::visitStmtNode(ASTStmtNode *node) {}

void SemanticChecker::visitExprStmtNode(ASTExprStmtNode *node) {
    for (auto e: node->exprs) e->accept(this);
}

void SemanticChecker::visitFuncExprNode(ASTFuncExprNode *node) {
    node->func->accept(this);
    auto f = dynamic_cast<ASTAtomExprNode*>(node->func);
    FuncType ft;
    if (!f) {
        auto f1 = dynamic_cast<ASTMemberExprNode*>(node->func);
        ft = scope->getFunction(f1->member);
    }
    else {
        ft = scope->getFunction(f->name);
    }
    if (!f) throw semantic_error("function call type error");
    if (ft.paras.size() != node->args.size()) {
        throw semantic_error("function call parameter sum error");
    }
    for (int i = 0; i < ft.paras.size(); ++i) {
        if (ft.paras[i] != node->args[i]->type) {
            throw semantic_error("function call parameter type error");
        }
    }
    node->type = ft.returnType;
    node->type.setConst();
}

void SemanticChecker::visitArrayExprNode(ASTArrayExprNode *node) {
    node->array->accept(this);
    if (!node->array->type.dim) {
        throw semantic_error("[] must be applied to array");
    }
    node->index->accept(this);
    if (!node->index->type.is_int()) {
        throw semantic_error("index must be int");
    }
    node->type = node->array->type;
    --node->type.dim;
}

void SemanticChecker::visitMemberExprNode(ASTMemberExprNode *node) {
    node->name->accept(this);
    if (node->type.is_basic()) {
        throw semantic_error("basic type has no member");
    }
    if (node->type.dim) {
        throw semantic_error("array has no member");
    }
    auto c = globalScope->getClassType(node->type.name);
    if (c->scope->hasVar(node->member)) node->type = c->scope->getVarType(node->member);
}

void SemanticChecker::visitSingleExprNode(ASTSingleExprNode *node) {
    node->expr->accept(this);
    node->type = node->expr->type;
    if (node->op == "++" || node->op == "--") {
        if (!node->type.is_int()) {
            throw semantic_error("++ or -- must be applied to int");
        }
        if (node->type.is_const()) {
            throw semantic_error("++ or -- cannot be applied to const");
        }
        if (node->right) node->type.setConst();
    }
    else if (node->op == "-") {
        if (!node->type.is_int()) {
            throw semantic_error("- must be applied to int");
        }
        node->type.setConst();
    }
    else if (node->op == "!") {
        if (!node->type.is_bool()) {
            throw semantic_error("! must be applied to bool");
        }
        node->type.setConst();
    }
    else if (node->op == "~") {
        if (!node->type.is_int()) {
            throw semantic_error("~ must be applied to int");
        }
        node->type.setConst();
    }
    else throw semantic_error("unknown unary operator: " + node->op);
}

void SemanticChecker::visitNewExprNode(ASTNewExprNode *node) {
    node->newType->accept(this);
    if (!globalScope->hasClassType(node->newType->name)) {
        throw semantic_error("type " + node->newType->name + " not defined");
    }
    node->type = Type(node->newType->name, node->newType->dim, true);
    if (node->type.is_void()) throw semantic_error("cannot new void");

}

void SemanticChecker::visitBinaryExprNode(ASTBinaryExprNode *node) {
    node->lhs->accept(this);
    node->rhs->accept(this);
    if (node->lhs->type == node->rhs->type) {
        node->type = node->lhs->type;
    }
    else throw semantic_error("type mismatch in binary expression");
}

void SemanticChecker::visitTernaryExprNode(ASTTernaryExprNode *node) {
    node->cond->accept(this);
    if (!node->cond->type.is_bool()) {
        throw semantic_error("condition of ternary expression must be bool");
    }
    node->True->accept(this);
    node->False->accept(this);
    
    if (node->True->type == node->False->type) {
        node->type = node->True->type;
    }
    else throw semantic_error("type mismatch in ternary expression");
    
}

void SemanticChecker::visitAssignExprNode(ASTAssignExprNode *node) {
    node->lhs->accept(this);
    node->rhs->accept(this);
    if (!node->lhs->type.assignable(node->rhs->type)) {
        throw semantic_error("type mismatch in assignment");
    }
    node->type = node->lhs->type;
}

void SemanticChecker::visitLiterExprNode(ASTLiterExprNode *node) {
    if (node->value == "null") {
        node->type = Type("null", 0, true);
    }
    else if (node->value == "true" || node->value == "false") {
        node->type = Type("bool", 0, true);
    }
    else if (isdigit(node->value[0])) {
        node->type = Type("int", 0, true);
    }
    else if (node->value[0] == '\"') {
        node->type = Type("string", 0, true);
    }
    else throw semantic_error("unknown literal type: "  + node->value);
}

void SemanticChecker::visitAtomExprNode(ASTAtomExprNode *node) {
    node->type = scope->getVarType(node->name);
}

void SemanticChecker::visitIfStmtNode(ASTIfStmtNode *node) {
    for (auto c: node->conds) {
        c->accept(this);
        if (!c->type.is_bool()) throw semantic_error("if condition must be bool");
    }
    for (auto b: node->blocks) b->accept(this);
}

void SemanticChecker::visitWhileStmtNode(ASTWhileStmtNode *node) {
    auto currentScope = scope;
    scope = new Scope(scope);
    node->cond->accept(this);
    if (!node->cond->type.is_bool()) throw semantic_error("while condition must be bool");
    ++loopDepth;
    visitBlockWithScope(node->block, this);
    --loopDepth;
    scope = currentScope;
}

void SemanticChecker::visitForStmtNode(ASTForStmtNode *node) {
    auto currentScope = scope;
    scope = new Scope(scope);
    if (node->init) node->init->accept(this);
    if (node->cond) {
        node->cond->accept(this);
        if (!node->cond->type.is_bool()) throw semantic_error("for condition must be bool");
    }
    if (node->step) node->step->accept(this);
    ++loopDepth;
    visitBlockWithScope(node->block, this);
    --loopDepth;
    scope = currentScope;
}

// void SemanticChecker::visitFlowStmtNode(ASTFlowStmtNode *node)         {}
void SemanticChecker::visitContinueStmtNode(ASTContinueStmtNode *node) {
    if (!loopDepth) throw semantic_error("continue must be in loop");
    
}
void SemanticChecker::visitBreakStmtNode(ASTBreakStmtNode *node) {
    if (!loopDepth) throw semantic_error("break must be in loop");
}
void SemanticChecker::visitReturnStmtNode(ASTReturnStmtNode *node) {
    if (!currentFunction) throw semantic_error("return must be in function");
    if (node->expr) {
        node->expr->accept(this);
        if (node->expr->type.name != currentFunction->returnType->name) throw semantic_error("return type not match");
    }
    else {
        if (currentFunction->returnType->name != "void") throw semantic_error("return type not match");
    }
}

void SemanticChecker::visitVarStmtNode(ASTVarStmtNode *node) {
    node->type->accept(this);
    for (auto v: node->vars) {
        if (v.second) v.second->accept(this);
        
        scope->addVariable(v.first, Type(node->type->name, node->type->dim));
    }
}

void SemanticChecker::visitNewTypeNode(ASTNewTypeNode *node) {
    for (auto s: node->size) {
        s->accept(this);
        if (!s->type.is_int()) throw semantic_error("array size must be int");
    }
}