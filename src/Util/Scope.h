#ifndef SCOPE_H
#define SCOPE_H
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include "Type.h"
#include "Exception.h"

using std::map;
using std::vector;
using std::string;

class Scope {
private:
    map<string, Type> vars;
    map<string, FuncType> funcs;
    Scope* parentScope;

public:
    explicit Scope(Scope* parentScope_): parentScope(parentScope_) {}
    bool hasVar(string name) { return vars.count(name); }
    void addVariable(string name, Type t) {
        if (vars.count(name)) throw semantic_error("variable redefine: " + name);
        if (t.name == "void") throw semantic_error("variable type cannot be void: " + name);
        vars.emplace(name, t);
    }
    Type getVarType(const string &name) {
        auto s = this;
        while (s) {
            if (s->vars.count(name)) return s->vars[name];
            s = s->parentScope;   
        }
        throw semantic_error("variable not found: " + name);
    }
    void addFunction(FuncType func) {
        if (funcs.count(func.name)) throw semantic_error("function exists: " + func.name);
        funcs.emplace(func.name, func);
        vars.emplace(func.name, func.returnType);
    }
    FuncType getFunction(const string &name) {
        auto s = this;
        while (s) {
            if (s->funcs.count(name)) return s->funcs[name];
            s = s->parentScope;
        }
        throw semantic_error("function not found: " + name);
    }
};

class GlobalScope: public Scope {
private:
    map<string, ClassType*> types;
public:
    GlobalScope(Scope* parentScope): Scope(parentScope) {}
    ~GlobalScope() {
        for (auto t: types) {
            delete t.second->scope;
            delete t.second;
        }
    }
    bool hasClassType(const string &name) { return types.count(name); }
    TypeName* addClassType(const string &name) {
        if (hasClassType(name)) throw semantic_error("class exists: " + name);
        auto type = new ClassType(name);
        types.emplace(name, type);
        return type;
    }
    ClassType* getClassType(const string &name) {
        if (!hasClassType(name)) throw semantic_error("class not found: " + name);
        return types[name];
    }
};
#endif