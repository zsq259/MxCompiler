
// Generated from MxParser.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  MxParser : public antlr4::Parser {
public:
  enum {
    Comment = 1, BlockComment = 2, LineComment = 3, Add = 4, Sub = 5, Mul = 6, 
    Div = 7, Mod = 8, Gt = 9, Lt = 10, Geq = 11, Leq = 12, Neq = 13, Eq = 14, 
    And = 15, Or = 16, Not = 17, Rs = 18, Ls = 19, BitAnd = 20, BitOr = 21, 
    BitXor = 22, BitInv = 23, Assign = 24, Incre = 25, Decre = 26, Dot = 27, 
    Ques = 28, Colon = 29, LeftBracket = 30, RightBracket = 31, LeftParen = 32, 
    RightParen = 33, LeftBrace = 34, RightBrace = 35, Semicolon = 36, Comma = 37, 
    LogicalLiteral = 38, NumberLiteral = 39, StringLiteral = 40, NullLiteral = 41, 
    Void = 42, Bool = 43, Int = 44, String = 45, New = 46, Class = 47, Null = 48, 
    True = 49, False = 50, This = 51, ElseIf = 52, If = 53, Else = 54, For = 55, 
    While = 56, Break = 57, Continue = 58, Return = 59, Identifier = 60, 
    Whitespace = 61, NewLine = 62
  };

  enum {
    RuleProgram = 0, RuleClassDef = 1, RuleClassSuite = 2, RuleConstructDef = 3, 
    RuleFunctionDef = 4, RuleParameters = 5, RuleVarDef = 6, RuleSuite = 7, 
    RuleBlock = 8, RuleStmt = 9, RuleExprStmt = 10, RuleExprList = 11, RuleIfStmt = 12, 
    RuleWhileStmt = 13, RuleForStmt = 14, RuleFlowStmt = 15, RuleExpression = 16, 
    RuleVarDefStmt = 17, RuleVarDefInit = 18, RuleTypeName = 19, RuleNewTypeName = 20, 
    RuleNewArrayExpr = 21, RuleNewArrayEmpty = 22, RuleLiteralExpr = 23, 
    RuleBasicType = 24
  };

  explicit MxParser(antlr4::TokenStream *input);

  MxParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~MxParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class ProgramContext;
  class ClassDefContext;
  class ClassSuiteContext;
  class ConstructDefContext;
  class FunctionDefContext;
  class ParametersContext;
  class VarDefContext;
  class SuiteContext;
  class BlockContext;
  class StmtContext;
  class ExprStmtContext;
  class ExprListContext;
  class IfStmtContext;
  class WhileStmtContext;
  class ForStmtContext;
  class FlowStmtContext;
  class ExpressionContext;
  class VarDefStmtContext;
  class VarDefInitContext;
  class TypeNameContext;
  class NewTypeNameContext;
  class NewArrayExprContext;
  class NewArrayEmptyContext;
  class LiteralExprContext;
  class BasicTypeContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<FunctionDefContext *> functionDef();
    FunctionDefContext* functionDef(size_t i);
    std::vector<ClassDefContext *> classDef();
    ClassDefContext* classDef(size_t i);
    std::vector<VarDefStmtContext *> varDefStmt();
    VarDefStmtContext* varDefStmt(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  ClassDefContext : public antlr4::ParserRuleContext {
  public:
    ClassDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Class();
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *LeftBrace();
    antlr4::tree::TerminalNode *RightBrace();
    antlr4::tree::TerminalNode *Semicolon();
    std::vector<ClassSuiteContext *> classSuite();
    ClassSuiteContext* classSuite(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassDefContext* classDef();

  class  ClassSuiteContext : public antlr4::ParserRuleContext {
  public:
    ClassSuiteContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VarDefStmtContext *varDefStmt();
    ConstructDefContext *constructDef();
    FunctionDefContext *functionDef();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ClassSuiteContext* classSuite();

  class  ConstructDefContext : public antlr4::ParserRuleContext {
  public:
    ConstructDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *LeftParen();
    antlr4::tree::TerminalNode *RightParen();
    BlockContext *block();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstructDefContext* constructDef();

  class  FunctionDefContext : public antlr4::ParserRuleContext {
  public:
    FunctionDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeNameContext *typeName();
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *LeftParen();
    antlr4::tree::TerminalNode *RightParen();
    BlockContext *block();
    ParametersContext *parameters();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionDefContext* functionDef();

  class  ParametersContext : public antlr4::ParserRuleContext {
  public:
    ParametersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<VarDefContext *> varDef();
    VarDefContext* varDef(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParametersContext* parameters();

  class  VarDefContext : public antlr4::ParserRuleContext {
  public:
    VarDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeNameContext *typeName();
    antlr4::tree::TerminalNode *Identifier();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarDefContext* varDef();

  class  SuiteContext : public antlr4::ParserRuleContext {
  public:
    SuiteContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    BlockContext *block();
    StmtContext *stmt();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SuiteContext* suite();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LeftBrace();
    antlr4::tree::TerminalNode *RightBrace();
    std::vector<StmtContext *> stmt();
    StmtContext* stmt(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block();

  class  StmtContext : public antlr4::ParserRuleContext {
  public:
    StmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExprStmtContext *exprStmt();
    IfStmtContext *ifStmt();
    WhileStmtContext *whileStmt();
    ForStmtContext *forStmt();
    FlowStmtContext *flowStmt();
    VarDefStmtContext *varDefStmt();
    BlockContext *block();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StmtContext* stmt();

  class  ExprStmtContext : public antlr4::ParserRuleContext {
  public:
    ExprStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Semicolon();
    ExprListContext *exprList();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExprStmtContext* exprStmt();

  class  ExprListContext : public antlr4::ParserRuleContext {
  public:
    ExprListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExprListContext* exprList();

  class  IfStmtContext : public antlr4::ParserRuleContext {
  public:
    IfStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *If();
    std::vector<antlr4::tree::TerminalNode *> LeftParen();
    antlr4::tree::TerminalNode* LeftParen(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> RightParen();
    antlr4::tree::TerminalNode* RightParen(size_t i);
    std::vector<SuiteContext *> suite();
    SuiteContext* suite(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ElseIf();
    antlr4::tree::TerminalNode* ElseIf(size_t i);
    antlr4::tree::TerminalNode *Else();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IfStmtContext* ifStmt();

  class  WhileStmtContext : public antlr4::ParserRuleContext {
  public:
    WhileStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *While();
    antlr4::tree::TerminalNode *LeftParen();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RightParen();
    SuiteContext *suite();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WhileStmtContext* whileStmt();

  class  ForStmtContext : public antlr4::ParserRuleContext {
  public:
    MxParser::ExpressionContext *condition = nullptr;
    MxParser::ExpressionContext *step = nullptr;
    ForStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *For();
    antlr4::tree::TerminalNode *LeftParen();
    antlr4::tree::TerminalNode *Semicolon();
    antlr4::tree::TerminalNode *RightParen();
    SuiteContext *suite();
    ExprStmtContext *exprStmt();
    VarDefStmtContext *varDefStmt();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForStmtContext* forStmt();

  class  FlowStmtContext : public antlr4::ParserRuleContext {
  public:
    FlowStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Semicolon();
    antlr4::tree::TerminalNode *Continue();
    antlr4::tree::TerminalNode *Break();
    antlr4::tree::TerminalNode *Return();
    ExpressionContext *expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FlowStmtContext* flowStmt();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExpressionContext() = default;
    void copyFrom(ExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ArrayExprContext : public ExpressionContext {
  public:
    ArrayExprContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *LeftBracket();
    antlr4::tree::TerminalNode *RightBracket();
    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FunctionExprContext : public ExpressionContext {
  public:
    FunctionExprContext(ExpressionContext *ctx);

    ExpressionContext *expression();
    antlr4::tree::TerminalNode *LeftParen();
    antlr4::tree::TerminalNode *RightParen();
    ExprListContext *exprList();
    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MemberExprContext : public ExpressionContext {
  public:
    MemberExprContext(ExpressionContext *ctx);

    ExpressionContext *expression();
    antlr4::tree::TerminalNode *Dot();
    antlr4::tree::TerminalNode *Identifier();
    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParentheseExprContext : public ExpressionContext {
  public:
    ParentheseExprContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *LeftParen();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RightParen();
    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LeftSingleExprContext : public ExpressionContext {
  public:
    LeftSingleExprContext(ExpressionContext *ctx);

    antlr4::Token *op = nullptr;
    MxParser::ExpressionContext *rhs = nullptr;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *Incre();
    antlr4::tree::TerminalNode *Decre();
    antlr4::tree::TerminalNode *Not();
    antlr4::tree::TerminalNode *BitInv();
    antlr4::tree::TerminalNode *Sub();
    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BinaryExprContext : public ExpressionContext {
  public:
    BinaryExprContext(ExpressionContext *ctx);

    MxParser::ExpressionContext *lhs = nullptr;
    antlr4::Token *op = nullptr;
    MxParser::ExpressionContext *rhs = nullptr;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *Mul();
    antlr4::tree::TerminalNode *Div();
    antlr4::tree::TerminalNode *Mod();
    antlr4::tree::TerminalNode *Add();
    antlr4::tree::TerminalNode *Sub();
    antlr4::tree::TerminalNode *Rs();
    antlr4::tree::TerminalNode *Ls();
    antlr4::tree::TerminalNode *Geq();
    antlr4::tree::TerminalNode *Leq();
    antlr4::tree::TerminalNode *Lt();
    antlr4::tree::TerminalNode *Gt();
    antlr4::tree::TerminalNode *Neq();
    antlr4::tree::TerminalNode *Eq();
    antlr4::tree::TerminalNode *BitAnd();
    antlr4::tree::TerminalNode *BitXor();
    antlr4::tree::TerminalNode *BitOr();
    antlr4::tree::TerminalNode *And();
    antlr4::tree::TerminalNode *Or();
    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NewExprContext : public ExpressionContext {
  public:
    NewExprContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *New();
    NewTypeNameContext *newTypeName();
    antlr4::tree::TerminalNode *LeftParen();
    antlr4::tree::TerminalNode *RightParen();
    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LiterExprContext : public ExpressionContext {
  public:
    LiterExprContext(ExpressionContext *ctx);

    LiteralExprContext *literalExpr();
    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  RightSingleExprContext : public ExpressionContext {
  public:
    RightSingleExprContext(ExpressionContext *ctx);

    MxParser::ExpressionContext *lhs = nullptr;
    antlr4::Token *op = nullptr;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *Incre();
    antlr4::tree::TerminalNode *Decre();
    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AtomExprContext : public ExpressionContext {
  public:
    AtomExprContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *This();
    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TernaryExprContext : public ExpressionContext {
  public:
    TernaryExprContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *Ques();
    antlr4::tree::TerminalNode *Colon();
    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AssignExprContext : public ExpressionContext {
  public:
    AssignExprContext(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *Assign();
    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  VarDefStmtContext : public antlr4::ParserRuleContext {
  public:
    VarDefStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeNameContext *typeName();
    std::vector<VarDefInitContext *> varDefInit();
    VarDefInitContext* varDefInit(size_t i);
    antlr4::tree::TerminalNode *Semicolon();
    std::vector<antlr4::tree::TerminalNode *> Comma();
    antlr4::tree::TerminalNode* Comma(size_t i);

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarDefStmtContext* varDefStmt();

  class  VarDefInitContext : public antlr4::ParserRuleContext {
  public:
    VarDefInitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Identifier();
    antlr4::tree::TerminalNode *Assign();
    ExpressionContext *expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarDefInitContext* varDefInit();

  class  TypeNameContext : public antlr4::ParserRuleContext {
  public:
    TypeNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    TypeNameContext() = default;
    void copyFrom(TypeNameContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ArrayContext : public TypeNameContext {
  public:
    ArrayContext(TypeNameContext *ctx);

    TypeNameContext *typeName();
    antlr4::tree::TerminalNode *LeftBracket();
    antlr4::tree::TerminalNode *RightBracket();
    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BasicContext : public TypeNameContext {
  public:
    BasicContext(TypeNameContext *ctx);

    BasicTypeContext *basicType();
    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ClassContext : public TypeNameContext {
  public:
    ClassContext(TypeNameContext *ctx);

    antlr4::tree::TerminalNode *Identifier();
    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  TypeNameContext* typeName();
  TypeNameContext* typeName(int precedence);
  class  NewTypeNameContext : public antlr4::ParserRuleContext {
  public:
    NewTypeNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    NewTypeNameContext() = default;
    void copyFrom(NewTypeNameContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  NewBasicArrayContext : public NewTypeNameContext {
  public:
    NewBasicArrayContext(NewTypeNameContext *ctx);

    MxParser::NewArrayExprContext *good = nullptr;
    MxParser::NewArrayExprContext *fail = nullptr;
    BasicTypeContext *basicType();
    std::vector<NewArrayEmptyContext *> newArrayEmpty();
    NewArrayEmptyContext* newArrayEmpty(size_t i);
    std::vector<NewArrayExprContext *> newArrayExpr();
    NewArrayExprContext* newArrayExpr(size_t i);
    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NewClassContext : public NewTypeNameContext {
  public:
    NewClassContext(NewTypeNameContext *ctx);

    antlr4::tree::TerminalNode *Identifier();
    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NewClassArrayContext : public NewTypeNameContext {
  public:
    NewClassArrayContext(NewTypeNameContext *ctx);

    MxParser::NewArrayExprContext *good = nullptr;
    MxParser::NewArrayExprContext *fail = nullptr;
    antlr4::tree::TerminalNode *Identifier();
    std::vector<NewArrayEmptyContext *> newArrayEmpty();
    NewArrayEmptyContext* newArrayEmpty(size_t i);
    std::vector<NewArrayExprContext *> newArrayExpr();
    NewArrayExprContext* newArrayExpr(size_t i);
    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  NewTypeNameContext* newTypeName();

  class  NewArrayExprContext : public antlr4::ParserRuleContext {
  public:
    NewArrayExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LeftBracket();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RightBracket();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NewArrayExprContext* newArrayExpr();

  class  NewArrayEmptyContext : public antlr4::ParserRuleContext {
  public:
    NewArrayEmptyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LeftBracket();
    antlr4::tree::TerminalNode *RightBracket();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NewArrayEmptyContext* newArrayEmpty();

  class  LiteralExprContext : public antlr4::ParserRuleContext {
  public:
    LiteralExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NumberLiteral();
    antlr4::tree::TerminalNode *StringLiteral();
    antlr4::tree::TerminalNode *NullLiteral();
    antlr4::tree::TerminalNode *LogicalLiteral();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LiteralExprContext* literalExpr();

  class  BasicTypeContext : public antlr4::ParserRuleContext {
  public:
    BasicTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Bool();
    antlr4::tree::TerminalNode *Int();
    antlr4::tree::TerminalNode *String();
    antlr4::tree::TerminalNode *Void();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BasicTypeContext* basicType();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);
  bool typeNameSempred(TypeNameContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

