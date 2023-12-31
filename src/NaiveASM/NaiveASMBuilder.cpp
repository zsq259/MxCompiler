#include "NaiveASMBuilder.h"
#include "NaiveASMNode.h"
#include "IRNode.h"
#include "RegisterAllocator.h"

NaiveASMLocalVarNode* NaiveASMBuilder::registerLocalVar(IRVarNode* var, bool p_ = false) {
    if (varMap.count(var->name)) {
        auto ret = dynamic_cast<NaiveASMLocalVarNode*>(varMap[var->name]);
        ret->is_ptr = p_;
        return ret;
    }
    auto ret = new NaiveASMLocalVarNode(var->name, spSize, p_);
    varSet.insert(ret);
    spSize += var->type->size();
    varMap[var->name] = ret;
    return ret;
}

NaiveASMVarNode* NaiveASMBuilder::getVarNode(IRVarNode* var) {
    if (varMap.count(var->name)) return varMap[var->name];
    else return registerLocalVar(var, false);
}

void NaiveASMBuilder::getPtr(NaiveASMVarNode* var, Register* reg) {
    if (!var->is_ptr) throw std::runtime_error("not a pointer");
    if (dynamic_cast<NaiveASMGlobalVarNode*>(var)) {
        auto tmp = dynamic_cast<NaiveASMGlobalVarNode*>(var);
        auto load = new NaiveASMLoadInsNode("lw", reg, nullptr, 0);
        load->label = tmp->name;
        currentBlock->insts.push_back(load);
        auto load2 = new NaiveASMLoadInsNode("lw", reg, reg, 0);
        currentBlock->insts.push_back(load2);
    }
    else {
        auto tmp = dynamic_cast<NaiveASMLocalVarNode*>(var);
        auto load = new NaiveASMLoadInsNode("lw", reg, regAllocator.getReg("sp"), tmp->offset);
        currentBlock->insts.push_back(load);
        auto load2 = new NaiveASMLoadInsNode("lw", reg, reg, 0);
        currentBlock->insts.push_back(load2);
    }
}

void NaiveASMBuilder::getVar(NaiveASMVarNode* var, Register* reg) {
    if (dynamic_cast<NaiveASMGlobalVarNode*>(var)) {
        auto tmp = dynamic_cast<NaiveASMGlobalVarNode*>(var);
        if (!var->is_ptr) {
            auto load = new NaiveASMLoadInsNode("lw", reg, nullptr, 0);
            load->label = tmp->name;
            currentBlock->insts.push_back(load);
        }
        else {
            auto la = new NaiveASMLaInsNode(reg, tmp->name);
            currentBlock->insts.push_back(la);
        }
    }
    else {
        auto tmp = dynamic_cast<NaiveASMLocalVarNode*>(var);
        auto load = new NaiveASMLoadInsNode("lw", reg, regAllocator.getReg("sp"), tmp->offset);
        currentBlock->insts.push_back(load);
    }
}

void NaiveASMBuilder::getValue(IRValueNode* value, Register* reg) {
    if (dynamic_cast<IRVarNode*>(value)) {
        auto tmp = dynamic_cast<IRVarNode*>(value);
        auto ptr = getVarNode(tmp);
        getVar(ptr, reg);
    }
    else if (dynamic_cast<IRLiteralNode*>(value)) {
        auto tmp = dynamic_cast<IRLiteralNode*>(value);
        auto load = new NaiveASMImmInsNode("addi", reg, regAllocator.getReg("zero"), tmp->value);
        currentBlock->insts.push_back(load);
    }
}

void NaiveASMBuilder::storeVar(NaiveASMVarNode* var, Register* reg) {
    if (dynamic_cast<NaiveASMGlobalVarNode*>(var)) {
        auto tmp = dynamic_cast<NaiveASMGlobalVarNode*>(var);
        auto la = new NaiveASMLaInsNode(regAllocator.getReg("s1"), tmp->name);
        currentBlock->insts.push_back(la);
        auto store = new NaiveASMStoreInsNode("sw", regAllocator.getReg("s1"), reg, 0);
        currentBlock->insts.push_back(store);
    }
    else {
        auto tmp = dynamic_cast<NaiveASMLocalVarNode*>(var);
        auto store = new NaiveASMStoreInsNode("sw", regAllocator.getReg("sp"), reg, tmp->offset);
        currentBlock->insts.push_back(store);
    }
}

