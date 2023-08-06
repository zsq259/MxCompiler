#include "ASTBaseVisitor.h"
#include "Scope.h"
#include "Type.h"
#include "ASTNode.h"

class ClassColletor: public ASTBaseVisitor {
private:
    GlobalScope *globalScope;
public:
    explicit ClassColletor(GlobalScope *globalScope_): globalScope(globalScope_) {}
    void visitProgramNode(ASTProgramNode *node) override {
        for (auto c: node->children) c->accept(this);
    }
    void visitClassNode(ASTClassNode *node) override {
        if (globalScope->hasClassType(node->name)) throw semantic_error("class exists: " + node->name);
        globalScope->addClassType(node->name);
    }
};

class FunctionCollector: public ASTBaseVisitor {
private:
    GlobalScope *globalScope;
public:
    explicit FunctionCollector(GlobalScope *globalScope_): globalScope(globalScope_) {}
    void visitProgramNode(ASTProgramNode *node) override {
        for (auto c: node->children) c->accept(this);
    }
    void visitFunctionNode(ASTFunctionNode *node) override {
        visitFunc(node, globalScope);
    }
    void visitFunc(ASTFunctionNode *node, Scope *scope, bool is_constructor = false) {
        if (!is_constructor && globalScope->hasClassType(node->name)) 
            throw semantic_error("function name conflicts with class: " + node->name);
        FuncType f(node->name);
        for (auto p: node->paras) {
            f.paras.emplace_back(p.first->name, p.first->dim);
        }
        f.returnType = Type(node->returnType->name, node->returnType->dim);
        scope->addFunction(f);
    }
    void visitClassNode(ASTClassNode *node) override {
        node->scope = new Scope(globalScope);
        for (auto v: node->variables) {
            auto t = Type(v->type->name, v->type->dim);
            for (auto n: v->vars) {
                node->scope->addVariable(n.first, t);
            }
        }
        for (auto c: node->constructors) {
            if (c->name != node->name) throw semantic_error("constructor name conflicts with class: " + c->name);
            visitFunc(c, node->scope, true);
        }
        for (auto f: node->functions) { visitFunc(f, node->scope); }
    }
};
