#include "IRBuilder.h"
#include "IRType.h"
#include "IRNode.h"
#include "ASTNode.h"

static IRVoidType voidType;
static IRIntType boolType(32);
static IRIntType intType(32);
static IRIntType i8Type(8);
static IRIntType i1Type(1);
static IRPtrType ptrType;
static IRStringType stringType;
static IRLiteralNode nullNode(&ptrType, 0);
static IRLiteralNode intZeroNode(&intType, 0);
static IRLiteralNode intOneNode(&intType, 1);
static IRLiteralNode intMinusOneNode(&intType, -1);
static IRLiteralNode boolTrueNode(&boolType, 1);
static IRLiteralNode boolFalseNode(&boolType, 0);

void IRBuilder::init() {
    opcode["+"] = "add";
    opcode["-"] = "sub";
    opcode["*"] = "mul";
    opcode["/"] = "sdiv";
    opcode["%"] = "srem";
    opcode["<<"] = "shl";
    opcode[">>"] = "ashr";
    opcode["&"] = "and";
    opcode["|"] = "or";
    opcode["^"] = "xor";
    opcode["<"] = "icmp slt";
    opcode["<="] = "icmp sle";
    opcode[">"] = "icmp sgt";
    opcode[">="] = "icmp sge";
    opcode["=="] = "icmp eq";
    opcode["!="] = "icmp ne";
    stropcode["+"] = "string.concat";
    stropcode["<"] = "string.less";
    stropcode["<="] = "string.lessEq";
    stropcode[">"] = "string.greater";
    stropcode[">="] = "string.greaterEq";
    stropcode["=="] = "string.equals";
    stropcode["!="] = "string.notEquals";

}

IRType* IRBuilder::toIRType(ASTTypeNode *node) {
    if (!node) return &voidType;
    // if (node->dim) return &ptrType;
    if (node->name == "int") return &intType;
    if (node->name == "bool") return &boolType;
    if (node->name == "void") return &voidType;
    if (node->name == "string") return &stringType;
    return &ptrType;
}

IRType* IRBuilder::toIRType(Type *type){
    if (type->dim) return &ptrType;
    if (type->name == "int") return &intType;
    if (type->name == "bool") return &boolType;
    if (type->name == "void") return &voidType;
    if (type->name == "string") return &stringType;
    return &ptrType;
}

IRValueNode* IRBuilder::defaultValue(IRType *type) {
    if (type == &intType) return &intZeroNode;
    if (type == &boolType) return &boolFalseNode;
    if (type == &stringType) return stringMap[""];
    return &nullNode;
}

void IRBuilder::registerClass(ASTClassNode *node) {
    auto clstype = new IRStructType;
    for (auto vars: node->variables) {
        auto type = toIRType(vars->type);
        for (auto v: vars->vars) {
            clstype->elements.push_back(type);
        }
    }
    auto cls = new IRClassType(node->name, clstype);
    auto classstmt = new IRClassStmtNode(cls);
    program->classes.push_back(classstmt);
    classMap[node->name] = cls;
}

