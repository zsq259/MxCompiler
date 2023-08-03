
// Generated from MxParser.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"
#include "MxParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by MxParser.
 */
class  MxParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by MxParser.
   */
    virtual std::any visitProgram(MxParser::ProgramContext *context) = 0;

    virtual std::any visitClassDef(MxParser::ClassDefContext *context) = 0;

    virtual std::any visitClassSuite(MxParser::ClassSuiteContext *context) = 0;

    virtual std::any visitConstructDef(MxParser::ConstructDefContext *context) = 0;

    virtual std::any visitFunctionDef(MxParser::FunctionDefContext *context) = 0;

    virtual std::any visitParameters(MxParser::ParametersContext *context) = 0;

    virtual std::any visitVarDef(MxParser::VarDefContext *context) = 0;

    virtual std::any visitSuite(MxParser::SuiteContext *context) = 0;

    virtual std::any visitBlock(MxParser::BlockContext *context) = 0;

    virtual std::any visitStmt(MxParser::StmtContext *context) = 0;

    virtual std::any visitExprStmt(MxParser::ExprStmtContext *context) = 0;

    virtual std::any visitExprList(MxParser::ExprListContext *context) = 0;

    virtual std::any visitIfStmt(MxParser::IfStmtContext *context) = 0;

    virtual std::any visitWhileStmt(MxParser::WhileStmtContext *context) = 0;

    virtual std::any visitForStmt(MxParser::ForStmtContext *context) = 0;

    virtual std::any visitFlowStmt(MxParser::FlowStmtContext *context) = 0;

    virtual std::any visitArrayExpr(MxParser::ArrayExprContext *context) = 0;

    virtual std::any visitFunctionExpr(MxParser::FunctionExprContext *context) = 0;

    virtual std::any visitMemberExpr(MxParser::MemberExprContext *context) = 0;

    virtual std::any visitParentheseExpr(MxParser::ParentheseExprContext *context) = 0;

    virtual std::any visitLeftSingleExpr(MxParser::LeftSingleExprContext *context) = 0;

    virtual std::any visitBinaryExpr(MxParser::BinaryExprContext *context) = 0;

    virtual std::any visitNewExpr(MxParser::NewExprContext *context) = 0;

    virtual std::any visitLiterExpr(MxParser::LiterExprContext *context) = 0;

    virtual std::any visitRightSingleExpr(MxParser::RightSingleExprContext *context) = 0;

    virtual std::any visitAtomExpr(MxParser::AtomExprContext *context) = 0;

    virtual std::any visitTernaryExpr(MxParser::TernaryExprContext *context) = 0;

    virtual std::any visitAssignExpr(MxParser::AssignExprContext *context) = 0;

    virtual std::any visitVarDefStmt(MxParser::VarDefStmtContext *context) = 0;

    virtual std::any visitVarDefInit(MxParser::VarDefInitContext *context) = 0;

    virtual std::any visitArray(MxParser::ArrayContext *context) = 0;

    virtual std::any visitBasic(MxParser::BasicContext *context) = 0;

    virtual std::any visitClass(MxParser::ClassContext *context) = 0;

    virtual std::any visitNewClass(MxParser::NewClassContext *context) = 0;

    virtual std::any visitNewClassArray(MxParser::NewClassArrayContext *context) = 0;

    virtual std::any visitNewBasicArray(MxParser::NewBasicArrayContext *context) = 0;

    virtual std::any visitNewArrayExpr(MxParser::NewArrayExprContext *context) = 0;

    virtual std::any visitNewArrayEmpty(MxParser::NewArrayEmptyContext *context) = 0;

    virtual std::any visitLiteralExpr(MxParser::LiteralExprContext *context) = 0;

    virtual std::any visitBasicType(MxParser::BasicTypeContext *context) = 0;


};

