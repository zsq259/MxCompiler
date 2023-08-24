#ifndef DOM_TREE_H
#define DOM_TREE_H
#include <vector>
#include <map>
#include <set>
#include <string>
#include "IRNode.h"

struct DomTreeNode {
    int id;
    std::string name;
    DomTreeNode* parent = nullptr;
    IRBlockNode* block = nullptr;
    std::vector<DomTreeNode*> children;
    std::set<int> frontier, dom;
    explicit DomTreeNode(std::string name_, int id_, IRBlockNode* block_) : name(name_), id(id_), block(block_) {}
};

class DomTreeBuilder;
class Mem2RegBuilder;

class DomTree {
private:
    int cnt = 0;
    std::map<std::string, DomTreeNode*> name2node;
    std::map<std::string, int> name2id;
    std::map<int, DomTreeNode*> id2node;
    DomTreeNode* root;
    friend class DomTreeBuilder;
    friend class Mem2RegBuilder;
public:
    ~DomTree() {
        for (auto it: name2node) delete it.second;
    }
    void init() {
        for (auto it: name2node) {
            for (int i = 0; i < cnt; ++i) it.second->dom.insert(i);
        }
    }
    void addNode(IRBlockNode* block) {
        auto node = new DomTreeNode(block->label, cnt, block);
        name2node[block->label] = node;
        id2node[cnt] = node;
        name2id[block->label] = cnt++;
    }
    void addEdge(std::string from, std::string to) {
        name2node[to]->parent = name2node[from];
        name2node[from]->children.push_back(name2node[to]);
    }
    void addEdge(DomTreeNode* from, DomTreeNode* to) {
        to->parent = from;
        from->children.push_back(to);
    }
    void printDom() {
        for (auto it: name2node) {
            std::cerr << it.first << ": ";
            for (auto id: it.second->dom) {
                std::cerr << id2node[id]->name << ", ";
            }
            std::cerr << '\n';
        }
        std::cerr << std::endl;
    }
    void print() {
        for (auto it: name2node) {
            std::cerr << it.first << ": ";
            for (auto child : it.second->children) {
                std::cerr << child->name << ", ";
            }
            std::cerr << "\n";
        }
        std::cerr << std::endl;
    }
    
};

#endif