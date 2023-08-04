
// Generated from MxParser.g4 by ANTLR 4.13.0


#include "MxParserVisitor.h"

#include "MxParser.h"


using namespace antlrcpp;
using namespace antlr4;

namespace {

struct MxParserStaticData final {
  MxParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  MxParserStaticData(const MxParserStaticData&) = delete;
  MxParserStaticData(MxParserStaticData&&) = delete;
  MxParserStaticData& operator=(const MxParserStaticData&) = delete;
  MxParserStaticData& operator=(MxParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag mxparserParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
MxParserStaticData *mxparserParserStaticData = nullptr;

void mxparserParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (mxparserParserStaticData != nullptr) {
    return;
  }
#else
  assert(mxparserParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<MxParserStaticData>(
    std::vector<std::string>{
      "program", "classDef", "classSuite", "constructDef", "functionDef", 
      "parameters", "varDef", "suite", "block", "stmt", "exprStmt", "exprList", 
      "ifStmt", "whileStmt", "forStmt", "flowStmt", "expression", "varDefStmt", 
      "varDefInit", "typeName", "newTypeName", "newArrayExpr", "newArrayEmpty", 
      "literalExpr", "basicType"
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
  	4,1,62,349,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,1,0,1,0,1,0,5,0,54,8,0,10,0,12,0,57,
  	9,0,1,0,1,0,1,1,1,1,1,1,1,1,5,1,65,8,1,10,1,12,1,68,9,1,1,1,1,1,1,1,1,
  	2,1,2,1,2,3,2,76,8,2,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,3,4,87,8,4,1,
  	4,1,4,1,4,1,5,1,5,1,5,5,5,95,8,5,10,5,12,5,98,9,5,1,6,1,6,1,6,1,7,1,7,
  	3,7,105,8,7,1,8,1,8,5,8,109,8,8,10,8,12,8,112,9,8,1,8,1,8,1,9,1,9,1,9,
  	1,9,1,9,1,9,1,9,3,9,123,8,9,1,10,3,10,126,8,10,1,10,1,10,1,11,1,11,1,
  	11,5,11,133,8,11,10,11,12,11,136,9,11,1,12,1,12,1,12,1,12,1,12,1,12,1,
  	12,1,12,1,12,1,12,1,12,5,12,149,8,12,10,12,12,12,152,9,12,1,12,1,12,3,
  	12,156,8,12,1,13,1,13,1,13,1,13,1,13,1,13,1,14,1,14,1,14,1,14,3,14,168,
  	8,14,1,14,3,14,171,8,14,1,14,1,14,3,14,175,8,14,1,14,1,14,1,14,1,15,1,
  	15,1,15,1,15,3,15,184,8,15,3,15,186,8,15,1,15,1,15,1,16,1,16,1,16,1,16,
  	1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,3,16,203,8,16,1,16,1,16,
  	3,16,207,8,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,
  	1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,
  	1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,
  	1,16,1,16,1,16,3,16,251,8,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,
  	1,16,1,16,1,16,5,16,264,8,16,10,16,12,16,267,9,16,1,17,1,17,1,17,1,17,
  	5,17,273,8,17,10,17,12,17,276,9,17,1,17,1,17,1,17,1,18,1,18,1,18,3,18,
  	284,8,18,1,19,1,19,1,19,3,19,289,8,19,1,19,1,19,1,19,5,19,294,8,19,10,
  	19,12,19,297,9,19,1,20,1,20,1,20,4,20,302,8,20,11,20,12,20,303,1,20,5,
  	20,307,8,20,10,20,12,20,310,9,20,1,20,5,20,313,8,20,10,20,12,20,316,9,
  	20,1,20,1,20,4,20,320,8,20,11,20,12,20,321,1,20,5,20,325,8,20,10,20,12,
  	20,328,9,20,1,20,5,20,331,8,20,10,20,12,20,334,9,20,3,20,336,8,20,1,21,
  	1,21,1,21,1,21,1,22,1,22,1,22,1,23,1,23,1,24,1,24,1,24,0,2,32,38,25,0,
  	2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,0,
  	10,1,0,25,26,3,0,5,5,17,17,23,23,2,0,51,51,60,60,1,0,6,8,1,0,4,5,1,0,
  	18,19,1,0,9,12,1,0,13,14,1,0,38,41,1,0,42,45,385,0,55,1,0,0,0,2,60,1,
  	0,0,0,4,75,1,0,0,0,6,77,1,0,0,0,8,82,1,0,0,0,10,91,1,0,0,0,12,99,1,0,
  	0,0,14,104,1,0,0,0,16,106,1,0,0,0,18,122,1,0,0,0,20,125,1,0,0,0,22,129,
  	1,0,0,0,24,137,1,0,0,0,26,157,1,0,0,0,28,163,1,0,0,0,30,185,1,0,0,0,32,
  	206,1,0,0,0,34,268,1,0,0,0,36,280,1,0,0,0,38,288,1,0,0,0,40,335,1,0,0,
  	0,42,337,1,0,0,0,44,341,1,0,0,0,46,344,1,0,0,0,48,346,1,0,0,0,50,54,3,
  	8,4,0,51,54,3,2,1,0,52,54,3,34,17,0,53,50,1,0,0,0,53,51,1,0,0,0,53,52,
  	1,0,0,0,54,57,1,0,0,0,55,53,1,0,0,0,55,56,1,0,0,0,56,58,1,0,0,0,57,55,
  	1,0,0,0,58,59,5,0,0,1,59,1,1,0,0,0,60,61,5,47,0,0,61,62,5,60,0,0,62,66,
  	5,34,0,0,63,65,3,4,2,0,64,63,1,0,0,0,65,68,1,0,0,0,66,64,1,0,0,0,66,67,
  	1,0,0,0,67,69,1,0,0,0,68,66,1,0,0,0,69,70,5,35,0,0,70,71,5,36,0,0,71,
  	3,1,0,0,0,72,76,3,34,17,0,73,76,3,6,3,0,74,76,3,8,4,0,75,72,1,0,0,0,75,
  	73,1,0,0,0,75,74,1,0,0,0,76,5,1,0,0,0,77,78,5,60,0,0,78,79,5,32,0,0,79,
  	80,5,33,0,0,80,81,3,16,8,0,81,7,1,0,0,0,82,83,3,38,19,0,83,84,5,60,0,
  	0,84,86,5,32,0,0,85,87,3,10,5,0,86,85,1,0,0,0,86,87,1,0,0,0,87,88,1,0,
  	0,0,88,89,5,33,0,0,89,90,3,16,8,0,90,9,1,0,0,0,91,96,3,12,6,0,92,93,5,
  	37,0,0,93,95,3,12,6,0,94,92,1,0,0,0,95,98,1,0,0,0,96,94,1,0,0,0,96,97,
  	1,0,0,0,97,11,1,0,0,0,98,96,1,0,0,0,99,100,3,38,19,0,100,101,5,60,0,0,
  	101,13,1,0,0,0,102,105,3,16,8,0,103,105,3,18,9,0,104,102,1,0,0,0,104,
  	103,1,0,0,0,105,15,1,0,0,0,106,110,5,34,0,0,107,109,3,18,9,0,108,107,
  	1,0,0,0,109,112,1,0,0,0,110,108,1,0,0,0,110,111,1,0,0,0,111,113,1,0,0,
  	0,112,110,1,0,0,0,113,114,5,35,0,0,114,17,1,0,0,0,115,123,3,20,10,0,116,
  	123,3,24,12,0,117,123,3,26,13,0,118,123,3,28,14,0,119,123,3,30,15,0,120,
  	123,3,34,17,0,121,123,3,16,8,0,122,115,1,0,0,0,122,116,1,0,0,0,122,117,
  	1,0,0,0,122,118,1,0,0,0,122,119,1,0,0,0,122,120,1,0,0,0,122,121,1,0,0,
  	0,123,19,1,0,0,0,124,126,3,22,11,0,125,124,1,0,0,0,125,126,1,0,0,0,126,
  	127,1,0,0,0,127,128,5,36,0,0,128,21,1,0,0,0,129,134,3,32,16,0,130,131,
  	5,37,0,0,131,133,3,32,16,0,132,130,1,0,0,0,133,136,1,0,0,0,134,132,1,
  	0,0,0,134,135,1,0,0,0,135,23,1,0,0,0,136,134,1,0,0,0,137,138,5,53,0,0,
  	138,139,5,32,0,0,139,140,3,32,16,0,140,141,5,33,0,0,141,150,3,14,7,0,
  	142,143,5,52,0,0,143,144,5,32,0,0,144,145,3,32,16,0,145,146,5,33,0,0,
  	146,147,3,14,7,0,147,149,1,0,0,0,148,142,1,0,0,0,149,152,1,0,0,0,150,
  	148,1,0,0,0,150,151,1,0,0,0,151,155,1,0,0,0,152,150,1,0,0,0,153,154,5,
  	54,0,0,154,156,3,14,7,0,155,153,1,0,0,0,155,156,1,0,0,0,156,25,1,0,0,
  	0,157,158,5,56,0,0,158,159,5,32,0,0,159,160,3,32,16,0,160,161,5,33,0,
  	0,161,162,3,14,7,0,162,27,1,0,0,0,163,164,5,55,0,0,164,167,5,32,0,0,165,
  	168,3,20,10,0,166,168,3,34,17,0,167,165,1,0,0,0,167,166,1,0,0,0,167,168,
  	1,0,0,0,168,170,1,0,0,0,169,171,3,32,16,0,170,169,1,0,0,0,170,171,1,0,
  	0,0,171,172,1,0,0,0,172,174,5,36,0,0,173,175,3,32,16,0,174,173,1,0,0,
  	0,174,175,1,0,0,0,175,176,1,0,0,0,176,177,5,33,0,0,177,178,3,14,7,0,178,
  	29,1,0,0,0,179,186,5,58,0,0,180,186,5,57,0,0,181,183,5,59,0,0,182,184,
  	3,32,16,0,183,182,1,0,0,0,183,184,1,0,0,0,184,186,1,0,0,0,185,179,1,0,
  	0,0,185,180,1,0,0,0,185,181,1,0,0,0,186,187,1,0,0,0,187,188,5,36,0,0,
  	188,31,1,0,0,0,189,190,6,16,-1,0,190,191,5,32,0,0,191,192,3,32,16,0,192,
  	193,5,33,0,0,193,207,1,0,0,0,194,195,7,0,0,0,195,207,3,32,16,17,196,197,
  	7,1,0,0,197,207,3,32,16,16,198,199,5,46,0,0,199,202,3,40,20,0,200,201,
  	5,32,0,0,201,203,5,33,0,0,202,200,1,0,0,0,202,203,1,0,0,0,203,207,1,0,
  	0,0,204,207,3,46,23,0,205,207,7,2,0,0,206,189,1,0,0,0,206,194,1,0,0,0,
  	206,196,1,0,0,0,206,198,1,0,0,0,206,204,1,0,0,0,206,205,1,0,0,0,207,265,
  	1,0,0,0,208,209,10,14,0,0,209,210,7,3,0,0,210,264,3,32,16,15,211,212,
  	10,13,0,0,212,213,7,4,0,0,213,264,3,32,16,14,214,215,10,12,0,0,215,216,
  	7,5,0,0,216,264,3,32,16,13,217,218,10,11,0,0,218,219,7,6,0,0,219,264,
  	3,32,16,12,220,221,10,10,0,0,221,222,7,7,0,0,222,264,3,32,16,11,223,224,
  	10,9,0,0,224,225,5,20,0,0,225,264,3,32,16,10,226,227,10,8,0,0,227,228,
  	5,22,0,0,228,264,3,32,16,9,229,230,10,7,0,0,230,231,5,21,0,0,231,264,
  	3,32,16,8,232,233,10,6,0,0,233,234,5,15,0,0,234,264,3,32,16,7,235,236,
  	10,5,0,0,236,237,5,16,0,0,237,264,3,32,16,6,238,239,10,4,0,0,239,240,
  	5,28,0,0,240,241,3,32,16,0,241,242,5,29,0,0,242,243,3,32,16,4,243,264,
  	1,0,0,0,244,245,10,3,0,0,245,246,5,24,0,0,246,264,3,32,16,3,247,248,10,
  	21,0,0,248,250,5,32,0,0,249,251,3,22,11,0,250,249,1,0,0,0,250,251,1,0,
  	0,0,251,252,1,0,0,0,252,264,5,33,0,0,253,254,10,20,0,0,254,255,5,30,0,
  	0,255,256,3,32,16,0,256,257,5,31,0,0,257,264,1,0,0,0,258,259,10,19,0,
  	0,259,260,5,27,0,0,260,264,5,60,0,0,261,262,10,18,0,0,262,264,7,0,0,0,
  	263,208,1,0,0,0,263,211,1,0,0,0,263,214,1,0,0,0,263,217,1,0,0,0,263,220,
  	1,0,0,0,263,223,1,0,0,0,263,226,1,0,0,0,263,229,1,0,0,0,263,232,1,0,0,
  	0,263,235,1,0,0,0,263,238,1,0,0,0,263,244,1,0,0,0,263,247,1,0,0,0,263,
  	253,1,0,0,0,263,258,1,0,0,0,263,261,1,0,0,0,264,267,1,0,0,0,265,263,1,
  	0,0,0,265,266,1,0,0,0,266,33,1,0,0,0,267,265,1,0,0,0,268,274,3,38,19,
  	0,269,270,3,36,18,0,270,271,5,37,0,0,271,273,1,0,0,0,272,269,1,0,0,0,
  	273,276,1,0,0,0,274,272,1,0,0,0,274,275,1,0,0,0,275,277,1,0,0,0,276,274,
  	1,0,0,0,277,278,3,36,18,0,278,279,5,36,0,0,279,35,1,0,0,0,280,283,5,60,
  	0,0,281,282,5,24,0,0,282,284,3,32,16,0,283,281,1,0,0,0,283,284,1,0,0,
  	0,284,37,1,0,0,0,285,286,6,19,-1,0,286,289,3,48,24,0,287,289,5,60,0,0,
  	288,285,1,0,0,0,288,287,1,0,0,0,289,295,1,0,0,0,290,291,10,1,0,0,291,
  	292,5,30,0,0,292,294,5,31,0,0,293,290,1,0,0,0,294,297,1,0,0,0,295,293,
  	1,0,0,0,295,296,1,0,0,0,296,39,1,0,0,0,297,295,1,0,0,0,298,336,5,60,0,
  	0,299,301,5,60,0,0,300,302,3,42,21,0,301,300,1,0,0,0,302,303,1,0,0,0,
  	303,301,1,0,0,0,303,304,1,0,0,0,304,308,1,0,0,0,305,307,3,44,22,0,306,
  	305,1,0,0,0,307,310,1,0,0,0,308,306,1,0,0,0,308,309,1,0,0,0,309,314,1,
  	0,0,0,310,308,1,0,0,0,311,313,3,42,21,0,312,311,1,0,0,0,313,316,1,0,0,
  	0,314,312,1,0,0,0,314,315,1,0,0,0,315,336,1,0,0,0,316,314,1,0,0,0,317,
  	319,3,48,24,0,318,320,3,42,21,0,319,318,1,0,0,0,320,321,1,0,0,0,321,319,
  	1,0,0,0,321,322,1,0,0,0,322,326,1,0,0,0,323,325,3,44,22,0,324,323,1,0,
  	0,0,325,328,1,0,0,0,326,324,1,0,0,0,326,327,1,0,0,0,327,332,1,0,0,0,328,
  	326,1,0,0,0,329,331,3,42,21,0,330,329,1,0,0,0,331,334,1,0,0,0,332,330,
  	1,0,0,0,332,333,1,0,0,0,333,336,1,0,0,0,334,332,1,0,0,0,335,298,1,0,0,
  	0,335,299,1,0,0,0,335,317,1,0,0,0,336,41,1,0,0,0,337,338,5,30,0,0,338,
  	339,3,32,16,0,339,340,5,31,0,0,340,43,1,0,0,0,341,342,5,30,0,0,342,343,
  	5,31,0,0,343,45,1,0,0,0,344,345,7,8,0,0,345,47,1,0,0,0,346,347,7,9,0,
  	0,347,49,1,0,0,0,34,53,55,66,75,86,96,104,110,122,125,134,150,155,167,
  	170,174,183,185,202,206,250,263,265,274,283,288,295,303,308,314,321,326,
  	332,335
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  mxparserParserStaticData = staticData.release();
}

}

MxParser::MxParser(TokenStream *input) : MxParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

MxParser::MxParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  MxParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *mxparserParserStaticData->atn, mxparserParserStaticData->decisionToDFA, mxparserParserStaticData->sharedContextCache, options);
}

MxParser::~MxParser() {
  delete _interpreter;
}

const atn::ATN& MxParser::getATN() const {
  return *mxparserParserStaticData->atn;
}

std::string MxParser::getGrammarFileName() const {
  return "MxParser.g4";
}

const std::vector<std::string>& MxParser::getRuleNames() const {
  return mxparserParserStaticData->ruleNames;
}

const dfa::Vocabulary& MxParser::getVocabulary() const {
  return mxparserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView MxParser::getSerializedATN() const {
  return mxparserParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

MxParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::ProgramContext::EOF() {
  return getToken(MxParser::EOF, 0);
}

std::vector<MxParser::FunctionDefContext *> MxParser::ProgramContext::functionDef() {
  return getRuleContexts<MxParser::FunctionDefContext>();
}

MxParser::FunctionDefContext* MxParser::ProgramContext::functionDef(size_t i) {
  return getRuleContext<MxParser::FunctionDefContext>(i);
}

std::vector<MxParser::ClassDefContext *> MxParser::ProgramContext::classDef() {
  return getRuleContexts<MxParser::ClassDefContext>();
}

MxParser::ClassDefContext* MxParser::ProgramContext::classDef(size_t i) {
  return getRuleContext<MxParser::ClassDefContext>(i);
}

std::vector<MxParser::VarDefStmtContext *> MxParser::ProgramContext::varDefStmt() {
  return getRuleContexts<MxParser::VarDefStmtContext>();
}

MxParser::VarDefStmtContext* MxParser::ProgramContext::varDefStmt(size_t i) {
  return getRuleContext<MxParser::VarDefStmtContext>(i);
}


size_t MxParser::ProgramContext::getRuleIndex() const {
  return MxParser::RuleProgram;
}

std::any MxParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ProgramContext* MxParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, MxParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(55);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1153128212792868864) != 0)) {
      setState(53);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(50);
        functionDef();
        break;
      }

