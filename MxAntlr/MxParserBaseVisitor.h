
// Generated from MxParser.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "MxParserVisitor.h"


/**
 * This class provides an empty implementation of MxParserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  MxParserBaseVisitor : public MxParserVisitor {
public:

  virtual std::any visitProgram(MxParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassDef(MxParser::ClassDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClassSuite(MxParser::ClassSuiteContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitConstructDef(MxParser::ConstructDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionDef(MxParser::FunctionDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParameters(MxParser::ParametersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDef(MxParser::VarDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSuite(MxParser::SuiteContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBlock(MxParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitStmt(MxParser::StmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprStmt(MxParser::ExprStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExprList(MxParser::ExprListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIfStmt(MxParser::IfStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWhileStmt(MxParser::WhileStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitForStmt(MxParser::ForStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFlowStmt(MxParser::FlowStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArrayExpr(MxParser::ArrayExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFunctionExpr(MxParser::FunctionExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitMemberExpr(MxParser::MemberExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParentheseExpr(MxParser::ParentheseExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLeftSingleExpr(MxParser::LeftSingleExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBinaryExpr(MxParser::BinaryExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNewExpr(MxParser::NewExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLiterExpr(MxParser::LiterExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitRightSingleExpr(MxParser::RightSingleExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAtomExpr(MxParser::AtomExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTernaryExpr(MxParser::TernaryExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitAssignExpr(MxParser::AssignExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDefStmt(MxParser::VarDefStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitVarDefInit(MxParser::VarDefInitContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitArray(MxParser::ArrayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBasic(MxParser::BasicContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitClass(MxParser::ClassContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNewClass(MxParser::NewClassContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNewClassArray(MxParser::NewClassArrayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNewBasicArray(MxParser::NewBasicArrayContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNewArrayExpr(MxParser::NewArrayExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNewArrayEmpty(MxParser::NewArrayEmptyContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitLiteralExpr(MxParser::LiteralExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitBasicType(MxParser::BasicTypeContext *ctx) override {
    return visitChildren(ctx);
  }


};