void IRBuilder::initBuiltin() {
    auto f = new IRFunctionNode(&intType, "print");
    f->args.emplace_back(&stringType, "str");
    program->functions.push_back(f);
    f = new IRFunctionNode(&intType, "println");
    f->args.emplace_back(&stringType, "str");
    program->functions.push_back(f);
    f = new IRFunctionNode(&intType, "printInt");
    f->args.emplace_back(&intType, "i");
    program->functions.push_back(f);
    f = new IRFunctionNode(&intType, "printlnInt");
    f->args.emplace_back(&intType, "i");
    program->functions.push_back(f);
    f = new IRFunctionNode(&ptrType, "getString");
    program->functions.push_back(f);
    f = new IRFunctionNode(&intType, "getInt");
    program->functions.push_back(f);
    f = new IRFunctionNode(&ptrType, "toString");
    f->args.emplace_back(&intType, "i");
    program->functions.push_back(f);
    f = new IRFunctionNode(&intType, "string.length");
    f->args.emplace_back(&stringType, "str");
    program->functions.push_back(f);
    f = new IRFunctionNode(&ptrType, "string.substring");
    f->args.emplace_back(&stringType, "str");
    f->args.emplace_back(&intType, "left");
    f->args.emplace_back(&intType, "right");
    program->functions.push_back(f);
    f = new IRFunctionNode(&intType, "string.parseInt");
    f->args.emplace_back(&stringType, "str");
    program->functions.push_back(f);
    f = new IRFunctionNode(&intType, "string.ord");
    f->args.emplace_back(&stringType, "str");
    f->args.emplace_back(&intType, "pos");
    program->functions.push_back(f);
    f = new IRFunctionNode(&intType, "string.concat");
    f->args.emplace_back(&stringType, "str1");
    f->args.emplace_back(&stringType, "str2");
    program->functions.push_back(f);
    f = new IRFunctionNode(&intType, "string.less");
    f->args.emplace_back(&stringType, "str1");
    f->args.emplace_back(&stringType, "str2");
    program->functions.push_back(f);
    f = new IRFunctionNode(&intType, "string.lessEq");
    f->args.emplace_back(&stringType, "str1");
    f->args.emplace_back(&stringType, "str2");
    program->functions.push_back(f);
    f = new IRFunctionNode(&intType, "string.greater");
    f->args.emplace_back(&stringType, "str1");
    f->args.emplace_back(&stringType, "str2");
    program->functions.push_back(f);
    f = new IRFunctionNode(&intType, "string.greaterEq");
    f->args.emplace_back(&stringType, "str1");
    f->args.emplace_back(&stringType, "str2");
    program->functions.push_back(f);
    f = new IRFunctionNode(&intType, "string.equals");
    f->args.emplace_back(&stringType, "str1");
    f->args.emplace_back(&stringType, "str2");
    program->functions.push_back(f);
    f = new IRFunctionNode(&intType, "string.notEquals");
    f->args.emplace_back(&stringType, "str1");
    f->args.emplace_back(&stringType, "str2");
    program->functions.push_back(f);
}

void IRBuilder::initEmptyString() {
    auto type = new IRArrayType(1, &i8Type);
    auto var = new IRGlobalVarNode(&ptrType, "_string" + std::to_string(counter["string"]++), true);
    auto str = new IRStringNode(type, "c\"\\00\"");
    program->global_vars.push_back(new IRGlobalVarStmtNode(str, var));
    stringMap[""] = var;
}

void IRBuilder::initGlobalVar() {
    if (varInitList.empty()) return;
    auto init = new IRFunctionNode(&voidType, "__.init");
    program->functions.push_back(init);
    init->blocks.push_back(new IRBlockNode("entry"));
    currentFunction = init;
    currentBlock = init->blocks.front();
    for (auto v: varInitList) {
        v.second->accept(this);
        auto rhs = setVariable(toIRType(&(v.second->type)), astValueMap[v.second]);
        currentBlock->stmts.push_back(new IRStoreStmtNode(rhs, v.first));
    }
    currentBlock->stmts.push_back(new IRRetStmtNode(nullptr));
    currentFunction = nullptr;
}

void IRBuilder::visitProgramNode(ASTProgramNode *node) {
    program = new IRProgramNode;
    initBuiltin();
    initEmptyString();
    for (auto c: node->children) {
        if (auto cls = dynamic_cast<ASTClassNode*>(c)) { registerClass(cls); }
    }
    for (auto c: node->children) {
        if (auto var = dynamic_cast<ASTVarStmtNode*>(c)) { var->accept(this); }
    }
    initGlobalVar();
    for (auto c: node->children) {
        if (auto func = dynamic_cast<ASTFunctionNode*>(c)) {
            func->accept(this);
        }
        else if (auto cls = dynamic_cast<ASTClassNode*>(c)) {
            cls->accept(this);
        }
    }
}

