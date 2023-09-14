#include "ASMNode.h"

std::string ASMLoadInsNode::to_string() {
    if (!dest->reg) {
        return op + " " + dest->name + ", " + std::to_string(offset) + "(" + src->name + ")";
        throw std::runtime_error("load dest reg is nullptr");
    }
    if (dynamic_cast<ASMLocalVarNode*>(src)) {
        if (!src->reg) {
            return op + " " + dest->name + ", " + std::to_string(offset) + "(" + src->name + ")";
            throw std::runtime_error("load src reg is nullptr");
        }
        return op + " " + dest->reg->name + ", " + std::to_string(offset) + "(" + src->reg->name + ")";
    }
    else 
        return op + " " + dest->reg->name + ", " + src->name;
}

std::string ASMStoreInsNode::to_string() {
    if (!src->reg || !dest->reg) {
        return op + " " + src->name + ", " + std::to_string(offset) + "(" + dest->name + ")";
        throw std::runtime_error("store src or dest reg is nullptr");
    }
    return op + " " + src->reg->name + ", " + std::to_string(offset) + "(" + dest->reg->name + ")";
}

std::string ASMLaInsNode::to_string() {
    if (!dest->reg) {
        return "la " + dest->name + ", " + name;
        throw std::runtime_error("la dest reg is nullptr");
    }
    return "la " + dest->reg->name + ", " + name;
}

std::string ASMBinaryInsNode::to_string() {
    if (!dest->reg || !src1->reg || !src2->reg) {
        return op + " " + dest->name + ", " + src1->name + ", " + src2->name;
        throw std::runtime_error("binary src or dest reg is nullptr");
    }
    return op + " " + dest->reg->name + ", " + src1->reg->name + ", " + src2->reg->name;
}

std::string ASMImmInsNode::to_string() {
    if (!dest->reg || !src->reg) {
        return op + " " + dest->name + ", " + src->name + ", " + std::to_string(imm);
        throw std::runtime_error("imm src or dest reg is nullptr");
    }
    return op + " " + dest->reg->name + ", " + src->reg->name + ", " + std::to_string(imm);
}

std::string ASMJumpInsNode::to_string() {
    return "j " + label;
}

std::string ASMRetInsNode::to_string() {
    return "ret";
}

std::string ASMBranchInsNode::to_string() {
    if (!src1->reg || !src2->reg) {
        return op + " " + src1->name + ", " + src2->name + ", " + label;
        throw std::runtime_error("branch src reg is nullptr");
    }
    return op + " " + src1->reg->name + ", " + src2->reg->name + ", " + label;
}

std::string ASMCallInsNode::to_string() {
    return "call " + name;
}

std::string ASMMoveInsNode::to_string() {
    if (!dest->reg || !src->reg) {
        return "mv " + dest->name + ", " + src->name;
        throw std::runtime_error("move src or dest reg is nullptr");
    }
    return "mv " + dest->reg->name + ", " + src->reg->name;
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
        ret += '\t' + ins->to_string() + '\n';
    }
    ret += '\n';
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

void ASMLoadInsNode::rewrite(std::vector<ASMInsNode*> &loadIns, std::vector<ASMInsNode*> &storeIns, std::set<ASMVarNode*> &rewriteSet) {
    // if (dest->reg && dest->reg->id == 2) throw std::runtime_error("load dest is sp");
    if (rewriteSet.contains(dest)) {
        auto tmp = new ASMLocalVarNode(".load.tmp" + std::to_string(counter[".load.tmp"]++), false);    
        auto store = new ASMStoreInsNode("sw", dest, tmp, dest->offset);
        storeIns.push_back(store);        
        dest = tmp;
    }
}