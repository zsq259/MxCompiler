#include "MxParserBaseVisitor.h"

class ASTBuilder: public MxParserBaseVisitor {
private:
    virtual std::any visitProgram(MxParser::ProgramContext *ctx) override;
    virtual std::any visitClassDef(MxParser::ClassDefContext *ctx) override;
    // virtual std::any visitClassSuite(MxParser::ClassSuiteContext *ctx) override;
    virtual std::any visitConstructDef(MxParser::ConstructDefContext *ctx) override;
    virtual std::any visitFunctionDef(MxParser::FunctionDefContext *ctx) override;
    virtual std::any visitParameters(MxParser::ParametersContext *ctx) override;
    // virtual std::any visitVarDef(MxParser::VarDefContext *ctx) override;
    // virtual std::any visitVarDefInit(MxParser::VarDefInitContext *ctx) override;
    virtual std::any visitSuite(MxParser::SuiteContext *ctx) override;
    virtual std::any visitBlock(MxParser::BlockContext *ctx) override;
    // virtual std::any visitStmt(MxParser::StmtContext *ctx) override;
    virtual std::any visitExprStmt(MxParser::ExprStmtContext *ctx) override;
    // virtual std::any visitExprList(MxParser::ExprListContext *ctx) override;
    virtual std::any visitIfStmt(MxParser::IfStmtContext *ctx) override;
    virtual std::any visitWhileStmt(MxParser::WhileStmtContext *ctx) override;
    virtual std::any visitForStmt(MxParser::ForStmtContext *ctx) override;
    virtual std::any visitFlowStmt(MxParser::FlowStmtContext *ctx) override;
    virtual std::any visitArrayExpr(MxParser::ArrayExprContext *ctx) override;
    virtual std::any visitFunctionExpr(MxParser::FunctionExprContext *ctx) override;
    virtual std::any visitMemberExpr(MxParser::MemberExprContext *ctx) override;
    virtual std::any visitParentheseExpr(MxParser::ParentheseExprContext *ctx) override;
    virtual std::any visitLeftSingleExpr(MxParser::LeftSingleExprContext *ctx) override;
    virtual std::any visitBinaryExpr(MxParser::BinaryExprContext *ctx) override;
    virtual std::any visitNewExpr(MxParser::NewExprContext *ctx) override;
    virtual std::any visitLiterExpr(MxParser::LiterExprContext *ctx) override;
    virtual std::any visitRightSingleExpr(MxParser::RightSingleExprContext *ctx) override;
    virtual std::any visitAtomExpr(MxParser::AtomExprContext *ctx) override;
    virtual std::any visitTernaryExpr(MxParser::TernaryExprContext *ctx) override;
    virtual std::any visitAssignExpr(MxParser::AssignExprContext *ctx) override;
    virtual std::any visitVarDefStmt(MxParser::VarDefStmtContext *ctx) override;
    virtual std::any visitArray(MxParser::ArrayContext *ctx) override;
    virtual std::any visitBasic(MxParser::BasicContext *ctx) override;
    virtual std::any visitClass(MxParser::ClassContext *ctx) override;
    virtual std::any visitNewClass(MxParser::NewClassContext *ctx) override;
    virtual std::any visitNewClassArray(MxParser::NewClassArrayContext *ctx) override;
    virtual std::any visitNewBasicArray(MxParser::NewBasicArrayContext *ctx) override;
    virtual std::any visitNewArrayExpr(MxParser::NewArrayExprContext *ctx) override;
    // virtual std::any visitNewArrayEmpty(MxParser::NewArrayEmptyContext *ctx) override;
    virtual std::any visitLiteralExpr(MxParser::LiteralExprContext *ctx) override;
    // virtual std::any visitBasicType(MxParser::BasicTypeContext *ctx) override;


};