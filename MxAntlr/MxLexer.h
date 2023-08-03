
// Generated from MxLexer.g4 by ANTLR 4.13.0

#pragma once


#include "antlr4-runtime.h"




class  MxLexer : public antlr4::Lexer {
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

  explicit MxLexer(antlr4::CharStream *input);

  ~MxLexer() override;


  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  // By default the static state used to implement the lexer is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:

  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

};

