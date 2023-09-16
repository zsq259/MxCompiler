#include "ASMBuilder.h"
#include "ASMNode.h"
#include "IRNode.h"
#include "RegisterAllocator.h"
using std::to_string;

ASMLocalVarNode* ASMBuilder::registerLocalVar(IRVarNode* var, bool p_ = false) {
    if (varMap.count(var->name)) {
        auto ret = dynamic_cast<ASMLocalVarNode*>(varMap[var->name]);
        ret->is_ptr = p_;
        return ret;
    }
    auto ret = new ASMLocalVarNode(var->name, p_);
    varSet.insert(ret);
    varMap[var->name] = ret;
    return ret;
}

ASMVarNode* ASMBuilder::getVarNode(IRVarNode* var) {
    if (varMap.count(var->name)) return varMap[var->name];
    else return registerLocalVar(var, false);
}

void ASMBuilder::getPtr(ASMVarNode* var, ASMVarNode* reg) {
    if (!var->is_ptr) throw std::runtime_error("not a pointer");
    if (dynamic_cast<ASMGlobalVarNode*>(var)) {
        auto tmp = dynamic_cast<ASMGlobalVarNode*>(var);
        auto load = new ASMLoadInsNode("lw", reg, tmp, 0);
        currentBlock->insts.push_back(load);
        auto load2 = new ASMLoadInsNode("lw", reg, reg, 0);
        currentBlock->insts.push_back(load2);
    }
    else {
        auto tmp = dynamic_cast<ASMLocalVarNode*>(var);
        auto mv = new ASMMoveInsNode(reg, tmp);
        currentBlock->insts.push_back(mv);
        auto load2 = new ASMLoadInsNode("lw", reg, reg, 0);
        currentBlock->insts.push_back(load2);
    }
}

void ASMBuilder::getVar(ASMVarNode* var, ASMVarNode* reg) {
    if (dynamic_cast<ASMGlobalVarNode*>(var)) {
        auto tmp = dynamic_cast<ASMGlobalVarNode*>(var);
        if (!var->is_ptr) {
            auto load = new ASMLoadInsNode("lw", reg, tmp, 0);
            currentBlock->insts.push_back(load);
        }
        else {
            auto la = new ASMLaInsNode(reg, tmp->name);
            currentBlock->insts.push_back(la);
        }
    }
    else {
        auto tmp = dynamic_cast<ASMLocalVarNode*>(var);
        auto mv = new ASMMoveInsNode(reg, tmp);
        currentBlock->insts.push_back(mv);
    }
}

void ASMBuilder::getValue(IRValueNode* value, ASMVarNode* reg) {
    if (dynamic_cast<IRVarNode*>(value)) {
        auto tmp = dynamic_cast<IRVarNode*>(value);
        auto ptr = getVarNode(tmp);
        getVar(ptr, reg);
    }
    else if (dynamic_cast<IRLiteralNode*>(value)) {
        auto tmp = dynamic_cast<IRLiteralNode*>(value);
        auto load = new ASMImmInsNode("addi", reg, regAllocator.zeroReg, tmp->value);
        currentBlock->insts.push_back(load);
    }
}

void ASMBuilder::storeVar(ASMVarNode* var, ASMVarNode* reg) {
    if (dynamic_cast<ASMGlobalVarNode*>(var)) {
        auto tmp = new ASMLocalVarNode(".tmp." + to_string(counter[".tmp."]++), false);
        auto la = new ASMLaInsNode(tmp, var->name);
        currentBlock->insts.push_back(la);
        auto store = new ASMStoreInsNode("sw", tmp, reg, 0);
        currentBlock->insts.push_back(store);
    }
    else {
        auto mv = new ASMMoveInsNode(var, reg);
        currentBlock->insts.push_back(mv);
    }
}

void ASMBuilder::storePtr(ASMVarNode* var, ASMVarNode* reg) {
    if (!var->is_ptr) throw std::runtime_error("not a pointer");
    if (dynamic_cast<ASMGlobalVarNode*>(var)) {
        auto tmp = new ASMLocalVarNode(".tmp." + to_string(counter[".tmp."]++), false);
        auto la = new ASMLaInsNode(tmp, var->name);
        currentBlock->insts.push_back(la);
        auto load = new ASMLoadInsNode("lw", tmp, tmp, 0);
        currentBlock->insts.push_back(load);
        auto store = new ASMStoreInsNode("sw", tmp, reg, 0);
        currentBlock->insts.push_back(store);
    }
    else {
        auto store = new ASMStoreInsNode("sw", var, reg, 0);
        currentBlock->insts.push_back(store);
    }
}