void IRBuilder::visitVarStmtNode(ASTVarStmtNode *node) {
    auto type = toIRType(node->type);
    if (!currentFunction) /* global */ {
        for (auto v: node->uniqueNameVars) {
            auto var = new IRGlobalVarNode(&ptrType, v.first, false);
            auto globalstmt = new IRGlobalVarStmtNode(static_cast<IRValueNode*>(defaultValue(type)), var);
            if (v.second) {
                if (auto liter = dynamic_cast<ASTLiterExprNode*>(v.second)) {
                    liter->accept(this);
                    globalstmt->value = astValueMap[liter];
                }
                else {
                    varInitList.emplace_back(var, v.second);
                }
            }
            program->global_vars.push_back(globalstmt);
            varMap[v.first] = var;
        }
    }
    else /* local */ {
        for (auto v: node->uniqueNameVars) {
            auto var = new IRVarNode(&ptrType, v.first, false);
            currentBlock->stmts.push_back(new IRAllocaStmtNode(var, type));
            if (v.second) {
                v.second->accept(this);
                auto rhs = setVariable(type, astValueMap[v.second]);
                currentBlock->stmts.push_back(new IRStoreStmtNode(rhs, var));   
            }
            varMap[v.first] = var;
        }
    }
}

void IRBuilder::visitFunctionNode(ASTFunctionNode *node) {
    auto func = new IRFunctionNode(toIRType(&(node->type)), "");
    if (currentClass) {
        func->name = currentClass->name + "::" + node->name;
        func->args.emplace_back(&ptrType, "this");
    }
    else func->name = node->name;
    for (auto arg: node->paras) {
        func->args.emplace_back(toIRType(arg.first), arg.second);
    }
    program->functions.push_back(func);

    func->blocks.push_back(new IRBlockNode("entry"));
    currentFunction = func;
    currentBlock = func->blocks.front();
    if (node->name == "main") {
        auto call = new IRCallStmtNode(nullptr, "__.init");
        currentBlock->stmts.push_back(call);
    }

    IRVarNode* ret = nullptr;
    if (func->retType->to_string() != "void") {
        currentBlock->stmts.push_back(new IRAllocaStmtNode(ret = new IRVarNode(&ptrType, "_func.return" + std::to_string(counter["func.return"]++), false), func->retType));
    }
    currentReturnVar = ret;

    node->block->accept(this);

    auto retBlock = new IRBlockNode("_return_block" + std::to_string(counter["return_block"]++));
    for (auto &b: func->blocks) {
        if (b->stmts.empty() || (!dynamic_cast<IRBrStmtNode*>(b->stmts.back()) && !dynamic_cast<IRBrCondStmtNode*>(b->stmts.back()))) {
            b->stmts.push_back(new IRBrStmtNode(retBlock->label));
        }
    }
    currentBlock = retBlock;
    if (func->retType->to_string() == "Void") {
        currentBlock->stmts.push_back(new IRRetStmtNode(nullptr));
    }
    else {
        auto tmp = new IRVarNode(func->retType, "_func.return.tmp" + std::to_string(counter["func.return.tmp"]++), true);
        retBlock->stmts.push_back(new IRLoadStmtNode(tmp, ret));
        retBlock->stmts.push_back(new IRRetStmtNode(tmp));
    }
    func->blocks.push_back(retBlock);
    currentBlock = nullptr;
    currentFunction = nullptr;
}

void IRBuilder::visitClassNode(ASTClassNode *node) {
    auto cls = classMap[node->name];
    currentClass = cls;
    for (auto cons: node->constructors) cons->accept(this);
    for (auto func: node->functions) func->accept(this);
    currentClass = nullptr;

}

void IRBuilder::visitBlockNode(ASTBlockNode *node) {
    for (auto stmt: node->stmts) stmt->accept(this);
}

