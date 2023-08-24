#ifndef CFG_BUILDER_H
#define CFG_BUILDER_H
#include "ControlFlowGraph.h"

class CFGBuilder {
private:
    ControlFlowGraph* cfg = nullptr;
public:
    ControlFlowGraph* buildCFG(IRFunctionNode* node) {
        cfg = new ControlFlowGraph;
        for (auto block: node->blocks) {
            cfg->addNode(block);
        }
        cfg->entry = cfg->name2node["entry"];
        for (auto block: node->blocks) {
            for (auto stmt: block->stmts) {
                if (auto br = dynamic_cast<IRBrStmtNode*>(stmt)) {
                    cfg->addEdge(block->label, br->label);
                    break;
                }
                if (auto br = dynamic_cast<IRBrCondStmtNode*>(stmt)) {
                    cfg->addEdge(block->label, br->trueLabel);
                    cfg->addEdge(block->label, br->falseLabel);
                    break;
                }
                if (dynamic_cast<IRRetStmtNode*>(stmt)) break;
            }
        }
        return cfg;
    }
};

#endif