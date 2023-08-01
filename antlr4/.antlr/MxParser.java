// Generated from /home/zsq259/桌面/项目/MxCompiler/antlr4/MxParser.g4 by ANTLR 4.9.2
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class MxParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.9.2", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		Comment=1, BlockComment=2, LineComment=3, Add=4, Sub=5, Mul=6, Div=7, 
		Mod=8, Gt=9, Lt=10, Geq=11, Leq=12, Neq=13, Eq=14, And=15, Or=16, Not=17, 
		Rs=18, Ls=19, BitAnd=20, BitOr=21, BitXor=22, BitInv=23, Assign=24, Incre=25, 
		Decre=26, Dot=27, Ques=28, Colon=29, LeftBracket=30, RightBracket=31, 
		LeftParen=32, RightParen=33, LeftBrace=34, RightBrace=35, Semicolon=36, 
		Comma=37, LogicalLiteral=38, NumberLiteral=39, StringLiteral=40, NullLiteral=41, 
		Void=42, Bool=43, Int=44, String=45, New=46, Class=47, Null=48, True=49, 
		False=50, This=51, ElseIf=52, If=53, Else=54, For=55, While=56, Break=57, 
		Continue=58, Return=59, Identifier=60, Whitespace=61, NewLine=62;
	public static final int
		RULE_program = 0, RULE_classDef = 1, RULE_classSuite = 2, RULE_constructDef = 3, 
		RULE_functionDef = 4, RULE_parameters = 5, RULE_varDef = 6, RULE_varDefInit = 7, 
		RULE_suite = 8, RULE_block = 9, RULE_stmt = 10, RULE_exprStmt = 11, RULE_exprList = 12, 
		RULE_ifStmt = 13, RULE_whileStmt = 14, RULE_forStmt = 15, RULE_flowStmt = 16, 
		RULE_expression = 17, RULE_varDefStmt = 18, RULE_typeName = 19, RULE_newTypeName = 20, 
		RULE_newArrayExpr = 21, RULE_newArrayEmpty = 22, RULE_literalExpr = 23, 
		RULE_basicType = 24;
	private static String[] makeRuleNames() {
		return new String[] {
			"program", "classDef", "classSuite", "constructDef", "functionDef", "parameters", 
			"varDef", "varDefInit", "suite", "block", "stmt", "exprStmt", "exprList", 
			"ifStmt", "whileStmt", "forStmt", "flowStmt", "expression", "varDefStmt", 
			"typeName", "newTypeName", "newArrayExpr", "newArrayEmpty", "literalExpr", 
			"basicType"
		};
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, null, null, null, "'+'", "'-'", "'*'", "'/'", "'%'", "'>'", "'<'", 
			"'>='", "'<='", "'!='", "'=='", "'&&'", "'||'", "'!'", "'>>'", "'<<'", 
			"'&'", "'|'", "'^'", "'~'", "'='", "'++'", "'--'", "'.'", "'?'", "':'", 
			"'['", "']'", "'('", "')'", "'{'", "'}'", "';'", "','", null, null, null, 
			null, "'void'", "'bool'", "'int'", "'string'", "'new'", "'class'", "'null'", 
			"'true'", "'false'", "'this'", null, "'if'", "'else'", "'for'", "'while'", 
			"'break'", "'continue'", "'return'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "Comment", "BlockComment", "LineComment", "Add", "Sub", "Mul", 
			"Div", "Mod", "Gt", "Lt", "Geq", "Leq", "Neq", "Eq", "And", "Or", "Not", 
			"Rs", "Ls", "BitAnd", "BitOr", "BitXor", "BitInv", "Assign", "Incre", 
			"Decre", "Dot", "Ques", "Colon", "LeftBracket", "RightBracket", "LeftParen", 
			"RightParen", "LeftBrace", "RightBrace", "Semicolon", "Comma", "LogicalLiteral", 
			"NumberLiteral", "StringLiteral", "NullLiteral", "Void", "Bool", "Int", 
			"String", "New", "Class", "Null", "True", "False", "This", "ElseIf", 
			"If", "Else", "For", "While", "Break", "Continue", "Return", "Identifier", 
			"Whitespace", "NewLine"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "MxParser.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public MxParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class ProgramContext extends ParserRuleContext {
		public TerminalNode EOF() { return getToken(MxParser.EOF, 0); }
		public List<FunctionDefContext> functionDef() {
			return getRuleContexts(FunctionDefContext.class);
		}
		public FunctionDefContext functionDef(int i) {
			return getRuleContext(FunctionDefContext.class,i);
		}
		public List<ClassDefContext> classDef() {
			return getRuleContexts(ClassDefContext.class);
		}
		public ClassDefContext classDef(int i) {
			return getRuleContext(ClassDefContext.class,i);
		}
		public List<VarDefStmtContext> varDefStmt() {
			return getRuleContexts(VarDefStmtContext.class);
		}
		public VarDefStmtContext varDefStmt(int i) {
			return getRuleContext(VarDefStmtContext.class,i);
		}
		public ProgramContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_program; }
	}

	public final ProgramContext program() throws RecognitionException {
		ProgramContext _localctx = new ProgramContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_program);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(55);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Void) | (1L << Bool) | (1L << Int) | (1L << String) | (1L << Class) | (1L << Identifier))) != 0)) {
				{
				setState(53);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,0,_ctx) ) {
				case 1:
					{
					setState(50);
					functionDef();
					}
					break;
				case 2:
					{
					setState(51);
					classDef();
					}
					break;
				case 3:
					{
					setState(52);
					varDefStmt();
					}
					break;
				}
				}
				setState(57);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(58);
			match(EOF);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ClassDefContext extends ParserRuleContext {
		public TerminalNode Class() { return getToken(MxParser.Class, 0); }
		public TerminalNode Identifier() { return getToken(MxParser.Identifier, 0); }
		public TerminalNode LeftBrace() { return getToken(MxParser.LeftBrace, 0); }
		public TerminalNode RightBrace() { return getToken(MxParser.RightBrace, 0); }
		public TerminalNode Semicolon() { return getToken(MxParser.Semicolon, 0); }
		public List<ClassSuiteContext> classSuite() {
			return getRuleContexts(ClassSuiteContext.class);
		}
		public ClassSuiteContext classSuite(int i) {
			return getRuleContext(ClassSuiteContext.class,i);
		}
		public ClassDefContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_classDef; }
	}

	public final ClassDefContext classDef() throws RecognitionException {
		ClassDefContext _localctx = new ClassDefContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_classDef);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(60);
			match(Class);
			setState(61);
			match(Identifier);
			setState(62);
			match(LeftBrace);
			setState(66);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Void) | (1L << Bool) | (1L << Int) | (1L << String) | (1L << Identifier))) != 0)) {
				{
				{
				setState(63);
				classSuite();
				}
				}
				setState(68);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(69);
			match(RightBrace);
			setState(70);
			match(Semicolon);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ClassSuiteContext extends ParserRuleContext {
		public VarDefStmtContext varDefStmt() {
			return getRuleContext(VarDefStmtContext.class,0);
		}
		public ConstructDefContext constructDef() {
			return getRuleContext(ConstructDefContext.class,0);
		}
		public FunctionDefContext functionDef() {
			return getRuleContext(FunctionDefContext.class,0);
		}
		public ClassSuiteContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_classSuite; }
	}

	public final ClassSuiteContext classSuite() throws RecognitionException {
		ClassSuiteContext _localctx = new ClassSuiteContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_classSuite);
		try {
			setState(75);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,3,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(72);
				varDefStmt();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(73);
				constructDef();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(74);
				functionDef();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ConstructDefContext extends ParserRuleContext {
		public TerminalNode Identifier() { return getToken(MxParser.Identifier, 0); }
		public TerminalNode LeftParen() { return getToken(MxParser.LeftParen, 0); }
		public TerminalNode RightParen() { return getToken(MxParser.RightParen, 0); }
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public ConstructDefContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_constructDef; }
	}

	public final ConstructDefContext constructDef() throws RecognitionException {
		ConstructDefContext _localctx = new ConstructDefContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_constructDef);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(77);
			match(Identifier);
			setState(78);
			match(LeftParen);
			setState(79);
			match(RightParen);
			setState(80);
			block();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FunctionDefContext extends ParserRuleContext {
		public TypeNameContext typeName() {
			return getRuleContext(TypeNameContext.class,0);
		}
		public TerminalNode Identifier() { return getToken(MxParser.Identifier, 0); }
		public TerminalNode LeftParen() { return getToken(MxParser.LeftParen, 0); }
		public TerminalNode RightParen() { return getToken(MxParser.RightParen, 0); }
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public ParametersContext parameters() {
			return getRuleContext(ParametersContext.class,0);
		}
		public FunctionDefContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_functionDef; }
	}

	public final FunctionDefContext functionDef() throws RecognitionException {
		FunctionDefContext _localctx = new FunctionDefContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_functionDef);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(82);
			typeName(0);
			setState(83);
			match(Identifier);
			setState(84);
			match(LeftParen);
			setState(86);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Void) | (1L << Bool) | (1L << Int) | (1L << String) | (1L << Identifier))) != 0)) {
				{
				setState(85);
				parameters();
				}
			}

			setState(88);
			match(RightParen);
			setState(89);
			block();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ParametersContext extends ParserRuleContext {
		public List<VarDefContext> varDef() {
			return getRuleContexts(VarDefContext.class);
		}
		public VarDefContext varDef(int i) {
			return getRuleContext(VarDefContext.class,i);
		}
		public List<TerminalNode> Comma() { return getTokens(MxParser.Comma); }
		public TerminalNode Comma(int i) {
			return getToken(MxParser.Comma, i);
		}
		public ParametersContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameters; }
	}

	public final ParametersContext parameters() throws RecognitionException {
		ParametersContext _localctx = new ParametersContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_parameters);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(91);
			varDef();
			setState(96);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==Comma) {
				{
				{
				setState(92);
				match(Comma);
				setState(93);
				varDef();
				}
				}
				setState(98);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class VarDefContext extends ParserRuleContext {
		public TypeNameContext typeName() {
			return getRuleContext(TypeNameContext.class,0);
		}
		public TerminalNode Identifier() { return getToken(MxParser.Identifier, 0); }
		public VarDefContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_varDef; }
	}

	public final VarDefContext varDef() throws RecognitionException {
		VarDefContext _localctx = new VarDefContext(_ctx, getState());
		enterRule(_localctx, 12, RULE_varDef);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(99);
			typeName(0);
			setState(100);
			match(Identifier);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class VarDefInitContext extends ParserRuleContext {
		public TerminalNode Identifier() { return getToken(MxParser.Identifier, 0); }
		public TerminalNode Assign() { return getToken(MxParser.Assign, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public VarDefInitContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_varDefInit; }
	}

	public final VarDefInitContext varDefInit() throws RecognitionException {
		VarDefInitContext _localctx = new VarDefInitContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_varDefInit);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(102);
			match(Identifier);
			setState(105);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==Assign) {
				{
				setState(103);
				match(Assign);
				setState(104);
				expression(0);
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SuiteContext extends ParserRuleContext {
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public StmtContext stmt() {
			return getRuleContext(StmtContext.class,0);
		}
		public SuiteContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_suite; }
	}

	public final SuiteContext suite() throws RecognitionException {
		SuiteContext _localctx = new SuiteContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_suite);
		try {
			setState(109);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,7,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(107);
				block();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(108);
				stmt();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BlockContext extends ParserRuleContext {
		public TerminalNode LeftBrace() { return getToken(MxParser.LeftBrace, 0); }
		public TerminalNode RightBrace() { return getToken(MxParser.RightBrace, 0); }
		public List<StmtContext> stmt() {
			return getRuleContexts(StmtContext.class);
		}
		public StmtContext stmt(int i) {
			return getRuleContext(StmtContext.class,i);
		}
		public BlockContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_block; }
	}

	public final BlockContext block() throws RecognitionException {
		BlockContext _localctx = new BlockContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_block);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(111);
			match(LeftBrace);
			setState(115);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Sub) | (1L << Not) | (1L << BitInv) | (1L << Incre) | (1L << Decre) | (1L << LeftParen) | (1L << LeftBrace) | (1L << Semicolon) | (1L << LogicalLiteral) | (1L << NumberLiteral) | (1L << StringLiteral) | (1L << NullLiteral) | (1L << Void) | (1L << Bool) | (1L << Int) | (1L << String) | (1L << New) | (1L << This) | (1L << If) | (1L << For) | (1L << While) | (1L << Break) | (1L << Continue) | (1L << Return) | (1L << Identifier))) != 0)) {
				{
				{
				setState(112);
				stmt();
				}
				}
				setState(117);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(118);
			match(RightBrace);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StmtContext extends ParserRuleContext {
		public ExprStmtContext exprStmt() {
			return getRuleContext(ExprStmtContext.class,0);
		}
		public IfStmtContext ifStmt() {
			return getRuleContext(IfStmtContext.class,0);
		}
		public WhileStmtContext whileStmt() {
			return getRuleContext(WhileStmtContext.class,0);
		}
		public ForStmtContext forStmt() {
			return getRuleContext(ForStmtContext.class,0);
		}
		public FlowStmtContext flowStmt() {
			return getRuleContext(FlowStmtContext.class,0);
		}
		public VarDefStmtContext varDefStmt() {
			return getRuleContext(VarDefStmtContext.class,0);
		}
		public BlockContext block() {
			return getRuleContext(BlockContext.class,0);
		}
		public StmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_stmt; }
	}

	public final StmtContext stmt() throws RecognitionException {
		StmtContext _localctx = new StmtContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_stmt);
		try {
			setState(127);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,9,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(120);
				exprStmt();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(121);
				ifStmt();
				}
				break;
			case 3:
				enterOuterAlt(_localctx, 3);
				{
				setState(122);
				whileStmt();
				}
				break;
			case 4:
				enterOuterAlt(_localctx, 4);
				{
				setState(123);
				forStmt();
				}
				break;
			case 5:
				enterOuterAlt(_localctx, 5);
				{
				setState(124);
				flowStmt();
				}
				break;
			case 6:
				enterOuterAlt(_localctx, 6);
				{
				setState(125);
				varDefStmt();
				}
				break;
			case 7:
				enterOuterAlt(_localctx, 7);
				{
				setState(126);
				block();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExprStmtContext extends ParserRuleContext {
		public TerminalNode Semicolon() { return getToken(MxParser.Semicolon, 0); }
		public ExprListContext exprList() {
			return getRuleContext(ExprListContext.class,0);
		}
		public ExprStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_exprStmt; }
	}

	public final ExprStmtContext exprStmt() throws RecognitionException {
		ExprStmtContext _localctx = new ExprStmtContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_exprStmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(130);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Sub) | (1L << Not) | (1L << BitInv) | (1L << Incre) | (1L << Decre) | (1L << LeftParen) | (1L << LogicalLiteral) | (1L << NumberLiteral) | (1L << StringLiteral) | (1L << NullLiteral) | (1L << New) | (1L << This) | (1L << Identifier))) != 0)) {
				{
				setState(129);
				exprList();
				}
			}

			setState(132);
			match(Semicolon);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExprListContext extends ParserRuleContext {
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public List<TerminalNode> Comma() { return getTokens(MxParser.Comma); }
		public TerminalNode Comma(int i) {
			return getToken(MxParser.Comma, i);
		}
		public ExprListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_exprList; }
	}

	public final ExprListContext exprList() throws RecognitionException {
		ExprListContext _localctx = new ExprListContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_exprList);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(134);
			expression(0);
			setState(139);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while (_la==Comma) {
				{
				{
				setState(135);
				match(Comma);
				setState(136);
				expression(0);
				}
				}
				setState(141);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IfStmtContext extends ParserRuleContext {
		public TerminalNode If() { return getToken(MxParser.If, 0); }
		public List<TerminalNode> LeftParen() { return getTokens(MxParser.LeftParen); }
		public TerminalNode LeftParen(int i) {
			return getToken(MxParser.LeftParen, i);
		}
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public List<TerminalNode> RightParen() { return getTokens(MxParser.RightParen); }
		public TerminalNode RightParen(int i) {
			return getToken(MxParser.RightParen, i);
		}
		public List<SuiteContext> suite() {
			return getRuleContexts(SuiteContext.class);
		}
		public SuiteContext suite(int i) {
			return getRuleContext(SuiteContext.class,i);
		}
		public List<TerminalNode> ElseIf() { return getTokens(MxParser.ElseIf); }
		public TerminalNode ElseIf(int i) {
			return getToken(MxParser.ElseIf, i);
		}
		public TerminalNode Else() { return getToken(MxParser.Else, 0); }
		public IfStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_ifStmt; }
	}

	public final IfStmtContext ifStmt() throws RecognitionException {
		IfStmtContext _localctx = new IfStmtContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_ifStmt);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(142);
			match(If);
			setState(143);
			match(LeftParen);
			setState(144);
			expression(0);
			setState(145);
			match(RightParen);
			setState(146);
			suite();
			setState(155);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(147);
					match(ElseIf);
					setState(148);
					match(LeftParen);
					setState(149);
					expression(0);
					setState(150);
					match(RightParen);
					setState(151);
					suite();
					}
					} 
				}
				setState(157);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,12,_ctx);
			}
			setState(160);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,13,_ctx) ) {
			case 1:
				{
				setState(158);
				match(Else);
				setState(159);
				suite();
				}
				break;
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class WhileStmtContext extends ParserRuleContext {
		public TerminalNode While() { return getToken(MxParser.While, 0); }
		public TerminalNode LeftParen() { return getToken(MxParser.LeftParen, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode RightParen() { return getToken(MxParser.RightParen, 0); }
		public SuiteContext suite() {
			return getRuleContext(SuiteContext.class,0);
		}
		public WhileStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_whileStmt; }
	}

	public final WhileStmtContext whileStmt() throws RecognitionException {
		WhileStmtContext _localctx = new WhileStmtContext(_ctx, getState());
		enterRule(_localctx, 28, RULE_whileStmt);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(162);
			match(While);
			setState(163);
			match(LeftParen);
			setState(164);
			expression(0);
			setState(165);
			match(RightParen);
			setState(166);
			suite();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ForStmtContext extends ParserRuleContext {
		public TerminalNode For() { return getToken(MxParser.For, 0); }
		public TerminalNode LeftParen() { return getToken(MxParser.LeftParen, 0); }
		public TerminalNode Semicolon() { return getToken(MxParser.Semicolon, 0); }
		public TerminalNode RightParen() { return getToken(MxParser.RightParen, 0); }
		public SuiteContext suite() {
			return getRuleContext(SuiteContext.class,0);
		}
		public ExprStmtContext exprStmt() {
			return getRuleContext(ExprStmtContext.class,0);
		}
		public VarDefStmtContext varDefStmt() {
			return getRuleContext(VarDefStmtContext.class,0);
		}
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public ForStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_forStmt; }
	}

	public final ForStmtContext forStmt() throws RecognitionException {
		ForStmtContext _localctx = new ForStmtContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_forStmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(168);
			match(For);
			setState(169);
			match(LeftParen);
			setState(172);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,14,_ctx) ) {
			case 1:
				{
				setState(170);
				exprStmt();
				}
				break;
			case 2:
				{
				setState(171);
				varDefStmt();
				}
				break;
			}
			setState(175);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Sub) | (1L << Not) | (1L << BitInv) | (1L << Incre) | (1L << Decre) | (1L << LeftParen) | (1L << LogicalLiteral) | (1L << NumberLiteral) | (1L << StringLiteral) | (1L << NullLiteral) | (1L << New) | (1L << This) | (1L << Identifier))) != 0)) {
				{
				setState(174);
				expression(0);
				}
			}

			setState(177);
			match(Semicolon);
			setState(179);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Sub) | (1L << Not) | (1L << BitInv) | (1L << Incre) | (1L << Decre) | (1L << LeftParen) | (1L << LogicalLiteral) | (1L << NumberLiteral) | (1L << StringLiteral) | (1L << NullLiteral) | (1L << New) | (1L << This) | (1L << Identifier))) != 0)) {
				{
				setState(178);
				expression(0);
				}
			}

			setState(181);
			match(RightParen);
			setState(182);
			suite();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FlowStmtContext extends ParserRuleContext {
		public TerminalNode Semicolon() { return getToken(MxParser.Semicolon, 0); }
		public TerminalNode Continue() { return getToken(MxParser.Continue, 0); }
		public TerminalNode Break() { return getToken(MxParser.Break, 0); }
		public TerminalNode Return() { return getToken(MxParser.Return, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public FlowStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_flowStmt; }
	}

	public final FlowStmtContext flowStmt() throws RecognitionException {
		FlowStmtContext _localctx = new FlowStmtContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_flowStmt);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(190);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Continue:
				{
				setState(184);
				match(Continue);
				}
				break;
			case Break:
				{
				setState(185);
				match(Break);
				}
				break;
			case Return:
				{
				{
				setState(186);
				match(Return);
				setState(188);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Sub) | (1L << Not) | (1L << BitInv) | (1L << Incre) | (1L << Decre) | (1L << LeftParen) | (1L << LogicalLiteral) | (1L << NumberLiteral) | (1L << StringLiteral) | (1L << NullLiteral) | (1L << New) | (1L << This) | (1L << Identifier))) != 0)) {
					{
					setState(187);
					expression(0);
					}
				}

				}
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			setState(192);
			match(Semicolon);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExpressionContext extends ParserRuleContext {
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
	 
		public ExpressionContext() { }
		public void copyFrom(ExpressionContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class ArrayExprContext extends ExpressionContext {
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode LeftBracket() { return getToken(MxParser.LeftBracket, 0); }
		public TerminalNode RightBracket() { return getToken(MxParser.RightBracket, 0); }
		public ArrayExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class FunctionExprContext extends ExpressionContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode LeftParen() { return getToken(MxParser.LeftParen, 0); }
		public TerminalNode RightParen() { return getToken(MxParser.RightParen, 0); }
		public ExprListContext exprList() {
			return getRuleContext(ExprListContext.class,0);
		}
		public FunctionExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class MemberExprContext extends ExpressionContext {
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode Dot() { return getToken(MxParser.Dot, 0); }
		public MemberExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class ParentheseExprContext extends ExpressionContext {
		public TerminalNode LeftParen() { return getToken(MxParser.LeftParen, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode RightParen() { return getToken(MxParser.RightParen, 0); }
		public ParentheseExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class LeftSingleExprContext extends ExpressionContext {
		public Token op;
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode Incre() { return getToken(MxParser.Incre, 0); }
		public TerminalNode Decre() { return getToken(MxParser.Decre, 0); }
		public TerminalNode Not() { return getToken(MxParser.Not, 0); }
		public TerminalNode BitInv() { return getToken(MxParser.BitInv, 0); }
		public TerminalNode Sub() { return getToken(MxParser.Sub, 0); }
		public LeftSingleExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class BinaryExprContext extends ExpressionContext {
		public ExpressionContext lhs;
		public Token op;
		public ExpressionContext rhs;
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode Mul() { return getToken(MxParser.Mul, 0); }
		public TerminalNode Div() { return getToken(MxParser.Div, 0); }
		public TerminalNode Mod() { return getToken(MxParser.Mod, 0); }
		public TerminalNode Add() { return getToken(MxParser.Add, 0); }
		public TerminalNode Sub() { return getToken(MxParser.Sub, 0); }
		public TerminalNode Rs() { return getToken(MxParser.Rs, 0); }
		public TerminalNode Ls() { return getToken(MxParser.Ls, 0); }
		public TerminalNode Geq() { return getToken(MxParser.Geq, 0); }
		public TerminalNode Leq() { return getToken(MxParser.Leq, 0); }
		public TerminalNode Lt() { return getToken(MxParser.Lt, 0); }
		public TerminalNode Gt() { return getToken(MxParser.Gt, 0); }
		public TerminalNode Neq() { return getToken(MxParser.Neq, 0); }
		public TerminalNode Eq() { return getToken(MxParser.Eq, 0); }
		public TerminalNode BitAnd() { return getToken(MxParser.BitAnd, 0); }
		public TerminalNode BitXor() { return getToken(MxParser.BitXor, 0); }
		public TerminalNode BitOr() { return getToken(MxParser.BitOr, 0); }
		public TerminalNode And() { return getToken(MxParser.And, 0); }
		public TerminalNode Or() { return getToken(MxParser.Or, 0); }
		public BinaryExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class NewExprContext extends ExpressionContext {
		public TerminalNode New() { return getToken(MxParser.New, 0); }
		public NewTypeNameContext newTypeName() {
			return getRuleContext(NewTypeNameContext.class,0);
		}
		public TerminalNode LeftParen() { return getToken(MxParser.LeftParen, 0); }
		public TerminalNode RightParen() { return getToken(MxParser.RightParen, 0); }
		public NewExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class LiterExprContext extends ExpressionContext {
		public LiteralExprContext literalExpr() {
			return getRuleContext(LiteralExprContext.class,0);
		}
		public LiterExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class RightSingleExprContext extends ExpressionContext {
		public Token op;
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode Incre() { return getToken(MxParser.Incre, 0); }
		public TerminalNode Decre() { return getToken(MxParser.Decre, 0); }
		public RightSingleExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class AtomExprContext extends ExpressionContext {
		public TerminalNode Identifier() { return getToken(MxParser.Identifier, 0); }
		public TerminalNode This() { return getToken(MxParser.This, 0); }
		public AtomExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class TernaryExprContext extends ExpressionContext {
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode Ques() { return getToken(MxParser.Ques, 0); }
		public TerminalNode Colon() { return getToken(MxParser.Colon, 0); }
		public TernaryExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}
	public static class AssignExprContext extends ExpressionContext {
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode Assign() { return getToken(MxParser.Assign, 0); }
		public AssignExprContext(ExpressionContext ctx) { copyFrom(ctx); }
	}

	public final ExpressionContext expression() throws RecognitionException {
		return expression(0);
	}

	private ExpressionContext expression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ExpressionContext _localctx = new ExpressionContext(_ctx, _parentState);
		ExpressionContext _prevctx = _localctx;
		int _startState = 34;
		enterRecursionRule(_localctx, 34, RULE_expression, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(211);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LeftParen:
				{
				_localctx = new ParentheseExprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(195);
				match(LeftParen);
				setState(196);
				expression(0);
				setState(197);
				match(RightParen);
				}
				break;
			case Incre:
			case Decre:
				{
				_localctx = new LeftSingleExprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(199);
				((LeftSingleExprContext)_localctx).op = _input.LT(1);
				_la = _input.LA(1);
				if ( !(_la==Incre || _la==Decre) ) {
					((LeftSingleExprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(200);
				expression(17);
				}
				break;
			case Sub:
			case Not:
			case BitInv:
				{
				_localctx = new LeftSingleExprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(201);
				((LeftSingleExprContext)_localctx).op = _input.LT(1);
				_la = _input.LA(1);
				if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Sub) | (1L << Not) | (1L << BitInv))) != 0)) ) {
					((LeftSingleExprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				setState(202);
				expression(16);
				}
				break;
			case New:
				{
				_localctx = new NewExprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(203);
				match(New);
				setState(204);
				newTypeName();
				setState(207);
				_errHandler.sync(this);
				switch ( getInterpreter().adaptivePredict(_input,19,_ctx) ) {
				case 1:
					{
					setState(205);
					match(LeftParen);
					setState(206);
					match(RightParen);
					}
					break;
				}
				}
				break;
			case LogicalLiteral:
			case NumberLiteral:
			case StringLiteral:
			case NullLiteral:
				{
				_localctx = new LiterExprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(209);
				literalExpr();
				}
				break;
			case This:
			case Identifier:
				{
				_localctx = new AtomExprContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(210);
				_la = _input.LA(1);
				if ( !(_la==This || _la==Identifier) ) {
				_errHandler.recoverInline(this);
				}
				else {
					if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
					_errHandler.reportMatch(this);
					consume();
				}
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(270);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,23,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(268);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,22,_ctx) ) {
					case 1:
						{
						_localctx = new MemberExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(213);
						if (!(precpred(_ctx, 19))) throw new FailedPredicateException(this, "precpred(_ctx, 19)");
						setState(214);
						match(Dot);
						setState(215);
						expression(20);
						}
						break;
					case 2:
						{
						_localctx = new BinaryExprContext(new ExpressionContext(_parentctx, _parentState));
						((BinaryExprContext)_localctx).lhs = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(216);
						if (!(precpred(_ctx, 14))) throw new FailedPredicateException(this, "precpred(_ctx, 14)");
						setState(217);
						((BinaryExprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Mul) | (1L << Div) | (1L << Mod))) != 0)) ) {
							((BinaryExprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(218);
						((BinaryExprContext)_localctx).rhs = expression(15);
						}
						break;
					case 3:
						{
						_localctx = new BinaryExprContext(new ExpressionContext(_parentctx, _parentState));
						((BinaryExprContext)_localctx).lhs = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(219);
						if (!(precpred(_ctx, 13))) throw new FailedPredicateException(this, "precpred(_ctx, 13)");
						setState(220);
						((BinaryExprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==Add || _la==Sub) ) {
							((BinaryExprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(221);
						((BinaryExprContext)_localctx).rhs = expression(14);
						}
						break;
					case 4:
						{
						_localctx = new BinaryExprContext(new ExpressionContext(_parentctx, _parentState));
						((BinaryExprContext)_localctx).lhs = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(222);
						if (!(precpred(_ctx, 12))) throw new FailedPredicateException(this, "precpred(_ctx, 12)");
						setState(223);
						((BinaryExprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==Rs || _la==Ls) ) {
							((BinaryExprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(224);
						((BinaryExprContext)_localctx).rhs = expression(13);
						}
						break;
					case 5:
						{
						_localctx = new BinaryExprContext(new ExpressionContext(_parentctx, _parentState));
						((BinaryExprContext)_localctx).lhs = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(225);
						if (!(precpred(_ctx, 11))) throw new FailedPredicateException(this, "precpred(_ctx, 11)");
						setState(226);
						((BinaryExprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Gt) | (1L << Lt) | (1L << Geq) | (1L << Leq))) != 0)) ) {
							((BinaryExprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(227);
						((BinaryExprContext)_localctx).rhs = expression(12);
						}
						break;
					case 6:
						{
						_localctx = new BinaryExprContext(new ExpressionContext(_parentctx, _parentState));
						((BinaryExprContext)_localctx).lhs = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(228);
						if (!(precpred(_ctx, 10))) throw new FailedPredicateException(this, "precpred(_ctx, 10)");
						setState(229);
						((BinaryExprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==Neq || _la==Eq) ) {
							((BinaryExprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						setState(230);
						((BinaryExprContext)_localctx).rhs = expression(11);
						}
						break;
					case 7:
						{
						_localctx = new BinaryExprContext(new ExpressionContext(_parentctx, _parentState));
						((BinaryExprContext)_localctx).lhs = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(231);
						if (!(precpred(_ctx, 9))) throw new FailedPredicateException(this, "precpred(_ctx, 9)");
						setState(232);
						((BinaryExprContext)_localctx).op = match(BitAnd);
						setState(233);
						((BinaryExprContext)_localctx).rhs = expression(10);
						}
						break;
					case 8:
						{
						_localctx = new BinaryExprContext(new ExpressionContext(_parentctx, _parentState));
						((BinaryExprContext)_localctx).lhs = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(234);
						if (!(precpred(_ctx, 8))) throw new FailedPredicateException(this, "precpred(_ctx, 8)");
						setState(235);
						((BinaryExprContext)_localctx).op = match(BitXor);
						setState(236);
						((BinaryExprContext)_localctx).rhs = expression(9);
						}
						break;
					case 9:
						{
						_localctx = new BinaryExprContext(new ExpressionContext(_parentctx, _parentState));
						((BinaryExprContext)_localctx).lhs = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(237);
						if (!(precpred(_ctx, 7))) throw new FailedPredicateException(this, "precpred(_ctx, 7)");
						setState(238);
						((BinaryExprContext)_localctx).op = match(BitOr);
						setState(239);
						((BinaryExprContext)_localctx).rhs = expression(8);
						}
						break;
					case 10:
						{
						_localctx = new BinaryExprContext(new ExpressionContext(_parentctx, _parentState));
						((BinaryExprContext)_localctx).lhs = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(240);
						if (!(precpred(_ctx, 6))) throw new FailedPredicateException(this, "precpred(_ctx, 6)");
						setState(241);
						((BinaryExprContext)_localctx).op = match(And);
						setState(242);
						((BinaryExprContext)_localctx).rhs = expression(7);
						}
						break;
					case 11:
						{
						_localctx = new BinaryExprContext(new ExpressionContext(_parentctx, _parentState));
						((BinaryExprContext)_localctx).lhs = _prevctx;
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(243);
						if (!(precpred(_ctx, 5))) throw new FailedPredicateException(this, "precpred(_ctx, 5)");
						setState(244);
						((BinaryExprContext)_localctx).op = match(Or);
						setState(245);
						((BinaryExprContext)_localctx).rhs = expression(6);
						}
						break;
					case 12:
						{
						_localctx = new TernaryExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(246);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(247);
						match(Ques);
						setState(248);
						expression(0);
						setState(249);
						match(Colon);
						setState(250);
						expression(4);
						}
						break;
					case 13:
						{
						_localctx = new AssignExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(252);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(253);
						match(Assign);
						setState(254);
						expression(3);
						}
						break;
					case 14:
						{
						_localctx = new FunctionExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(255);
						if (!(precpred(_ctx, 21))) throw new FailedPredicateException(this, "precpred(_ctx, 21)");
						setState(256);
						match(LeftParen);
						setState(258);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Sub) | (1L << Not) | (1L << BitInv) | (1L << Incre) | (1L << Decre) | (1L << LeftParen) | (1L << LogicalLiteral) | (1L << NumberLiteral) | (1L << StringLiteral) | (1L << NullLiteral) | (1L << New) | (1L << This) | (1L << Identifier))) != 0)) {
							{
							setState(257);
							exprList();
							}
						}

						setState(260);
						match(RightParen);
						}
						break;
					case 15:
						{
						_localctx = new ArrayExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(261);
						if (!(precpred(_ctx, 20))) throw new FailedPredicateException(this, "precpred(_ctx, 20)");
						setState(262);
						match(LeftBracket);
						setState(263);
						expression(0);
						setState(264);
						match(RightBracket);
						}
						break;
					case 16:
						{
						_localctx = new RightSingleExprContext(new ExpressionContext(_parentctx, _parentState));
						pushNewRecursionContext(_localctx, _startState, RULE_expression);
						setState(266);
						if (!(precpred(_ctx, 18))) throw new FailedPredicateException(this, "precpred(_ctx, 18)");
						setState(267);
						((RightSingleExprContext)_localctx).op = _input.LT(1);
						_la = _input.LA(1);
						if ( !(_la==Incre || _la==Decre) ) {
							((RightSingleExprContext)_localctx).op = (Token)_errHandler.recoverInline(this);
						}
						else {
							if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
							_errHandler.reportMatch(this);
							consume();
						}
						}
						break;
					}
					} 
				}
				setState(272);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,23,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class VarDefStmtContext extends ParserRuleContext {
		public TypeNameContext typeName() {
			return getRuleContext(TypeNameContext.class,0);
		}
		public List<VarDefInitContext> varDefInit() {
			return getRuleContexts(VarDefInitContext.class);
		}
		public VarDefInitContext varDefInit(int i) {
			return getRuleContext(VarDefInitContext.class,i);
		}
		public TerminalNode Semicolon() { return getToken(MxParser.Semicolon, 0); }
		public List<TerminalNode> Comma() { return getTokens(MxParser.Comma); }
		public TerminalNode Comma(int i) {
			return getToken(MxParser.Comma, i);
		}
		public VarDefStmtContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_varDefStmt; }
	}

	public final VarDefStmtContext varDefStmt() throws RecognitionException {
		VarDefStmtContext _localctx = new VarDefStmtContext(_ctx, getState());
		enterRule(_localctx, 36, RULE_varDefStmt);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(273);
			typeName(0);
			setState(279);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,24,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					{
					{
					setState(274);
					varDefInit();
					setState(275);
					match(Comma);
					}
					} 
				}
				setState(281);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,24,_ctx);
			}
			setState(282);
			varDefInit();
			setState(283);
			match(Semicolon);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class TypeNameContext extends ParserRuleContext {
		public TypeNameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_typeName; }
	 
		public TypeNameContext() { }
		public void copyFrom(TypeNameContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class ArrayContext extends TypeNameContext {
		public TypeNameContext typeName() {
			return getRuleContext(TypeNameContext.class,0);
		}
		public TerminalNode LeftBracket() { return getToken(MxParser.LeftBracket, 0); }
		public TerminalNode RightBracket() { return getToken(MxParser.RightBracket, 0); }
		public ArrayContext(TypeNameContext ctx) { copyFrom(ctx); }
	}
	public static class BasicContext extends TypeNameContext {
		public BasicTypeContext basicType() {
			return getRuleContext(BasicTypeContext.class,0);
		}
		public BasicContext(TypeNameContext ctx) { copyFrom(ctx); }
	}
	public static class ClassContext extends TypeNameContext {
		public TerminalNode Identifier() { return getToken(MxParser.Identifier, 0); }
		public ClassContext(TypeNameContext ctx) { copyFrom(ctx); }
	}

	public final TypeNameContext typeName() throws RecognitionException {
		return typeName(0);
	}

	private TypeNameContext typeName(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		TypeNameContext _localctx = new TypeNameContext(_ctx, _parentState);
		TypeNameContext _prevctx = _localctx;
		int _startState = 38;
		enterRecursionRule(_localctx, 38, RULE_typeName, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			setState(288);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Void:
			case Bool:
			case Int:
			case String:
				{
				_localctx = new BasicContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;

				setState(286);
				basicType();
				}
				break;
			case Identifier:
				{
				_localctx = new ClassContext(_localctx);
				_ctx = _localctx;
				_prevctx = _localctx;
				setState(287);
				match(Identifier);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
			_ctx.stop = _input.LT(-1);
			setState(295);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,26,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ArrayContext(new TypeNameContext(_parentctx, _parentState));
					pushNewRecursionContext(_localctx, _startState, RULE_typeName);
					setState(290);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(291);
					match(LeftBracket);
					setState(292);
					match(RightBracket);
					}
					} 
				}
				setState(297);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,26,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class NewTypeNameContext extends ParserRuleContext {
		public NewTypeNameContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_newTypeName; }
	 
		public NewTypeNameContext() { }
		public void copyFrom(NewTypeNameContext ctx) {
			super.copyFrom(ctx);
		}
	}
	public static class NewBasicArrayContext extends NewTypeNameContext {
		public NewArrayExprContext fail;
		public BasicTypeContext basicType() {
			return getRuleContext(BasicTypeContext.class,0);
		}
		public List<NewArrayExprContext> newArrayExpr() {
			return getRuleContexts(NewArrayExprContext.class);
		}
		public NewArrayExprContext newArrayExpr(int i) {
			return getRuleContext(NewArrayExprContext.class,i);
		}
		public List<NewArrayEmptyContext> newArrayEmpty() {
			return getRuleContexts(NewArrayEmptyContext.class);
		}
		public NewArrayEmptyContext newArrayEmpty(int i) {
			return getRuleContext(NewArrayEmptyContext.class,i);
		}
		public NewBasicArrayContext(NewTypeNameContext ctx) { copyFrom(ctx); }
	}
	public static class NewClassContext extends NewTypeNameContext {
		public TerminalNode Identifier() { return getToken(MxParser.Identifier, 0); }
		public NewClassContext(NewTypeNameContext ctx) { copyFrom(ctx); }
	}
	public static class NewClassArrayContext extends NewTypeNameContext {
		public NewArrayExprContext fail;
		public TerminalNode Identifier() { return getToken(MxParser.Identifier, 0); }
		public List<NewArrayExprContext> newArrayExpr() {
			return getRuleContexts(NewArrayExprContext.class);
		}
		public NewArrayExprContext newArrayExpr(int i) {
			return getRuleContext(NewArrayExprContext.class,i);
		}
		public List<NewArrayEmptyContext> newArrayEmpty() {
			return getRuleContexts(NewArrayEmptyContext.class);
		}
		public NewArrayEmptyContext newArrayEmpty(int i) {
			return getRuleContext(NewArrayEmptyContext.class,i);
		}
		public NewClassArrayContext(NewTypeNameContext ctx) { copyFrom(ctx); }
	}

	public final NewTypeNameContext newTypeName() throws RecognitionException {
		NewTypeNameContext _localctx = new NewTypeNameContext(_ctx, getState());
		enterRule(_localctx, 40, RULE_newTypeName);
		try {
			int _alt;
			setState(335);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,33,_ctx) ) {
			case 1:
				_localctx = new NewClassContext(_localctx);
				enterOuterAlt(_localctx, 1);
				{
				setState(298);
				match(Identifier);
				}
				break;
			case 2:
				_localctx = new NewClassArrayContext(_localctx);
				enterOuterAlt(_localctx, 2);
				{
				setState(299);
				match(Identifier);
				setState(301); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(300);
						newArrayExpr();
						}
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					setState(303); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,27,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				setState(308);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,28,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(305);
						newArrayEmpty();
						}
						} 
					}
					setState(310);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,28,_ctx);
				}
				setState(314);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,29,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(311);
						((NewClassArrayContext)_localctx).fail = newArrayExpr();
						}
						} 
					}
					setState(316);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,29,_ctx);
				}
				}
				break;
			case 3:
				_localctx = new NewBasicArrayContext(_localctx);
				enterOuterAlt(_localctx, 3);
				{
				setState(317);
				basicType();
				setState(319); 
				_errHandler.sync(this);
				_alt = 1;
				do {
					switch (_alt) {
					case 1:
						{
						{
						setState(318);
						newArrayExpr();
						}
						}
						break;
					default:
						throw new NoViableAltException(this);
					}
					setState(321); 
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,30,_ctx);
				} while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER );
				setState(326);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,31,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(323);
						newArrayEmpty();
						}
						} 
					}
					setState(328);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,31,_ctx);
				}
				setState(332);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,32,_ctx);
				while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
					if ( _alt==1 ) {
						{
						{
						setState(329);
						((NewBasicArrayContext)_localctx).fail = newArrayExpr();
						}
						} 
					}
					setState(334);
					_errHandler.sync(this);
					_alt = getInterpreter().adaptivePredict(_input,32,_ctx);
				}
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class NewArrayExprContext extends ParserRuleContext {
		public TerminalNode LeftBracket() { return getToken(MxParser.LeftBracket, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode RightBracket() { return getToken(MxParser.RightBracket, 0); }
		public NewArrayExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_newArrayExpr; }
	}

	public final NewArrayExprContext newArrayExpr() throws RecognitionException {
		NewArrayExprContext _localctx = new NewArrayExprContext(_ctx, getState());
		enterRule(_localctx, 42, RULE_newArrayExpr);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(337);
			match(LeftBracket);
			setState(338);
			expression(0);
			setState(339);
			match(RightBracket);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class NewArrayEmptyContext extends ParserRuleContext {
		public TerminalNode LeftBracket() { return getToken(MxParser.LeftBracket, 0); }
		public TerminalNode RightBracket() { return getToken(MxParser.RightBracket, 0); }
		public NewArrayEmptyContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_newArrayEmpty; }
	}

	public final NewArrayEmptyContext newArrayEmpty() throws RecognitionException {
		NewArrayEmptyContext _localctx = new NewArrayEmptyContext(_ctx, getState());
		enterRule(_localctx, 44, RULE_newArrayEmpty);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(341);
			match(LeftBracket);
			setState(342);
			match(RightBracket);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class LiteralExprContext extends ParserRuleContext {
		public TerminalNode NumberLiteral() { return getToken(MxParser.NumberLiteral, 0); }
		public TerminalNode StringLiteral() { return getToken(MxParser.StringLiteral, 0); }
		public TerminalNode NullLiteral() { return getToken(MxParser.NullLiteral, 0); }
		public TerminalNode LogicalLiteral() { return getToken(MxParser.LogicalLiteral, 0); }
		public LiteralExprContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_literalExpr; }
	}

	public final LiteralExprContext literalExpr() throws RecognitionException {
		LiteralExprContext _localctx = new LiteralExprContext(_ctx, getState());
		enterRule(_localctx, 46, RULE_literalExpr);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(344);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << LogicalLiteral) | (1L << NumberLiteral) | (1L << StringLiteral) | (1L << NullLiteral))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class BasicTypeContext extends ParserRuleContext {
		public TerminalNode Bool() { return getToken(MxParser.Bool, 0); }
		public TerminalNode Int() { return getToken(MxParser.Int, 0); }
		public TerminalNode String() { return getToken(MxParser.String, 0); }
		public TerminalNode Void() { return getToken(MxParser.Void, 0); }
		public BasicTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_basicType; }
	}

	public final BasicTypeContext basicType() throws RecognitionException {
		BasicTypeContext _localctx = new BasicTypeContext(_ctx, getState());
		enterRule(_localctx, 48, RULE_basicType);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(346);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Void) | (1L << Bool) | (1L << Int) | (1L << String))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 17:
			return expression_sempred((ExpressionContext)_localctx, predIndex);
		case 19:
			return typeName_sempred((TypeNameContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean expression_sempred(ExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 19);
		case 1:
			return precpred(_ctx, 14);
		case 2:
			return precpred(_ctx, 13);
		case 3:
			return precpred(_ctx, 12);
		case 4:
			return precpred(_ctx, 11);
		case 5:
			return precpred(_ctx, 10);
		case 6:
			return precpred(_ctx, 9);
		case 7:
			return precpred(_ctx, 8);
		case 8:
			return precpred(_ctx, 7);
		case 9:
			return precpred(_ctx, 6);
		case 10:
			return precpred(_ctx, 5);
		case 11:
			return precpred(_ctx, 4);
		case 12:
			return precpred(_ctx, 3);
		case 13:
			return precpred(_ctx, 21);
		case 14:
			return precpred(_ctx, 20);
		case 15:
			return precpred(_ctx, 18);
		}
		return true;
	}
	private boolean typeName_sempred(TypeNameContext _localctx, int predIndex) {
		switch (predIndex) {
		case 16:
			return precpred(_ctx, 1);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3@\u015f\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"+
		"\4\32\t\32\3\2\3\2\3\2\7\28\n\2\f\2\16\2;\13\2\3\2\3\2\3\3\3\3\3\3\3\3"+
		"\7\3C\n\3\f\3\16\3F\13\3\3\3\3\3\3\3\3\4\3\4\3\4\5\4N\n\4\3\5\3\5\3\5"+
		"\3\5\3\5\3\6\3\6\3\6\3\6\5\6Y\n\6\3\6\3\6\3\6\3\7\3\7\3\7\7\7a\n\7\f\7"+
		"\16\7d\13\7\3\b\3\b\3\b\3\t\3\t\3\t\5\tl\n\t\3\n\3\n\5\np\n\n\3\13\3\13"+
		"\7\13t\n\13\f\13\16\13w\13\13\3\13\3\13\3\f\3\f\3\f\3\f\3\f\3\f\3\f\5"+
		"\f\u0082\n\f\3\r\5\r\u0085\n\r\3\r\3\r\3\16\3\16\3\16\7\16\u008c\n\16"+
		"\f\16\16\16\u008f\13\16\3\17\3\17\3\17\3\17\3\17\3\17\3\17\3\17\3\17\3"+
		"\17\3\17\7\17\u009c\n\17\f\17\16\17\u009f\13\17\3\17\3\17\5\17\u00a3\n"+
		"\17\3\20\3\20\3\20\3\20\3\20\3\20\3\21\3\21\3\21\3\21\5\21\u00af\n\21"+
		"\3\21\5\21\u00b2\n\21\3\21\3\21\5\21\u00b6\n\21\3\21\3\21\3\21\3\22\3"+
		"\22\3\22\3\22\5\22\u00bf\n\22\5\22\u00c1\n\22\3\22\3\22\3\23\3\23\3\23"+
		"\3\23\3\23\3\23\3\23\3\23\3\23\3\23\3\23\3\23\3\23\5\23\u00d2\n\23\3\23"+
		"\3\23\5\23\u00d6\n\23\3\23\3\23\3\23\3\23\3\23\3\23\3\23\3\23\3\23\3\23"+
		"\3\23\3\23\3\23\3\23\3\23\3\23\3\23\3\23\3\23\3\23\3\23\3\23\3\23\3\23"+
		"\3\23\3\23\3\23\3\23\3\23\3\23\3\23\3\23\3\23\3\23\3\23\3\23\3\23\3\23"+
		"\3\23\3\23\3\23\3\23\3\23\3\23\3\23\5\23\u0105\n\23\3\23\3\23\3\23\3\23"+
		"\3\23\3\23\3\23\3\23\7\23\u010f\n\23\f\23\16\23\u0112\13\23\3\24\3\24"+
		"\3\24\3\24\7\24\u0118\n\24\f\24\16\24\u011b\13\24\3\24\3\24\3\24\3\25"+
		"\3\25\3\25\5\25\u0123\n\25\3\25\3\25\3\25\7\25\u0128\n\25\f\25\16\25\u012b"+
		"\13\25\3\26\3\26\3\26\6\26\u0130\n\26\r\26\16\26\u0131\3\26\7\26\u0135"+
		"\n\26\f\26\16\26\u0138\13\26\3\26\7\26\u013b\n\26\f\26\16\26\u013e\13"+
		"\26\3\26\3\26\6\26\u0142\n\26\r\26\16\26\u0143\3\26\7\26\u0147\n\26\f"+
		"\26\16\26\u014a\13\26\3\26\7\26\u014d\n\26\f\26\16\26\u0150\13\26\5\26"+
		"\u0152\n\26\3\27\3\27\3\27\3\27\3\30\3\30\3\30\3\31\3\31\3\32\3\32\3\32"+
		"\2\4$(\33\2\4\6\b\n\f\16\20\22\24\26\30\32\34\36 \"$&(*,.\60\62\2\f\3"+
		"\2\33\34\5\2\7\7\23\23\31\31\4\2\65\65>>\3\2\b\n\3\2\6\7\3\2\24\25\3\2"+
		"\13\16\3\2\17\20\3\2(+\3\2,/\2\u0183\29\3\2\2\2\4>\3\2\2\2\6M\3\2\2\2"+
		"\bO\3\2\2\2\nT\3\2\2\2\f]\3\2\2\2\16e\3\2\2\2\20h\3\2\2\2\22o\3\2\2\2"+
		"\24q\3\2\2\2\26\u0081\3\2\2\2\30\u0084\3\2\2\2\32\u0088\3\2\2\2\34\u0090"+
		"\3\2\2\2\36\u00a4\3\2\2\2 \u00aa\3\2\2\2\"\u00c0\3\2\2\2$\u00d5\3\2\2"+
		"\2&\u0113\3\2\2\2(\u0122\3\2\2\2*\u0151\3\2\2\2,\u0153\3\2\2\2.\u0157"+
		"\3\2\2\2\60\u015a\3\2\2\2\62\u015c\3\2\2\2\648\5\n\6\2\658\5\4\3\2\66"+
		"8\5&\24\2\67\64\3\2\2\2\67\65\3\2\2\2\67\66\3\2\2\28;\3\2\2\29\67\3\2"+
		"\2\29:\3\2\2\2:<\3\2\2\2;9\3\2\2\2<=\7\2\2\3=\3\3\2\2\2>?\7\61\2\2?@\7"+
		">\2\2@D\7$\2\2AC\5\6\4\2BA\3\2\2\2CF\3\2\2\2DB\3\2\2\2DE\3\2\2\2EG\3\2"+
		"\2\2FD\3\2\2\2GH\7%\2\2HI\7&\2\2I\5\3\2\2\2JN\5&\24\2KN\5\b\5\2LN\5\n"+
		"\6\2MJ\3\2\2\2MK\3\2\2\2ML\3\2\2\2N\7\3\2\2\2OP\7>\2\2PQ\7\"\2\2QR\7#"+
		"\2\2RS\5\24\13\2S\t\3\2\2\2TU\5(\25\2UV\7>\2\2VX\7\"\2\2WY\5\f\7\2XW\3"+
		"\2\2\2XY\3\2\2\2YZ\3\2\2\2Z[\7#\2\2[\\\5\24\13\2\\\13\3\2\2\2]b\5\16\b"+
		"\2^_\7\'\2\2_a\5\16\b\2`^\3\2\2\2ad\3\2\2\2b`\3\2\2\2bc\3\2\2\2c\r\3\2"+
		"\2\2db\3\2\2\2ef\5(\25\2fg\7>\2\2g\17\3\2\2\2hk\7>\2\2ij\7\32\2\2jl\5"+
		"$\23\2ki\3\2\2\2kl\3\2\2\2l\21\3\2\2\2mp\5\24\13\2np\5\26\f\2om\3\2\2"+
		"\2on\3\2\2\2p\23\3\2\2\2qu\7$\2\2rt\5\26\f\2sr\3\2\2\2tw\3\2\2\2us\3\2"+
		"\2\2uv\3\2\2\2vx\3\2\2\2wu\3\2\2\2xy\7%\2\2y\25\3\2\2\2z\u0082\5\30\r"+
		"\2{\u0082\5\34\17\2|\u0082\5\36\20\2}\u0082\5 \21\2~\u0082\5\"\22\2\177"+
		"\u0082\5&\24\2\u0080\u0082\5\24\13\2\u0081z\3\2\2\2\u0081{\3\2\2\2\u0081"+
		"|\3\2\2\2\u0081}\3\2\2\2\u0081~\3\2\2\2\u0081\177\3\2\2\2\u0081\u0080"+
		"\3\2\2\2\u0082\27\3\2\2\2\u0083\u0085\5\32\16\2\u0084\u0083\3\2\2\2\u0084"+
		"\u0085\3\2\2\2\u0085\u0086\3\2\2\2\u0086\u0087\7&\2\2\u0087\31\3\2\2\2"+
		"\u0088\u008d\5$\23\2\u0089\u008a\7\'\2\2\u008a\u008c\5$\23\2\u008b\u0089"+
		"\3\2\2\2\u008c\u008f\3\2\2\2\u008d\u008b\3\2\2\2\u008d\u008e\3\2\2\2\u008e"+
		"\33\3\2\2\2\u008f\u008d\3\2\2\2\u0090\u0091\7\67\2\2\u0091\u0092\7\"\2"+
		"\2\u0092\u0093\5$\23\2\u0093\u0094\7#\2\2\u0094\u009d\5\22\n\2\u0095\u0096"+
		"\7\66\2\2\u0096\u0097\7\"\2\2\u0097\u0098\5$\23\2\u0098\u0099\7#\2\2\u0099"+
		"\u009a\5\22\n\2\u009a\u009c\3\2\2\2\u009b\u0095\3\2\2\2\u009c\u009f\3"+
		"\2\2\2\u009d\u009b\3\2\2\2\u009d\u009e\3\2\2\2\u009e\u00a2\3\2\2\2\u009f"+
		"\u009d\3\2\2\2\u00a0\u00a1\78\2\2\u00a1\u00a3\5\22\n\2\u00a2\u00a0\3\2"+
		"\2\2\u00a2\u00a3\3\2\2\2\u00a3\35\3\2\2\2\u00a4\u00a5\7:\2\2\u00a5\u00a6"+
		"\7\"\2\2\u00a6\u00a7\5$\23\2\u00a7\u00a8\7#\2\2\u00a8\u00a9\5\22\n\2\u00a9"+
		"\37\3\2\2\2\u00aa\u00ab\79\2\2\u00ab\u00ae\7\"\2\2\u00ac\u00af\5\30\r"+
		"\2\u00ad\u00af\5&\24\2\u00ae\u00ac\3\2\2\2\u00ae\u00ad\3\2\2\2\u00ae\u00af"+
		"\3\2\2\2\u00af\u00b1\3\2\2\2\u00b0\u00b2\5$\23\2\u00b1\u00b0\3\2\2\2\u00b1"+
		"\u00b2\3\2\2\2\u00b2\u00b3\3\2\2\2\u00b3\u00b5\7&\2\2\u00b4\u00b6\5$\23"+
		"\2\u00b5\u00b4\3\2\2\2\u00b5\u00b6\3\2\2\2\u00b6\u00b7\3\2\2\2\u00b7\u00b8"+
		"\7#\2\2\u00b8\u00b9\5\22\n\2\u00b9!\3\2\2\2\u00ba\u00c1\7<\2\2\u00bb\u00c1"+
		"\7;\2\2\u00bc\u00be\7=\2\2\u00bd\u00bf\5$\23\2\u00be\u00bd\3\2\2\2\u00be"+
		"\u00bf\3\2\2\2\u00bf\u00c1\3\2\2\2\u00c0\u00ba\3\2\2\2\u00c0\u00bb\3\2"+
		"\2\2\u00c0\u00bc\3\2\2\2\u00c1\u00c2\3\2\2\2\u00c2\u00c3\7&\2\2\u00c3"+
		"#\3\2\2\2\u00c4\u00c5\b\23\1\2\u00c5\u00c6\7\"\2\2\u00c6\u00c7\5$\23\2"+
		"\u00c7\u00c8\7#\2\2\u00c8\u00d6\3\2\2\2\u00c9\u00ca\t\2\2\2\u00ca\u00d6"+
		"\5$\23\23\u00cb\u00cc\t\3\2\2\u00cc\u00d6\5$\23\22\u00cd\u00ce\7\60\2"+
		"\2\u00ce\u00d1\5*\26\2\u00cf\u00d0\7\"\2\2\u00d0\u00d2\7#\2\2\u00d1\u00cf"+
		"\3\2\2\2\u00d1\u00d2\3\2\2\2\u00d2\u00d6\3\2\2\2\u00d3\u00d6\5\60\31\2"+
		"\u00d4\u00d6\t\4\2\2\u00d5\u00c4\3\2\2\2\u00d5\u00c9\3\2\2\2\u00d5\u00cb"+
		"\3\2\2\2\u00d5\u00cd\3\2\2\2\u00d5\u00d3\3\2\2\2\u00d5\u00d4\3\2\2\2\u00d6"+
		"\u0110\3\2\2\2\u00d7\u00d8\f\25\2\2\u00d8\u00d9\7\35\2\2\u00d9\u010f\5"+
		"$\23\26\u00da\u00db\f\20\2\2\u00db\u00dc\t\5\2\2\u00dc\u010f\5$\23\21"+
		"\u00dd\u00de\f\17\2\2\u00de\u00df\t\6\2\2\u00df\u010f\5$\23\20\u00e0\u00e1"+
		"\f\16\2\2\u00e1\u00e2\t\7\2\2\u00e2\u010f\5$\23\17\u00e3\u00e4\f\r\2\2"+
		"\u00e4\u00e5\t\b\2\2\u00e5\u010f\5$\23\16\u00e6\u00e7\f\f\2\2\u00e7\u00e8"+
		"\t\t\2\2\u00e8\u010f\5$\23\r\u00e9\u00ea\f\13\2\2\u00ea\u00eb\7\26\2\2"+
		"\u00eb\u010f\5$\23\f\u00ec\u00ed\f\n\2\2\u00ed\u00ee\7\30\2\2\u00ee\u010f"+
		"\5$\23\13\u00ef\u00f0\f\t\2\2\u00f0\u00f1\7\27\2\2\u00f1\u010f\5$\23\n"+
		"\u00f2\u00f3\f\b\2\2\u00f3\u00f4\7\21\2\2\u00f4\u010f\5$\23\t\u00f5\u00f6"+
		"\f\7\2\2\u00f6\u00f7\7\22\2\2\u00f7\u010f\5$\23\b\u00f8\u00f9\f\6\2\2"+
		"\u00f9\u00fa\7\36\2\2\u00fa\u00fb\5$\23\2\u00fb\u00fc\7\37\2\2\u00fc\u00fd"+
		"\5$\23\6\u00fd\u010f\3\2\2\2\u00fe\u00ff\f\5\2\2\u00ff\u0100\7\32\2\2"+
		"\u0100\u010f\5$\23\5\u0101\u0102\f\27\2\2\u0102\u0104\7\"\2\2\u0103\u0105"+
		"\5\32\16\2\u0104\u0103\3\2\2\2\u0104\u0105\3\2\2\2\u0105\u0106\3\2\2\2"+
		"\u0106\u010f\7#\2\2\u0107\u0108\f\26\2\2\u0108\u0109\7 \2\2\u0109\u010a"+
		"\5$\23\2\u010a\u010b\7!\2\2\u010b\u010f\3\2\2\2\u010c\u010d\f\24\2\2\u010d"+
		"\u010f\t\2\2\2\u010e\u00d7\3\2\2\2\u010e\u00da\3\2\2\2\u010e\u00dd\3\2"+
		"\2\2\u010e\u00e0\3\2\2\2\u010e\u00e3\3\2\2\2\u010e\u00e6\3\2\2\2\u010e"+
		"\u00e9\3\2\2\2\u010e\u00ec\3\2\2\2\u010e\u00ef\3\2\2\2\u010e\u00f2\3\2"+
		"\2\2\u010e\u00f5\3\2\2\2\u010e\u00f8\3\2\2\2\u010e\u00fe\3\2\2\2\u010e"+
		"\u0101\3\2\2\2\u010e\u0107\3\2\2\2\u010e\u010c\3\2\2\2\u010f\u0112\3\2"+
		"\2\2\u0110\u010e\3\2\2\2\u0110\u0111\3\2\2\2\u0111%\3\2\2\2\u0112\u0110"+
		"\3\2\2\2\u0113\u0119\5(\25\2\u0114\u0115\5\20\t\2\u0115\u0116\7\'\2\2"+
		"\u0116\u0118\3\2\2\2\u0117\u0114\3\2\2\2\u0118\u011b\3\2\2\2\u0119\u0117"+
		"\3\2\2\2\u0119\u011a\3\2\2\2\u011a\u011c\3\2\2\2\u011b\u0119\3\2\2\2\u011c"+
		"\u011d\5\20\t\2\u011d\u011e\7&\2\2\u011e\'\3\2\2\2\u011f\u0120\b\25\1"+
		"\2\u0120\u0123\5\62\32\2\u0121\u0123\7>\2\2\u0122\u011f\3\2\2\2\u0122"+
		"\u0121\3\2\2\2\u0123\u0129\3\2\2\2\u0124\u0125\f\3\2\2\u0125\u0126\7 "+
		"\2\2\u0126\u0128\7!\2\2\u0127\u0124\3\2\2\2\u0128\u012b\3\2\2\2\u0129"+
		"\u0127\3\2\2\2\u0129\u012a\3\2\2\2\u012a)\3\2\2\2\u012b\u0129\3\2\2\2"+
		"\u012c\u0152\7>\2\2\u012d\u012f\7>\2\2\u012e\u0130\5,\27\2\u012f\u012e"+
		"\3\2\2\2\u0130\u0131\3\2\2\2\u0131\u012f\3\2\2\2\u0131\u0132\3\2\2\2\u0132"+
		"\u0136\3\2\2\2\u0133\u0135\5.\30\2\u0134\u0133\3\2\2\2\u0135\u0138\3\2"+
		"\2\2\u0136\u0134\3\2\2\2\u0136\u0137\3\2\2\2\u0137\u013c\3\2\2\2\u0138"+
		"\u0136\3\2\2\2\u0139\u013b\5,\27\2\u013a\u0139\3\2\2\2\u013b\u013e\3\2"+
		"\2\2\u013c\u013a\3\2\2\2\u013c\u013d\3\2\2\2\u013d\u0152\3\2\2\2\u013e"+
		"\u013c\3\2\2\2\u013f\u0141\5\62\32\2\u0140\u0142\5,\27\2\u0141\u0140\3"+
		"\2\2\2\u0142\u0143\3\2\2\2\u0143\u0141\3\2\2\2\u0143\u0144\3\2\2\2\u0144"+
		"\u0148\3\2\2\2\u0145\u0147\5.\30\2\u0146\u0145\3\2\2\2\u0147\u014a\3\2"+
		"\2\2\u0148\u0146\3\2\2\2\u0148\u0149\3\2\2\2\u0149\u014e\3\2\2\2\u014a"+
		"\u0148\3\2\2\2\u014b\u014d\5,\27\2\u014c\u014b\3\2\2\2\u014d\u0150\3\2"+
		"\2\2\u014e\u014c\3\2\2\2\u014e\u014f\3\2\2\2\u014f\u0152\3\2\2\2\u0150"+
		"\u014e\3\2\2\2\u0151\u012c\3\2\2\2\u0151\u012d\3\2\2\2\u0151\u013f\3\2"+
		"\2\2\u0152+\3\2\2\2\u0153\u0154\7 \2\2\u0154\u0155\5$\23\2\u0155\u0156"+
		"\7!\2\2\u0156-\3\2\2\2\u0157\u0158\7 \2\2\u0158\u0159\7!\2\2\u0159/\3"+
		"\2\2\2\u015a\u015b\t\n\2\2\u015b\61\3\2\2\2\u015c\u015d\t\13\2\2\u015d"+
		"\63\3\2\2\2$\679DMXbkou\u0081\u0084\u008d\u009d\u00a2\u00ae\u00b1\u00b5"+
		"\u00be\u00c0\u00d1\u00d5\u0104\u010e\u0110\u0119\u0122\u0129\u0131\u0136"+
		"\u013c\u0143\u0148\u014e\u0151";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}