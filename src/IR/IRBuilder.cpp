#include "IRBuilder.h"
#include "IRType.h"
#include "IRNode.h"
#include "ASTNode.h"

static IRVoidType voidType;
static IRIntType boolType(32);
static IRIntType intType(32);
static IRIntType i1Type(1);
static IRPtrType ptrType;
static IRLiteralNode nullNode(&ptrType, 0);
static IRLiteralNode intZeroNode(&intType, 0);
static IRLiteralNode intOneNode(&intType, 1);
static IRLiteralNode intMinusOneNode(&intType, -1);
static IRLiteralNode boolTrueNode(&boolType, 1);
static IRLiteralNode boolFalseNode(&boolType, 0);


IRType* IRBuilder::toIRType(ASTTypeNode *node) {
    if (!node) return &voidType;
    // if (node->dim) return &ptrType;
    if (node->name == "int") return &intType;
    if (node->name == "bool") return &boolType;
    if (node->name == "void") return &voidType;
    return &ptrType;
}

IRType* IRBuilder::toIRType(Type *type){
    if (type->dim) return &ptrType;
    if (type->name == "int") return &intType;
    if (type->name == "bool") return &boolType;
    if (type->name == "void") return &voidType;
    return &ptrType;
}

IRLiteralNode* IRBuilder::defaultValue(IRType *type) {
    if (type == &intType) return &intZeroNode;
    if (type == &boolType) return &boolFalseNode;
    return &nullNode;
}

void IRBuilder::visitProgramNode(ASTProgramNode *node) {
    program = new IRProgramNode;
    for (auto c: node->children) {
        if (auto var = dynamic_cast<ASTVarStmtNode*>(c)) {
            var->accept(this);
        }
        else if (auto func = dynamic_cast<ASTFunctionNode*>(c)) {
            func->accept(this);
        }
        else if (auto cls = dynamic_cast<ASTClassNode*>(c)) {
            
        }
    }
}

void IRBuilder::visitVarStmtNode(ASTVarStmtNode *node) {
    auto type = toIRType(node->type);
    if (!currentFunction) /* global */ {
        for (auto v: node->uniqueNameVars) {
            auto var = new IRVarNode(type, v.first);
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
            auto var = new IRVarNode(&ptrType, v.first);
            currentBlock->stmts.push_back(new IRAllocaStmtNode(var, type));
            if (v.second) {
                v.second->accept(this);
                currentBlock->stmts.push_back(new IRStoreStmtNode(astValueMap[v.second], var));   
            }
            varMap[v.first] = var;
        }
    }
}

void IRBuilder::visitFunctionNode(ASTFunctionNode *node) {
    auto func = new IRFunctionNode(toIRType(&(node->type)), "");
    if (currentClass) {
        func->name = currentClass->name + "." + node->name;
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

    IRVarNode* ret = nullptr;
    if (func->retType->to_string() != "void") {
        currentBlock->stmts.push_back(new IRAllocaStmtNode(ret = new IRVarNode(&ptrType, std::to_string(count++)), func->retType));
    }
    currentReturnVar = ret;

    node->block->accept(this);

    auto retBlock = new IRBlockNode("return_block" + std::to_string(returnCnt++));
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
        auto tmp = new IRVarNode(func->retType, std::to_string(count++));
        retBlock->stmts.push_back(new IRLoadStmtNode(tmp, ret));
        currentBlock->stmts.push_back(new IRRetStmtNode(tmp));
    }
    func->blocks.push_back(retBlock);
    currentBlock = nullptr;
    currentFunction = nullptr;
}

void IRBuilder::visitBlockNode(ASTBlockNode *node) {
    for (auto stmt: node->stmts) stmt->accept(this);
}

void IRBuilder::setCondition(IRValueNode* cond, IRBlockNode* block1, IRBlockNode* block2) {
    if (cond->type->to_string() != "ptr") {
        auto tmp = new IRVarNode(&i1Type, std::to_string(count++));
        currentBlock->stmts.push_back(new IRTruncStmtNode(tmp, cond));
        currentBlock->stmts.push_back(new IRBrCondStmtNode(tmp, block1->label, block2->label));
    }
    else {
        auto tmp = new IRVarNode(&boolType, std::to_string(count++));
        currentBlock->stmts.push_back(new IRLoadStmtNode(tmp, dynamic_cast<IRVarNode*>(cond)));
        auto tmp2 = new IRVarNode(&i1Type, std::to_string(count++));
        currentBlock->stmts.push_back(new IRTruncStmtNode(tmp2, tmp));
        currentBlock->stmts.push_back(new IRBrCondStmtNode(tmp2, block1->label, block2->label));
    }
}

