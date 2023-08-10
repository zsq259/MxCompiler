#include "IRBuilder.h"
#include "IRType.h"
#include "IRNode.h"
#include "ASTNode.h"

static IRVoidType voidType;
static IRIntType boolType(32);
static IRIntType intType(32);
static IRPtrType ptrType;
static IRLiteralNode nullNode(&ptrType, 0);
static IRLiteralNode intZeroNode(&intType, 0);
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
            auto var = new IRVarNode(v.first);
            var->type = type;

            auto globalstmt = new IRGlobalVarStmtNode;
            globalstmt->var = var;
            globalstmt->value = defaultValue(type);
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
        }
    }
    else /* local */ {
        for (auto v: node->uniqueNameVars) {
            auto var = new IRVarNode(v.first);
            var->type = type;
            var->name = v.first;
            auto stmt = new IRVarStmtNode;
            stmt->var = var;
            if (v.second) {
                v.second->accept(this);
                stmt->value = astValueMap[v.second];
            }
            currentBlock->stmts.push_back(stmt);
        }
    }
}

void IRBuilder::visitFunctionNode(ASTFunctionNode *node) {
    auto func = new IRFunctionNode;
    if (currentClass) {
        func->name = currentClass->name + "." + node->name;
        func->args.emplace_back(&ptrType, "this");
    }
    else func->name = node->name;
    func->retType = toIRType(&(node->type));
    for (auto arg: node->paras) {
        func->args.emplace_back(toIRType(arg.first), arg.second);
    }
    program->functions.push_back(func);
    func->blocks.push_back(new IRBlockNode("entry"));
    currentFunction = func;
    currentBlock = func->blocks[0];
    node->block->accept(this);
    currentBlock = nullptr;
    currentFunction = nullptr;
}

void IRBuilder::visitBlockNode(ASTBlockNode *node) {
    for (auto stmt: node->stmts) stmt->accept(this);
}

void IRBuilder::visitIfStmtNode(ASTIfStmtNode *node) {
    int cnt = node->blocks.size();
    auto endBlock = new IRBlockNode("if.end" + (++ifendCnt));
    for (int i = 0; i < cnt; ++i) {
        if (i < node->conds.size()) {
            auto block = new IRBlockNode("if.else" + (++ifelseCnt));
            currentFunction->blocks.push_back(block);
            IRBlockNode* condblock = nullptr;
            if (i == cnt - 1 && node->conds.size() == node->blocks.size()) condblock = endBlock;
            else condblock = new IRBlockNode("if.then" + (++ifthenCnt)), currentFunction->blocks.push_back(condblock);
            node->conds[i]->accept(this);
            currentBlock->stmts.push_back(new IRBrCondStmtNode(astValueMap[node->conds[i]], block->label, condblock->label));
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

void IRBuilder::visitClassNode(ASTClassNode *node) {}

void IRBuilder::visitTypeNode(ASTTypeNode *node) {}

void IRBuilder::visitStmtNode(ASTStmtNode *node) {}
void IRBuilder::visitExprStmtNode(ASTExprStmtNode *node) {}
void IRBuilder::visitExprNode(ASTExprNode *node) {}
void IRBuilder::visitFuncExprNode(ASTFuncExprNode *node) {}
void IRBuilder::visitArrayExprNode(ASTArrayExprNode *node) {}
void IRBuilder::visitMemberExprNode(ASTMemberExprNode *node) {}
void IRBuilder::visitSingleExprNode(ASTSingleExprNode *node) {}
void IRBuilder::visitNewExprNode(ASTNewExprNode *node) {}
void IRBuilder::visitBinaryExprNode(ASTBinaryExprNode *node) {}
void IRBuilder::visitTernaryExprNode(ASTTernaryExprNode *node) {}
void IRBuilder::visitAssignExprNode(ASTAssignExprNode *node) {}
void IRBuilder::visitLiterExprNode(ASTLiterExprNode *node) {}
void IRBuilder::visitAtomExprNode(ASTAtomExprNode *node) {}

void IRBuilder::visitWhileStmtNode(ASTWhileStmtNode *node) {}
void IRBuilder::visitForStmtNode(ASTForStmtNode *node) {}
void IRBuilder::visitFlowStmtNode(ASTFlowStmtNode *node) {}
void IRBuilder::visitContinueStmtNode(ASTContinueStmtNode *node) {}
void IRBuilder::visitBreakStmtNode(ASTBreakStmtNode *node) {}
void IRBuilder::visitReturnStmtNode(ASTReturnStmtNode *node) {}

void IRBuilder::visitNewTypeNode(ASTNewTypeNode *node) {}