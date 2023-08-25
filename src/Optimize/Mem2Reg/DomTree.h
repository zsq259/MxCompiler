#ifndef DOM_TREE_H
#define DOM_TREE_H
#include <vector>
#include <map>
#include <set>
#include <string>
#include "IRNode.h"

struct DomTreeNode {
    std::string name;
    IRBlockNode* block = nullptr;
    std::set<DomTreeNode*> frontier, dom;
    explicit DomTreeNode(std::string name_, IRBlockNode* block_) : name(name_), block(block_) {}
};

class DomTreeBuilder;
class Mem2RegBuilder;

class DomTree {
private:
    std::map<std::string, DomTreeNode*> name2node;
    DomTreeNode* root;
    friend class DomTreeBuilder;
    friend class Mem2RegBuilder;
public:
    ~DomTree() {
        for (auto it: name2node) delete it.second;
    }
    void init() {
        std::set<DomTreeNode*> domInit;
        for (auto it: name2node) domInit.insert(it.second);
        for (auto it: name2node) it.second->dom = domInit;
    }
    void addNode(IRBlockNode* block) {
        auto node = new DomTreeNode(block->label, block);
        name2node[block->label] = node;
    }
    void printDom() {
        for (auto it: name2node) {
            std::cerr << it.first << ": ";
            for (auto d: it.second->dom) {
                std::cerr << d->name << ", ";
            }
            std::cerr << '\n';
        }
        std::cerr << std::endl;
    }
};

#endif