      case 2: {
        setState(51);
        classDef();
        break;
      }

      case 3: {
        setState(52);
        varDefStmt();
        break;
      }

      default:
        break;
      }
      setState(57);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(58);
    match(MxParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassDefContext ------------------------------------------------------------------

MxParser::ClassDefContext::ClassDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::ClassDefContext::Class() {
  return getToken(MxParser::Class, 0);
}

tree::TerminalNode* MxParser::ClassDefContext::Identifier() {
  return getToken(MxParser::Identifier, 0);
}

tree::TerminalNode* MxParser::ClassDefContext::LeftBrace() {
  return getToken(MxParser::LeftBrace, 0);
}

tree::TerminalNode* MxParser::ClassDefContext::RightBrace() {
  return getToken(MxParser::RightBrace, 0);
}

tree::TerminalNode* MxParser::ClassDefContext::Semicolon() {
  return getToken(MxParser::Semicolon, 0);
}

std::vector<MxParser::ClassSuiteContext *> MxParser::ClassDefContext::classSuite() {
  return getRuleContexts<MxParser::ClassSuiteContext>();
}

MxParser::ClassSuiteContext* MxParser::ClassDefContext::classSuite(size_t i) {
  return getRuleContext<MxParser::ClassSuiteContext>(i);
}


size_t MxParser::ClassDefContext::getRuleIndex() const {
  return MxParser::RuleClassDef;
}

std::any MxParser::ClassDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitClassDef(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ClassDefContext* MxParser::classDef() {
  ClassDefContext *_localctx = _tracker.createInstance<ClassDefContext>(_ctx, getState());
  enterRule(_localctx, 2, MxParser::RuleClassDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(60);
    match(MxParser::Class);
    setState(61);
    match(MxParser::Identifier);
    setState(62);
    match(MxParser::LeftBrace);
    setState(66);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1152987475304513536) != 0)) {
      setState(63);
      classSuite();
      setState(68);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(69);
    match(MxParser::RightBrace);
    setState(70);
    match(MxParser::Semicolon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ClassSuiteContext ------------------------------------------------------------------

MxParser::ClassSuiteContext::ClassSuiteContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MxParser::VarDefStmtContext* MxParser::ClassSuiteContext::varDefStmt() {
  return getRuleContext<MxParser::VarDefStmtContext>(0);
}

MxParser::ConstructDefContext* MxParser::ClassSuiteContext::constructDef() {
  return getRuleContext<MxParser::ConstructDefContext>(0);
}

MxParser::FunctionDefContext* MxParser::ClassSuiteContext::functionDef() {
  return getRuleContext<MxParser::FunctionDefContext>(0);
}


size_t MxParser::ClassSuiteContext::getRuleIndex() const {
  return MxParser::RuleClassSuite;
}

std::any MxParser::ClassSuiteContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitClassSuite(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ClassSuiteContext* MxParser::classSuite() {
  ClassSuiteContext *_localctx = _tracker.createInstance<ClassSuiteContext>(_ctx, getState());
  enterRule(_localctx, 4, MxParser::RuleClassSuite);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(75);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(72);
      varDefStmt();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(73);
      constructDef();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(74);
      functionDef();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstructDefContext ------------------------------------------------------------------

MxParser::ConstructDefContext::ConstructDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::ConstructDefContext::Identifier() {
  return getToken(MxParser::Identifier, 0);
}

tree::TerminalNode* MxParser::ConstructDefContext::LeftParen() {
  return getToken(MxParser::LeftParen, 0);
}

tree::TerminalNode* MxParser::ConstructDefContext::RightParen() {
  return getToken(MxParser::RightParen, 0);
}

MxParser::BlockContext* MxParser::ConstructDefContext::block() {
  return getRuleContext<MxParser::BlockContext>(0);
}


size_t MxParser::ConstructDefContext::getRuleIndex() const {
  return MxParser::RuleConstructDef;
}

std::any MxParser::ConstructDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitConstructDef(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ConstructDefContext* MxParser::constructDef() {
  ConstructDefContext *_localctx = _tracker.createInstance<ConstructDefContext>(_ctx, getState());
  enterRule(_localctx, 6, MxParser::RuleConstructDef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(77);
    match(MxParser::Identifier);
    setState(78);
    match(MxParser::LeftParen);
    setState(79);
    match(MxParser::RightParen);
    setState(80);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDefContext ------------------------------------------------------------------

MxParser::FunctionDefContext::FunctionDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MxParser::TypeNameContext* MxParser::FunctionDefContext::typeName() {
  return getRuleContext<MxParser::TypeNameContext>(0);
}

tree::TerminalNode* MxParser::FunctionDefContext::Identifier() {
  return getToken(MxParser::Identifier, 0);
}

tree::TerminalNode* MxParser::FunctionDefContext::LeftParen() {
  return getToken(MxParser::LeftParen, 0);
}

tree::TerminalNode* MxParser::FunctionDefContext::RightParen() {
  return getToken(MxParser::RightParen, 0);
}

MxParser::BlockContext* MxParser::FunctionDefContext::block() {
  return getRuleContext<MxParser::BlockContext>(0);
}

MxParser::ParametersContext* MxParser::FunctionDefContext::parameters() {
  return getRuleContext<MxParser::ParametersContext>(0);
}


size_t MxParser::FunctionDefContext::getRuleIndex() const {
  return MxParser::RuleFunctionDef;
}

std::any MxParser::FunctionDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitFunctionDef(this);
  else
    return visitor->visitChildren(this);
}

MxParser::FunctionDefContext* MxParser::functionDef() {
  FunctionDefContext *_localctx = _tracker.createInstance<FunctionDefContext>(_ctx, getState());
  enterRule(_localctx, 8, MxParser::RuleFunctionDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(82);
    typeName(0);
    setState(83);
    match(MxParser::Identifier);
    setState(84);
    match(MxParser::LeftParen);
    setState(86);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1152987475304513536) != 0)) {
      setState(85);
      parameters();
    }
    setState(88);
    match(MxParser::RightParen);
    setState(89);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParametersContext ------------------------------------------------------------------

MxParser::ParametersContext::ParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MxParser::VarDefContext *> MxParser::ParametersContext::varDef() {
  return getRuleContexts<MxParser::VarDefContext>();
}

MxParser::VarDefContext* MxParser::ParametersContext::varDef(size_t i) {
  return getRuleContext<MxParser::VarDefContext>(i);
}

std::vector<tree::TerminalNode *> MxParser::ParametersContext::Comma() {
  return getTokens(MxParser::Comma);
}

tree::TerminalNode* MxParser::ParametersContext::Comma(size_t i) {
  return getToken(MxParser::Comma, i);
}


size_t MxParser::ParametersContext::getRuleIndex() const {
  return MxParser::RuleParameters;
}

std::any MxParser::ParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitParameters(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ParametersContext* MxParser::parameters() {
  ParametersContext *_localctx = _tracker.createInstance<ParametersContext>(_ctx, getState());
  enterRule(_localctx, 10, MxParser::RuleParameters);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(91);
    varDef();
    setState(96);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MxParser::Comma) {
      setState(92);
      match(MxParser::Comma);
      setState(93);
      varDef();
      setState(98);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDefContext ------------------------------------------------------------------

MxParser::VarDefContext::VarDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MxParser::TypeNameContext* MxParser::VarDefContext::typeName() {
  return getRuleContext<MxParser::TypeNameContext>(0);
}

tree::TerminalNode* MxParser::VarDefContext::Identifier() {
  return getToken(MxParser::Identifier, 0);
}


size_t MxParser::VarDefContext::getRuleIndex() const {
  return MxParser::RuleVarDef;
}

std::any MxParser::VarDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitVarDef(this);
  else
    return visitor->visitChildren(this);
}

MxParser::VarDefContext* MxParser::varDef() {
  VarDefContext *_localctx = _tracker.createInstance<VarDefContext>(_ctx, getState());
  enterRule(_localctx, 12, MxParser::RuleVarDef);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(99);
    typeName(0);
    setState(100);
    match(MxParser::Identifier);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SuiteContext ------------------------------------------------------------------

MxParser::SuiteContext::SuiteContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MxParser::BlockContext* MxParser::SuiteContext::block() {
  return getRuleContext<MxParser::BlockContext>(0);
}

MxParser::StmtContext* MxParser::SuiteContext::stmt() {
  return getRuleContext<MxParser::StmtContext>(0);
}


size_t MxParser::SuiteContext::getRuleIndex() const {
  return MxParser::RuleSuite;
}

std::any MxParser::SuiteContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitSuite(this);
  else
    return visitor->visitChildren(this);
}

MxParser::SuiteContext* MxParser::suite() {
  SuiteContext *_localctx = _tracker.createInstance<SuiteContext>(_ctx, getState());
  enterRule(_localctx, 14, MxParser::RuleSuite);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(104);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(102);
      block();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(103);
      stmt();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

MxParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::BlockContext::LeftBrace() {
  return getToken(MxParser::LeftBrace, 0);
}

tree::TerminalNode* MxParser::BlockContext::RightBrace() {
  return getToken(MxParser::RightBrace, 0);
}

std::vector<MxParser::StmtContext *> MxParser::BlockContext::stmt() {
  return getRuleContexts<MxParser::StmtContext>();
}

MxParser::StmtContext* MxParser::BlockContext::stmt(size_t i) {
  return getRuleContext<MxParser::StmtContext>(i);
}


size_t MxParser::BlockContext::getRuleIndex() const {
  return MxParser::RuleBlock;
}

std::any MxParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

MxParser::BlockContext* MxParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 16, MxParser::RuleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(106);
    match(MxParser::LeftBrace);
    setState(110);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 2281213764177100832) != 0)) {
      setState(107);
      stmt();
      setState(112);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(113);
    match(MxParser::RightBrace);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

MxParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MxParser::ExprStmtContext* MxParser::StmtContext::exprStmt() {
  return getRuleContext<MxParser::ExprStmtContext>(0);
}

MxParser::IfStmtContext* MxParser::StmtContext::ifStmt() {
  return getRuleContext<MxParser::IfStmtContext>(0);
}

MxParser::WhileStmtContext* MxParser::StmtContext::whileStmt() {
  return getRuleContext<MxParser::WhileStmtContext>(0);
}

MxParser::ForStmtContext* MxParser::StmtContext::forStmt() {
  return getRuleContext<MxParser::ForStmtContext>(0);
}

MxParser::FlowStmtContext* MxParser::StmtContext::flowStmt() {
  return getRuleContext<MxParser::FlowStmtContext>(0);
}

MxParser::VarDefStmtContext* MxParser::StmtContext::varDefStmt() {
  return getRuleContext<MxParser::VarDefStmtContext>(0);
}

MxParser::BlockContext* MxParser::StmtContext::block() {
  return getRuleContext<MxParser::BlockContext>(0);
}


size_t MxParser::StmtContext::getRuleIndex() const {
  return MxParser::RuleStmt;
}

std::any MxParser::StmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitStmt(this);
  else
    return visitor->visitChildren(this);
}

MxParser::StmtContext* MxParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 18, MxParser::RuleStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(122);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(115);
      exprStmt();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(116);
      ifStmt();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(117);
      whileStmt();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(118);
      forStmt();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(119);
      flowStmt();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(120);
      varDefStmt();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(121);
      block();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprStmtContext ------------------------------------------------------------------

MxParser::ExprStmtContext::ExprStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::ExprStmtContext::Semicolon() {
  return getToken(MxParser::Semicolon, 0);
}

MxParser::ExprListContext* MxParser::ExprStmtContext::exprList() {
  return getRuleContext<MxParser::ExprListContext>(0);
}


size_t MxParser::ExprStmtContext::getRuleIndex() const {
  return MxParser::RuleExprStmt;
}

std::any MxParser::ExprStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitExprStmt(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ExprStmtContext* MxParser::exprStmt() {
  ExprStmtContext *_localctx = _tracker.createInstance<ExprStmtContext>(_ctx, getState());
  enterRule(_localctx, 20, MxParser::RuleExprStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(125);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1155247800737464352) != 0)) {
      setState(124);
      exprList();
    }
    setState(127);
    match(MxParser::Semicolon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprListContext ------------------------------------------------------------------

MxParser::ExprListContext::ExprListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<MxParser::ExpressionContext *> MxParser::ExprListContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext* MxParser::ExprListContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> MxParser::ExprListContext::Comma() {
  return getTokens(MxParser::Comma);
}

tree::TerminalNode* MxParser::ExprListContext::Comma(size_t i) {
  return getToken(MxParser::Comma, i);
}


size_t MxParser::ExprListContext::getRuleIndex() const {
  return MxParser::RuleExprList;
}

std::any MxParser::ExprListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitExprList(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ExprListContext* MxParser::exprList() {
  ExprListContext *_localctx = _tracker.createInstance<ExprListContext>(_ctx, getState());
  enterRule(_localctx, 22, MxParser::RuleExprList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(129);
    expression(0);
    setState(134);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == MxParser::Comma) {
      setState(130);
      match(MxParser::Comma);
      setState(131);
      expression(0);
      setState(136);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStmtContext ------------------------------------------------------------------

MxParser::IfStmtContext::IfStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::IfStmtContext::If() {
  return getToken(MxParser::If, 0);
}

std::vector<tree::TerminalNode *> MxParser::IfStmtContext::LeftParen() {
  return getTokens(MxParser::LeftParen);
}

tree::TerminalNode* MxParser::IfStmtContext::LeftParen(size_t i) {
  return getToken(MxParser::LeftParen, i);
}

std::vector<MxParser::ExpressionContext *> MxParser::IfStmtContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext* MxParser::IfStmtContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> MxParser::IfStmtContext::RightParen() {
  return getTokens(MxParser::RightParen);
}

tree::TerminalNode* MxParser::IfStmtContext::RightParen(size_t i) {
  return getToken(MxParser::RightParen, i);
}

std::vector<MxParser::SuiteContext *> MxParser::IfStmtContext::suite() {
  return getRuleContexts<MxParser::SuiteContext>();
}

MxParser::SuiteContext* MxParser::IfStmtContext::suite(size_t i) {
  return getRuleContext<MxParser::SuiteContext>(i);
}

std::vector<tree::TerminalNode *> MxParser::IfStmtContext::ElseIf() {
  return getTokens(MxParser::ElseIf);
}

tree::TerminalNode* MxParser::IfStmtContext::ElseIf(size_t i) {
  return getToken(MxParser::ElseIf, i);
}

tree::TerminalNode* MxParser::IfStmtContext::Else() {
  return getToken(MxParser::Else, 0);
}


size_t MxParser::IfStmtContext::getRuleIndex() const {
  return MxParser::RuleIfStmt;
}

std::any MxParser::IfStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitIfStmt(this);
  else
    return visitor->visitChildren(this);
}

MxParser::IfStmtContext* MxParser::ifStmt() {
  IfStmtContext *_localctx = _tracker.createInstance<IfStmtContext>(_ctx, getState());
  enterRule(_localctx, 24, MxParser::RuleIfStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(137);
    match(MxParser::If);
    setState(138);
    match(MxParser::LeftParen);
    setState(139);
    expression(0);
    setState(140);
    match(MxParser::RightParen);
    setState(141);
    suite();
    setState(150);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(142);
        match(MxParser::ElseIf);
        setState(143);
        match(MxParser::LeftParen);
        setState(144);
        expression(0);
        setState(145);
        match(MxParser::RightParen);
        setState(146);
        suite(); 
      }
      setState(152);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    }
    setState(155);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      setState(153);
      match(MxParser::Else);
      setState(154);
      suite();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileStmtContext ------------------------------------------------------------------

MxParser::WhileStmtContext::WhileStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::WhileStmtContext::While() {
  return getToken(MxParser::While, 0);
}

tree::TerminalNode* MxParser::WhileStmtContext::LeftParen() {
  return getToken(MxParser::LeftParen, 0);
}

MxParser::ExpressionContext* MxParser::WhileStmtContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}

tree::TerminalNode* MxParser::WhileStmtContext::RightParen() {
  return getToken(MxParser::RightParen, 0);
}

MxParser::SuiteContext* MxParser::WhileStmtContext::suite() {
  return getRuleContext<MxParser::SuiteContext>(0);
}


size_t MxParser::WhileStmtContext::getRuleIndex() const {
  return MxParser::RuleWhileStmt;
}

std::any MxParser::WhileStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitWhileStmt(this);
  else
    return visitor->visitChildren(this);
}

MxParser::WhileStmtContext* MxParser::whileStmt() {
  WhileStmtContext *_localctx = _tracker.createInstance<WhileStmtContext>(_ctx, getState());
  enterRule(_localctx, 26, MxParser::RuleWhileStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(157);
    match(MxParser::While);
    setState(158);
    match(MxParser::LeftParen);
    setState(159);
    expression(0);
    setState(160);
    match(MxParser::RightParen);
    setState(161);
    suite();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStmtContext ------------------------------------------------------------------

MxParser::ForStmtContext::ForStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::ForStmtContext::For() {
  return getToken(MxParser::For, 0);
}

tree::TerminalNode* MxParser::ForStmtContext::LeftParen() {
  return getToken(MxParser::LeftParen, 0);
}

tree::TerminalNode* MxParser::ForStmtContext::Semicolon() {
  return getToken(MxParser::Semicolon, 0);
}

tree::TerminalNode* MxParser::ForStmtContext::RightParen() {
  return getToken(MxParser::RightParen, 0);
}

MxParser::SuiteContext* MxParser::ForStmtContext::suite() {
  return getRuleContext<MxParser::SuiteContext>(0);
}

MxParser::ExprStmtContext* MxParser::ForStmtContext::exprStmt() {
  return getRuleContext<MxParser::ExprStmtContext>(0);
}

MxParser::VarDefStmtContext* MxParser::ForStmtContext::varDefStmt() {
  return getRuleContext<MxParser::VarDefStmtContext>(0);
}

std::vector<MxParser::ExpressionContext *> MxParser::ForStmtContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext* MxParser::ForStmtContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}


size_t MxParser::ForStmtContext::getRuleIndex() const {
  return MxParser::RuleForStmt;
}

std::any MxParser::ForStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitForStmt(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ForStmtContext* MxParser::forStmt() {
  ForStmtContext *_localctx = _tracker.createInstance<ForStmtContext>(_ctx, getState());
  enterRule(_localctx, 28, MxParser::RuleForStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(163);
    match(MxParser::For);
    setState(164);
    match(MxParser::LeftParen);
    setState(167);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      setState(165);
      exprStmt();
      break;
    }

    case 2: {
      setState(166);
      varDefStmt();
      break;
    }

    default:
      break;
    }
    setState(170);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1155247800737464352) != 0)) {
      setState(169);
      antlrcpp::downCast<ForStmtContext *>(_localctx)->condition = expression(0);
    }
    setState(172);
    match(MxParser::Semicolon);
    setState(174);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1155247800737464352) != 0)) {
      setState(173);
      antlrcpp::downCast<ForStmtContext *>(_localctx)->step = expression(0);
    }
    setState(176);
    match(MxParser::RightParen);
    setState(177);
    suite();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FlowStmtContext ------------------------------------------------------------------

MxParser::FlowStmtContext::FlowStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::FlowStmtContext::Semicolon() {
  return getToken(MxParser::Semicolon, 0);
}

tree::TerminalNode* MxParser::FlowStmtContext::Continue() {
  return getToken(MxParser::Continue, 0);
}

tree::TerminalNode* MxParser::FlowStmtContext::Break() {
  return getToken(MxParser::Break, 0);
}

tree::TerminalNode* MxParser::FlowStmtContext::Return() {
  return getToken(MxParser::Return, 0);
}

MxParser::ExpressionContext* MxParser::FlowStmtContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}


size_t MxParser::FlowStmtContext::getRuleIndex() const {
  return MxParser::RuleFlowStmt;
}

std::any MxParser::FlowStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitFlowStmt(this);
  else
    return visitor->visitChildren(this);
}

