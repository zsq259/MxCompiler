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
        auto res = visit(paras);
        node->paras = *any_cast<vector<pair<ASTTypeNode*, string>>>(&res);
    }
    node->block = any_cast<ASTBlockNode*>(visit(ctx->block()));
    return node;
}

std::any ASTBuilder::visitParameters(MxParser::ParametersContext *ctx) {
    vector<pair<ASTTypeNode*, string>> paras;
    for (auto var: ctx->varDef()) {
        auto type = any_cast<ASTTypeNode*>(visit(var->typeName()));
        paras.emplace_back(type, var->Identifier()->getText());
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
        auto res = visit(ctx->block());
        if (auto node = *any_cast<ASTBlockNode*>(&res)) return node;
    }
    auto node = new ASTBlockNode;
    if (ctx->stmt()) {
        auto res = visit(ctx->stmt());
        if (auto st = *any_cast<ASTStmtNode*>(&res)) node->stmts.push_back(st);
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

std::any ASTBuilder::visitExprStmt(MxParser::ExprStmtContext *ctx) {
    auto node = new ASTExprStmtNode;
    auto list = ctx->exprList();
    if (list) {
        for (auto child: list->children) {
            auto res = visit(child);
            if (!res.has_value()) continue;
            node->exprs.push_back(any_cast<ASTExprNode*>(res));
        }
    }
    return static_cast<ASTStmtNode*>(node);
}

std::any ASTBuilder::visitIfStmt(MxParser::IfStmtContext *ctx) {
    auto node = new ASTIfStmtNode;
    for (auto cond: ctx->expression()) {
        node->conds.push_back(any_cast<ASTExprNode*>(visit(cond)));
    }
    for (auto block: ctx->suite()) {
        node->blocks.push_back(any_cast<ASTBlockNode*>(visit(block)));
    }
    
    return static_cast<ASTStmtNode*>(node);
}

std::any ASTBuilder::visitWhileStmt(MxParser::WhileStmtContext *ctx) {
    auto node = new ASTWhileStmtNode;
    node->cond = any_cast<ASTExprNode*>(visit(ctx->expression()));
    node->block = any_cast<ASTBlockNode*>(visit(ctx->suite()));
    return static_cast<ASTStmtNode*>(node);
}

std::any ASTBuilder::visitForStmt(MxParser::ForStmtContext *ctx) {
    auto node = new ASTForStmtNode;
    if (auto init = ctx->exprStmt()) {
        auto res = visit(init);
        if (res.has_value()) {
            node->init = any_cast<ASTStmtNode*>(res);
        }
    }
    
    if (auto init = ctx->varDefStmt()) {
        auto res = visit(init);
        if (res.has_value()) {
            node->init = any_cast<ASTStmtNode*>(res);
        }
    }
    if (auto cond = ctx->condition) {
        auto res = visit(cond);
        if (res.has_value()) {
            node->cond = any_cast<ASTExprNode*>(res);
        }
    }
    if (auto step = ctx->step) {
        auto res = visit(step);
        if (res.has_value()) {
            node->step = any_cast<ASTExprNode*>(res);
        }
    }
    auto res = visit(ctx->suite());
    node->block = any_cast<ASTBlockNode*>(res);
    return static_cast<ASTStmtNode*>(node);
}

std::any ASTBuilder::visitFlowStmt(MxParser::FlowStmtContext *ctx) {
    ASTStmtNode* node = nullptr;
    if (ctx->Continue()) node = new ASTContinueStmtNode;
    else if (ctx->Break()) node = new ASTBreakStmtNode;
    else {
        auto node_ = new ASTReturnStmtNode;
        if (ctx->expression()) node_->expr = any_cast<ASTExprNode*>(visit(ctx->expression()));
        else node_->expr = nullptr;
        node = node_;
    }
    return node;
}

std::any ASTBuilder::visitVarDefStmt(MxParser::VarDefStmtContext *ctx) {
    auto node = new ASTVarStmtNode;
    node->type = any_cast<ASTTypeNode*>(visit(ctx->typeName()));
    for (auto var: ctx->varDefInit()) {
        node->vars.emplace_back(var->Identifier()->getText(), nullptr);
        if (auto expr = var->expression()) {
            auto res = visit(expr);
            node->vars.back().second = any_cast<ASTExprNode*>(res);
        }
    }
    return static_cast<ASTStmtNode*>(node);
}

std::any ASTBuilder::visitParentheseExpr(MxParser::ParentheseExprContext *ctx) {
    return visit(ctx->expression());
}

std::any ASTBuilder::visitArrayExpr(MxParser::ArrayExprContext *ctx) {
    auto node = new ASTArrayExprNode;
    node->array = any_cast<ASTExprNode*>(visit(ctx->expression()[0]));
    node->index = any_cast<ASTExprNode*>(visit(ctx->expression()[1]));
    return static_cast<ASTExprNode*>(node);
}

std::any ASTBuilder::visitFunctionExpr(MxParser::FunctionExprContext *ctx) {
    auto node = new ASTFuncExprNode;
    node->func = any_cast<ASTExprNode*>(visit(ctx->expression()));
    if (ctx->exprList()) {
        for (auto expr: ctx->exprList()->expression()) {
            node->args.push_back(any_cast<ASTExprNode*>(visit(expr)));
        }
    }
    return static_cast<ASTExprNode*>(node);
}

std::any ASTBuilder::visitMemberExpr(MxParser::MemberExprContext *ctx) {
    auto node = new ASTMemberExprNode;
    node->name = any_cast<ASTExprNode*>(visit(ctx->expression()));
    node->member = ctx->Identifier()->getText();
    return static_cast<ASTExprNode*>(node);
}

std::any ASTBuilder::visitLeftSingleExpr(MxParser::LeftSingleExprContext *ctx) {
    auto node = new ASTSingleExprNode;
    node->expr = any_cast<ASTExprNode*>(visit(ctx->expression()));
    node->op = ctx->op->getText();
    node->right = false;
    return static_cast<ASTExprNode*>(node);
}

std::any ASTBuilder::visitRightSingleExpr(MxParser::RightSingleExprContext *ctx) {
    auto node = new ASTSingleExprNode;
    node->expr = any_cast<ASTExprNode*>(visit(ctx->expression()));
    node->op = ctx->op->getText();
    node->right = true;
    return static_cast<ASTExprNode*>(node);
}

std::any ASTBuilder::visitBinaryExpr(MxParser::BinaryExprContext *ctx) {
    auto node = new ASTBinaryExprNode;
    node->lhs = any_cast<ASTExprNode*>(visit(ctx->lhs));
    node->rhs = any_cast<ASTExprNode*>(visit(ctx->rhs));
    node->op = ctx->op->getText();
    return static_cast<ASTExprNode*>(node);
}

std::any ASTBuilder::visitNewExpr(MxParser::NewExprContext *ctx) {
    
    auto node = new ASTNewExprNode;
    node->newType = any_cast<ASTNewTypeNode*>(visit(ctx->newTypeName()));
    return static_cast<ASTExprNode*>(node);
}

std::any ASTBuilder::visitLiterExpr(MxParser::LiterExprContext *ctx) {
    return visit(ctx->literalExpr());
}

std::any ASTBuilder::visitLiteralExpr(MxParser::LiteralExprContext *ctx) {
    auto node = new ASTLiterExprNode;
    node->value = ctx->getText();
    return static_cast<ASTExprNode*>(node);
}

std::any ASTBuilder::visitAtomExpr(MxParser::AtomExprContext *ctx) {
    auto node = new ASTAtomExprNode;
    node->name = ctx->getText();
    return static_cast<ASTExprNode*>(node);
}

std::any ASTBuilder::visitTernaryExpr(MxParser::TernaryExprContext *ctx) {
    auto node = new ASTTernaryExprNode;
    node->cond = any_cast<ASTExprNode*>(visit(ctx->expression()[0]));
    node->True = any_cast<ASTExprNode*>(visit(ctx->expression()[1]));
    node->False = any_cast<ASTExprNode*>(visit(ctx->expression()[2]));
    return static_cast<ASTExprNode*>(node);
}

std::any ASTBuilder::visitAssignExpr(MxParser::AssignExprContext *ctx) {
    auto node = new ASTAssignExprNode;
    node->lhs = any_cast<ASTExprNode*>(visit(ctx->expression()[0]));
    node->rhs = any_cast<ASTExprNode*>(visit(ctx->expression()[1]));
    return static_cast<ASTExprNode*>(node);
}


std::any ASTBuilder::visitNewClass(MxParser::NewClassContext *ctx) {
    auto node = new ASTNewTypeNode;
    node->name = ctx->Identifier()->getText();
    node->dim = 0;
    return node;
}

std::any ASTBuilder::visitNewClassArray(MxParser::NewClassArrayContext *ctx) {
    auto node = new ASTNewTypeNode;
    node->name = ctx->Identifier()->getText();
    if (ctx->fail) throw std::exception();
    for (auto e: ctx->newArrayExpr()) {
        node->size.push_back(any_cast<ASTExprNode*>(visit(e)));
    }
    node->dim = ctx->newArrayExpr().size() + ctx->newArrayEmpty().size();
    return node;
}

std::any ASTBuilder::visitNewBasicArray(MxParser::NewBasicArrayContext *ctx) {
    auto node = new ASTNewTypeNode;
    node->name = ctx->basicType()->getText();
    if (ctx->fail) throw std::exception();
    for (auto e: ctx->newArrayExpr()) {
        node->size.push_back(any_cast<ASTExprNode*>(visit(e)));
    }
    node->dim = ctx->newArrayExpr().size() + ctx->newArrayEmpty().size();
    return node;
}

std::any ASTBuilder::visitNewArrayExpr(MxParser::NewArrayExprContext *ctx) {
    return visit(ctx->expression());
}