void NaiveASMBuilder::storePtr(NaiveASMVarNode* var, Register* reg) {
    if (!var->is_ptr) throw std::runtime_error("not a pointer");
    if (dynamic_cast<NaiveASMGlobalVarNode*>(var)) {
        auto tmp = dynamic_cast<NaiveASMGlobalVarNode*>(var);
        auto la = new NaiveASMLaInsNode(regAllocator.getReg("s1"), tmp->name);
        currentBlock->insts.push_back(la);
        auto load = new NaiveASMLoadInsNode("lw", regAllocator.getReg("s1"), regAllocator.getReg("s1"), 0);
        currentBlock->insts.push_back(load);
        auto store = new NaiveASMStoreInsNode("sw", regAllocator.getReg("s1"), reg, 0);
        currentBlock->insts.push_back(store);
    }
    else {
        auto tmp = dynamic_cast<NaiveASMLocalVarNode*>(var);
        auto load = new NaiveASMLoadInsNode("lw", regAllocator.getReg("s1"), regAllocator.getReg("sp"), tmp->offset);
        currentBlock->insts.push_back(load);
        auto store = new NaiveASMStoreInsNode("sw", regAllocator.getReg("s1"), reg, 0);
        currentBlock->insts.push_back(store);
    }
}

void NaiveASMBuilder::visitValue(IRValueNode* node) {}
void NaiveASMBuilder::visitVar(IRVarNode* node) {}
void NaiveASMBuilder::visitGlobalVar(IRGlobalVarNode* node) {}
void NaiveASMBuilder::visitLiteral(IRLiteralNode* node) {}
void NaiveASMBuilder::visitString(IRStringNode* node) {}

void NaiveASMBuilder::visitCallStmt(IRCallStmtNode* node) {
    NaiveASMLocalVarNode* var = nullptr;
    if(node->var) {
        var = registerLocalVar(node->var, node->var->type->to_string() == "ptr");
    }
    int cnt = 0;
    for (int i = 0, k = node->args.size(); i < k; ++i) {
        auto arg = node->args[i];
        if (i < 8) {
            getValue(arg, regAllocator.getReg("a" + std::to_string(i)));    
        }
        else {
            getValue(arg, regAllocator.getReg("s0"));
            cnt += arg->type->size();
            auto store = new NaiveASMStoreInsNode("sw", regAllocator.getReg("sp"), regAllocator.getReg("s0"), -cnt);
            currentBlock->insts.push_back(store);
        }
    }
    auto call = new NaiveASMCallInsNode(node->funcName);
    currentBlock->insts.push_back(call);
    if (var) storeVar(var, regAllocator.getReg("a0"));
}

void NaiveASMBuilder::visitPhiStmt(IRPhiStmtNode* node) {}

void NaiveASMBuilder::visitGetElementPtrStmt(IRGetElementPtrStmtNode* node) {
    auto var = registerLocalVar(node->var, true);
    auto ptr= varMap[node->ptr->name];
    getVar(ptr, regAllocator.getReg("s0"));
    getValue(node->index, regAllocator.getReg("s1"));
    auto tmp = new NaiveASMImmInsNode("addi", regAllocator.getReg("t1"), regAllocator.getReg("zero"), node->var->type->size());
    currentBlock->insts.push_back(tmp);
    auto ind = new NaiveASMBinaryInsNode("mul", regAllocator.getReg("s1"), regAllocator.getReg("s1"), regAllocator.getReg("t1"));
    currentBlock->insts.push_back(ind);
    auto add = new NaiveASMBinaryInsNode("add", regAllocator.getReg("s0"), regAllocator.getReg("s0"), regAllocator.getReg("s1"));
    currentBlock->insts.push_back(add);
    storeVar(var, regAllocator.getReg("s0"));
}

