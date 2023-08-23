#ifndef DOMTREE_BUILDER_H
#define DOMTREE_BUILDER_H

#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include "IRBaseVisitor.h"
#include "IRNode.h"
#include "DomTree.h"
#include "ControlFlowGraph.h"

class DomTreeBuilder {
private:
    DomTree* domTree = nullptr;
    ControlFlowGraph* cfg = nullptr;
    bool changeFlag = true;
    std::set<int> visited;
public:
    void visit(IRFunctionNode* node) {
        clear();
        buildCFG(node);
        buildDomTree(node);
        
    }
    void updateDom(CFGNode* node) {
        auto now = domTree->name2node[node->name];
        std::vector<int> dom = now->dom;
        int size = dom.size();
        for (auto p: node->pred) {
            auto tmp = domTree->name2node[p->name];
            std::vector<int> newdom;
            std::set_intersection(dom.begin(), dom.end(), tmp->dom.begin(), tmp->dom.end(), std::back_inserter(newdom));
            dom = newdom;
        }
        if (!node->pred.size()) dom.clear();
        now->dom.clear();
        bool flag = false;
        for (auto id: dom) {
            if (!flag && id > now->id) now->dom.push_back(now->id), flag = true;
            now->dom.push_back(id);
        }
        if (!flag) now->dom.push_back(now->id);
        if (now->dom.size() != size) changeFlag = true;
    }
    void getDom() {
        std::queue<CFGNode*> que;
        que.push(cfg->entry);
        visited.clear();
        while (!que.empty()) {
            auto now = que.front();
            que.pop();
            if (visited.count(now->id)) continue;
            visited.insert(now->id);
            updateDom(now);
            for (auto next: now->next) {
                que.push(next);
            }
        }
    }
    void buildDomTree(IRFunctionNode* node) {
        domTree = new DomTree();
        for (auto block: node->blocks) {
            domTree->addNode(block->label);
        }
        changeFlag = true;
        domTree->init();
        while (changeFlag) {
            changeFlag = false;
            getDom();
        }
    }
    void buildCFG(IRFunctionNode* node) {
        cfg = new ControlFlowGraph();
        for (auto block: node->blocks) {
            cfg->addNode(block->label);
        }
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
    }
    void clear() {
        delete domTree;
        domTree = nullptr;
    }
};

#endif