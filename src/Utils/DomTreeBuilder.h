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
#include "CFGBuilder.h"

class Mem2RegBuilder;

class DomTreeBuilder {
private:
    DomTree* domTree = nullptr;
    ControlFlowGraph* cfg = nullptr;
    CFGBuilder* cfgBuilder = nullptr;
    bool changeFlag = true;
    friend class Mem2RegBuilder;
public:
    DomTreeBuilder() { cfgBuilder = new CFGBuilder; }
    ~DomTreeBuilder() { clear(); delete cfgBuilder; }
    void visit(IRFunctionNode* node) {
        clear();
        cfg = cfgBuilder->buildCFG(node);
        buildDomTree(node);
        getFrontier(node);
    }
    void updateDom(CFGNode* node) {
        auto now = domTree->name2node[node->name];
        std::set<DomTreeNode*> dom = now->dom;
        int size = dom.size();
        for (auto p: node->pred) {
            auto tmp = domTree->name2node[p->name];
            std::vector<DomTreeNode*> newdom;
            std::set_intersection(dom.begin(), dom.end(), tmp->dom.begin(), tmp->dom.end(), std::back_inserter(newdom));
            dom.clear();
            for (auto d: newdom) dom.insert(d);
        }
        now->dom = dom;
        now->dom.insert(now);
        if (now->dom.size() != size) changeFlag = true;
    }
    void getDom() {
        std::queue<CFGNode*> que;
        std::set<CFGNode*> visited;
        que.push(cfg->entry);
        while (!que.empty()) {
            auto now = que.front();
            que.pop();
            if (!visited.insert(now).second) continue;
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
        domTree->root->dom.clear();
        domTree->root->dom.insert(domTree->root);
        while (changeFlag) {
            changeFlag = false;
            getDom();
        }
    }
    void getFrontier(IRFunctionNode* node) {
        for (auto block: node->blocks) {
            auto now = domTree->name2node[block->label];
            auto b = cfg->name2node[block->label];
            for (auto p: b->pred) {
                auto pred = domTree->name2node[p->name];
                for (auto dom: pred->dom) {
                    if(!now->dom.count(dom) || dom == now) dom->frontier.insert(now);
                }                
            }
        }
    }
    void printFrontier() {
        for (auto it: domTree->name2node) {
            auto node = it.second;
            std::cerr << node->name << ": ";
            for (auto frt: node->frontier) {
                std::cerr << frt->name << ", ";
            }
            std::cerr << '\n';
        }
    }
    void printDom() {
        for (auto it: domTree->name2node) {
            auto node = it.second;
            std::cerr << node->name << ": ";
            for (auto d: node->dom) {
                std::cerr << d->name << ", ";
            }
            std::cerr << '\n';
        }
        std::cerr << std::endl;
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