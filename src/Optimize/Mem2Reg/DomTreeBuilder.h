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
    void visit(IRFunctionNode* node) {
        clear();
        cfg = cfgBuilder->buildCFG(node);
        buildDomTree(node);
        getFrontier(node);
        printFrontier();
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
    }
    void getFrontier(IRFunctionNode* node) {
        for (auto block: node->blocks) {
            auto now = domTree->name2node[block->label];
            auto b = cfg->name2node[block->label];
            for (auto p: b->pred) {
                auto pred = domTree->name2node[p->name];
                for (auto dom: pred->dom) {
                    if(!now->dom.count(dom) || dom == now->id) domTree->id2node[dom]->frontier.insert(now->id);
                }
                
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