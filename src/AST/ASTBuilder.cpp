#include "ASTBuilder.h"
#include "ASTNode.h"
using std::any_cast;

std::any ASTBuilder::visitProgram(MxParser::ProgramContext *ctx) {
    auto node = new ASTProgramNode;
    auto children = ctx->children;
    for (auto child: children) {
        auto res = visit(child);
        if (!res.has_value()) continue;
        if (auto Class = any_cast<ASTClassNode*>(&res)) node->children.push_back(*Class);
        else if (auto Func = any_cast<ASTFunctionNode*>(&res)) node->children.push_back(*Func);
        else if (auto Var = any_cast<ASTVarStmtNode*>(&res)) node->children.push_back(*Var);
        else throw std::exception();
    }
    return static_cast<ASTNode*>(node);
}

std::any ASTBuilder::visitClassDef(MxParser::ClassDefContext *ctx) {
    auto node = new ASTClassNode;
    auto suite = ctx->classSuite();
    node->name = ctx->Identifier()->getText();
    for (auto v: suite) {
        auto children = v->children;
        for (auto child: children) {
            auto res = visit(child);
            if (!res.has_value()) continue;
            if (auto Var = any_cast<ASTVarStmtNode*>(&res)) node->variables.push_back(*Var);
            if (auto Cons = any_cast<ASTConstructNode*>(&res)) node->constructors.push_back(*Cons);
            if (auto Func = any_cast<ASTFunctionNode*>(&res)) node->functions.push_back(*Func);
        }
    }
    return node;
}

std::any ASTBuilder::visitConstructDef(MxParser::ConstructDefContext *ctx) {
    auto node = new ASTConstructNode;
    node->name = ctx->Identifier()->getText();
    node->block = any_cast<ASTBlockNode*>(visit(ctx->block()));
    return node;
}

std::any ASTBuilder::visitFunctionDef(MxParser::FunctionDefContext *ctx) {
    auto node = new ASTFunctionNode;
    node->name = ctx->Identifier()->getText();
    node->returnType = any_cast<ASTTypeNode*>(visit(ctx->typeName()));
    if (auto paras = ctx->parameters()) {
        node->paras = *any_cast<vector<pair<ASTTypeNode*, string>>>(&visit(paras));
    }
    node->block = any_cast<ASTBlockNode*>(visit(ctx->block()));
    return node;
}

std::any ASTBuilder::visitParameters(MxParser::ParametersContext *ctx) {
    vector<pair<ASTTypeNode*, string>> paras;
    for (auto Var: ctx->varDef()) {
        auto type = any_cast<ASTTypeNode*>(visit(Var->typeName()));
        paras.emplace_back(type, Var->Identifier()->getText());
    }
    return paras;
}

std::any ASTBuilder::visitArray(MxParser::ArrayContext *ctx) {
    auto node = any_cast<ASTTypeNode*>(visit(ctx->typeName()));
    ++node->dim;
    return node;
}

std::any ASTBuilder::visitBasic(MxParser::BasicContext *ctx) {
    auto node = new ASTTypeNode;
    node->name = ctx->basicType()->getText();
    return node;
}

std::any ASTBuilder::visitClass(MxParser::ClassContext *ctx) {
    auto node = new ASTTypeNode;
    node->name = ctx->Identifier()->getText();
    return node;
}

std::any ASTBuilder::visitSuite(MxParser::SuiteContext *ctx) {
    if (ctx->block()) {
        if (auto node = *any_cast<ASTBlockNode*>(&visit(ctx->block()))) return node;
    }
    auto node = new ASTBlockNode;
    if (ctx->stmt()) {
        if (auto st = *any_cast<ASTStmtNode*>(&visit(ctx->stmt()))) node->stmts.push_back(st);
    }
    return node;
}

std::any ASTBuilder::visitBlock(MxParser::BlockContext *ctx) {
    auto node = new ASTBlockNode;
    for (auto st:ctx->stmt()) {
        node->stmts.push_back(any_cast<ASTStmtNode*>(visit(st)));
    }
    return node;
}

std::any ASTBuilder::visitStmt(MxParser::StmtContext *ctx) {
    auto node 
}



std::any ASTBuilder::visitVarDefInit(MxParser::VarDefInitContext *ctx) {}
std::any ASTBuilder::visitExprStmt(MxParser::ExprStmtContext *ctx) {}
std::any ASTBuilder::visitExprList(MxParser::ExprListContext *ctx) {}
std::any ASTBuilder::visitIfStmt(MxParser::IfStmtContext *ctx) {}
std::any ASTBuilder::visitWhileStmt(MxParser::WhileStmtContext *ctx) {}
std::any ASTBuilder::visitForStmt(MxParser::ForStmtContext *ctx) {}
std::any ASTBuilder::visitFlowStmt(MxParser::FlowStmtContext *ctx) {}
std::any ASTBuilder::visitArrayExpr(MxParser::ArrayExprContext *ctx) {}
std::any ASTBuilder::visitFunctionExpr(MxParser::FunctionExprContext *ctx) {}
std::any ASTBuilder::visitMemberExpr(MxParser::MemberExprContext *ctx) {}
std::any ASTBuilder::visitParentheseExpr(MxParser::ParentheseExprContext *ctx) {}
std::any ASTBuilder::visitLeftSingleExpr(MxParser::LeftSingleExprContext *ctx) {}
std::any ASTBuilder::visitBinaryExpr(MxParser::BinaryExprContext *ctx) {}
std::any ASTBuilder::visitNewExpr(MxParser::NewExprContext *ctx) {}
std::any ASTBuilder::visitLiterExpr(MxParser::LiterExprContext *ctx) {}
std::any ASTBuilder::visitRightSingleExpr(MxParser::RightSingleExprContext *ctx) {}
std::any ASTBuilder::visitAtomExpr(MxParser::AtomExprContext *ctx) {}
std::any ASTBuilder::visitTernaryExpr(MxParser::TernaryExprContext *ctx) {}
std::any ASTBuilder::visitAssignExpr(MxParser::AssignExprContext *ctx) {}
std::any ASTBuilder::visitVarDefStmt(MxParser::VarDefStmtContext *ctx) {}

std::any ASTBuilder::visitNewClass(MxParser::NewClassContext *ctx) {}
std::any ASTBuilder::visitNewClassArray(MxParser::NewClassArrayContext *ctx) {}
std::any ASTBuilder::visitNewBasicArray(MxParser::NewBasicArrayContext *ctx) {}
std::any ASTBuilder::visitNewArrayExpr(MxParser::NewArrayExprContext *ctx) {}
std::any ASTBuilder::visitNewArrayEmpty(MxParser::NewArrayEmptyContext *ctx) {}
std::any ASTBuilder::visitLiteralExpr(MxParser::LiteralExprContext *ctx) {}
std::any ASTBuilder::visitBasicType(MxParser::BasicTypeContext *ctx) {}
