#include "MxParser.h"
#include "Exception.h"

class MxParserErrorListener : public antlr4::BaseErrorListener {
	void syntaxError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol, size_t line, size_t charPositionInLine,
					 const std::string &msg, std::exception_ptr e) override {
		throw syntax_error{"syntaxError: " + msg};
	}
};