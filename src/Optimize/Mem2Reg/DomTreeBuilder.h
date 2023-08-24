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

class Mem2RegBuilder;

class DomTreeBuilder {
private:
    DomTree* domTree = nullptr;
    ControlFlowGraph* cfg = nullptr;
    bool changeFlag = true;
    friend class Mem2RegBuilder;
public:
    void visit(IRFunctionNode* node) {
        clear();
        buildCFG(node);
        buildDomTree(node);
        
    }
    void updateDom(CFGNode* node) {
        auto now = domTree->name2node[node->name];
        std::set<int> dom = now->dom;
        int size = dom.size();
        for (auto p: node->pred) {
            auto tmp = domTree->name2node[p->name];
            std::vector<int> newdom;
            std::set_intersection(dom.begin(), dom.end(), tmp->dom.begin(), tmp->dom.end(), std::back_inserter(newdom));
            dom.clear();
            for (auto id: newdom) dom.insert(id);
        }
        if (!node->pred.size()) dom.clear();
        now->dom.clear();
        bool flag = false;
        for (auto id: dom) {
            if (!flag && id > now->id) now->dom.insert(now->id), flag = true;
            now->dom.insert(id);
        }
        if (!flag) now->dom.insert(now->id);
        if (now->dom.size() != size) changeFlag = true;
    }
    void getDom() {
        std::queue<CFGNode*> que;
        std::set<int> visited;
        que.push(cfg->entry);
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
        domTree = new DomTree;
        for (auto block: node->blocks) {
            domTree->addNode(block);
        }
        domTree->root = domTree->name2node["entry"];
        changeFlag = true;
        domTree->init();
        while (changeFlag) {
            changeFlag = false;
            getDom();
            
        }
        for (auto block: node->blocks) {
            if (block->label == "entry") continue;
            auto now = domTree->name2node[block->label];
            DomTreeNode* father = nullptr;
            int sum = 0;
            for (auto p: now->dom) {
                if (p == now->id) continue;
                auto tmp = domTree->id2node[p];
                if (tmp->dom.size() > sum) {
                    sum = tmp->dom.size();
                    father = domTree->id2node[p];
                }
            }
            domTree->addEdge(father, now);
        }
    }
    void getFrontier() {
        for (auto it: cfg->name2node) {
            auto node = it.second;
            if (node->pred.size() < 2) continue;
            auto now = domTree->name2node[node->name];
            for (auto p: node->pred) {
                auto tmp = domTree->name2node[p->name];
                auto tmp2 = tmp;
                while (true) {
                    if (now->dom.count(tmp->id)) break;
                    tmp->frontier.insert(now->id);
                    domTree->frontierLabelMap[std::make_pair(tmp, now)] = tmp2->name;
                    tmp = tmp->parent;
                }
            }
        }
    }
    void buildCFG(IRFunctionNode* node) {
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
    }
    void printFrontier() {
        for (auto it: domTree->name2node) {
            auto node = it.second;
            std::cerr << node->name << ": ";
            for (auto id: node->frontier) {
                std::cerr << domTree->id2node[id]->name << ", ";
            }
            std::cerr << '\n';
        }
    }
    void printDom() {
        for (auto it: domTree->name2node) {
            auto node = it.second;
            std::cerr << node->name << ": ";
            for (auto id: node->dom) {
                std::cerr << domTree->id2node[id]->name << ", ";
            }
            std::cerr << '\n';
        }
        std::cerr << std::endl;
    }
    void printDomTree() {
        domTree->print();
    }
    void printCFG() {
        cfg->print();
    }
    void clear() {
        delete domTree;
        delete cfg;
        domTree = nullptr;
        cfg = nullptr;
    }
};

#endif