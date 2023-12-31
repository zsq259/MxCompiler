#include "ASTNode.h"
#include "ASTBuilder.h"
#include "MxErrorListener.h"
#include "Scope.h"
#include "SymbolCollector.h"
#include "SemanticChecker.h"
#include "IRBuilder.h"
#include "ASMBuilder.h"
#include "NaiveASMBuilder.h"
#include "Mem2RegBuilder.h"
#include "RegisterAllocator.h"
#include "ConstantPropagatior.h"
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
	for (int i = 1; i < argc; i++) { 
		if (argv[i][0] != '-') files.push_back(argv[i]); 
	}
	try {
		AST ast;
    	if (files.empty()) { ast.root = getAST(); }
		else {
			std::ifstream in(files[0]);
			ast.root = getAST(in);
			in.close();
		}
		GlobalScope globalscope(nullptr);
		globalscope.scopeName = ".0";
		ClassColletor classcollector(&globalscope);
		classcollector.init();
		classcollector.visit(ast.root);
		
		FunctionCollector functioncollector(&globalscope);
		functioncollector.init();
		functioncollector.visit(ast.root);

		SemanticChecker semanticchecker(&globalscope);
		semanticchecker.visit(ast.root);

		for (int i = 1; i < argc; ++i) {
			if (std::string(argv[i]) == "-fsyntax-only") return 0;
		}
		
		IRBuilder irbuilder;
		std::cerr << "okkkkk1\n";
		irbuilder.visit(ast.root);
		std::cerr << "okkkkk2\n";
		
		DeadCodeEliminator deadcodeeliminator;
		deadcodeeliminator.visit(irbuilder.root());

		Mem2RegBuilder mem2regbuilder;
		mem2regbuilder.visit(irbuilder.root());
		std::cerr << "okkkkk3\n";

		ConstantPropagator constantpropagator;
		constantpropagator.visit(irbuilder.root());
		std::cerr << "okkkkk4\n";
		for (int i = 1; i < argc; ++i) {
			if (std::string(argv[i]) == "-emit-llvm") { irbuilder.print(); return 0; }
		}

		ASMBuilder asmbuilder;
		// NaiveASMBuilder asmbuilder;
		asmbuilder.visit(irbuilder.root());
		std::cerr << "okkkkk5\n";
		for (int i = 1; i < argc; ++i) {
			if (std::string(argv[i]) == "-S") asmbuilder.print();
		}
	}
	catch (std::exception &e) {
		cerr << e.what() << '\n';
		return 1;
	}
    return 0;
}