void ASMBuilder::visitValue(IRValueNode* node) {}
void ASMBuilder::visitVar(IRVarNode* node) {}
void ASMBuilder::visitGlobalVar(IRGlobalVarNode* node) {}
void ASMBuilder::visitLiteral(IRLiteralNode* node) {}
void ASMBuilder::visitString(IRStringNode* node) {}

void ASMBuilder::visitCallStmt(IRCallStmtNode* node) {
    ASMLocalVarNode* var = nullptr;
    if(node->var) {
        var = registerLocalVar(node->var, node->var->type->to_string() == "ptr");
    }
    int cnt = 0;
    for (int i = 0, k = node->args.size(); i < k; ++i) {
        auto arg = node->args[i];
        if (i < 8) {
            getValue(arg, regAllocator.aReg[i]);    
        }
        else {
            auto tmp = new ASMLocalVarNode(".tmp." + to_string(counter[".tmp."]++), false);
            getValue(arg, tmp);
            cnt += arg->type->size();
            auto store = new ASMStoreInsNode("sw", regAllocator.spReg, tmp, -cnt);
            currentBlock->insts.push_back(store);
        }
    }
    auto call = new ASMCallInsNode(node->funcName);
    currentBlock->insts.push_back(call);
    if (var) storeVar(var, regAllocator.aReg[0]);
}

void ASMBuilder::visitPhiStmt(IRPhiStmtNode* node) {}

void ASMBuilder::visitGetElementPtrStmt(IRGetElementPtrStmtNode* node) {
    auto var = registerLocalVar(node->var, true);
    auto ptr= varMap[node->ptr->name];
    auto tmp0 = new ASMLocalVarNode(".tmp." + to_string(counter[".tmp."]++), false);
    auto tmp1 = new ASMLocalVarNode(".tmp." + to_string(counter[".tmp."]++), false);
    auto tmp2 = new ASMLocalVarNode(".tmp." + to_string(counter[".tmp."]++), false);
    getVar(ptr, tmp0);
    getValue(node->index, tmp1);
    auto tmp = new ASMImmInsNode("addi", tmp2, regAllocator.zeroReg, node->var->type->size());
    currentBlock->insts.push_back(tmp);
    auto ind = new ASMBinaryInsNode("mul", tmp1, tmp1, tmp2);
    currentBlock->insts.push_back(ind);
    auto add = new ASMBinaryInsNode("add", tmp0, tmp0, tmp1);
    currentBlock->insts.push_back(add); 
    storeVar(var, tmp0);
}

void ASMBuilder::visitBinaryStmt(IRBinaryStmtNode* node) {
    auto tmp0 = new ASMLocalVarNode(".tmp." + to_string(counter[".tmp."]++), false);
    auto tmp1 = new ASMLocalVarNode(".tmp." + to_string(counter[".tmp."]++), false);
    getValue(node->lhs, tmp0);
    getValue(node->rhs, tmp1);
    auto var = registerLocalVar(node->var, false);
    std::string op = node->op;
    if (node->op == "sdiv") op = "div";
    else if (node->op == "srem") op = "rem";
    else if (node->op == "shl") op = "sll";
    else if (node->op == "ashr") op = "sra";
    auto binary = new ASMBinaryInsNode(op, tmp0, tmp0, tmp1);
    currentBlock->insts.push_back(binary);
    storeVar(var, tmp0);
}