void IRBuilder::setCondition(IRValueNode* cond, IRBlockNode* block1, IRBlockNode* block2) {
    if (cond->type->to_string() != "ptr") {
        auto tmp = new IRVarNode(&i1Type, "_cond.tmp" + std::to_string(counter["cond.tmp"]++), true);
        currentBlock->stmts.push_back(new IRTruncStmtNode(tmp, cond));
        currentBlock->stmts.push_back(new IRBrCondStmtNode(tmp, block1->label, block2->label));
    }
    else {
        auto tmp = new IRVarNode(&boolType, "_cond.tmp" + std::to_string(counter["cond.tmp"]++), true);
        currentBlock->stmts.push_back(new IRLoadStmtNode(tmp, dynamic_cast<IRVarNode*>(cond)));
        auto tmp2 = new IRVarNode(&i1Type, "_cond.tmp" + std::to_string(counter["cond.tmp"]++), true);
        currentBlock->stmts.push_back(new IRTruncStmtNode(tmp2, tmp));
        currentBlock->stmts.push_back(new IRBrCondStmtNode(tmp2, block1->label, block2->label));
    }
}

void IRBuilder::visitIfStmtNode(ASTIfStmtNode *node) {
    int cnt = node->blocks.size();
    auto endBlock = new IRBlockNode("_if.end" + std::to_string(counter["if.end"]++));
    for (int i = 0; i < cnt; ++i) {
        if (i < node->conds.size()) {
            auto block = new IRBlockNode("_if.else" + std::to_string(counter["if.else"]++));
            currentFunction->blocks.push_back(block);
            IRBlockNode* condblock = nullptr;
            if (i == cnt - 1 && node->conds.size() == node->blocks.size()) condblock = endBlock;
            else condblock = new IRBlockNode("_if.then" + std::to_string(counter["if.then"]++)), currentFunction->blocks.push_back(condblock);
            node->conds[i]->accept(this);

            setCondition(astValueMap[node->conds[i]], block, condblock);

            currentBlock = block;
            node->blocks[i]->accept(this);
            currentBlock->stmts.push_back(new IRBrStmtNode(endBlock->label));
            currentBlock = condblock;
        }
        else {
            node->blocks[i]->accept(this);
            currentBlock->stmts.push_back(new IRBrStmtNode(endBlock->label));
        }
    }
    currentFunction->blocks.push_back(endBlock);
    currentBlock = endBlock;
}

void IRBuilder::visitForStmtNode(ASTForStmtNode *node) {
    auto cond = new IRBlockNode("_for.cond" + std::to_string(counter["for.cond"]++));
    currentFunction->blocks.push_back(cond);

    auto body = new IRBlockNode("_for.body" + std::to_string(counter["for.body"]++));
    currentFunction->blocks.push_back(body);

    auto step = new IRBlockNode("_for.step" + std::to_string(counter["for.step"]++));
    currentFunction->blocks.push_back(step);

    auto endBlock = new IRBlockNode("_for.end" + std::to_string(counter["for.end"]++));
    currentFunction->blocks.push_back(endBlock);

    if (node->init) node->init->accept(this);
    currentBlock->stmts.push_back(new IRBrStmtNode(cond->label));
    currentBlock = cond;

    if (node->cond) {
        node->cond->accept(this);
        setCondition(astValueMap[node->cond], body, endBlock);
        // cond->stmts.push_back(new IRBrCondStmtNode(astValueMap[node->cond], body->label, endBlock->label));
    }
    else cond->stmts.push_back(new IRBrStmtNode(body->label));

    currentBlock = body;
    currentCondBlock = cond;
    currentEndBlock = endBlock;
    node->block->accept(this);
    currentBlock->stmts.push_back(new IRBrStmtNode(step->label));
    currentCondBlock = nullptr;
    currentEndBlock = nullptr;

    currentBlock = step;
    if (node->step) node->step->accept(this);
    currentBlock->stmts.push_back(new IRBrStmtNode(cond->label));

    currentBlock = endBlock;
}

