#include <map>
#include <vector>
#include <string>
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
    Scope(Scope* parentScope_): parentScope(parentScope_) {}
    Scope* parentScope() { return parentScope; }
    void defineVariable(string name, Type t) {

    }
};

class GlobalScope: public Scope {
private:
    map<string, ClassType*> types;
public:
    GlobalScope(Scope* parentScope): Scope(parentScope) {}
    ~GlobalScope() {
        for (auto t: types) delete t.second;
    }
    bool hasType(const string &name) { return types.count(name); }
    TypeName* addType(const string &name) {
        if (hasType(name)) throw semantic_error("class existed: " + name);
        auto type = new ClassType(name);
        types.emplace(name, type);
        return type;
    }
    ClassType* getType(const string &name) {
        if (!hasType(name)) throw semantic_error("no such class: " + name);
        return types[name];
    }
};