void ASMBuilder::visitIcmpStmt(IRIcmpStmtNode* node) {
    auto tmp0 = new ASMLocalVarNode(".tmp." + to_string(counter[".tmp."]++), false);
    auto tmp1 = new ASMLocalVarNode(".tmp." + to_string(counter[".tmp."]++), false);
    getValue(node->lhs, tmp0);
    getValue(node->rhs, tmp1);
    auto var = registerLocalVar(node->var, false);
    if (node->op == "icmp eq") {
        auto tmp = new ASMBinaryInsNode("xor", tmp0, tmp0, tmp1);
        currentBlock->insts.push_back(tmp);
        auto set = new ASMImmInsNode("sltiu", tmp0, tmp0, 1); // |s0| < 1
        currentBlock->insts.push_back(set);
    }
    else if (node->op == "icmp ne") {
        auto tmp = new ASMBinaryInsNode("xor", tmp0, tmp0, tmp1);
        currentBlock->insts.push_back(tmp);
        auto set = new ASMBinaryInsNode("sltu", tmp0, regAllocator.zeroReg, tmp0); // |s0| > 0
        currentBlock->insts.push_back(set);
    }
    else if (node->op == "icmp sgt") {
        auto set = new ASMBinaryInsNode("slt", tmp0, tmp1, tmp0); // s1 < s0
        currentBlock->insts.push_back(set);
    }
    else if (node->op == "icmp sge") {
        auto set = new ASMBinaryInsNode("slt", tmp0, tmp0, tmp1); // s0 < s1
        currentBlock->insts.push_back(set);
        auto set2 = new ASMImmInsNode("xori", tmp0, tmp0, 1); // |s0| < 1
        currentBlock->insts.push_back(set2);
    }
    else if (node->op == "icmp slt") {
        auto set = new ASMBinaryInsNode("slt", tmp0, tmp0, tmp1); // s0 < s1
        currentBlock->insts.push_back(set);
    }
    else if (node->op == "icmp sle") {
        auto set = new ASMBinaryInsNode("slt", tmp0, tmp1, tmp0); // s1 < s0
        currentBlock->insts.push_back(set);
        auto set2 = new ASMImmInsNode("xori", tmp0, tmp0, 1); // |s0| < 1
        currentBlock->insts.push_back(set2);
    }
    else throw std::runtime_error("unknown icmp op");
    storeVar(var, tmp0);
}

void ASMBuilder::visitBrCondStmt(IRBrCondStmtNode* node) {
    auto tmp0 = new ASMLocalVarNode(".tmp." + to_string(counter[".tmp."]++), false);
    getValue(node->cond, tmp0);
    auto bne = new ASMBranchInsNode("bne", tmp0, regAllocator.zeroReg, ".L" + node->trueLabel);
    currentBlock->insts.push_back(bne);
    auto j = new ASMJumpInsNode(".L" + node->falseLabel);
    currentBlock->insts.push_back(j);
}

void ASMBuilder::visitRetStmt(IRRetStmtNode* node) {
    if(node->value) {
        getValue(node->value, regAllocator.aReg[0]);
    }

    // auto raMove = new ASMMoveInsNode(regAllocator.raReg, raVar);
    // currentBlock->insts.push_back(raMove);    
    
    auto spAdd = new ASMImmInsNode("addi", regAllocator.spReg, regAllocator.spReg, 0);
    currentASMFunction->spRetIns = spAdd;
    currentBlock->insts.push_back(spAdd);
    currentBlock->insts.push_back(new ASMRetInsNode);
}

void ASMBuilder::visitBrStmt(IRBrStmtNode* node) {
    auto j = new ASMJumpInsNode(".L" + node->label);
    currentBlock->insts.push_back(j);
}

void ASMBuilder::visitTruncStmt(IRTruncStmtNode* node) {
    auto var = registerLocalVar(node->var, false);
    getValue(node->value, var);
}

void ASMBuilder::visitZextStmt(IRZextStmtNode* node) {
    auto var = registerLocalVar(node->var, false);
    getValue(node->value, var);
}

void ASMBuilder::visitLoadStmt(IRLoadStmtNode* node) {
    auto var = registerLocalVar(node->var, node->var->type->to_string() == "ptr");
    auto ptr = varMap[node->ptr->name];
    if (ptr->is_ptr) getPtr(ptr, var);
    else getVar(ptr, var);
}

void ASMBuilder::visitStoreStmt(IRStoreStmtNode* node) {
    auto tmp = new ASMLocalVarNode(".tmp." + to_string(counter[".tmp."]++), false);
    getValue(node->value, tmp);
    auto ptr = varMap[node->ptr->name];
    if (ptr->is_ptr) storePtr(ptr, tmp);
    else storeVar(ptr, tmp);
    if (node->is_ptr) ptr->is_ptr = true;
}

void ASMBuilder::visitAllocaStmt(IRAllocaStmtNode* node) {
    registerLocalVar(node->var, false);
}