void IRBuilder::visitWhileStmtNode(ASTWhileStmtNode *node) {
    auto cond = new IRBlockNode("_while.cond" + std::to_string(counter["while.cond"]++));
    currentFunction->blocks.push_back(cond);

    auto body = new IRBlockNode("_while.body" + std::to_string(counter["while.body"]++));
    currentFunction->blocks.push_back(body);

    auto endBlock = new IRBlockNode("_while.end" + std::to_string(counter["while.end"]++));
    currentFunction->blocks.push_back(endBlock);

    currentBlock->stmts.push_back(new IRBrStmtNode(cond->label));
    currentBlock = cond;
    
    if (node->cond) {
        node->cond->accept(this);
        setCondition(astValueMap[node->cond], body, endBlock);
        // cond->stmts.push_back(new IRBrCondStmtNode(astValueMap[node->cond], body->label, endBlock->label));
    }
    else cond->stmts.push_back(new IRBrStmtNode(body->label));

    currentBlock = body;
    currentCondBlock = cond;
    currentEndBlock = endBlock;
    node->block->accept(this);
    currentBlock->stmts.push_back(new IRBrStmtNode(cond->label));
    currentCondBlock = nullptr;
    currentEndBlock = nullptr;

    currentBlock = endBlock;
}

void IRBuilder::visitContinueStmtNode(ASTContinueStmtNode *node) {
    currentBlock->stmts.push_back(new IRBrStmtNode(currentCondBlock->label));
}

void IRBuilder::visitBreakStmtNode(ASTBreakStmtNode *node) {
    currentBlock->stmts.push_back(new IRBrStmtNode(currentEndBlock->label));
}

void IRBuilder::visitReturnStmtNode(ASTReturnStmtNode *node) {
    if (node->expr) {
        node->expr->accept(this);
        auto ret = setVariable(toIRType(&(node->expr->type)), astValueMap[node->expr]);
        currentBlock->stmts.push_back(new IRStoreStmtNode(ret, currentReturnVar));
    }
    else currentBlock->stmts.push_back(new IRRetStmtNode(nullptr));
}

void IRBuilder::visitSingleExprNode(ASTSingleExprNode *node) {
    auto type = toIRType(&(node->type));
    auto tmp = new IRVarNode(type, "_single.tmp" + std::to_string(counter["single.tmp"]++), true);
    node->expr->accept(this);
    auto expr = dynamic_cast<IRVarNode*>(astValueMap[node->expr]);
    if (!expr) throw std::runtime_error("not a lvalue");

    currentBlock->stmts.push_back(new IRLoadStmtNode(tmp, expr));
    
    auto ret = new IRVarNode(type, "_single.return.tmp" + std::to_string(counter["single.return.tmp"]++), true);
    if (node->op == "++") {
        currentBlock->stmts.push_back(new IRBinaryStmtNode("add", ret, tmp, &intOneNode));
        currentBlock->stmts.push_back(new IRStoreStmtNode(ret, expr));
    }
    else if (node->op == "--") {
        currentBlock->stmts.push_back(new IRBinaryStmtNode("sub", ret, tmp, &intOneNode));
        currentBlock->stmts.push_back(new IRStoreStmtNode(ret, expr));
    }
    else if (node->op == "-") {
        currentBlock->stmts.push_back(new IRBinaryStmtNode("sub", ret, &intZeroNode, tmp));
    }
    else if (node->op == "~") {
        currentBlock->stmts.push_back(new IRBinaryStmtNode("xor", ret, tmp, &intMinusOneNode));
    }
    else if (node->op == "!") {
        auto tmp2 = new IRVarNode(type, "_single.return.tmp" + std::to_string(counter["single.return.tmp"]++), true);
        currentBlock->stmts.push_back(new IRBinaryStmtNode("icmp eq", tmp2, tmp, &intZeroNode));
        currentBlock->stmts.push_back(new IRBinaryStmtNode("xor", ret, tmp2, &boolTrueNode));
    }
    if (node->right) astValueMap[node] = tmp;
    else astValueMap[node] = ret;
}

