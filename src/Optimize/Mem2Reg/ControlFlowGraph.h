#ifndef CONTROL_FLOW_GRAPH_H
#define CONTROL_FLOW_GRAPH_H

#include <vector>
#include <map>
#include <string>

struct CFGNode {
    int id;
    std::string name;
    std::vector<CFGNode*> pred, next;
    explicit CFGNode(std::string name_, int id_) : name(name_), id(id_) {}
};

class DomTreeBuilder;

class ControlFlowGraph {
private:
    int cnt = 0;
    CFGNode* entry;
    std::map<std::string, CFGNode*> name2node;
    friend class DomTreeBuilder;
public:
    void addNode(std::string name) {
        name2node[name] = new CFGNode(name, cnt++);
    }
    void addEdge(std::string from, std::string to) {
        name2node[from]->next.push_back(name2node[to]);
        name2node[to]->pred.push_back(name2node[from]);
    }
    void print() {
        for (auto it = name2node.begin(); it != name2node.end(); it++) {
            std::cerr << it->first << ": ";
            for (auto child : it->second->next) {
                std::cerr << child->name << ", ";
            }
            std::cerr << std::endl;
        }
    }
};

#endif