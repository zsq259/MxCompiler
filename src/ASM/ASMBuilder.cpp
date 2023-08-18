#include "ASMBuilder.h"
#include "ASMNode.h"
#include "IRNode.h"

void ASMBuilder::setVar(ASMVarNode* var, Register* reg) {
    if (dynamic_cast<ASMGlobalVarNode*>(var)) {
        auto tmp = dynamic_cast<ASMGlobalVarNode*>(var);
        auto la = new ASMLaInsNode(regAllocator.getReg("s0"), tmp->name);
        currentBlock->insts.push_back(la);
        auto load2 = new ASMLoadInsNode("lw", reg, regAllocator.getReg("s0"), 0);
        currentBlock->insts.push_back(load2);
    }
    else {
        auto tmp = dynamic_cast<ASMLocalVarNode*>(var);
        auto load = new ASMLoadInsNode("lw", reg, regAllocator.getReg("sp"), tmp->offset);
        currentBlock->insts.push_back(load);
    }
}

void ASMBuilder::setValue(IRValueNode* value, Register* reg) {
    if (dynamic_cast<IRVarNode*>(value)) {
        auto tmp = dynamic_cast<IRVarNode*>(value);
        auto ptr = varMap[tmp->name];
        setVar(ptr, reg);
    }
    else if (dynamic_cast<IRLiteralNode*>(value)) {
        auto tmp = dynamic_cast<IRLiteralNode*>(value);
        auto load = new ASMImmInsNode("addi", reg, regAllocator.getReg("zero"), tmp->value);
        currentBlock->insts.push_back(load);
    }
}

void ASMBuilder::storeVar(ASMVarNode* var, Register* reg) {
    auto it = currentBlock->insts.end();
    if (dynamic_cast<ASMGlobalVarNode*>(var)) {
        auto tmp = dynamic_cast<ASMGlobalVarNode*>(var);
        auto la = new ASMLaInsNode(regAllocator.getReg("s0"), tmp->name);
        currentBlock->insts.push_back(la);
        auto store = new ASMStoreInsNode("sw", regAllocator.getReg("s0"), reg, 0);
        currentBlock->insts.push_back(store);
    }
    else {
        auto tmp = dynamic_cast<ASMLocalVarNode*>(var);
        auto store = new ASMStoreInsNode("sw", regAllocator.getReg("sp"), reg, tmp->offset);
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
        var = new ASMLocalVarNode(node->var->name, spSize);
        spSize += node->var->type->size();
        varMap[node->var->name] = var;
    }
    int cnt = 0;
    for (int i = 0, k = node->args.size(); i < k; ++i) {
        auto arg = node->args[i];
        if (i < 8) setValue(arg, regAllocator.getReg("a" + std::to_string(i)));
        else {
            setValue(arg, regAllocator.getReg("s0"));
            cnt += arg->type->size();
            auto store = new ASMStoreInsNode("sw", regAllocator.getReg("sp"), regAllocator.getReg("s0"), -cnt);
            currentBlock->insts.push_back(store);
        }
    }
    auto call = new ASMCallInsNode(node->funcName);
    currentBlock->insts.push_back(call);
    if (var) storeVar(var, regAllocator.getReg("a0"));
}

void ASMBuilder::visitPhiStmt(IRPhiStmtNode* node) {
    auto var = new ASMLocalVarNode(node->var->name, spSize);
    spSize += node->var->type->size();
    varMap[node->var->name] = var;
    auto endBlock = new ASMBlockNode("endPhi" + counter["endPhi"]++);
    for (auto p: node->values) {
        auto value = p.first;
        auto label = p.second;
        if (label == "entry") label = currentFunction->name;
        else label = ".L" + label;
        auto block = new ASMBlockNode("loadPhiValue" + counter["loadPhiValue"]++);
        auto la = new ASMLaInsNode(regAllocator.getReg("t5"), label);
        currentBlock->insts.push_back(la);
        auto neq = new ASMBranchInsNode("bne", regAllocator.getReg("t5"), regAllocator.getReg("t6"), block->name);
        currentBlock->insts.push_back(neq);
        auto formerBlock = currentBlock;
        currentBlock = block;
        setValue(value, regAllocator.getReg("s0"));
        auto j = new ASMJumpInsNode(endBlock->name);
        currentBlock->insts.push_back(j);
        program->text->functions.back()->blocks.push_back(block);
        currentBlock = formerBlock;
    }
    currentBlock = endBlock;
    storeVar(var, regAllocator.getReg("s0"));
}

