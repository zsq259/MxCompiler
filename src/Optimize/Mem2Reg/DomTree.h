#ifndef DOM_TREE_H
#define DOM_TREE_H
#include <vector>
#include <map>
#include <set>
#include <string>

struct DomTreeNode {
    int id;
    std::string name;
    DomTreeNode* parent = nullptr;
    std::vector<DomTreeNode*> children;
    std::set<int> frontier, dom;
    explicit DomTreeNode(std::string name_, int id_) : name(name_), id(id_) {}
};

class DomTreeBuilder;

class DomTree {
private:
    int cnt = 0;
    std::map<std::string, DomTreeNode*> name2node;
    std::map<std::string, int> name2id;
    std::map<int, DomTreeNode*> id2node;
    DomTreeNode* root;
    friend class DomTreeBuilder;
public:
    ~DomTree() {
        for (auto it: name2node) delete it.second;
    }
    void init() {
        for (auto it: name2node) {
            for (int i = 0; i < cnt; ++i) it.second->dom.insert(i);
        }
    }
    void addNode(std::string name) {
        auto node = new DomTreeNode(name, cnt);
        name2node[name] = node;
        id2node[cnt] = node;
        name2id[name] = cnt++;
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