MxParser::FlowStmtContext* MxParser::flowStmt() {
  FlowStmtContext *_localctx = _tracker.createInstance<FlowStmtContext>(_ctx, getState());
  enterRule(_localctx, 30, MxParser::RuleFlowStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(185);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MxParser::Continue: {
        setState(179);
        match(MxParser::Continue);
        break;
      }

      case MxParser::Break: {
        setState(180);
        match(MxParser::Break);
        break;
      }

      case MxParser::Return: {
        setState(181);
        match(MxParser::Return);
        setState(183);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if ((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 1155247800737464352) != 0)) {
          setState(182);
          expression(0);
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(187);
    match(MxParser::Semicolon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

MxParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MxParser::ExpressionContext::getRuleIndex() const {
  return MxParser::RuleExpression;
}

void MxParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ArrayExprContext ------------------------------------------------------------------

std::vector<MxParser::ExpressionContext *> MxParser::ArrayExprContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext* MxParser::ArrayExprContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}

tree::TerminalNode* MxParser::ArrayExprContext::LeftBracket() {
  return getToken(MxParser::LeftBracket, 0);
}

tree::TerminalNode* MxParser::ArrayExprContext::RightBracket() {
  return getToken(MxParser::RightBracket, 0);
}

MxParser::ArrayExprContext::ArrayExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

std::any MxParser::ArrayExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitArrayExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionExprContext ------------------------------------------------------------------

MxParser::ExpressionContext* MxParser::FunctionExprContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}

tree::TerminalNode* MxParser::FunctionExprContext::LeftParen() {
  return getToken(MxParser::LeftParen, 0);
}

tree::TerminalNode* MxParser::FunctionExprContext::RightParen() {
  return getToken(MxParser::RightParen, 0);
}

MxParser::ExprListContext* MxParser::FunctionExprContext::exprList() {
  return getRuleContext<MxParser::ExprListContext>(0);
}

MxParser::FunctionExprContext::FunctionExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

std::any MxParser::FunctionExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitFunctionExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MemberExprContext ------------------------------------------------------------------

MxParser::ExpressionContext* MxParser::MemberExprContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}

tree::TerminalNode* MxParser::MemberExprContext::Dot() {
  return getToken(MxParser::Dot, 0);
}

tree::TerminalNode* MxParser::MemberExprContext::Identifier() {
  return getToken(MxParser::Identifier, 0);
}

MxParser::MemberExprContext::MemberExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

std::any MxParser::MemberExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitMemberExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParentheseExprContext ------------------------------------------------------------------

tree::TerminalNode* MxParser::ParentheseExprContext::LeftParen() {
  return getToken(MxParser::LeftParen, 0);
}

MxParser::ExpressionContext* MxParser::ParentheseExprContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}