IRValueNode* IRBuilder::setVariable(IRType* type, IRValueNode* value) {
    if (auto var = dynamic_cast<IRVarNode*>(value)) {
        if (var->isConst) return value;
        auto tmp = new IRVarNode(type, "_var.tmp" + std::to_string(counter["var.tmp"]++), true);
        currentBlock->stmts.push_back(new IRLoadStmtNode(tmp, dynamic_cast<IRVarNode*>(value)));
        return tmp;
    }
    else return value;
}

void IRBuilder::visitBinaryExprNode(ASTBinaryExprNode *node) {
    auto type = toIRType(&(node->type));
    IRVarNode* ret = new IRVarNode(type, "_binary.tmp" + std::to_string(counter["binary.tmp"]++), true);
    if (node->type.is_string()) {
        node->lhs->accept(this);
        node->rhs->accept(this);
        auto lhs = setVariable(type, astValueMap[node->lhs]);
        auto rhs = setVariable(type, astValueMap[node->rhs]);
        auto call = new IRCallStmtNode(ret, stropcode[node->op]);
        call->args.push_back(lhs);
        call->args.push_back(rhs);
        currentBlock->stmts.push_back(call);
    }
    else if (node->op == "&&" || node->op == "||") {
        node->lhs->accept(this);
        auto block = new IRBlockNode("_logic" + std::to_string(counter["logic"]++));
        auto endBlock = new IRBlockNode("_logic.end" + std::to_string(counter["logic.end"]++));
        auto lhs = astValueMap[node->lhs];
        if (node->op == "&&") {
            setCondition(lhs, block, endBlock);
        }
        else {
            setCondition(lhs, endBlock, block);
        }
        currentFunction->blocks.push_back(block);
        currentFunction->blocks.push_back(endBlock);

        auto tmp = new IRPhiStmtNode(ret);
        tmp->values.emplace_back(setVariable(type, lhs), currentBlock->label);

        currentBlock = block;
        node->rhs->accept(this);
        currentBlock->stmts.push_back(new IRBrStmtNode(endBlock->label));

        auto rhs = astValueMap[node->rhs];
        tmp->values.emplace_back(setVariable(type, rhs), currentBlock->label);

        currentBlock = endBlock;
        endBlock->stmts.push_back(tmp);
        astValueMap[node] = ret;
    }
    else {
        node->lhs->accept(this);
        node->rhs->accept(this);
        auto lhs = setVariable(type, astValueMap[node->lhs]);
        auto rhs = setVariable(type, astValueMap[node->rhs]);
        auto op = opcode[node->op];
        if (op.find("icmp") != std::string::npos) {
            auto tmp = new IRVarNode(&i1Type, "_binary.tmp" + std::to_string(counter["binary.tmp"]++), true);
            currentBlock->stmts.push_back(new IRIcmpStmtNode(op, tmp, lhs, rhs));
            currentBlock->stmts.push_back(new IRZextStmtNode(ret, tmp));
        }
        else {
            currentBlock->stmts.push_back(new IRBinaryStmtNode(op, ret, lhs, rhs));
        }
    }
    astValueMap[node] = ret; 
}

