#include "ASTBaseVisitor.h"
#include "Scope.h"

class SemanticChecker: public ASTBaseVisitor {
private:
    Scope *scope = nullptr;
};