tree::TerminalNode* MxParser::ParentheseExprContext::RightParen() {
  return getToken(MxParser::RightParen, 0);
}

MxParser::ParentheseExprContext::ParentheseExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

std::any MxParser::ParentheseExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitParentheseExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LeftSingleExprContext ------------------------------------------------------------------

MxParser::ExpressionContext* MxParser::LeftSingleExprContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}

tree::TerminalNode* MxParser::LeftSingleExprContext::Incre() {
  return getToken(MxParser::Incre, 0);
}

tree::TerminalNode* MxParser::LeftSingleExprContext::Decre() {
  return getToken(MxParser::Decre, 0);
}

tree::TerminalNode* MxParser::LeftSingleExprContext::Not() {
  return getToken(MxParser::Not, 0);
}

tree::TerminalNode* MxParser::LeftSingleExprContext::BitInv() {
  return getToken(MxParser::BitInv, 0);
}

tree::TerminalNode* MxParser::LeftSingleExprContext::Sub() {
  return getToken(MxParser::Sub, 0);
}

MxParser::LeftSingleExprContext::LeftSingleExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

std::any MxParser::LeftSingleExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitLeftSingleExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BinaryExprContext ------------------------------------------------------------------

std::vector<MxParser::ExpressionContext *> MxParser::BinaryExprContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext* MxParser::BinaryExprContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}