void IRBuilder::visitTernaryExprNode(ASTTernaryExprNode* node) {
    auto type = toIRType(&(node->type));
    auto trueBlock = new IRBlockNode("_ternary.true" + std::to_string(counter["ternary.true"]++));
    auto falseBlock = new IRBlockNode("_ternary.false" + std::to_string(counter["ternary.false"]++));
    auto endBlock = new IRBlockNode("_ternary.end" + std::to_string(counter["ternary.end"]++));
    currentFunction->blocks.push_back(trueBlock);
    currentFunction->blocks.push_back(falseBlock);
    currentFunction->blocks.push_back(endBlock);

    auto ret = new IRVarNode(&ptrType, "_ternary.return" + std::to_string(counter["ternary.return"]++), false);
    currentBlock->stmts.push_back(new IRAllocaStmtNode(ret, type));
    node->cond->accept(this);
    setCondition(astValueMap[node->cond], trueBlock, falseBlock);

    currentBlock = trueBlock;
    node->True->accept(this);
    auto True = setVariable(type, astValueMap[node->True]);
    currentBlock->stmts.push_back(new IRStoreStmtNode(True, ret));
    currentBlock->stmts.push_back(new IRBrStmtNode(endBlock->label));
    
    currentBlock = falseBlock;
    node->False->accept(this);
    auto False = setVariable(type, astValueMap[node->False]);
    currentBlock->stmts.push_back(new IRStoreStmtNode(False, ret));
    currentBlock->stmts.push_back(new IRBrStmtNode(endBlock->label));
    currentBlock = endBlock;
    astValueMap[node] = ret;    
}

void IRBuilder::visitExprStmtNode(ASTExprStmtNode *node) {
    for (auto expr: node->exprs) expr->accept(this);
}

void IRBuilder::visitFuncExprNode(ASTFuncExprNode *node) {
    auto type = toIRType(&(node->type));
    IRVarNode* var = nullptr;
    if (type->to_string() != "void") var = new IRVarNode(type, "_call.tmp" + std::to_string(counter["call.tmp"]++), true);
    IRCallStmtNode* call = nullptr;
    if (auto func = dynamic_cast<ASTAtomExprNode*>(node->func)) call = new IRCallStmtNode(var, func->name);
    else {
        node->func->accept(this);
        call = new IRCallStmtNode(var, "");
    }
    for (auto arg: node->args) {
        arg->accept(this);
        call->args.push_back(setVariable(toIRType(&(arg->type)), astValueMap[arg]));
    }
    currentBlock->stmts.push_back(call);
    astValueMap[node] = var;
}

void IRBuilder::visitArrayExprNode(ASTArrayExprNode *node) {}
void IRBuilder::visitMemberExprNode(ASTMemberExprNode *node) {}

void IRBuilder::visitNewExprNode(ASTNewExprNode *node) {}

void IRBuilder::visitAssignExprNode(ASTAssignExprNode *node) {
    auto type = toIRType(&(node->type));
    node->lhs->accept(this);
    auto lhs = dynamic_cast<IRVarNode*>(astValueMap[node->lhs]);
    node->rhs->accept(this);
    auto rhs = node->type.is_string()? astValueMap[node->rhs]: setVariable(type, astValueMap[node->rhs]);
    currentBlock->stmts.push_back(new IRStoreStmtNode(rhs, lhs));
}

void IRBuilder::visitLiterExprNode(ASTLiterExprNode *node) {
    if (node->type.is_int()) {
        astValueMap[node] = new IRLiteralNode(&intType, std::stoi(node->value));
    }
    else if (node->type.is_bool()) {
        astValueMap[node] = new IRLiteralNode(&boolType, node->value == "true" ? 1 : 0);
    }
    else if (node->type.is_string()) {
        auto value = node->value.substr(1, node->value.size() - 2);
        if (stringMap.count(value)) {
            astValueMap[node] = stringMap[value];
            return;
        }
        auto type = new IRArrayType(value.size() + 1, &i8Type);
        auto var = new IRGlobalVarNode(&ptrType, "_string" + std::to_string(counter["string"]++), true);
        auto str = new IRStringNode(type, "c\"" + value + "\\00\"");
        program->global_vars.push_back(new IRGlobalVarStmtNode(str, var));
        stringMap[value] = var;
        astValueMap[node] = var;
    }
    else if (node->type.is_null()) {
        
    }
}

void IRBuilder::visitAtomExprNode(ASTAtomExprNode *node) {
    if (node->name == "this") {
    
    }
    else {
        astValueMap[node] = varMap[node->uniqueName];
    }
}





void IRBuilder::visitNewTypeNode(ASTNewTypeNode *node) {}