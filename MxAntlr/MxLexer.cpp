
// Generated from MxLexer.g4 by ANTLR 4.13.0


#include "MxLexer.h"


using namespace antlr4;


using namespace antlr4;

namespace {

struct MxLexerStaticData final {
  MxLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  MxLexerStaticData(const MxLexerStaticData&) = delete;
  MxLexerStaticData(MxLexerStaticData&&) = delete;
  MxLexerStaticData& operator=(const MxLexerStaticData&) = delete;
  MxLexerStaticData& operator=(MxLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag mxlexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
MxLexerStaticData *mxlexerLexerStaticData = nullptr;

void mxlexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (mxlexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(mxlexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<MxLexerStaticData>(
    std::vector<std::string>{
      "Comment", "BlockComment", "LineComment", "Add", "Sub", "Mul", "Div", 
      "Mod", "Gt", "Lt", "Geq", "Leq", "Neq", "Eq", "And", "Or", "Not", 
      "Rs", "Ls", "BitAnd", "BitOr", "BitXor", "BitInv", "Assign", "Incre", 
      "Decre", "Dot", "Ques", "Colon", "LeftBracket", "RightBracket", "LeftParen", 
      "RightParen", "LeftBrace", "RightBrace", "Semicolon", "Comma", "EscapeChar", 
      "LogicalLiteral", "NumberLiteral", "StringLiteral", "NullLiteral", 
      "Void", "Bool", "Int", "String", "New", "Class", "Null", "True", "False", 
      "This", "ElseIf", "If", "Else", "For", "While", "Break", "Continue", 
      "Return", "Digit", "Letter", "Identifier", "Whitespace", "NewLine"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "", "", "", "'+'", "'-'", "'*'", "'/'", "'%'", "'>'", "'<'", "'>='", 
      "'<='", "'!='", "'=='", "'&&'", "'||'", "'!'", "'>>'", "'<<'", "'&'", 
      "'|'", "'^'", "'~'", "'='", "'++'", "'--'", "'.'", "'\\u003F'", "':'", 
      "'['", "']'", "'('", "')'", "'{'", "'}'", "';'", "','", "", "", "", 
      "", "'void'", "'bool'", "'int'", "'string'", "'new'", "'class'", "'null'", 
      "'true'", "'false'", "'this'", "", "'if'", "'else'", "'for'", "'while'", 
      "'break'", "'continue'", "'return'"
    },
    std::vector<std::string>{
      "", "Comment", "BlockComment", "LineComment", "Add", "Sub", "Mul", 
      "Div", "Mod", "Gt", "Lt", "Geq", "Leq", "Neq", "Eq", "And", "Or", 
      "Not", "Rs", "Ls", "BitAnd", "BitOr", "BitXor", "BitInv", "Assign", 
      "Incre", "Decre", "Dot", "Ques", "Colon", "LeftBracket", "RightBracket", 
      "LeftParen", "RightParen", "LeftBrace", "RightBrace", "Semicolon", 
      "Comma", "LogicalLiteral", "NumberLiteral", "StringLiteral", "NullLiteral", 
      "Void", "Bool", "Int", "String", "New", "Class", "Null", "True", "False", 
      "This", "ElseIf", "If", "Else", "For", "While", "Break", "Continue", 
      "Return", "Identifier", "Whitespace", "NewLine"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,62,399,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,
  	7,42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,
  	7,49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,2,56,
  	7,56,2,57,7,57,2,58,7,58,2,59,7,59,2,60,7,60,2,61,7,61,2,62,7,62,2,63,
  	7,63,2,64,7,64,1,0,1,0,3,0,134,8,0,1,0,1,0,1,1,1,1,1,1,1,1,5,1,142,8,
  	1,10,1,12,1,145,9,1,1,1,1,1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,5,2,156,8,2,10,
  	2,12,2,159,9,2,1,2,1,2,3,2,163,8,2,1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,1,
  	6,1,6,1,7,1,7,1,8,1,8,1,9,1,9,1,10,1,10,1,10,1,11,1,11,1,11,1,12,1,12,
  	1,12,1,13,1,13,1,13,1,14,1,14,1,14,1,15,1,15,1,15,1,16,1,16,1,17,1,17,
  	1,17,1,18,1,18,1,18,1,19,1,19,1,20,1,20,1,21,1,21,1,22,1,22,1,23,1,23,
  	1,24,1,24,1,24,1,25,1,25,1,25,1,26,1,26,1,27,1,27,1,28,1,28,1,29,1,29,
  	1,30,1,30,1,31,1,31,1,32,1,32,1,33,1,33,1,34,1,34,1,35,1,35,1,36,1,36,
  	1,37,1,37,1,37,1,37,1,37,1,37,1,37,1,37,3,37,253,8,37,1,38,1,38,3,38,
  	257,8,38,1,39,1,39,5,39,261,8,39,10,39,12,39,264,9,39,1,39,3,39,267,8,
  	39,1,40,1,40,1,40,5,40,272,8,40,10,40,12,40,275,9,40,1,40,1,40,1,41,1,
  	41,1,42,1,42,1,42,1,42,1,42,1,43,1,43,1,43,1,43,1,43,1,44,1,44,1,44,1,
  	44,1,45,1,45,1,45,1,45,1,45,1,45,1,45,1,46,1,46,1,46,1,46,1,47,1,47,1,
  	47,1,47,1,47,1,47,1,48,1,48,1,48,1,48,1,48,1,49,1,49,1,49,1,49,1,49,1,
  	50,1,50,1,50,1,50,1,50,1,50,1,51,1,51,1,51,1,51,1,51,1,52,1,52,1,52,1,
  	52,1,53,1,53,1,53,1,54,1,54,1,54,1,54,1,54,1,55,1,55,1,55,1,55,1,56,1,
  	56,1,56,1,56,1,56,1,56,1,57,1,57,1,57,1,57,1,57,1,57,1,58,1,58,1,58,1,
  	58,1,58,1,58,1,58,1,58,1,58,1,59,1,59,1,59,1,59,1,59,1,59,1,59,1,60,1,
  	60,1,61,1,61,1,62,1,62,1,62,1,62,5,62,385,8,62,10,62,12,62,388,9,62,1,
  	63,1,63,3,63,392,8,63,1,63,1,63,1,64,1,64,1,64,1,64,3,143,157,273,0,65,
  	1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,25,13,27,14,
  	29,15,31,16,33,17,35,18,37,19,39,20,41,21,43,22,45,23,47,24,49,25,51,
  	26,53,27,55,28,57,29,59,30,61,31,63,32,65,33,67,34,69,35,71,36,73,37,
  	75,0,77,38,79,39,81,40,83,41,85,42,87,43,89,44,91,45,93,46,95,47,97,48,
  	99,49,101,50,103,51,105,52,107,53,109,54,111,55,113,56,115,57,117,58,
  	119,59,121,0,123,0,125,60,127,61,129,62,1,0,5,1,0,49,57,1,0,48,57,2,0,
  	65,90,97,122,4,0,9,9,11,12,32,32,160,160,3,0,10,10,13,13,8232,8233,411,
  	0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,
  	0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,
  	0,23,1,0,0,0,0,25,1,0,0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,
  	1,0,0,0,0,35,1,0,0,0,0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,
  	0,0,0,45,1,0,0,0,0,47,1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,
  	0,55,1,0,0,0,0,57,1,0,0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,0,65,
  	1,0,0,0,0,67,1,0,0,0,0,69,1,0,0,0,0,71,1,0,0,0,0,73,1,0,0,0,0,77,1,0,
  	0,0,0,79,1,0,0,0,0,81,1,0,0,0,0,83,1,0,0,0,0,85,1,0,0,0,0,87,1,0,0,0,
  	0,89,1,0,0,0,0,91,1,0,0,0,0,93,1,0,0,0,0,95,1,0,0,0,0,97,1,0,0,0,0,99,
  	1,0,0,0,0,101,1,0,0,0,0,103,1,0,0,0,0,105,1,0,0,0,0,107,1,0,0,0,0,109,
  	1,0,0,0,0,111,1,0,0,0,0,113,1,0,0,0,0,115,1,0,0,0,0,117,1,0,0,0,0,119,
  	1,0,0,0,0,125,1,0,0,0,0,127,1,0,0,0,0,129,1,0,0,0,1,133,1,0,0,0,3,137,
  	1,0,0,0,5,151,1,0,0,0,7,166,1,0,0,0,9,168,1,0,0,0,11,170,1,0,0,0,13,172,
  	1,0,0,0,15,174,1,0,0,0,17,176,1,0,0,0,19,178,1,0,0,0,21,180,1,0,0,0,23,
  	183,1,0,0,0,25,186,1,0,0,0,27,189,1,0,0,0,29,192,1,0,0,0,31,195,1,0,0,
  	0,33,198,1,0,0,0,35,200,1,0,0,0,37,203,1,0,0,0,39,206,1,0,0,0,41,208,
  	1,0,0,0,43,210,1,0,0,0,45,212,1,0,0,0,47,214,1,0,0,0,49,216,1,0,0,0,51,
  	219,1,0,0,0,53,222,1,0,0,0,55,224,1,0,0,0,57,226,1,0,0,0,59,228,1,0,0,
  	0,61,230,1,0,0,0,63,232,1,0,0,0,65,234,1,0,0,0,67,236,1,0,0,0,69,238,
  	1,0,0,0,71,240,1,0,0,0,73,242,1,0,0,0,75,252,1,0,0,0,77,256,1,0,0,0,79,
  	266,1,0,0,0,81,268,1,0,0,0,83,278,1,0,0,0,85,280,1,0,0,0,87,285,1,0,0,
  	0,89,290,1,0,0,0,91,294,1,0,0,0,93,301,1,0,0,0,95,305,1,0,0,0,97,311,
  	1,0,0,0,99,316,1,0,0,0,101,321,1,0,0,0,103,327,1,0,0,0,105,332,1,0,0,
  	0,107,336,1,0,0,0,109,339,1,0,0,0,111,344,1,0,0,0,113,348,1,0,0,0,115,
  	354,1,0,0,0,117,360,1,0,0,0,119,369,1,0,0,0,121,376,1,0,0,0,123,378,1,
  	0,0,0,125,380,1,0,0,0,127,391,1,0,0,0,129,395,1,0,0,0,131,134,3,3,1,0,
  	132,134,3,5,2,0,133,131,1,0,0,0,133,132,1,0,0,0,134,135,1,0,0,0,135,136,
  	6,0,0,0,136,2,1,0,0,0,137,138,5,47,0,0,138,139,5,42,0,0,139,143,1,0,0,
  	0,140,142,9,0,0,0,141,140,1,0,0,0,142,145,1,0,0,0,143,144,1,0,0,0,143,
  	141,1,0,0,0,144,146,1,0,0,0,145,143,1,0,0,0,146,147,5,42,0,0,147,148,
  	5,47,0,0,148,149,1,0,0,0,149,150,6,1,0,0,150,4,1,0,0,0,151,152,5,47,0,
  	0,152,153,5,47,0,0,153,157,1,0,0,0,154,156,9,0,0,0,155,154,1,0,0,0,156,
  	159,1,0,0,0,157,158,1,0,0,0,157,155,1,0,0,0,158,162,1,0,0,0,159,157,1,
  	0,0,0,160,163,3,129,64,0,161,163,5,0,0,1,162,160,1,0,0,0,162,161,1,0,
  	0,0,163,164,1,0,0,0,164,165,6,2,0,0,165,6,1,0,0,0,166,167,5,43,0,0,167,
  	8,1,0,0,0,168,169,5,45,0,0,169,10,1,0,0,0,170,171,5,42,0,0,171,12,1,0,
  	0,0,172,173,5,47,0,0,173,14,1,0,0,0,174,175,5,37,0,0,175,16,1,0,0,0,176,
  	177,5,62,0,0,177,18,1,0,0,0,178,179,5,60,0,0,179,20,1,0,0,0,180,181,5,
  	62,0,0,181,182,5,61,0,0,182,22,1,0,0,0,183,184,5,60,0,0,184,185,5,61,
  	0,0,185,24,1,0,0,0,186,187,5,33,0,0,187,188,5,61,0,0,188,26,1,0,0,0,189,
  	190,5,61,0,0,190,191,5,61,0,0,191,28,1,0,0,0,192,193,5,38,0,0,193,194,
  	5,38,0,0,194,30,1,0,0,0,195,196,5,124,0,0,196,197,5,124,0,0,197,32,1,
  	0,0,0,198,199,5,33,0,0,199,34,1,0,0,0,200,201,5,62,0,0,201,202,5,62,0,
  	0,202,36,1,0,0,0,203,204,5,60,0,0,204,205,5,60,0,0,205,38,1,0,0,0,206,
  	207,5,38,0,0,207,40,1,0,0,0,208,209,5,124,0,0,209,42,1,0,0,0,210,211,
  	5,94,0,0,211,44,1,0,0,0,212,213,5,126,0,0,213,46,1,0,0,0,214,215,5,61,
  	0,0,215,48,1,0,0,0,216,217,5,43,0,0,217,218,5,43,0,0,218,50,1,0,0,0,219,
  	220,5,45,0,0,220,221,5,45,0,0,221,52,1,0,0,0,222,223,5,46,0,0,223,54,
  	1,0,0,0,224,225,5,63,0,0,225,56,1,0,0,0,226,227,5,58,0,0,227,58,1,0,0,
  	0,228,229,5,91,0,0,229,60,1,0,0,0,230,231,5,93,0,0,231,62,1,0,0,0,232,
  	233,5,40,0,0,233,64,1,0,0,0,234,235,5,41,0,0,235,66,1,0,0,0,236,237,5,
  	123,0,0,237,68,1,0,0,0,238,239,5,125,0,0,239,70,1,0,0,0,240,241,5,59,
  	0,0,241,72,1,0,0,0,242,243,5,44,0,0,243,74,1,0,0,0,244,245,5,92,0,0,245,
  	253,5,92,0,0,246,247,5,92,0,0,247,253,5,110,0,0,248,249,5,92,0,0,249,
  	253,5,116,0,0,250,251,5,92,0,0,251,253,5,34,0,0,252,244,1,0,0,0,252,246,
  	1,0,0,0,252,248,1,0,0,0,252,250,1,0,0,0,253,76,1,0,0,0,254,257,3,99,49,
  	0,255,257,3,101,50,0,256,254,1,0,0,0,256,255,1,0,0,0,257,78,1,0,0,0,258,
  	262,7,0,0,0,259,261,3,121,60,0,260,259,1,0,0,0,261,264,1,0,0,0,262,260,
  	1,0,0,0,262,263,1,0,0,0,263,267,1,0,0,0,264,262,1,0,0,0,265,267,5,48,
  	0,0,266,258,1,0,0,0,266,265,1,0,0,0,267,80,1,0,0,0,268,273,5,34,0,0,269,
  	272,3,75,37,0,270,272,9,0,0,0,271,269,1,0,0,0,271,270,1,0,0,0,272,275,
  	1,0,0,0,273,274,1,0,0,0,273,271,1,0,0,0,274,276,1,0,0,0,275,273,1,0,0,
  	0,276,277,5,34,0,0,277,82,1,0,0,0,278,279,3,97,48,0,279,84,1,0,0,0,280,
  	281,5,118,0,0,281,282,5,111,0,0,282,283,5,105,0,0,283,284,5,100,0,0,284,
  	86,1,0,0,0,285,286,5,98,0,0,286,287,5,111,0,0,287,288,5,111,0,0,288,289,
  	5,108,0,0,289,88,1,0,0,0,290,291,5,105,0,0,291,292,5,110,0,0,292,293,
  	5,116,0,0,293,90,1,0,0,0,294,295,5,115,0,0,295,296,5,116,0,0,296,297,
  	5,114,0,0,297,298,5,105,0,0,298,299,5,110,0,0,299,300,5,103,0,0,300,92,
  	1,0,0,0,301,302,5,110,0,0,302,303,5,101,0,0,303,304,5,119,0,0,304,94,
  	1,0,0,0,305,306,5,99,0,0,306,307,5,108,0,0,307,308,5,97,0,0,308,309,5,
  	115,0,0,309,310,5,115,0,0,310,96,1,0,0,0,311,312,5,110,0,0,312,313,5,
  	117,0,0,313,314,5,108,0,0,314,315,5,108,0,0,315,98,1,0,0,0,316,317,5,
  	116,0,0,317,318,5,114,0,0,318,319,5,117,0,0,319,320,5,101,0,0,320,100,
  	1,0,0,0,321,322,5,102,0,0,322,323,5,97,0,0,323,324,5,108,0,0,324,325,
  	5,115,0,0,325,326,5,101,0,0,326,102,1,0,0,0,327,328,5,116,0,0,328,329,
  	5,104,0,0,329,330,5,105,0,0,330,331,5,115,0,0,331,104,1,0,0,0,332,333,
  	3,109,54,0,333,334,3,127,63,0,334,335,3,107,53,0,335,106,1,0,0,0,336,
  	337,5,105,0,0,337,338,5,102,0,0,338,108,1,0,0,0,339,340,5,101,0,0,340,
  	341,5,108,0,0,341,342,5,115,0,0,342,343,5,101,0,0,343,110,1,0,0,0,344,
  	345,5,102,0,0,345,346,5,111,0,0,346,347,5,114,0,0,347,112,1,0,0,0,348,
  	349,5,119,0,0,349,350,5,104,0,0,350,351,5,105,0,0,351,352,5,108,0,0,352,
  	353,5,101,0,0,353,114,1,0,0,0,354,355,5,98,0,0,355,356,5,114,0,0,356,
  	357,5,101,0,0,357,358,5,97,0,0,358,359,5,107,0,0,359,116,1,0,0,0,360,
  	361,5,99,0,0,361,362,5,111,0,0,362,363,5,110,0,0,363,364,5,116,0,0,364,
  	365,5,105,0,0,365,366,5,110,0,0,366,367,5,117,0,0,367,368,5,101,0,0,368,
  	118,1,0,0,0,369,370,5,114,0,0,370,371,5,101,0,0,371,372,5,116,0,0,372,
  	373,5,117,0,0,373,374,5,114,0,0,374,375,5,110,0,0,375,120,1,0,0,0,376,
  	377,7,1,0,0,377,122,1,0,0,0,378,379,7,2,0,0,379,124,1,0,0,0,380,386,3,
  	123,61,0,381,385,3,123,61,0,382,385,3,121,60,0,383,385,5,95,0,0,384,381,
  	1,0,0,0,384,382,1,0,0,0,384,383,1,0,0,0,385,388,1,0,0,0,386,384,1,0,0,
  	0,386,387,1,0,0,0,387,126,1,0,0,0,388,386,1,0,0,0,389,392,7,3,0,0,390,
  	392,3,129,64,0,391,389,1,0,0,0,391,390,1,0,0,0,392,393,1,0,0,0,393,394,
  	6,63,0,0,394,128,1,0,0,0,395,396,7,4,0,0,396,397,1,0,0,0,397,398,6,64,
  	0,0,398,130,1,0,0,0,14,0,133,143,157,162,252,256,262,266,271,273,384,
  	386,391,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  mxlexerLexerStaticData = staticData.release();
}

}

MxLexer::MxLexer(CharStream *input) : Lexer(input) {
  MxLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *mxlexerLexerStaticData->atn, mxlexerLexerStaticData->decisionToDFA, mxlexerLexerStaticData->sharedContextCache);
}

MxLexer::~MxLexer() {
  delete _interpreter;
}

std::string MxLexer::getGrammarFileName() const {
  return "MxLexer.g4";
}

const std::vector<std::string>& MxLexer::getRuleNames() const {
  return mxlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& MxLexer::getChannelNames() const {
  return mxlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& MxLexer::getModeNames() const {
  return mxlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& MxLexer::getVocabulary() const {
  return mxlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView MxLexer::getSerializedATN() const {
  return mxlexerLexerStaticData->serializedATN;
}

const atn::ATN& MxLexer::getATN() const {
  return *mxlexerLexerStaticData->atn;
}




void MxLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  mxlexerLexerInitialize();
#else
  ::antlr4::internal::call_once(mxlexerLexerOnceFlag, mxlexerLexerInitialize);
#endif
}