tree::TerminalNode* MxParser::BinaryExprContext::Mul() {
  return getToken(MxParser::Mul, 0);
}

tree::TerminalNode* MxParser::BinaryExprContext::Div() {
  return getToken(MxParser::Div, 0);
}

tree::TerminalNode* MxParser::BinaryExprContext::Mod() {
  return getToken(MxParser::Mod, 0);
}

tree::TerminalNode* MxParser::BinaryExprContext::Add() {
  return getToken(MxParser::Add, 0);
}

tree::TerminalNode* MxParser::BinaryExprContext::Sub() {
  return getToken(MxParser::Sub, 0);
}

tree::TerminalNode* MxParser::BinaryExprContext::Rs() {
  return getToken(MxParser::Rs, 0);
}

tree::TerminalNode* MxParser::BinaryExprContext::Ls() {
  return getToken(MxParser::Ls, 0);
}

tree::TerminalNode* MxParser::BinaryExprContext::Geq() {
  return getToken(MxParser::Geq, 0);
}

tree::TerminalNode* MxParser::BinaryExprContext::Leq() {
  return getToken(MxParser::Leq, 0);
}

tree::TerminalNode* MxParser::BinaryExprContext::Lt() {
  return getToken(MxParser::Lt, 0);
}

tree::TerminalNode* MxParser::BinaryExprContext::Gt() {
  return getToken(MxParser::Gt, 0);
}

