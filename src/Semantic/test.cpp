#include "../AST/ASTNode.h"
#include "../AST/ASTBuilder.h"
#include "../Util/MxErrorListener.h"
#include "../Util/Scope.h"
#include "../Semantic/SymbolCollector.h"
#include "../Semantic/SemanticChecker.h"
#include "MxLexer.h"
using std::cerr;

ASTNode* getAST(std::istream &in = std::cin) {
	antlr4::ANTLRInputStream input(in);
	MxErrorListener errorListener;

    MxLexer lexer(&input);
	lexer.removeErrorListeners();
	lexer.addErrorListener(&errorListener);
	antlr4::CommonTokenStream tokens(&lexer);
	MxParser parser(&tokens);
	parser.removeErrorListeners();
	parser.addErrorListener(&errorListener);

	auto tree = parser.program();
	ASTBuilder builder;
	auto visit_result = builder.visit(tree);
	if (!visit_result.has_value())
		throw std::runtime_error("AST build failed");
	return std::any_cast<ASTNode *>(visit_result);
}

int main(int argc, char const *argv[]) {
	vector<string> files;
	for (int i = 1; i < argc; i++) { files.push_back(argv[i]); }
	try {
		AST ast;
    	if (files.empty()) { ast.root = getAST(); }
		else {
			std::ifstream in(files[0]);
			ast.root = getAST(in);
			in.close();
		}
		// ast.root->print();
		GlobalScope globalscope(nullptr);
		
		ClassColletor classcollector(&globalscope);
		classcollector.init();
		classcollector.visit(ast.root);
		
		FunctionCollector functioncollector(&globalscope);
		functioncollector.init();
		functioncollector.visit(ast.root);
		SemanticChecker semanticchecker(&globalscope);
		semanticchecker.visit(ast.root);
		
	}
	catch (std::exception &e) {
		cerr << e.what() << '\n';
		return 1;
	}
    return 0;
}