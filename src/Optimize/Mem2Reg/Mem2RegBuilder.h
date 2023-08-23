#ifndef MEM2REG_BUILDER_H
#define MEM2REG_BUILDER_H

#include "DomTreeBuilder.h"
#include "IRBaseVisitor.h"

class Mem2RegBuilder : public IRBaseVisitor {
private:
    DomTreeBuilder* domTreeBuilder = nullptr;
public:
    Mem2RegBuilder() { domTreeBuilder = new DomTreeBuilder; }
    void visitFunction(IRFunctionNode* node) override {
        if (!node->blocks.size()) return;
        domTreeBuilder->clear();
        domTreeBuilder->buildCFG(node);
        domTreeBuilder->buildDomTree(node);
        domTreeBuilder->getFrontier();
        // domTreeBuilder->printDomTree();
    }
    void visitProgram(IRProgramNode* node) override {
        for (auto func: node->functions) visitFunction(func);
    }

};

#endif