void ASMBuilder::visitGetElementPtrStmt(IRGetElementPtrStmtNode* node) {
    auto var = new ASMLocalVarNode(node->var->name, spSize);
    spSize += node->var->type->size();
    varMap[node->var->name] = var;
    setVar(varMap[node->ptr->name], regAllocator.getReg("s0"));
    setValue(node->index, regAllocator.getReg("s1"));
    auto tmp = new ASMImmInsNode("addi", regAllocator.getReg("t1"), regAllocator.getReg("zero"), -node->var->type->size());
    currentBlock->insts.push_back(tmp);
    auto ind = new ASMBinaryInsNode("mul", regAllocator.getReg("s1"), regAllocator.getReg("s1"), regAllocator.getReg("t1"));
    currentBlock->insts.push_back(ind);
    auto add = new ASMBinaryInsNode("add", regAllocator.getReg("s0"), regAllocator.getReg("s0"), regAllocator.getReg("s1"));
    currentBlock->insts.push_back(add);
    storeVar(var, regAllocator.getReg("s0"));
}

void ASMBuilder::visitBinaryStmt(IRBinaryStmtNode* node) {
    setValue(node->lhs, regAllocator.getReg("s0"));
    setValue(node->rhs, regAllocator.getReg("s1"));
    auto var = new ASMLocalVarNode(node->var->name, spSize);
    spSize += node->lhs->type->size();
    varMap[node->var->name] = var;
    std::string op = node->op;
    if (node->op == "sdiv") op = "div";
    else if (node->op == "srem") op = "rem";
    else if (node->op == "shl") op = "sll";
    else if (node->op == "ashr") op = "sra";
    auto binary = new ASMBinaryInsNode(op, regAllocator.getReg("s0"), regAllocator.getReg("s0"), regAllocator.getReg("s1"));
    currentBlock->insts.push_back(binary);
    storeVar(var, regAllocator.getReg("s0"));
}

void ASMBuilder::visitIcmpStmt(IRIcmpStmtNode* node) {
    setValue(node->lhs, regAllocator.getReg("s0"));
    setValue(node->rhs, regAllocator.getReg("s1"));
    auto var = new ASMLocalVarNode(node->var->name, spSize);
    spSize += node->lhs->type->size();
    varMap[node->var->name] = var;
    if (node->op == "icmp eq") {
        auto tmp = new ASMBinaryInsNode("xor", regAllocator.getReg("s0"), regAllocator.getReg("s0"), regAllocator.getReg("s1"));
        currentBlock->insts.push_back(tmp);
        auto set = new ASMImmInsNode("sltiu", regAllocator.getReg("s0"), regAllocator.getReg("s0"), 1); // |s0| < 1
        currentBlock->insts.push_back(set);
    }
    else if (node->op == "icmp ne") {
        auto tmp = new ASMBinaryInsNode("xor", regAllocator.getReg("s0"), regAllocator.getReg("s0"), regAllocator.getReg("s1"));
        currentBlock->insts.push_back(tmp);
        auto set = new ASMBinaryInsNode("sltu", regAllocator.getReg("s0"), regAllocator.getReg("zero"), regAllocator.getReg("s0")); // |s0| > 0
        currentBlock->insts.push_back(set);
    }
    else if (node->op == "icmp sgt") {
        auto set = new ASMBinaryInsNode("slt", regAllocator.getReg("s0"), regAllocator.getReg("s1"), regAllocator.getReg("s0")); // s1 < s0
        currentBlock->insts.push_back(set);
    }
    else if (node->op == "icmp sge") {
        auto set = new ASMBinaryInsNode("slt", regAllocator.getReg("s0"), regAllocator.getReg("s0"), regAllocator.getReg("s1")); // s0 < s1
        currentBlock->insts.push_back(set);
        auto set2 = new ASMImmInsNode("xori", regAllocator.getReg("s0"), regAllocator.getReg("s0"), 1); // |s0| < 1
        currentBlock->insts.push_back(set2);
    }
    else if (node->op == "icmp slt") {
        auto set = new ASMBinaryInsNode("slt", regAllocator.getReg("s0"), regAllocator.getReg("s0"), regAllocator.getReg("s1")); // s0 < s1
        currentBlock->insts.push_back(set);
    }
    else if (node->op == "icmp sle") {
        auto set = new ASMBinaryInsNode("slt", regAllocator.getReg("s0"), regAllocator.getReg("s1"), regAllocator.getReg("s0")); // s1 < s0
        currentBlock->insts.push_back(set);
        auto set2 = new ASMImmInsNode("xori", regAllocator.getReg("s0"), regAllocator.getReg("s0"), 1); // |s0| < 1
        currentBlock->insts.push_back(set2);
    }
    else throw std::runtime_error("unknown icmp op");
    storeVar(var, regAllocator.getReg("s0"));
}

void ASMBuilder::visitBrCondStmt(IRBrCondStmtNode* node) {
    auto la = new ASMLaInsNode(regAllocator.getReg("t6"), currentBlock->name);
    currentBlock->insts.push_back(la);
    setValue(node->cond, regAllocator.getReg("s0"));
    auto bne = new ASMBranchInsNode("bne", regAllocator.getReg("s0"), regAllocator.getReg("zero"), ".L" + node->trueLabel);
    currentBlock->insts.push_back(bne);
    auto j = new ASMJumpInsNode(".L" + node->falseLabel);
    currentBlock->insts.push_back(j);
}