void NaiveASMBuilder::visitBinaryStmt(IRBinaryStmtNode* node) {
    getValue(node->lhs, regAllocator.getReg("s0"));
    getValue(node->rhs, regAllocator.getReg("s1"));
    auto var = registerLocalVar(node->var, false);
    std::string op = node->op;
    if (node->op == "sdiv") op = "div";
    else if (node->op == "srem") op = "rem";
    else if (node->op == "shl") op = "sll";
    else if (node->op == "ashr") op = "sra";
    auto binary = new NaiveASMBinaryInsNode(op, regAllocator.getReg("s0"), regAllocator.getReg("s0"), regAllocator.getReg("s1"));
    currentBlock->insts.push_back(binary);
    storeVar(var, regAllocator.getReg("s0"));
}

void NaiveASMBuilder::visitIcmpStmt(IRIcmpStmtNode* node) {
    getValue(node->lhs, regAllocator.getReg("s0"));
    getValue(node->rhs, regAllocator.getReg("s1"));
    auto var = registerLocalVar(node->var, false);
    if (node->op == "icmp eq") {
        auto tmp = new NaiveASMBinaryInsNode("xor", regAllocator.getReg("s0"), regAllocator.getReg("s0"), regAllocator.getReg("s1"));
        currentBlock->insts.push_back(tmp);
        auto set = new NaiveASMImmInsNode("sltiu", regAllocator.getReg("s0"), regAllocator.getReg("s0"), 1); // |s0| < 1
        currentBlock->insts.push_back(set);
    }
    else if (node->op == "icmp ne") {
        auto tmp = new NaiveASMBinaryInsNode("xor", regAllocator.getReg("s0"), regAllocator.getReg("s0"), regAllocator.getReg("s1"));
        currentBlock->insts.push_back(tmp);
        auto set = new NaiveASMBinaryInsNode("sltu", regAllocator.getReg("s0"), regAllocator.getReg("zero"), regAllocator.getReg("s0")); // |s0| > 0
        currentBlock->insts.push_back(set);
    }
    else if (node->op == "icmp sgt") {
        auto set = new NaiveASMBinaryInsNode("slt", regAllocator.getReg("s0"), regAllocator.getReg("s1"), regAllocator.getReg("s0")); // s1 < s0
        currentBlock->insts.push_back(set);
    }
    else if (node->op == "icmp sge") {
        auto set = new NaiveASMBinaryInsNode("slt", regAllocator.getReg("s0"), regAllocator.getReg("s0"), regAllocator.getReg("s1")); // s0 < s1
        currentBlock->insts.push_back(set);
        auto set2 = new NaiveASMImmInsNode("xori", regAllocator.getReg("s0"), regAllocator.getReg("s0"), 1); // |s0| < 1
        currentBlock->insts.push_back(set2);
    }
    else if (node->op == "icmp slt") {
        auto set = new NaiveASMBinaryInsNode("slt", regAllocator.getReg("s0"), regAllocator.getReg("s0"), regAllocator.getReg("s1")); // s0 < s1
        currentBlock->insts.push_back(set);
    }
    else if (node->op == "icmp sle") {
        auto set = new NaiveASMBinaryInsNode("slt", regAllocator.getReg("s0"), regAllocator.getReg("s1"), regAllocator.getReg("s0")); // s1 < s0
        currentBlock->insts.push_back(set);
        auto set2 = new NaiveASMImmInsNode("xori", regAllocator.getReg("s0"), regAllocator.getReg("s0"), 1); // |s0| < 1
        currentBlock->insts.push_back(set2);
    }
    else throw std::runtime_error("unknown icmp op");
    storeVar(var, regAllocator.getReg("s0"));
}

void NaiveASMBuilder::visitBrCondStmt(IRBrCondStmtNode* node) {
    getValue(node->cond, regAllocator.getReg("s0"));
    auto bne = new NaiveASMBranchInsNode("bne", regAllocator.getReg("s0"), regAllocator.getReg("zero"), ".L" + node->trueLabel);
    currentBlock->insts.push_back(bne);
    auto j = new NaiveASMJumpInsNode(".L" + node->falseLabel);
    currentBlock->insts.push_back(j);
}

