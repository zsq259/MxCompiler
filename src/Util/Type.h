#ifndef __TYPE_H__
#define __TYPE_H__
#include <vector>
#include <string>
using std::vector;
using std::string;

class TypeName {
// private:
    
public:
    string name;
    TypeName() = default;
    TypeName(const string &name_): name(name_) {} 
};

class Type: public TypeName {
private:
    int dim = 0;
    bool isConst = false;
    friend class SemanticChecker;
public:
    Type() = default;
    Type(const string &name_, const int dim_ = 0, const bool isC = false): TypeName(name_), dim(dim_), isConst(isC) {}
    Type &operator=(const Type &t) {
        name = t.name;
        dim = t.dim;
        isConst = t.isConst;
        return *this;
    }
    void setConst() { isConst = true; }
    bool operator==(const Type &t) const { return name == t.name && dim == t.dim; }
    bool operator!=(const Type &t) const { return !(*this == t); }
    bool assignable(const Type &t) const {
        if (isConst) return false;
        return convertible(t);
    }
    bool convertible(const Type &t) const {
        if (t.is_null()) return dim > 0 || !is_basic();
        return name == t.name && dim == t.dim;
    }
    bool is(const string &name_) { return dim == 0 && name == name_; }
    bool is_int()    const { return dim == 0 &&  name == "int"; }
    bool is_bool()   const { return dim == 0 && (name == "true" || name == "false"); }
    bool is_null()   const { return dim == 0 &&  name == "null"; }
    bool is_void()   const { return dim == 0 &&  name == "void"; }
    bool is_string() const { return dim == 0 &&  name == "string"; }
    bool is_basic()  const { return dim == 0 && (name == "int" || name == "bool" || name == "string" || name == "void"); }
    bool is_const()  const { return isConst; }
};

class Scope;

class ClassType: public Type {
private:
    Scope *scope = nullptr;
    friend class SemanticChecker;
public:
    ClassType(const string &name): Type(name) {}
};

class FuncType: public Type {
private:
    Type returnType;
    vector<Type> paras;
    friend class FunctionCollector;
    friend class SemanticChecker;
public:
    FuncType() = default;
    FuncType(const string &name): Type(name) {}
    FuncType(const FuncType &) = default;
};
#endif