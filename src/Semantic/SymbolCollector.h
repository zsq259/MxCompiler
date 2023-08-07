#include "../AST/ASTBaseVisitor.h"
#include "Scope.h"
#include "Type.h"
#include "ASTNode.h"

class ClassColletor: public ASTBaseVisitor {
private:
    GlobalScope *globalScope;
public:
    explicit ClassColletor(GlobalScope *globalScope_): globalScope(globalScope_) {}
    void init() {
        globalScope->addClassType("int");
        globalScope->addClassType("bool");
        globalScope->addClassType("string");
        globalScope->addClassType("void");
    }
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
    void init() {
        FuncType f;
        f.name = "print";
        f.returnType = Type("void", 0, true);
        f.paras.emplace_back("string", 0);
        globalScope->addFunction(f);
        f.paras.clear();

        f.name = "println";
        f.returnType = Type("void", 0, true);
        f.paras.emplace_back("string", 0);
        globalScope->addFunction(f);
        f.paras.clear();

        f.name = "printInt";
        f.returnType = Type("void", 0, true);
        f.paras.emplace_back("int", 0);
        globalScope->addFunction(f);
        f.paras.clear();

        f.name = "printlnInt";
        f.returnType = Type("void", 0, true);
        f.paras.emplace_back("int", 0);
        globalScope->addFunction(f);
        f.paras.clear();

        f.name = "getString";
        f.returnType = Type("string", 0, true);
        globalScope->addFunction(f);
        f.paras.clear();

        f.name = "getInt";
        f.returnType = Type("int", 0, true);
        globalScope->addFunction(f);
        f.paras.clear();

        f.name = "toString";
        f.returnType = Type("string", 0, true);
        f.paras.emplace_back("int", 0);
        globalScope->addFunction(f);
        f.paras.clear();

        f.name = "length";
        f.returnType = Type("int", 0, true);
        globalScope->addFunction(f);
        f.paras.clear();

        f.name = "substring";
        f.returnType = Type("string", 0, true);
        f.paras.emplace_back("int", 0);
        f.paras.emplace_back("int", 0);
        globalScope->addFunction(f);
        f.paras.clear();

        f.name = "parseInt";
        f.returnType = Type("int", 0, true);
        globalScope->addFunction(f);
        f.paras.clear();

        f.name = "ord";
        f.returnType = Type("int", 0, true);
        f.paras.emplace_back("int", 0);
        globalScope->addFunction(f);
        f.paras.clear();

        f.name = "size";
        f.returnType = Type("int", 0, true);
        globalScope->addFunction(f);
        f.paras.clear();
    }
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
        if (node->returnType) f.returnType = Type(node->returnType->name, node->returnType->dim);
        else f.returnType = Type("void", 0);
        scope->addFunction(f);
    }
    void visitClassNode(ASTClassNode *node) override {
        node->scope = new Scope(globalScope);
        globalScope->getClassType(node->name)->scope = node->scope;
        node->scope->addVariable("this", Type(node->name, 0));
        for (auto v: node->variables) {
            if (!v->type) throw semantic_error("class type not found");
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