void ASMBuilder::visitRetStmt(IRRetStmtNode* node) {
    if(node->var) {
        setVar(varMap[node->var->name], regAllocator.getReg("a0"));
    }
    auto spAdd = new ASMImmInsNode("addi", regAllocator.getReg("sp"), regAllocator.getReg("sp"), spSize);
    currentBlock->insts.push_back(spAdd);
    currentBlock->insts.push_back(new ASMRetInsNode);
}

void ASMBuilder::visitBrStmt(IRBrStmtNode* node) {
    auto la = new ASMLaInsNode(regAllocator.getReg("t6"), currentBlock->name);
    currentBlock->insts.push_back(la);
    auto j = new ASMJumpInsNode(".L" + node->label);
    currentBlock->insts.push_back(j);
}

void ASMBuilder::visitTruncStmt(IRTruncStmtNode* node) {
    setValue(node->value, regAllocator.getReg("s0"));
    auto var = new ASMLocalVarNode(node->var->name, spSize);
    spSize += node->value->type->size();
    varMap[node->var->name] = var;
    storeVar(var, regAllocator.getReg("s0"));
}

void ASMBuilder::visitZextStmt(IRZextStmtNode* node) {
    setValue(node->value, regAllocator.getReg("s0"));
    auto var = new ASMLocalVarNode(node->var->name, spSize);
    spSize += node->var->type->size();
    varMap[node->var->name] = var;
    storeVar(var, regAllocator.getReg("s0"));
}

void ASMBuilder::visitLoadStmt(IRLoadStmtNode* node) {
    auto var = new ASMLocalVarNode(node->var->name, spSize);
    varMap[node->var->name] = var;
    spSize += node->var->type->size();
    auto ptr = varMap[node->ptr->name];
    setVar(ptr, regAllocator.getReg("s0"));
    auto load = new ASMLoadInsNode("lw", regAllocator.getReg("s0"), regAllocator.getReg("sp"), spSize);
    currentBlock->insts.push_back(load);
}

void ASMBuilder::visitStoreStmt(IRStoreStmtNode* node) {
    setValue(node->value, regAllocator.getReg("s0"));
    auto ptr = varMap[node->ptr->name];
    storeVar(ptr, regAllocator.getReg("s0"));
}

void ASMBuilder::visitAllocaStmt(IRAllocaStmtNode* node) {
    auto var = new ASMLocalVarNode(node->var->name, spSize);
    varMap[node->var->name] = var;
    spSize += node->type->size();
}

void ASMBuilder::visitBlock(IRBlockNode* node) {
    ASMBlockNode* block = nullptr;
    std::cerr << "asdoad " << node->label << std::endl;
    if (node->label == "entry") {
        block = new ASMBlockNode(currentFunction->name);
        currentBlock = block;
        int cnt = 0;
        for (int i = 8, k = currentFunction->args.size(); i < k; ++i) {
            auto arg = currentFunction->args[i];
            auto var = new ASMLocalVarNode(arg.second, spSize);
            spSize += arg.first->size();
            varMap[arg.second] = var;
            cnt += arg.first->size();
            auto load = new ASMLoadInsNode("lw", regAllocator.getReg("s0"), regAllocator.getReg("sp"), -cnt);
            currentBlock->insts.push_back(load);
            storeVar(var, regAllocator.getReg("s0"));
        }
        for (int i = 0, k = currentFunction->args.size(); i < std::min(8, k); ++i) {
            auto arg = currentFunction->args[i];
            auto var = new ASMLocalVarNode(arg.second, spSize);
            varMap[arg.second] = var;
            spSize += arg.first->size();
            storeVar(var, regAllocator.getReg("a" + std::to_string(i)));
        }

        auto spAdd = new ASMImmInsNode("addi", regAllocator.getReg("sp"), regAllocator.getReg("sp"), -spSize);
        block->insts.push_back(spAdd);
        spAddIns = spAdd;
    }
    else {
        block = new ASMBlockNode(".L" + node->label);
    }
    program->text->functions.back()->blocks.push_back(block);
    currentBlock = block;
    for (auto& stmt : node->stmts) {
        stmt->accept(this);
    }
}

void ASMBuilder::visitFunction(IRFunctionNode* node) {
    if (!node->blocks.size()) return;
    auto function = new ASMFunctionNode;
    program->text->functions.push_back(function);
    currentFunction = node;
    spSize = 0;
    for (auto& block : node->blocks) {
        block->accept(this);
    }
    spSize = (spSize + 15) / 16 * 16;
    spAddIns->imm = -spSize;
    currentFunction = nullptr;
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
    varMap[node->var->name] = new ASMGlobalVarNode(node->var->name);
}

void ASMBuilder::visitProgram(IRProgramNode* node) {
    program = new ASMProgramNode;
    if (node->globalVars.size()) program->data = new ASMDataSectionNode;
    if (node->functions.size()) program->text = new ASMTextSectionNode;
    for (auto globalVar : node->globalVars) {
        globalVar->accept(this);
    }
    for (auto function : node->functions) {
        function->accept(this);
    }
}