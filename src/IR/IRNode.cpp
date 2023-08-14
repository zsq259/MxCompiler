#include "IRNode.h"

std::string IRProgramNode::to_string() {
    std::string ret = "";
    for (auto c:classes) {
        ret += c->to_string() + "\n";
    }
    for (auto g:global_vars) {
        ret += g->to_string() + "\n";
    }
    ret += '\n';
    for (auto f:functions) {
        ret += f->to_string() + "\n";
    }
    return ret;
}

std::string IRLiteralNode::to_string() {
    if (type->to_string() == "i32") return std::to_string(value);
    if (type->to_string() == "i1") return value ? "true" : "false";
    if (type->to_string() == "ptr") return "null";
    return "";
}

std::string IRStringNode::to_string() {
    std::string ret = "c\"";
    for (auto c: str) {
        if (c == '\n') ret += "\\0A";
        else if (c == '\\') ret += "\\\\";
        else if (c == '\"') ret += "\\22";
        else ret += c;
    }
    ret += "\\00\"";
    return ret;
}

std::string IRGlobalVarNode::to_string() {
    return "@" + name;
}

std::string IRVarNode::to_string() {
    return "%" + name;
}

std::string IRGlobalVarStmtNode::to_string() {
    std::string ret = "";
    ret += var->to_string() + " = global " + value->type->to_string() + " " + value->to_string();
    return ret;
}

std::string IRClassStmtNode::to_string() {
    std::string ret = "";
    ret += type->to_string() + " = " + type->type->to_string();
    return ret;
}

std::string IRFunctionNode::to_string() {
    std::string ret = "";
    if (blocks.empty()) ret += "declare ";
    else ret += "define ";
    ret += retType->to_string() + " @" + name + "(";
    for (int i = 0, n = args.size(); i < n; ++i) {
        if (i < n - 1) ret += args[i].first->to_string() + " %" + args[i].second + ", ";
        else ret += args[i].first->to_string() + " %" + args[i].second;
    }
    ret += ")";
    if (blocks.empty()) return ret; 
    ret += "{\n";
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

std::string IRBrCondStmtNode::to_string() {
    std::string ret = "";
    ret += "br i1 " + cond->to_string() + ", label %" + trueLabel + ", label %" + falseLabel;
    return ret;
}

std::string IRBrStmtNode::to_string() {
    std::string ret = "";
    ret += "br label %" + label;
    return ret;
}

std::string IRRetStmtNode::to_string() {
    std::string ret = "";
    ret += "ret " + (var ? var->type->to_string() + " " + var->to_string() : "void");
    return ret;
}

std::string IRBinaryStmtNode::to_string() {
    std::string ret = "";
    ret += var->to_string() + " = ";
    ret += op + " " + lhs->type->to_string() + " " + lhs->to_string() + ", " + rhs->to_string();
    return ret;
}

std::string IRAllocaStmtNode::to_string() {
    std::string ret = "";
    ret += var->to_string() + " = alloca " + type->to_string();
    return ret;
}

std::string IRLoadStmtNode::to_string() {
    std::string ret = "";
    ret += var->to_string() + " = ";
    ret += "load " + var->type->to_string() + ", " + ptr->type->to_string() + " " + ptr->to_string();
    return ret;
}

std::string IRStoreStmtNode::to_string() {
    std::string ret = "";
    ret += "store " + value->type->to_string() + " " + value->to_string() + ", " + ptr->type->to_string() + " " + ptr->to_string();
    return ret;
}

std::string IRIcmpStmtNode::to_string() {
    std::string ret = "";
    ret += var->to_string() + " = ";
    ret += op + " " + lhs->type->to_string() + " " + lhs->to_string() + ", " + rhs->to_string();
    return ret;
}

std::string IRTruncStmtNode::to_string() {
    std::string ret = "";
    ret += var->to_string() + " = ";
    ret += "trunc " + value->type->to_string() + " " + value->to_string() + " to " + var->type->to_string();
    return ret;
}

std::string IRZextStmtNode::to_string() {
    std::string ret = "";
    ret += var->to_string() + " = ";
    ret += "zext " + value->type->to_string() + " " + value->to_string() + " to " + var->type->to_string();
    return ret;
}

std::string IRCallStmtNode::to_string() {
    std::string ret = "";
    if (var) ret += var->to_string() + " = ";
    ret += "call " + (var? var->type->to_string(): "void") + " @" + funcName + "(";
    for (int i = 0, k = args.size(); i < k; ++i) {
        if (i < k - 1) ret += args[i]->type->to_string() + " " + args[i]->to_string() + ", ";
        else ret += args[i]->type->to_string() + " " + args[i]->to_string();
    }
    ret += ")";
    return ret;
}

std::string IRPhiStmtNode::to_string() {
    std::string ret = "";
    ret += var->to_string() + " = phi " + var->type->to_string() + " ";
    for (int i = 0, k = values.size(); i < k; ++i) {
        if (i < k - 1) ret += "[ " + values[i].first->to_string() + ", %" + values[i].second + " ], ";
        else ret += "[ " + values[i].first->to_string() + ", %" + values[i].second + " ]";
    }
    return ret;
}

std::string IRGetElementPtrStmtNode::to_string() {
    std::string ret = "";
    ret += var->to_string() + " = getelementptr " + type->to_string();
    ret += ", ptr " + ptr->to_string() + ", i32 " + index->to_string();
    return ret;
}