tree::TerminalNode* MxParser::BinaryExprContext::Neq() {
  return getToken(MxParser::Neq, 0);
}

tree::TerminalNode* MxParser::BinaryExprContext::Eq() {
  return getToken(MxParser::Eq, 0);
}

tree::TerminalNode* MxParser::BinaryExprContext::BitAnd() {
  return getToken(MxParser::BitAnd, 0);
}

tree::TerminalNode* MxParser::BinaryExprContext::BitXor() {
  return getToken(MxParser::BitXor, 0);
}

tree::TerminalNode* MxParser::BinaryExprContext::BitOr() {
  return getToken(MxParser::BitOr, 0);
}

tree::TerminalNode* MxParser::BinaryExprContext::And() {
  return getToken(MxParser::And, 0);
}

tree::TerminalNode* MxParser::BinaryExprContext::Or() {
  return getToken(MxParser::Or, 0);
}

MxParser::BinaryExprContext::BinaryExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

std::any MxParser::BinaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitBinaryExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NewExprContext ------------------------------------------------------------------

tree::TerminalNode* MxParser::NewExprContext::New() {
  return getToken(MxParser::New, 0);
}

MxParser::NewTypeNameContext* MxParser::NewExprContext::newTypeName() {
  return getRuleContext<MxParser::NewTypeNameContext>(0);
}

tree::TerminalNode* MxParser::NewExprContext::LeftParen() {
  return getToken(MxParser::LeftParen, 0);
}

tree::TerminalNode* MxParser::NewExprContext::RightParen() {
  return getToken(MxParser::RightParen, 0);
}

MxParser::NewExprContext::NewExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

std::any MxParser::NewExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitNewExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LiterExprContext ------------------------------------------------------------------

MxParser::LiteralExprContext* MxParser::LiterExprContext::literalExpr() {
  return getRuleContext<MxParser::LiteralExprContext>(0);
}

MxParser::LiterExprContext::LiterExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

std::any MxParser::LiterExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitLiterExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- RightSingleExprContext ------------------------------------------------------------------

MxParser::ExpressionContext* MxParser::RightSingleExprContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}

tree::TerminalNode* MxParser::RightSingleExprContext::Incre() {
  return getToken(MxParser::Incre, 0);
}

tree::TerminalNode* MxParser::RightSingleExprContext::Decre() {
  return getToken(MxParser::Decre, 0);
}

MxParser::RightSingleExprContext::RightSingleExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

std::any MxParser::RightSingleExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitRightSingleExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AtomExprContext ------------------------------------------------------------------

tree::TerminalNode* MxParser::AtomExprContext::Identifier() {
  return getToken(MxParser::Identifier, 0);
}

tree::TerminalNode* MxParser::AtomExprContext::This() {
  return getToken(MxParser::This, 0);
}

MxParser::AtomExprContext::AtomExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

std::any MxParser::AtomExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitAtomExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TernaryExprContext ------------------------------------------------------------------

std::vector<MxParser::ExpressionContext *> MxParser::TernaryExprContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext* MxParser::TernaryExprContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}

tree::TerminalNode* MxParser::TernaryExprContext::Ques() {
  return getToken(MxParser::Ques, 0);
}

tree::TerminalNode* MxParser::TernaryExprContext::Colon() {
  return getToken(MxParser::Colon, 0);
}

MxParser::TernaryExprContext::TernaryExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

std::any MxParser::TernaryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitTernaryExpr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssignExprContext ------------------------------------------------------------------

std::vector<MxParser::ExpressionContext *> MxParser::AssignExprContext::expression() {
  return getRuleContexts<MxParser::ExpressionContext>();
}

MxParser::ExpressionContext* MxParser::AssignExprContext::expression(size_t i) {
  return getRuleContext<MxParser::ExpressionContext>(i);
}

tree::TerminalNode* MxParser::AssignExprContext::Assign() {
  return getToken(MxParser::Assign, 0);
}

MxParser::AssignExprContext::AssignExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

std::any MxParser::AssignExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitAssignExpr(this);
  else
    return visitor->visitChildren(this);
}

MxParser::ExpressionContext* MxParser::expression() {
   return expression(0);
}

MxParser::ExpressionContext* MxParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MxParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  MxParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 32;
  enterRecursionRule(_localctx, 32, MxParser::RuleExpression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(206);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MxParser::LeftParen: {
        _localctx = _tracker.createInstance<ParentheseExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(190);
        match(MxParser::LeftParen);
        setState(191);
        expression(0);
        setState(192);
        match(MxParser::RightParen);
        break;
      }

      case MxParser::Incre:
      case MxParser::Decre: {
        _localctx = _tracker.createInstance<LeftSingleExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(194);
        antlrcpp::downCast<LeftSingleExprContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == MxParser::Incre

        || _la == MxParser::Decre)) {
          antlrcpp::downCast<LeftSingleExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(195);
        antlrcpp::downCast<LeftSingleExprContext *>(_localctx)->rhs = expression(17);
        break;
      }

      case MxParser::Sub:
      case MxParser::Not:
      case MxParser::BitInv: {
        _localctx = _tracker.createInstance<LeftSingleExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(196);
        antlrcpp::downCast<LeftSingleExprContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & 8519712) != 0))) {
          antlrcpp::downCast<LeftSingleExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(197);
        antlrcpp::downCast<LeftSingleExprContext *>(_localctx)->rhs = expression(16);
        break;
      }

      case MxParser::New: {
        _localctx = _tracker.createInstance<NewExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(198);
        match(MxParser::New);
        setState(199);
        newTypeName();
        setState(202);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
        case 1: {
          setState(200);
          match(MxParser::LeftParen);
          setState(201);
          match(MxParser::RightParen);
          break;
        }

        default:
          break;
        }
        break;
      }

      case MxParser::LogicalLiteral:
      case MxParser::NumberLiteral:
      case MxParser::StringLiteral:
      case MxParser::NullLiteral: {
        _localctx = _tracker.createInstance<LiterExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(204);
        literalExpr();
        break;
      }

      case MxParser::This:
      case MxParser::Identifier: {
        _localctx = _tracker.createInstance<AtomExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(205);
        _la = _input->LA(1);
        if (!(_la == MxParser::This

        || _la == MxParser::Identifier)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(265);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(263);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(208);

          if (!(precpred(_ctx, 14))) throw FailedPredicateException(this, "precpred(_ctx, 14)");
          setState(209);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 448) != 0))) {
            antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(210);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->rhs = expression(15);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(211);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(212);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MxParser::Add

          || _la == MxParser::Sub)) {
            antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(213);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->rhs = expression(14);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(214);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(215);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MxParser::Rs

          || _la == MxParser::Ls)) {
            antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(216);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->rhs = expression(13);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(217);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(218);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 7680) != 0))) {
            antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(219);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->rhs = expression(12);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(220);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(221);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MxParser::Neq

          || _la == MxParser::Eq)) {
            antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(222);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->rhs = expression(11);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(223);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(224);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = match(MxParser::BitAnd);
          setState(225);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->rhs = expression(10);
          break;
        }

        case 7: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(226);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(227);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = match(MxParser::BitXor);
          setState(228);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->rhs = expression(9);
          break;
        }

        case 8: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(229);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(230);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = match(MxParser::BitOr);
          setState(231);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->rhs = expression(8);
          break;
        }

        case 9: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(232);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(233);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = match(MxParser::And);
          setState(234);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->rhs = expression(7);
          break;
        }

        case 10: {
          auto newContext = _tracker.createInstance<BinaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(235);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(236);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->op = match(MxParser::Or);
          setState(237);
          antlrcpp::downCast<BinaryExprContext *>(_localctx)->rhs = expression(6);
          break;
        }

        case 11: {
          auto newContext = _tracker.createInstance<TernaryExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(238);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(239);
          match(MxParser::Ques);
          setState(240);
          expression(0);
          setState(241);
          match(MxParser::Colon);
          setState(242);
          expression(4);
          break;
        }

        case 12: {
          auto newContext = _tracker.createInstance<AssignExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(244);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(245);
          match(MxParser::Assign);
          setState(246);
          expression(3);
          break;
        }

        case 13: {
          auto newContext = _tracker.createInstance<FunctionExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(247);

          if (!(precpred(_ctx, 21))) throw FailedPredicateException(this, "precpred(_ctx, 21)");
          setState(248);
          match(MxParser::LeftParen);
          setState(250);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if ((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 1155247800737464352) != 0)) {
            setState(249);
            exprList();
          }
          setState(252);
          match(MxParser::RightParen);
          break;
        }

        case 14: {
          auto newContext = _tracker.createInstance<ArrayExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(253);

          if (!(precpred(_ctx, 20))) throw FailedPredicateException(this, "precpred(_ctx, 20)");
          setState(254);
          match(MxParser::LeftBracket);
          setState(255);
          expression(0);
          setState(256);
          match(MxParser::RightBracket);
          break;
        }

        case 15: {
          auto newContext = _tracker.createInstance<MemberExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(258);

          if (!(precpred(_ctx, 19))) throw FailedPredicateException(this, "precpred(_ctx, 19)");
          setState(259);
          match(MxParser::Dot);
          setState(260);
          match(MxParser::Identifier);
          break;
        }

        case 16: {
          auto newContext = _tracker.createInstance<RightSingleExprContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->lhs = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(261);

          if (!(precpred(_ctx, 18))) throw FailedPredicateException(this, "precpred(_ctx, 18)");
          setState(262);
          antlrcpp::downCast<RightSingleExprContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == MxParser::Incre

          || _la == MxParser::Decre)) {
            antlrcpp::downCast<RightSingleExprContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          break;
        }

        default:
          break;
        } 
      }
      setState(267);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- VarDefStmtContext ------------------------------------------------------------------