void NaiveASMBuilder::visitRetStmt(IRRetStmtNode* node) {
    if(node->value) {
        getValue(node->value, regAllocator.getReg("a0"));
    }
    auto raVar = dynamic_cast<NaiveASMLocalVarNode*>(varMap["..ra" + currentFunction->name]);
    auto raLoad = new NaiveASMLoadInsNode("lw", regAllocator.getReg("ra"), regAllocator.getReg("sp"), raVar->offset);
    currentBlock->insts.push_back(raLoad);
    auto spAdd = new NaiveASMImmInsNode("addi", regAllocator.getReg("sp"), regAllocator.getReg("sp"), spSize);
    spRetIns = spAdd;
    currentBlock->insts.push_back(spAdd);
    currentBlock->insts.push_back(new NaiveASMRetInsNode);
}

void NaiveASMBuilder::visitBrStmt(IRBrStmtNode* node) {
    auto j = new NaiveASMJumpInsNode(".L" + node->label);
    currentBlock->insts.push_back(j);
}

void NaiveASMBuilder::visitTruncStmt(IRTruncStmtNode* node) {
    getValue(node->value, regAllocator.getReg("s0"));
    auto var = registerLocalVar(node->var, false);
    storeVar(var, regAllocator.getReg("s0"));
}

void NaiveASMBuilder::visitZextStmt(IRZextStmtNode* node) {
    getValue(node->value, regAllocator.getReg("s0"));
    auto var = registerLocalVar(node->var, false);
    storeVar(var, regAllocator.getReg("s0"));
}

void NaiveASMBuilder::visitLoadStmt(IRLoadStmtNode* node) {
    auto var = registerLocalVar(node->var, node->var->type->to_string() == "ptr");
    auto ptr = varMap[node->ptr->name];
    if (ptr->is_ptr) getPtr(ptr, regAllocator.getReg("s0"));
    else getVar(ptr, regAllocator.getReg("s0"));
    storeVar(var, regAllocator.getReg("s0"));
}

void NaiveASMBuilder::visitStoreStmt(IRStoreStmtNode* node) {
    getValue(node->value, regAllocator.getReg("s0"));
    auto ptr = varMap[node->ptr->name];
    if (ptr->is_ptr) storePtr(ptr, regAllocator.getReg("s0"));
    else storeVar(ptr, regAllocator.getReg("s0"));
    if (node->is_ptr) ptr->is_ptr = true;
}

void NaiveASMBuilder::visitAllocaStmt(IRAllocaStmtNode* node) {
    registerLocalVar(node->var, false);
}

void NaiveASMBuilder::setPhiVar(IRBlockNode* node, IRBlockNode* nextBlock) {
    for (auto stmt: nextBlock->stmts) {
        if (auto phi = dynamic_cast<IRPhiStmtNode*>(stmt)) {
            if (phi->values.count(node->label)) {
                auto value = phi->values[node->label];
                auto tmp = new IRVarNode(phi->var->type, phi->var->name + ".phi.tmp" + std::to_string(counter["phi.tmp"]++), phi->var->isConst);
                irVarSet.insert(tmp);
                auto tmpVar = registerLocalVar(tmp, false);
                auto phiVar = registerLocalVar(phi->var, false);
                phiVars.emplace_back(tmpVar, phiVar);
                getValue(value, regAllocator.getReg("s0"));
                storeVar(tmpVar, regAllocator.getReg("s0"));
            }
        }
        else break;
    }
}

