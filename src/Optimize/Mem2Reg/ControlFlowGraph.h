#ifndef CONTROL_FLOW_GRAPH_H
#define CONTROL_FLOW_GRAPH_H

#include <vector>
#include <map>
#include <string>
#include "IRNode.h"

struct CFGNode {
    int id;
    IRBlockNode* block = nullptr;
    std::string name;
    std::vector<CFGNode*> pred, next;
    explicit CFGNode(std::string name_, int id_, IRBlockNode* block_) : name(name_), id(id_), block(block_) {}
};

class DomTreeBuilder;
class Mem2RegBuilder;
class CFGBuilder;
class ASMBuilder;

class ControlFlowGraph {
private:
    int cnt = 0;
    CFGNode* entry;
    std::map<std::string, CFGNode*> name2node;
    friend class DomTreeBuilder;
    friend class Mem2RegBuilder;
    friend class CFGBuilder;
    friend class ASMBuilder;
public:
    void addNode(IRBlockNode* block) {
        name2node[block->label] = new CFGNode(block->label, cnt++, block);
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