MxParser::VarDefStmtContext::VarDefStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

MxParser::TypeNameContext* MxParser::VarDefStmtContext::typeName() {
  return getRuleContext<MxParser::TypeNameContext>(0);
}

std::vector<MxParser::VarDefInitContext *> MxParser::VarDefStmtContext::varDefInit() {
  return getRuleContexts<MxParser::VarDefInitContext>();
}

MxParser::VarDefInitContext* MxParser::VarDefStmtContext::varDefInit(size_t i) {
  return getRuleContext<MxParser::VarDefInitContext>(i);
}

tree::TerminalNode* MxParser::VarDefStmtContext::Semicolon() {
  return getToken(MxParser::Semicolon, 0);
}

std::vector<tree::TerminalNode *> MxParser::VarDefStmtContext::Comma() {
  return getTokens(MxParser::Comma);
}

tree::TerminalNode* MxParser::VarDefStmtContext::Comma(size_t i) {
  return getToken(MxParser::Comma, i);
}


size_t MxParser::VarDefStmtContext::getRuleIndex() const {
  return MxParser::RuleVarDefStmt;
}

std::any MxParser::VarDefStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitVarDefStmt(this);
  else
    return visitor->visitChildren(this);
}

MxParser::VarDefStmtContext* MxParser::varDefStmt() {
  VarDefStmtContext *_localctx = _tracker.createInstance<VarDefStmtContext>(_ctx, getState());
  enterRule(_localctx, 34, MxParser::RuleVarDefStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(268);
    typeName(0);
    setState(274);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(269);
        varDefInit();
        setState(270);
        match(MxParser::Comma); 
      }
      setState(276);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    }
    setState(277);
    varDefInit();
    setState(278);
    match(MxParser::Semicolon);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDefInitContext ------------------------------------------------------------------

MxParser::VarDefInitContext::VarDefInitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::VarDefInitContext::Identifier() {
  return getToken(MxParser::Identifier, 0);
}

tree::TerminalNode* MxParser::VarDefInitContext::Assign() {
  return getToken(MxParser::Assign, 0);
}

MxParser::ExpressionContext* MxParser::VarDefInitContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}


size_t MxParser::VarDefInitContext::getRuleIndex() const {
  return MxParser::RuleVarDefInit;
}

std::any MxParser::VarDefInitContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitVarDefInit(this);
  else
    return visitor->visitChildren(this);
}

MxParser::VarDefInitContext* MxParser::varDefInit() {
  VarDefInitContext *_localctx = _tracker.createInstance<VarDefInitContext>(_ctx, getState());
  enterRule(_localctx, 36, MxParser::RuleVarDefInit);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(280);
    match(MxParser::Identifier);
    setState(283);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == MxParser::Assign) {
      setState(281);
      match(MxParser::Assign);
      setState(282);
      expression(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeNameContext ------------------------------------------------------------------

MxParser::TypeNameContext::TypeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MxParser::TypeNameContext::getRuleIndex() const {
  return MxParser::RuleTypeName;
}

void MxParser::TypeNameContext::copyFrom(TypeNameContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ArrayContext ------------------------------------------------------------------

MxParser::TypeNameContext* MxParser::ArrayContext::typeName() {
  return getRuleContext<MxParser::TypeNameContext>(0);
}

tree::TerminalNode* MxParser::ArrayContext::LeftBracket() {
  return getToken(MxParser::LeftBracket, 0);
}

tree::TerminalNode* MxParser::ArrayContext::RightBracket() {
  return getToken(MxParser::RightBracket, 0);
}

MxParser::ArrayContext::ArrayContext(TypeNameContext *ctx) { copyFrom(ctx); }

std::any MxParser::ArrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitArray(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BasicContext ------------------------------------------------------------------

MxParser::BasicTypeContext* MxParser::BasicContext::basicType() {
  return getRuleContext<MxParser::BasicTypeContext>(0);
}

MxParser::BasicContext::BasicContext(TypeNameContext *ctx) { copyFrom(ctx); }

std::any MxParser::BasicContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitBasic(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ClassContext ------------------------------------------------------------------

tree::TerminalNode* MxParser::ClassContext::Identifier() {
  return getToken(MxParser::Identifier, 0);
}

MxParser::ClassContext::ClassContext(TypeNameContext *ctx) { copyFrom(ctx); }

std::any MxParser::ClassContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitClass(this);
  else
    return visitor->visitChildren(this);
}

MxParser::TypeNameContext* MxParser::typeName() {
   return typeName(0);
}

MxParser::TypeNameContext* MxParser::typeName(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  MxParser::TypeNameContext *_localctx = _tracker.createInstance<TypeNameContext>(_ctx, parentState);
  MxParser::TypeNameContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 38;
  enterRecursionRule(_localctx, 38, MxParser::RuleTypeName, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(288);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case MxParser::Void:
      case MxParser::Bool:
      case MxParser::Int:
      case MxParser::String: {
        _localctx = _tracker.createInstance<BasicContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(286);
        basicType();
        break;
      }

      case MxParser::Identifier: {
        _localctx = _tracker.createInstance<ClassContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(287);
        match(MxParser::Identifier);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(295);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        auto newContext = _tracker.createInstance<ArrayContext>(_tracker.createInstance<TypeNameContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RuleTypeName);
        setState(290);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(291);
        match(MxParser::LeftBracket);
        setState(292);
        match(MxParser::RightBracket); 
      }
      setState(297);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- NewTypeNameContext ------------------------------------------------------------------

MxParser::NewTypeNameContext::NewTypeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t MxParser::NewTypeNameContext::getRuleIndex() const {
  return MxParser::RuleNewTypeName;
}

void MxParser::NewTypeNameContext::copyFrom(NewTypeNameContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- NewBasicArrayContext ------------------------------------------------------------------

MxParser::BasicTypeContext* MxParser::NewBasicArrayContext::basicType() {
  return getRuleContext<MxParser::BasicTypeContext>(0);
}

std::vector<MxParser::NewArrayExprContext *> MxParser::NewBasicArrayContext::newArrayExpr() {
  return getRuleContexts<MxParser::NewArrayExprContext>();
}

MxParser::NewArrayExprContext* MxParser::NewBasicArrayContext::newArrayExpr(size_t i) {
  return getRuleContext<MxParser::NewArrayExprContext>(i);
}

std::vector<MxParser::NewArrayEmptyContext *> MxParser::NewBasicArrayContext::newArrayEmpty() {
  return getRuleContexts<MxParser::NewArrayEmptyContext>();
}

MxParser::NewArrayEmptyContext* MxParser::NewBasicArrayContext::newArrayEmpty(size_t i) {
  return getRuleContext<MxParser::NewArrayEmptyContext>(i);
}

MxParser::NewBasicArrayContext::NewBasicArrayContext(NewTypeNameContext *ctx) { copyFrom(ctx); }

std::any MxParser::NewBasicArrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitNewBasicArray(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NewClassContext ------------------------------------------------------------------

tree::TerminalNode* MxParser::NewClassContext::Identifier() {
  return getToken(MxParser::Identifier, 0);
}

MxParser::NewClassContext::NewClassContext(NewTypeNameContext *ctx) { copyFrom(ctx); }

std::any MxParser::NewClassContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitNewClass(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NewClassArrayContext ------------------------------------------------------------------

tree::TerminalNode* MxParser::NewClassArrayContext::Identifier() {
  return getToken(MxParser::Identifier, 0);
}

std::vector<MxParser::NewArrayExprContext *> MxParser::NewClassArrayContext::newArrayExpr() {
  return getRuleContexts<MxParser::NewArrayExprContext>();
}

MxParser::NewArrayExprContext* MxParser::NewClassArrayContext::newArrayExpr(size_t i) {
  return getRuleContext<MxParser::NewArrayExprContext>(i);
}

std::vector<MxParser::NewArrayEmptyContext *> MxParser::NewClassArrayContext::newArrayEmpty() {
  return getRuleContexts<MxParser::NewArrayEmptyContext>();
}

MxParser::NewArrayEmptyContext* MxParser::NewClassArrayContext::newArrayEmpty(size_t i) {
  return getRuleContext<MxParser::NewArrayEmptyContext>(i);
}

MxParser::NewClassArrayContext::NewClassArrayContext(NewTypeNameContext *ctx) { copyFrom(ctx); }

std::any MxParser::NewClassArrayContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitNewClassArray(this);
  else
    return visitor->visitChildren(this);
}
MxParser::NewTypeNameContext* MxParser::newTypeName() {
  NewTypeNameContext *_localctx = _tracker.createInstance<NewTypeNameContext>(_ctx, getState());
  enterRule(_localctx, 40, MxParser::RuleNewTypeName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(335);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<MxParser::NewClassContext>(_localctx);
      enterOuterAlt(_localctx, 1);
      setState(298);
      match(MxParser::Identifier);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<MxParser::NewClassArrayContext>(_localctx);
      enterOuterAlt(_localctx, 2);
      setState(299);
      match(MxParser::Identifier);
      setState(301); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(300);
                newArrayExpr();
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(303); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(308);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(305);
          newArrayEmpty(); 
        }
        setState(310);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
      }

      setState(314);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(311);
          antlrcpp::downCast<NewClassArrayContext *>(_localctx)->fail = newArrayExpr(); 
        }
        setState(316);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
      }
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<MxParser::NewBasicArrayContext>(_localctx);
      enterOuterAlt(_localctx, 3);
      setState(317);
      basicType();
      setState(319); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(318);
                newArrayExpr();
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(321); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(326);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(323);
          newArrayEmpty(); 
        }
        setState(328);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
      }

      setState(332);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(329);
          antlrcpp::downCast<NewBasicArrayContext *>(_localctx)->fail = newArrayExpr(); 
        }
        setState(334);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx);
      }
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NewArrayExprContext ------------------------------------------------------------------

MxParser::NewArrayExprContext::NewArrayExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::NewArrayExprContext::LeftBracket() {
  return getToken(MxParser::LeftBracket, 0);
}

MxParser::ExpressionContext* MxParser::NewArrayExprContext::expression() {
  return getRuleContext<MxParser::ExpressionContext>(0);
}

tree::TerminalNode* MxParser::NewArrayExprContext::RightBracket() {
  return getToken(MxParser::RightBracket, 0);
}


size_t MxParser::NewArrayExprContext::getRuleIndex() const {
  return MxParser::RuleNewArrayExpr;
}

std::any MxParser::NewArrayExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitNewArrayExpr(this);
  else
    return visitor->visitChildren(this);
}