void IRBuilder::visitIfStmtNode(ASTIfStmtNode *node) {
    int cnt = node->blocks.size();
    auto endBlock = new IRBlockNode("if.end" + std::to_string(ifendCnt++));
    for (int i = 0; i < cnt; ++i) {
        if (i < node->conds.size()) {
            auto block = new IRBlockNode("if.else" + std::to_string(ifelseCnt++));
            currentFunction->blocks.push_back(block);
            IRBlockNode* condblock = nullptr;
            if (i == cnt - 1 && node->conds.size() == node->blocks.size()) condblock = endBlock;
            else condblock = new IRBlockNode("if.then" + std::to_string(ifthenCnt++)), currentFunction->blocks.push_back(condblock);
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
    auto cond = new IRBlockNode("for.cond" + std::to_string(forcondCnt++));
    currentFunction->blocks.push_back(cond);

    auto body = new IRBlockNode("for.body" + std::to_string(forbodyCnt++));
    currentFunction->blocks.push_back(body);

    auto step = new IRBlockNode("for.step" + std::to_string(forstepCnt++));
    currentFunction->blocks.push_back(step);

    auto endBlock = new IRBlockNode("for.end" + std::to_string(forendCnt++));
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
    body->stmts.push_back(new IRBrStmtNode(step->label));
    currentCondBlock = nullptr;
    currentEndBlock = nullptr;

    currentBlock = step;
    if (node->step) node->step->accept(this);
    step->stmts.push_back(new IRBrStmtNode(cond->label));

    currentBlock = endBlock;
}

void IRBuilder::visitWhileStmtNode(ASTWhileStmtNode *node) {
    auto cond = new IRBlockNode("while.cond" + std::to_string(whilecondCnt++));
    currentFunction->blocks.push_back(cond);

    auto body = new IRBlockNode("while.body" + std::to_string(whilebodyCnt++));
    currentFunction->blocks.push_back(body);

    auto endBlock = new IRBlockNode("while.end" + std::to_string(whileendCnt++));
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
    body->stmts.push_back(new IRBrStmtNode(cond->label));
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
        currentBlock->stmts.push_back(new IRStoreStmtNode(astValueMap[node->expr], currentReturnVar));
    }
    else currentBlock->stmts.push_back(new IRRetStmtNode(nullptr));
}

void IRBuilder::visitSingleExprNode(ASTSingleExprNode *node) {
    auto type = toIRType(&(node->type));
    auto tmp = new IRVarNode(type, std::to_string(count++));
    node->expr->accept(this);
    auto expr = dynamic_cast<IRVarNode*>(astValueMap[node->expr]);
    if (!expr) throw std::runtime_error("not a lvalue");

    currentBlock->stmts.push_back(new IRLoadStmtNode(tmp, expr));
    
    auto ret = new IRVarNode(type, std::to_string(count++));
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
        auto tmp2 = new IRVarNode(type, std::to_string(count++));
        currentBlock->stmts.push_back(new IRBinaryStmtNode("icmp eq", tmp2, tmp, &intZeroNode));
        currentBlock->stmts.push_back(new IRBinaryStmtNode("xor", ret, tmp2, &boolTrueNode));
    }
    if (node->right) astValueMap[node] = tmp;
    else astValueMap[node] = ret;
}

void IRBuilder::visitBinaryExprNode(ASTBinaryExprNode *node) {
    auto type = toIRType(&(node->type));
    node->lhs->accept(this);
    node->rhs->accept(this);
    auto lhs = astValueMap[node->lhs];
    auto rhs = astValueMap[node->rhs];
    auto ret = new IRVarNode(type, std::to_string(count++));
    

}

void IRBuilder::visitClassNode(ASTClassNode *node) {}

void IRBuilder::visitTypeNode(ASTTypeNode *node) {}

void IRBuilder::visitExprStmtNode(ASTExprStmtNode *node) {
    for (auto expr: node->exprs) expr->accept(this);
}

void IRBuilder::visitFuncExprNode(ASTFuncExprNode *node) {}
void IRBuilder::visitArrayExprNode(ASTArrayExprNode *node) {}
void IRBuilder::visitMemberExprNode(ASTMemberExprNode *node) {}


void IRBuilder::visitNewExprNode(ASTNewExprNode *node) {}

void IRBuilder::visitTernaryExprNode(ASTTernaryExprNode *node) {}
void IRBuilder::visitAssignExprNode(ASTAssignExprNode *node) {}

void IRBuilder::visitLiterExprNode(ASTLiterExprNode *node) {
    if (node->type.is_int()) {
        astValueMap[node] = new IRLiteralNode(&intType, std::stoi(node->value));
    }
    else if (node->type.is_bool()) {
        astValueMap[node] = new IRLiteralNode(&boolType, node->value == "true" ? 1 : 0);
    }
    else if (node->type.is_string()) {
        
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