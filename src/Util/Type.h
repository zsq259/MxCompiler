#include <vector>
#include <string>
using std::vector;
using std::string;

class TypeName {
private:
    string name;
    friend class Type;
public:
    TypeName() = default;
    TypeName(const string &name_): name(name_) {} 
};

class Type: public TypeName {
private:
    int dim = 0;
public:
    Type() = default;
    Type(const string &name_, const int dim_ = 0): TypeName(name_), dim(dim_) {}
    bool is(const string &name_) { return dim == 0 && name == name_; }
    bool is_int()    { return dim == 0 &&  name == "int"; }
    bool is_bool()   { return dim == 0 && (name == "true" || name == "false"); }
    bool is_null()   { return dim == 0 &&  name == "null"; }
    bool is_void()   { return dim == 0 &&  name == "void"; }
    bool is_string() { return dim == 0 && name == "string"; }
};

class Scope;

class ClassType: public TypeName {
private:
    Scope *scope = nullptr;
public:
    ClassType(const string &name): TypeName(name) {}
};

class FuncType: public TypeName {
private:
    Type returnType;
    vector<Type> args;
public:
    FuncType(const string &name): TypeName(name) {

    }
};