MxParser::NewArrayExprContext* MxParser::newArrayExpr() {
  NewArrayExprContext *_localctx = _tracker.createInstance<NewArrayExprContext>(_ctx, getState());
  enterRule(_localctx, 42, MxParser::RuleNewArrayExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(337);
    match(MxParser::LeftBracket);
    setState(338);
    expression(0);
    setState(339);
    match(MxParser::RightBracket);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NewArrayEmptyContext ------------------------------------------------------------------

MxParser::NewArrayEmptyContext::NewArrayEmptyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::NewArrayEmptyContext::LeftBracket() {
  return getToken(MxParser::LeftBracket, 0);
}

tree::TerminalNode* MxParser::NewArrayEmptyContext::RightBracket() {
  return getToken(MxParser::RightBracket, 0);
}


size_t MxParser::NewArrayEmptyContext::getRuleIndex() const {
  return MxParser::RuleNewArrayEmpty;
}

std::any MxParser::NewArrayEmptyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitNewArrayEmpty(this);
  else
    return visitor->visitChildren(this);
}

MxParser::NewArrayEmptyContext* MxParser::newArrayEmpty() {
  NewArrayEmptyContext *_localctx = _tracker.createInstance<NewArrayEmptyContext>(_ctx, getState());
  enterRule(_localctx, 44, MxParser::RuleNewArrayEmpty);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(341);
    match(MxParser::LeftBracket);
    setState(342);
    match(MxParser::RightBracket);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralExprContext ------------------------------------------------------------------

MxParser::LiteralExprContext::LiteralExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::LiteralExprContext::NumberLiteral() {
  return getToken(MxParser::NumberLiteral, 0);
}

tree::TerminalNode* MxParser::LiteralExprContext::StringLiteral() {
  return getToken(MxParser::StringLiteral, 0);
}

tree::TerminalNode* MxParser::LiteralExprContext::NullLiteral() {
  return getToken(MxParser::NullLiteral, 0);
}

tree::TerminalNode* MxParser::LiteralExprContext::LogicalLiteral() {
  return getToken(MxParser::LogicalLiteral, 0);
}


size_t MxParser::LiteralExprContext::getRuleIndex() const {
  return MxParser::RuleLiteralExpr;
}

std::any MxParser::LiteralExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitLiteralExpr(this);
  else
    return visitor->visitChildren(this);
}

MxParser::LiteralExprContext* MxParser::literalExpr() {
  LiteralExprContext *_localctx = _tracker.createInstance<LiteralExprContext>(_ctx, getState());
  enterRule(_localctx, 46, MxParser::RuleLiteralExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(344);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 4123168604160) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BasicTypeContext ------------------------------------------------------------------

MxParser::BasicTypeContext::BasicTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* MxParser::BasicTypeContext::Bool() {
  return getToken(MxParser::Bool, 0);
}

tree::TerminalNode* MxParser::BasicTypeContext::Int() {
  return getToken(MxParser::Int, 0);
}

tree::TerminalNode* MxParser::BasicTypeContext::String() {
  return getToken(MxParser::String, 0);
}

tree::TerminalNode* MxParser::BasicTypeContext::Void() {
  return getToken(MxParser::Void, 0);
}


size_t MxParser::BasicTypeContext::getRuleIndex() const {
  return MxParser::RuleBasicType;
}

std::any MxParser::BasicTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<MxParserVisitor*>(visitor))
    return parserVisitor->visitBasicType(this);
  else
    return visitor->visitChildren(this);
}

MxParser::BasicTypeContext* MxParser::basicType() {
  BasicTypeContext *_localctx = _tracker.createInstance<BasicTypeContext>(_ctx, getState());
  enterRule(_localctx, 48, MxParser::RuleBasicType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(346);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 65970697666560) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool MxParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 16: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);
    case 19: return typeNameSempred(antlrcpp::downCast<TypeNameContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool MxParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 14);
    case 1: return precpred(_ctx, 13);
    case 2: return precpred(_ctx, 12);
    case 3: return precpred(_ctx, 11);
    case 4: return precpred(_ctx, 10);
    case 5: return precpred(_ctx, 9);
    case 6: return precpred(_ctx, 8);
    case 7: return precpred(_ctx, 7);
    case 8: return precpred(_ctx, 6);
    case 9: return precpred(_ctx, 5);
    case 10: return precpred(_ctx, 4);
    case 11: return precpred(_ctx, 3);
    case 12: return precpred(_ctx, 21);
    case 13: return precpred(_ctx, 20);
    case 14: return precpred(_ctx, 19);
    case 15: return precpred(_ctx, 18);

  default:
    break;
  }
  return true;
}

bool MxParser::typeNameSempred(TypeNameContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 16: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

void MxParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  mxparserParserInitialize();
#else
  ::antlr4::internal::call_once(mxparserParserOnceFlag, mxparserParserInitialize);
#endif
}
