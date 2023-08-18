#include "ASMNode.h"

std::string ASMLoadInsNode::to_string() {
    return op + " " + dest->name + ", " + std::to_string(offset) + "(" + src->name + ")";
}

std::string ASMStoreInsNode::to_string() {
    return op + " " + src->name + ", " + std::to_string(offset) + "(" + dest->name + ")";
}

std::string ASMLaInsNode::to_string() {
    return "la " + dest->name + ", " + name;
}

std::string ASMBinaryInsNode::to_string() {
    return op + " " + dest->name + ", " + src1->name + ", " + src2->name;
}

std::string ASMImmInsNode::to_string() {
    return op + " " + dest->name + ", " + src->name + ", " + std::to_string(imm);
}

std::string ASMJumpInsNode::to_string() {
    return "j " + label;
}

std::string ASMRetInsNode::to_string() {
    return "ret";
}

std::string ASMBranchInsNode::to_string() {
    return op + " " + src1->name + ", " + src2->name + ", " + label;
}

std::string ASMCallInsNode::to_string() {
    return "call " + name;
}

std::string ASMLocalVarNode::to_string() {
    return name;
}

std::string ASMGlobalVarNode::to_string() {
    return name;
}

std::string ASMBlockNode::to_string() {
    std::string ret = "";
    if (name == "main") ret += ".globl main\n";
    ret += name;
    ret += ":\n";
    for (auto ins: insts) {
        ret += ins->to_string();
        ret += '\n';
    }
    return ret;
}

std::string ASMFunctionNode::to_string() {
    std::string ret = "";
    for (auto b: blocks) { ret += b->to_string(); }
    return ret;
}

std::string ASMGlobalVarStmtNode::to_string() {
    std::string ret = "";
    ret += name;

    if (is_string) {
        if (value.size()) {
            ret += ": .asciiz ";
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

std::string ASMDataSectionNode::to_string() {
    std::string ret = "";
    ret += ".data\n";
    for (auto var: globalVarStmts) {
        ret += var->to_string();
        ret += '\n';
    }
    return ret;
}

std::string ASMTextSectionNode::to_string() {
    std::string ret = "";
    ret += ".text\n";
    for (auto func: functions) {
        ret += func->to_string();
        ret += '\n';
    }
    return ret;
}

std::string ASMProgramNode::to_string() {
    std::string ret = "";
    if (data) ret += data->to_string(), ret += '\n';
    if (text) ret += text->to_string(), ret += '\n';
    return ret;   
}