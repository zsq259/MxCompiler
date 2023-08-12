#ifndef IR_TYPE_H
#define IR_TYPE_H
#include <string>
#include <vector>

class IRType {
public:
    virtual std::string to_string() = 0;
    virtual int size() = 0;
};

class IRVoidType: public IRType {
public:
    std::string to_string() override { return "void"; }
    int size() override { return 0; }
};

class IRIntType: public IRType {
public:
    int bits;
    explicit IRIntType(int bits_): bits(bits_) {}
    std::string to_string() override { return "i" + std::to_string(bits); }
    int size() override { return (bits + 7) / 8; }
};

class IRPtrType: public IRType {
public:
    std::string to_string() override { return "ptr"; }
    int size() override { return 4; }
};

class IRArrayType: public IRType {
public:
    int length;
    IRType *type;

    explicit IRArrayType(int length_, IRType *type_): length(length_), type(type_) {}
    std::string to_string() override {
        return "[" + std::to_string(length) + " x " + type->to_string() + "]";
    }
    int size() override { return length * type->size(); }
};

class IRStructType: public IRType {
public:
    std::vector<IRType *> elements;
    std::string to_string() override {
        std::string ret = "{ ";
        for (int i = 0, n = elements.size(); i < n; ++i) {
            if (i < n - 1) ret += elements[i]->to_string() + ", ";
            else ret += elements[i]->to_string();
        }
        ret += " }";
        if (size() % 4) ret = "<" + ret + ">";
        return ret;
    }
    int size() override {
        int ret = 0;
        for (auto element : elements) ret += element->size();
        return ret;
    }
};

#endif