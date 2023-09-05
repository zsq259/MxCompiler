#include "NaiveASMNode.h"

std::string NaiveASMLoadInsNode::to_string() {
    return op + " " + dest->name + ", " + std::to_string(offset) + "(" + src->name + ")";
}

std::string NaiveASMStoreInsNode::to_string() {
    return op + " " + src->name + ", " + std::to_string(offset) + "(" + dest->name + ")";
}

std::string NaiveASMLaInsNode::to_string() {
    return "la " + dest->name + ", " + name;
}

std::string NaiveASMBinaryInsNode::to_string() {
    return op + " " + dest->name + ", " + src1->name + ", " + src2->name;
}

std::string NaiveASMImmInsNode::to_string() {
    return op + " " + dest->name + ", " + src->name + ", " + std::to_string(imm);
}

std::string NaiveASMJumpInsNode::to_string() {
    return "j " + label;
}

std::string NaiveASMRetInsNode::to_string() {
    return "ret";
}

std::string NaiveASMBranchInsNode::to_string() {
    return op + " " + src1->name + ", " + src2->name + ", " + label;
}

std::string NaiveASMCallInsNode::to_string() {
    return "call " + name;
}

std::string NaiveASMLocalVarNode::to_string() {
    return name;
}

std::string NaiveASMGlobalVarNode::to_string() {
    return name;
}

std::string NaiveASMBlockNode::to_string() {
    std::string ret = "";
    if (name == "main") ret += ".globl main\n";
    ret += name;
    ret += ":\n";
    for (auto ins: insts) {
        ret += '\t' + ins->to_string() + '\n';
    }
    ret += '\n';
    return ret;
}

std::string NaiveASMFunctionNode::to_string() {
    std::string ret = "";
    for (auto b: blocks) { ret += b->to_string(); }
    return ret;
}

std::string NaiveASMGlobalVarStmtNode::to_string() {
    std::string ret = "";
    ret += name;

    if (is_string) {
        if (value.size()) {
            ret += ": .asciz ";
            ret += "\"";
            for (auto c:value) {
                if (c == '\n') ret += "\\n";
                else if (c == '\"') ret += "\\\"";
                else if (c == '\\') ret += "\\\\";
                else ret += c;
            }
            ret += "\"";
        }
        else ret += ": .zero 1";
    }
    else {
        ret +=  ": .word ";
        ret += value;
    }
    return ret;
}

std::string NaiveASMDataSectionNode::to_string() {
    std::string ret = "";
    ret += ".data\n";
    for (auto var: globalVarStmts) {
        ret += var->to_string();
        ret += '\n';
    }
    return ret;
}

std::string NaiveASMTextSectionNode::to_string() {
    std::string ret = "";
    ret += ".text\n";
    for (auto func: functions) {
        ret += func->to_string();
        ret += '\n';
    }
    return ret;
}

std::string NaiveASMProgramNode::to_string() {
    std::string ret = "";
    if (data) ret += data->to_string(), ret += '\n';
    if (text) ret += text->to_string(), ret += '\n';
    return ret;   
}