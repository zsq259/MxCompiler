#include "ASTNode.h"
#include "ASTBuilder.h"
#include "MxLexer.h"

ASTNode* getAST() {
	antlr4::ANTLRInputStream input(std::cin);
    MxLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
	MxParser parser(&tokens);
    auto tree = parser.program();
	ASTBuilder builder;
	auto visit_result = builder.visit(tree);

	if (!visit_result.has_value())
		throw std::runtime_error("AST build failed");
	return std::any_cast<ASTNode *>(visit_result);
}

int main() {
    auto root = getAST();
    root->print();

    return 0;
}