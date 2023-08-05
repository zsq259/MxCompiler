#ifndef SEMANTIC_CHECKER_H
#define SEMANTIC_CHECKER_H
#include "ASTBaseVisitor.h"
#include "Scope.h"

class SemanticChecker: public ASTBaseVisitor {
private:
    Scope *scope = nullptr;
};
#endif