void ASMBuilder::setPhiVar(IRBlockNode* node, IRBlockNode* nextBlock) {
    for (auto stmt: nextBlock->stmts) {
        if (auto phi = dynamic_cast<IRPhiStmtNode*>(stmt)) {
            if (phi->values.count(node->label)) {
                auto value = phi->values[node->label];
                auto tmp = new IRVarNode(phi->var->type, phi->var->name + ".phi.tmp" + std::to_string(counter["phi.tmp"]++), phi->var->isConst);
                irVarSet.insert(tmp);
                auto tmpVar = registerLocalVar(tmp, false);
                auto phiVar = registerLocalVar(phi->var, false);
                phiVars.emplace_back(tmpVar, phiVar);
                getValue(value, tmpVar);
            }
        }
        else break;
    }
}

void ASMBuilder::visitBlock(IRBlockNode* node) {
    ASMBlockNode* block = nullptr;
    if (node->label == "entry") {
        block = new ASMBlockNode(currentFunction->name);
        currentBlock = block;
        auto spAdd = new ASMImmInsNode("addi", regAllocator.spReg, regAllocator.spReg, 0);
        block->insts.push_back(spAdd);
        currentASMFunction->spAddIns = spAdd;

        // raVar = new ASMLocalVarNode("..ra" + currentFunction->name, false);
        // varSet.insert(raVar);
        // varMap["..ra" + currentFunction->name] = raVar;

        // auto raMove = new ASMMoveInsNode(raVar, regAllocator.raReg);
        // block->insts.push_back(raMove);        
        
        int cnt = 0;
        for (int i = 8, k = currentFunction->args.size(); i < k; ++i) {
            auto arg = currentFunction->args[i];
            auto var = new ASMLocalVarNode(arg.second, false);
            varSet.insert(var);
            varMap[arg.second] = var;
            cnt += arg.first->size();
            auto load = new ASMLoadInsNode("lw", var, regAllocator.spReg, -cnt);
            currentBlock->insts.push_back(load);
        }
        for (int i = 0, k = currentFunction->args.size(); i < std::min(8, k); ++i) {
            auto arg = currentFunction->args[i];
            auto var = new ASMLocalVarNode(arg.second, false);
            varSet.insert(var);
            varMap[arg.second] = var;
            storeVar(var, regAllocator.aReg[i]);
        }
    }
    else {
        block = new ASMBlockNode(".L" + node->label);
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
    // for (auto p: phiVars) {
    for (int i = phiVars.size() - 1; i >= 0; --i) {
        auto p = phiVars[i];
        auto mv = new ASMMoveInsNode(p.second, p.first);
        currentBlock->insts.push_back(mv);
    }    
    currentBlock->insts.push_back(finalinst);
}

void ASMBuilder::visitFunction(IRFunctionNode* node) {
    if (!node->blocks.size()) return;
    auto function = new ASMFunctionNode;
    program->text->functions.push_back(function);
    currentFunction = node;
    currentASMFunction = function;
    blockMap.clear();
    for (auto block: node->blocks) blockMap[block->label] = block;
    for (auto block: node->blocks) block->accept(this); 

    regAllocator.work(function);
    currentFunction = nullptr;
    currentASMFunction = nullptr;
}

void ASMBuilder::visitGlobalVarStmt(IRGlobalVarStmtNode* node) {
    bool is_string = (dynamic_cast<IRStringNode*>(node->value) != nullptr);
    std::string str = "";
    if (is_string) str = dynamic_cast<IRStringNode*>(node->value)->str;
    else {
        str = node->value->to_string();
        if (str[0] == '@') str = str.substr(1);
        if (str == "null") str = "0";
    }
    auto globalVar = new ASMGlobalVarStmtNode(node->var->name, str, is_string);
    program->data->globalVarStmts.push_back(globalVar);
    auto var = new ASMGlobalVarNode(node->var->name, is_string, regAllocator.getReg("zero"));
    varSet.insert(var);
    varMap[node->var->name] = var;
}

void ASMBuilder::visitProgram(IRProgramNode* node) {
    program = new ASMProgramNode;
    if (node->globalVars.size()) program->data = new ASMDataSectionNode;
    if (node->functions.size()) program->text = new ASMTextSectionNode;
    for (auto globalVar : node->globalVars) globalVar->accept(this);
    for (auto function : node->functions) function->accept(this);
}