void NaiveASMBuilder::visitBlock(IRBlockNode* node) {
    NaiveASMBlockNode* block = nullptr;
    if (node->label == "entry") {
        block = new NaiveASMBlockNode(currentFunction->name);
        currentBlock = block;
        auto spAdd = new NaiveASMImmInsNode("addi", regAllocator.getReg("sp"), regAllocator.getReg("sp"), -spSize);
        block->insts.push_back(spAdd);
        spAddIns = spAdd;
        int cnt = 0;
        for (int i = 8, k = currentFunction->args.size(); i < k; ++i) {
            auto arg = currentFunction->args[i];
            auto var = new NaiveASMLocalVarNode(arg.second, spSize, false);
            varSet.insert(var);
            spSize += arg.first->size();
            varMap[arg.second] = var;
            cnt += arg.first->size();
            auto load = new NaiveASMLoadInsNode("lw", regAllocator.getReg("s0"), regAllocator.getReg("sp"), -cnt);
            currentBlock->insts.push_back(load);
            storeVar(var, regAllocator.getReg("s0"));
        }
        for (int i = 0, k = currentFunction->args.size(); i < std::min(8, k); ++i) {
            auto arg = currentFunction->args[i];
            auto var = new NaiveASMLocalVarNode(arg.second, spSize, false);
            varSet.insert(var);
            varMap[arg.second] = var;
            spSize += arg.first->size();
            storeVar(var, regAllocator.getReg("a" + std::to_string(i)));
        }
        auto raVar = new NaiveASMLocalVarNode("..ra" + currentFunction->name, spSize, false);
        varSet.insert(raVar);
        spSize += 4;
        varMap["..ra" + currentFunction->name] = raVar;
        auto raStore = new NaiveASMStoreInsNode("sw", regAllocator.getReg("sp"), regAllocator.getReg("ra"), raVar->offset);
        block->insts.push_back(raStore);
    }
    else {
        block = new NaiveASMBlockNode(".L" + node->label);
    }
    program->text->functions.back()->blocks.push_back(block);
    currentBlock = block;
    for (auto stmt: node->stmts) {
        stmt->accept(this);
    }

    auto finalinst = currentBlock->insts.back();
    currentBlock->insts.pop_back();
    
    phiVars.clear();
    if (auto stmt = dynamic_cast<IRBrCondStmtNode*>(node->stmts.back())) {
        setPhiVar(node, blockMap[stmt->trueLabel]);
        setPhiVar(node, blockMap[stmt->falseLabel]);
    }
    else if (auto stmt = dynamic_cast<IRBrStmtNode*>(node->stmts.back())) {
        setPhiVar(node, blockMap[stmt->label]);
    }
    for (auto p: phiVars) {
        auto load = new NaiveASMLoadInsNode("lw", regAllocator.getReg("s0"), regAllocator.getReg("sp"), p.first->offset);
        currentBlock->insts.push_back(load);
        auto store = new NaiveASMStoreInsNode("sw", regAllocator.getReg("sp"), regAllocator.getReg("s0"), p.second->offset);
        currentBlock->insts.push_back(store);
    }
    currentBlock->insts.push_back(finalinst);
}

void NaiveASMBuilder::visitFunction(IRFunctionNode* node) {
    if (!node->blocks.size()) return;
    auto function = new NaiveASMFunctionNode;
    program->text->functions.push_back(function);
    currentFunction = node;
    spSize = 0;
    blockMap.clear();
    for (auto block: node->blocks) {
        blockMap[block->label] = block;
    }
    for (auto block: node->blocks) {
        block->accept(this);
    }
    spSize = (spSize + 15) / 16 * 16;
    spAddIns->imm = -spSize;
    spRetIns->imm = spSize;
    currentFunction = nullptr;
}

void NaiveASMBuilder::visitGlobalVarStmt(IRGlobalVarStmtNode* node) {
    bool is_string = (dynamic_cast<IRStringNode*>(node->value) != nullptr);
    std::string str = "";
    if (is_string) str = dynamic_cast<IRStringNode*>(node->value)->str;
    else {
        str = node->value->to_string();
        if (str[0] == '@') str = str.substr(1);
        if (str == "null") str = "0";
    }
    auto globalVar = new NaiveASMGlobalVarStmtNode(node->var->name, str, is_string);
    program->data->globalVarStmts.push_back(globalVar);
    auto var = new NaiveASMGlobalVarNode(node->var->name, is_string);
    varSet.insert(var);
    varMap[node->var->name] = var;
}

void NaiveASMBuilder::visitProgram(IRProgramNode* node) {
    program = new NaiveASMProgramNode;
    if (node->globalVars.size()) program->data = new NaiveASMDataSectionNode;
    if (node->functions.size()) program->text = new NaiveASMTextSectionNode;
    for (auto globalVar : node->globalVars) {
        globalVar->accept(this);
    }
    for (auto function : node->functions) {
        function->accept(this);
    }
}