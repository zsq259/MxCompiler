#include "IRNode.h"

std::string IRProgramNode::to_string() {
    std::string ret = "";
    for (auto g:global_vars) {
        ret += g->to_string() + "\n";
    }
    for (auto c:classes) {
        ret += c->to_string() + "\n";
    }
    for (auto f:functions) {
        ret += f->to_string() + "\n";
    }
    return ret;
}

std::string IRLiteralNode::to_string() {
    if (type->to_string() == "i32") return std::to_string(value);
    if (type->to_string() == "i1") return value ? "true" : "false";
    return "";
}

std::string IRStringNode::to_string() {
    return str;
}

std::string IRGlobalVarStmtNode::to_string() {
    std::string ret = "";
    ret += "@" + var->name + " = global " + value->type->to_string() + " " + value->to_string();
    return ret;
}

std::string IRVarStmtNode::to_string() {
    std::string ret = "";
    ret += "%" + var->name + " = alloca " + var->type->to_string() + "\n";
    if (value) ret += "store " + value->type->to_string() + " " + value->to_string() + ", " + "ptr" + var->name + '\n';
    return ret;
}

std::string IRFunctionNode::to_string() {
    std::string ret = "";
    ret += "define " + retType->to_string() + " @" + name + "(";
    for (int i = 0, n = args.size(); i < n; ++i) {
        if (i < n - 1) ret += args[i].first->to_string() + " %" + args[i].second + ", ";
        else ret += args[i].first->to_string() + " %" + args[i].second;
    }
    ret += ") {\n";
    for (auto b:blocks) {
        ret += b->to_string() + "\n";
    }
    ret += "}\n";
    return ret;
}

std::string IRBlockNode::to_string() {
    std::string ret = "";
    ret += label + ":\n";
    for (auto s:stmts) {
        ret += "  " + s->to_string() + "\n";
    }
    return ret;
}

std::string IRClassNode::to_string() {
    std::string ret = "";
    return ret;
}