// Generated from /home/zsq259/桌面/项目/MxCompiler/antlr4/MxLexer.g4 by ANTLR 4.9.2
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class MxLexer extends Lexer {
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
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"Comment", "BlockComment", "LineComment", "Add", "Sub", "Mul", "Div", 
			"Mod", "Gt", "Lt", "Geq", "Leq", "Neq", "Eq", "And", "Or", "Not", "Rs", 
			"Ls", "BitAnd", "BitOr", "BitXor", "BitInv", "Assign", "Incre", "Decre", 
			"Dot", "Ques", "Colon", "LeftBracket", "RightBracket", "LeftParen", "RightParen", 
			"LeftBrace", "RightBrace", "Semicolon", "Comma", "EscapeChar", "LogicalLiteral", 
			"NumberLiteral", "StringLiteral", "NullLiteral", "Void", "Bool", "Int", 
			"String", "New", "Class", "Null", "True", "False", "This", "ElseIf", 
			"If", "Else", "For", "While", "Break", "Continue", "Return", "Digit", 
			"Letter", "Identifier", "Whitespace", "NewLine"
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


	public MxLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "MxLexer.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2@\u0191\b\1\4\2\t"+
		"\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"+
		"\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t \4!"+
		"\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\4&\t&\4\'\t\'\4(\t(\4)\t)\4*\t*\4+\t+\4"+
		",\t,\4-\t-\4.\t.\4/\t/\4\60\t\60\4\61\t\61\4\62\t\62\4\63\t\63\4\64\t"+
		"\64\4\65\t\65\4\66\t\66\4\67\t\67\48\t8\49\t9\4:\t:\4;\t;\4<\t<\4=\t="+
		"\4>\t>\4?\t?\4@\t@\4A\tA\4B\tB\3\2\3\2\5\2\u0088\n\2\3\2\3\2\3\3\3\3\3"+
		"\3\3\3\7\3\u0090\n\3\f\3\16\3\u0093\13\3\3\3\3\3\3\3\3\3\3\3\3\4\3\4\3"+
		"\4\3\4\7\4\u009e\n\4\f\4\16\4\u00a1\13\4\3\4\3\4\5\4\u00a5\n\4\3\4\3\4"+
		"\3\5\3\5\3\6\3\6\3\7\3\7\3\b\3\b\3\t\3\t\3\n\3\n\3\13\3\13\3\f\3\f\3\f"+
		"\3\r\3\r\3\r\3\16\3\16\3\16\3\17\3\17\3\17\3\20\3\20\3\20\3\21\3\21\3"+
		"\21\3\22\3\22\3\23\3\23\3\23\3\24\3\24\3\24\3\25\3\25\3\26\3\26\3\27\3"+
		"\27\3\30\3\30\3\31\3\31\3\32\3\32\3\32\3\33\3\33\3\33\3\34\3\34\3\35\3"+
		"\35\3\36\3\36\3\37\3\37\3 \3 \3!\3!\3\"\3\"\3#\3#\3$\3$\3%\3%\3&\3&\3"+
		"\'\3\'\3\'\3\'\3\'\3\'\3\'\3\'\5\'\u00ff\n\'\3(\3(\5(\u0103\n(\3)\3)\7"+
		")\u0107\n)\f)\16)\u010a\13)\3)\5)\u010d\n)\3*\3*\3*\7*\u0112\n*\f*\16"+
		"*\u0115\13*\3*\3*\3+\3+\3,\3,\3,\3,\3,\3-\3-\3-\3-\3-\3.\3.\3.\3.\3/\3"+
		"/\3/\3/\3/\3/\3/\3\60\3\60\3\60\3\60\3\61\3\61\3\61\3\61\3\61\3\61\3\62"+
		"\3\62\3\62\3\62\3\62\3\63\3\63\3\63\3\63\3\63\3\64\3\64\3\64\3\64\3\64"+
		"\3\64\3\65\3\65\3\65\3\65\3\65\3\66\3\66\3\66\3\66\3\67\3\67\3\67\38\3"+
		"8\38\38\38\39\39\39\39\3:\3:\3:\3:\3:\3:\3;\3;\3;\3;\3;\3;\3<\3<\3<\3"+
		"<\3<\3<\3<\3<\3<\3=\3=\3=\3=\3=\3=\3=\3>\3>\3?\3?\3@\3@\3@\3@\7@\u0183"+
		"\n@\f@\16@\u0186\13@\3A\3A\5A\u018a\nA\3A\3A\3B\3B\3B\3B\5\u0091\u009f"+
		"\u0113\2C\3\3\5\4\7\5\t\6\13\7\r\b\17\t\21\n\23\13\25\f\27\r\31\16\33"+
		"\17\35\20\37\21!\22#\23%\24\'\25)\26+\27-\30/\31\61\32\63\33\65\34\67"+
		"\359\36;\37= ?!A\"C#E$G%I&K\'M\2O(Q)S*U+W,Y-[.]/_\60a\61c\62e\63g\64i"+
		"\65k\66m\67o8q9s:u;w<y={\2}\2\177>\u0081?\u0083@\3\2\7\3\2\63;\3\2\62"+
		";\4\2C\\c|\6\2\13\13\r\16\"\"\u00a2\u00a2\5\2\f\f\17\17\u202a\u202b\2"+
		"\u019d\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2\2\2\2\t\3\2\2\2\2\13\3\2\2\2\2"+
		"\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2\23\3\2\2\2\2\25\3\2\2\2\2\27\3"+
		"\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3\2\2\2\2\37\3\2\2\2\2!\3\2\2\2"+
		"\2#\3\2\2\2\2%\3\2\2\2\2\'\3\2\2\2\2)\3\2\2\2\2+\3\2\2\2\2-\3\2\2\2\2"+
		"/\3\2\2\2\2\61\3\2\2\2\2\63\3\2\2\2\2\65\3\2\2\2\2\67\3\2\2\2\29\3\2\2"+
		"\2\2;\3\2\2\2\2=\3\2\2\2\2?\3\2\2\2\2A\3\2\2\2\2C\3\2\2\2\2E\3\2\2\2\2"+
		"G\3\2\2\2\2I\3\2\2\2\2K\3\2\2\2\2O\3\2\2\2\2Q\3\2\2\2\2S\3\2\2\2\2U\3"+
		"\2\2\2\2W\3\2\2\2\2Y\3\2\2\2\2[\3\2\2\2\2]\3\2\2\2\2_\3\2\2\2\2a\3\2\2"+
		"\2\2c\3\2\2\2\2e\3\2\2\2\2g\3\2\2\2\2i\3\2\2\2\2k\3\2\2\2\2m\3\2\2\2\2"+
		"o\3\2\2\2\2q\3\2\2\2\2s\3\2\2\2\2u\3\2\2\2\2w\3\2\2\2\2y\3\2\2\2\2\177"+
		"\3\2\2\2\2\u0081\3\2\2\2\2\u0083\3\2\2\2\3\u0087\3\2\2\2\5\u008b\3\2\2"+
		"\2\7\u0099\3\2\2\2\t\u00a8\3\2\2\2\13\u00aa\3\2\2\2\r\u00ac\3\2\2\2\17"+
		"\u00ae\3\2\2\2\21\u00b0\3\2\2\2\23\u00b2\3\2\2\2\25\u00b4\3\2\2\2\27\u00b6"+
		"\3\2\2\2\31\u00b9\3\2\2\2\33\u00bc\3\2\2\2\35\u00bf\3\2\2\2\37\u00c2\3"+
		"\2\2\2!\u00c5\3\2\2\2#\u00c8\3\2\2\2%\u00ca\3\2\2\2\'\u00cd\3\2\2\2)\u00d0"+
		"\3\2\2\2+\u00d2\3\2\2\2-\u00d4\3\2\2\2/\u00d6\3\2\2\2\61\u00d8\3\2\2\2"+
		"\63\u00da\3\2\2\2\65\u00dd\3\2\2\2\67\u00e0\3\2\2\29\u00e2\3\2\2\2;\u00e4"+
		"\3\2\2\2=\u00e6\3\2\2\2?\u00e8\3\2\2\2A\u00ea\3\2\2\2C\u00ec\3\2\2\2E"+
		"\u00ee\3\2\2\2G\u00f0\3\2\2\2I\u00f2\3\2\2\2K\u00f4\3\2\2\2M\u00fe\3\2"+
		"\2\2O\u0102\3\2\2\2Q\u010c\3\2\2\2S\u010e\3\2\2\2U\u0118\3\2\2\2W\u011a"+
		"\3\2\2\2Y\u011f\3\2\2\2[\u0124\3\2\2\2]\u0128\3\2\2\2_\u012f\3\2\2\2a"+
		"\u0133\3\2\2\2c\u0139\3\2\2\2e\u013e\3\2\2\2g\u0143\3\2\2\2i\u0149\3\2"+
		"\2\2k\u014e\3\2\2\2m\u0152\3\2\2\2o\u0155\3\2\2\2q\u015a\3\2\2\2s\u015e"+
		"\3\2\2\2u\u0164\3\2\2\2w\u016a\3\2\2\2y\u0173\3\2\2\2{\u017a\3\2\2\2}"+
		"\u017c\3\2\2\2\177\u017e\3\2\2\2\u0081\u0189\3\2\2\2\u0083\u018d\3\2\2"+
		"\2\u0085\u0088\5\5\3\2\u0086\u0088\5\7\4\2\u0087\u0085\3\2\2\2\u0087\u0086"+
		"\3\2\2\2\u0088\u0089\3\2\2\2\u0089\u008a\b\2\2\2\u008a\4\3\2\2\2\u008b"+
		"\u008c\7\61\2\2\u008c\u008d\7,\2\2\u008d\u0091\3\2\2\2\u008e\u0090\13"+
		"\2\2\2\u008f\u008e\3\2\2\2\u0090\u0093\3\2\2\2\u0091\u0092\3\2\2\2\u0091"+
		"\u008f\3\2\2\2\u0092\u0094\3\2\2\2\u0093\u0091\3\2\2\2\u0094\u0095\7,"+
		"\2\2\u0095\u0096\7\61\2\2\u0096\u0097\3\2\2\2\u0097\u0098\b\3\2\2\u0098"+
		"\6\3\2\2\2\u0099\u009a\7\61\2\2\u009a\u009b\7\61\2\2\u009b\u009f\3\2\2"+
		"\2\u009c\u009e\13\2\2\2\u009d\u009c\3\2\2\2\u009e\u00a1\3\2\2\2\u009f"+
		"\u00a0\3\2\2\2\u009f\u009d\3\2\2\2\u00a0\u00a4\3\2\2\2\u00a1\u009f\3\2"+
		"\2\2\u00a2\u00a5\5\u0083B\2\u00a3\u00a5\7\2\2\3\u00a4\u00a2\3\2\2\2\u00a4"+
		"\u00a3\3\2\2\2\u00a5\u00a6\3\2\2\2\u00a6\u00a7\b\4\2\2\u00a7\b\3\2\2\2"+
		"\u00a8\u00a9\7-\2\2\u00a9\n\3\2\2\2\u00aa\u00ab\7/\2\2\u00ab\f\3\2\2\2"+
		"\u00ac\u00ad\7,\2\2\u00ad\16\3\2\2\2\u00ae\u00af\7\61\2\2\u00af\20\3\2"+
		"\2\2\u00b0\u00b1\7\'\2\2\u00b1\22\3\2\2\2\u00b2\u00b3\7@\2\2\u00b3\24"+
		"\3\2\2\2\u00b4\u00b5\7>\2\2\u00b5\26\3\2\2\2\u00b6\u00b7\7@\2\2\u00b7"+
		"\u00b8\7?\2\2\u00b8\30\3\2\2\2\u00b9\u00ba\7>\2\2\u00ba\u00bb\7?\2\2\u00bb"+
		"\32\3\2\2\2\u00bc\u00bd\7#\2\2\u00bd\u00be\7?\2\2\u00be\34\3\2\2\2\u00bf"+
		"\u00c0\7?\2\2\u00c0\u00c1\7?\2\2\u00c1\36\3\2\2\2\u00c2\u00c3\7(\2\2\u00c3"+
		"\u00c4\7(\2\2\u00c4 \3\2\2\2\u00c5\u00c6\7~\2\2\u00c6\u00c7\7~\2\2\u00c7"+
		"\"\3\2\2\2\u00c8\u00c9\7#\2\2\u00c9$\3\2\2\2\u00ca\u00cb\7@\2\2\u00cb"+
		"\u00cc\7@\2\2\u00cc&\3\2\2\2\u00cd\u00ce\7>\2\2\u00ce\u00cf\7>\2\2\u00cf"+
		"(\3\2\2\2\u00d0\u00d1\7(\2\2\u00d1*\3\2\2\2\u00d2\u00d3\7~\2\2\u00d3,"+
		"\3\2\2\2\u00d4\u00d5\7`\2\2\u00d5.\3\2\2\2\u00d6\u00d7\7\u0080\2\2\u00d7"+
		"\60\3\2\2\2\u00d8\u00d9\7?\2\2\u00d9\62\3\2\2\2\u00da\u00db\7-\2\2\u00db"+
		"\u00dc\7-\2\2\u00dc\64\3\2\2\2\u00dd\u00de\7/\2\2\u00de\u00df\7/\2\2\u00df"+
		"\66\3\2\2\2\u00e0\u00e1\7\60\2\2\u00e18\3\2\2\2\u00e2\u00e3\7A\2\2\u00e3"+
		":\3\2\2\2\u00e4\u00e5\7<\2\2\u00e5<\3\2\2\2\u00e6\u00e7\7]\2\2\u00e7>"+
		"\3\2\2\2\u00e8\u00e9\7_\2\2\u00e9@\3\2\2\2\u00ea\u00eb\7*\2\2\u00ebB\3"+
		"\2\2\2\u00ec\u00ed\7+\2\2\u00edD\3\2\2\2\u00ee\u00ef\7}\2\2\u00efF\3\2"+
		"\2\2\u00f0\u00f1\7\177\2\2\u00f1H\3\2\2\2\u00f2\u00f3\7=\2\2\u00f3J\3"+
		"\2\2\2\u00f4\u00f5\7.\2\2\u00f5L\3\2\2\2\u00f6\u00f7\7^\2\2\u00f7\u00ff"+
		"\7^\2\2\u00f8\u00f9\7^\2\2\u00f9\u00ff\7p\2\2\u00fa\u00fb\7^\2\2\u00fb"+
		"\u00ff\7v\2\2\u00fc\u00fd\7^\2\2\u00fd\u00ff\7$\2\2\u00fe\u00f6\3\2\2"+
		"\2\u00fe\u00f8\3\2\2\2\u00fe\u00fa\3\2\2\2\u00fe\u00fc\3\2\2\2\u00ffN"+
		"\3\2\2\2\u0100\u0103\5e\63\2\u0101\u0103\5g\64\2\u0102\u0100\3\2\2\2\u0102"+
		"\u0101\3\2\2\2\u0103P\3\2\2\2\u0104\u0108\t\2\2\2\u0105\u0107\5{>\2\u0106"+
		"\u0105\3\2\2\2\u0107\u010a\3\2\2\2\u0108\u0106\3\2\2\2\u0108\u0109\3\2"+
		"\2\2\u0109\u010d\3\2\2\2\u010a\u0108\3\2\2\2\u010b\u010d\7\62\2\2\u010c"+
		"\u0104\3\2\2\2\u010c\u010b\3\2\2\2\u010dR\3\2\2\2\u010e\u0113\7$\2\2\u010f"+
		"\u0112\5M\'\2\u0110\u0112\13\2\2\2\u0111\u010f\3\2\2\2\u0111\u0110\3\2"+
		"\2\2\u0112\u0115\3\2\2\2\u0113\u0114\3\2\2\2\u0113\u0111\3\2\2\2\u0114"+
		"\u0116\3\2\2\2\u0115\u0113\3\2\2\2\u0116\u0117\7$\2\2\u0117T\3\2\2\2\u0118"+
		"\u0119\5c\62\2\u0119V\3\2\2\2\u011a\u011b\7x\2\2\u011b\u011c\7q\2\2\u011c"+
		"\u011d\7k\2\2\u011d\u011e\7f\2\2\u011eX\3\2\2\2\u011f\u0120\7d\2\2\u0120"+
		"\u0121\7q\2\2\u0121\u0122\7q\2\2\u0122\u0123\7n\2\2\u0123Z\3\2\2\2\u0124"+
		"\u0125\7k\2\2\u0125\u0126\7p\2\2\u0126\u0127\7v\2\2\u0127\\\3\2\2\2\u0128"+
		"\u0129\7u\2\2\u0129\u012a\7v\2\2\u012a\u012b\7t\2\2\u012b\u012c\7k\2\2"+
		"\u012c\u012d\7p\2\2\u012d\u012e\7i\2\2\u012e^\3\2\2\2\u012f\u0130\7p\2"+
		"\2\u0130\u0131\7g\2\2\u0131\u0132\7y\2\2\u0132`\3\2\2\2\u0133\u0134\7"+
		"e\2\2\u0134\u0135\7n\2\2\u0135\u0136\7c\2\2\u0136\u0137\7u\2\2\u0137\u0138"+
		"\7u\2\2\u0138b\3\2\2\2\u0139\u013a\7p\2\2\u013a\u013b\7w\2\2\u013b\u013c"+
		"\7n\2\2\u013c\u013d\7n\2\2\u013dd\3\2\2\2\u013e\u013f\7v\2\2\u013f\u0140"+
		"\7t\2\2\u0140\u0141\7w\2\2\u0141\u0142\7g\2\2\u0142f\3\2\2\2\u0143\u0144"+
		"\7h\2\2\u0144\u0145\7c\2\2\u0145\u0146\7n\2\2\u0146\u0147\7u\2\2\u0147"+
		"\u0148\7g\2\2\u0148h\3\2\2\2\u0149\u014a\7v\2\2\u014a\u014b\7j\2\2\u014b"+
		"\u014c\7k\2\2\u014c\u014d\7u\2\2\u014dj\3\2\2\2\u014e\u014f\5o8\2\u014f"+
		"\u0150\5\u0081A\2\u0150\u0151\5m\67\2\u0151l\3\2\2\2\u0152\u0153\7k\2"+
		"\2\u0153\u0154\7h\2\2\u0154n\3\2\2\2\u0155\u0156\7g\2\2\u0156\u0157\7"+
		"n\2\2\u0157\u0158\7u\2\2\u0158\u0159\7g\2\2\u0159p\3\2\2\2\u015a\u015b"+
		"\7h\2\2\u015b\u015c\7q\2\2\u015c\u015d\7t\2\2\u015dr\3\2\2\2\u015e\u015f"+
		"\7y\2\2\u015f\u0160\7j\2\2\u0160\u0161\7k\2\2\u0161\u0162\7n\2\2\u0162"+
		"\u0163\7g\2\2\u0163t\3\2\2\2\u0164\u0165\7d\2\2\u0165\u0166\7t\2\2\u0166"+
		"\u0167\7g\2\2\u0167\u0168\7c\2\2\u0168\u0169\7m\2\2\u0169v\3\2\2\2\u016a"+
		"\u016b\7e\2\2\u016b\u016c\7q\2\2\u016c\u016d\7p\2\2\u016d\u016e\7v\2\2"+
		"\u016e\u016f\7k\2\2\u016f\u0170\7p\2\2\u0170\u0171\7w\2\2\u0171\u0172"+
		"\7g\2\2\u0172x\3\2\2\2\u0173\u0174\7t\2\2\u0174\u0175\7g\2\2\u0175\u0176"+
		"\7v\2\2\u0176\u0177\7w\2\2\u0177\u0178\7t\2\2\u0178\u0179\7p\2\2\u0179"+
		"z\3\2\2\2\u017a\u017b\t\3\2\2\u017b|\3\2\2\2\u017c\u017d\t\4\2\2\u017d"+
		"~\3\2\2\2\u017e\u0184\5}?\2\u017f\u0183\5}?\2\u0180\u0183\5{>\2\u0181"+
		"\u0183\7a\2\2\u0182\u017f\3\2\2\2\u0182\u0180\3\2\2\2\u0182\u0181\3\2"+
		"\2\2\u0183\u0186\3\2\2\2\u0184\u0182\3\2\2\2\u0184\u0185\3\2\2\2\u0185"+
		"\u0080\3\2\2\2\u0186\u0184\3\2\2\2\u0187\u018a\t\5\2\2\u0188\u018a\5\u0083"+
		"B\2\u0189\u0187\3\2\2\2\u0189\u0188\3\2\2\2\u018a\u018b\3\2\2\2\u018b"+
		"\u018c\bA\2\2\u018c\u0082\3\2\2\2\u018d\u018e\t\6\2\2\u018e\u018f\3\2"+
		"\2\2\u018f\u0190\bB\2\2\u0190\u0084\3\2\2\2\20\2\u0087\u0091\u009f\u00a4"+
		"\u00fe\u0102\u0108\u010c\u0111\u0113\u0182\u0184\u0189\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}