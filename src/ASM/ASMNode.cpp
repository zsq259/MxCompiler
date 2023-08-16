#include "ASMNode.h"

std::string ASMGlobalVarStmtNode::to_string() {
    std::string ret = "";
    ret += name;

    if (is_string) {
        if (value.size()) {
            ret += ": .asciiz ";
            ret += value;
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
    ret += data->to_string();
    ret += '\n';
    ret += text->to_string();
    ret += '\n';
    return ret;   
}