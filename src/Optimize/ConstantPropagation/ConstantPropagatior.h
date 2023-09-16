#ifndef CONSTANT_PROPAGATOR_H
#define CONSTANT_PROPAGATOR_H

#include <map>
#include <unordered_map>
#include <set>
#include <queue> 
#include <vector>
#include "IRNode.h"
#include "CFGBuilder.h"

class ConstantPropagator: public IRBaseVisitor {
private:
    CFGBuilder cfgBuilder;
    std::unordered_map<IRValueNode*, IRStmtNode*> defMap;
    std::map<IRValueNode*, std::set<IRStmtNode*>> useMap;
    std::map<IRValueNode*, IRValueNode*> valueMap;
    std::set<IRNode*> deleted;
    std::unordered_map<IRBrCondStmtNode*, CFGNode*> condMap;
    std::queue<IRValueNode*> valueQue;
    std::set<CFGNode*> visited;
public:    
    void visitBrStmt(IRBrStmtNode* node) override {}
    void visitRetStmt(IRRetStmtNode* node) override {}
    void visitLoadStmt(IRLoadStmtNode* node) override {}
    void visitStoreStmt(IRStoreStmtNode* node) override {}
    void visitCallStmt(IRCallStmtNode* node) override {}
    void visitGetElementPtrStmt(IRGetElementPtrStmtNode* node) override {}
    void visitGlobalVarStmt(IRGlobalVarStmtNode* node) override {}

    void removePrevNode(CFGNode* node, CFGNode* next) {
        for (int i = 0, k = node->next.size(); i < k; ++i) {
            if (node->next[i] == next) {
                node->next.erase(node->next.begin() + i);
                break;
            }
        }
        for (int i = 0, k = next->pred.size(); i < k; ++i) {
            if (next->pred[i] == node) {
                next->pred.erase(next->pred.begin() + i);
                break;
            }
        }
        if (!next->pred.size()) {
            removeBlock(next);
        }
        else {
            auto &stmts = next->block->stmts;
            for (auto stmt: stmts) {
                if (auto phi = dynamic_cast<IRPhiStmtNode*>(stmt)) {
                    phi->values.erase(node->block->label);
                    phi->accept(this);
                }
                else break;
            }
        }
    }

    void removeBlock(CFGNode* node) {
        deleted.insert(node->block);
        for (auto next: node->next) {
            removePrevNode(node, next);
        }        
    }

    void visitBrCondStmt(IRBrCondStmtNode* node) override {
        auto cond = node->cond;
        if (auto val = dynamic_cast<IRLiteralNode*>(cond)) {            
            auto label = val->value ? node->trueLabel : node->falseLabel;
            auto failLabel = val->value ? node->falseLabel : node->trueLabel;
            auto br = new IRBrStmtNode(label);
            auto cfgBlock = condMap[node];
            auto block = cfgBlock->block;
            auto &stmts = block->stmts;
            stmts.pop_back();
            stmts.push_back(br);
            CFGNode* next = nullptr;
            for (auto n: cfgBlock->next) {
                if (n->block->label == failLabel) {
                    next = n;
                    break;
                }
            }
            if (next == nullptr) throw std::runtime_error("ConstantPropagator: no next block");
            removePrevNode(cfgBlock, next);
        }        
    }

    void visitBinaryStmt(IRBinaryStmtNode* node) override {
        auto lhs = dynamic_cast<IRLiteralNode*>(node->lhs);
        auto rhs = dynamic_cast<IRLiteralNode*>(node->rhs);
        if (lhs == nullptr || rhs == nullptr) return;
        if (dynamic_cast<IRStringNode*>(lhs) || dynamic_cast<IRStringNode*>(rhs)) return;
        auto var = node->var;
        auto value = new IRLiteralNode(var->type, 0);
        auto op = node->op;
        if (op == "add") { value->value = lhs->value + rhs->value; }
        else if (op == "sub") { value->value = lhs->value - rhs->value; }
        else if (op == "mul") { value->value = lhs->value * rhs->value; }
        else if (op == "sdiv") { value->value = rhs->value? lhs->value / rhs->value: 0; }
        else if (op == "srem") { value->value = lhs->value % rhs->value; }
        else if (op == "and") { value->value = lhs->value & rhs->value; }
        else if (op == "or") { value->value = lhs->value | rhs->value; }
        else if (op == "xor") { value->value = lhs->value ^ rhs->value; }
        else if (op == "shl") { value->value = lhs->value << rhs->value; }
        else if (op == "ashr") { value->value = lhs->value >> rhs->value; }
        valueMap[var] = value;
        valueQue.push(var);
    }        
    void visitIcmpStmt(IRIcmpStmtNode* node) override {
        auto lhs = dynamic_cast<IRLiteralNode*>(node->lhs);
        auto rhs = dynamic_cast<IRLiteralNode*>(node->rhs);
        if (lhs == nullptr || rhs == nullptr) return;
        auto var = node->var;
        auto value = new IRLiteralNode(var->type, 0);
        auto op = node->op;        
        if (op == "icmp eq") { value->value = lhs->value == rhs->value; }
        else if (op == "icmp ne") { value->value = lhs->value != rhs->value; }
        else if (op == "icmp slt") { value->value = lhs->value < rhs->value; }
        else if (op == "icmp sle") { value->value = lhs->value <= rhs->value; }
        else if (op == "icmp sgt") { value->value = lhs->value > rhs->value; }
        else if (op == "icmp sge") { value->value = lhs->value >= rhs->value; }
        valueMap[var] = value;
        valueQue.push(var);        
    }
    void visitTruncStmt(IRTruncStmtNode* node) override {
        auto var = node->var;
        if (auto val = dynamic_cast<IRLiteralNode*>(node->value)) {
            auto value = new IRLiteralNode(var->type, val->value);
            valueMap[var] = value;
            valueQue.push(var);
        }
    }
    void visitZextStmt(IRZextStmtNode* node) override {
        auto var = node->var;
        if (auto val = dynamic_cast<IRLiteralNode*>(node->value)) {
            auto value = new IRLiteralNode(var->type, val->value);
            valueMap[var] = value;
            valueQue.push(var);
        }
    }    
    void visitPhiStmt(IRPhiStmtNode* node) override {
        auto var = node->var;
        bool flag = true, isConst = true;
        if (node->values.size() == 1) {
            valueMap[var] = node->values.begin()->second;
            valueQue.push(var);
            return;
        }
        for (auto v: node->values) {
            if (v.second == var) continue;
            if (!dynamic_cast<IRLiteralNode*>(v.second)) {
                isConst = false;
                break;
            }
        }
        IRValueNode* value = nullptr;
        int constValue = 0;
        if (isConst) {
            for (auto v: node->values) {
                if (v.second == var) continue;
                auto val = dynamic_cast<IRLiteralNode*>(v.second);                
                if (value == nullptr) {
                    value = val;      
                    constValue = val->value;
                }                                
                else if (constValue != val->value) {
                    flag = false;
                    break;
                }
            }
        }
        else {
            for (auto v: node->values) {
                auto val = v.second;
                if (value == nullptr) {
                    value = val;                
                }
                if (val == var) continue;
                else if (val != value) {
                    flag = false;
                    break;
                }
            }        
        }
        if (flag) {
            valueMap[var] = value;
            valueQue.push(var);
        }
    }
    void removeBrStmt(CFGNode* node) {        
        if (!node->next.size() || visited.contains(node)) return; 
        auto flag = true;
        if (node->next.size() > 1) flag = false;
        auto next = node->next[0];
        if (next->pred.size() > 1) flag = false;
        if (!flag) {
            visited.insert(node);
            for (auto next: node->next) removeBrStmt(next);
            return ;
        }                        
        auto block = node->block;
        auto &stmts = block->stmts;
        stmts.pop_back();
        for (auto stmt: next->block->stmts) stmts.push_back(stmt);        
        deleted.insert(next->block);
        node->next = next->next;
        for (auto newNext: node->next) {            
            for (auto &pred: newNext->pred) {
                if (pred == next) pred = node;
            }
            auto &nextStmts = newNext->block->stmts;
            for (auto stmt: nextStmts) {
                if (auto phi = dynamic_cast<IRPhiStmtNode*>(stmt)) {
                    phi->values[node->block->label] = phi->values[next->block->label];
                    phi->values.erase(next->block->label);
                }
                else break;
            }
        }        
        removeBrStmt(node);
    }    

    void visitFunction(IRFunctionNode* node) override {   
        if (!node->blocks.size()) return;     
        defMap.clear();
        useMap.clear();
        valueMap.clear();
        condMap.clear();
        deleted.clear();
        
        auto cfg = cfgBuilder.buildCFG(node);        
        for (auto block: node->blocks) {
            for (auto stmt: block->stmts) {
                stmt->collectUse(useMap);
                stmt->collectDef(defMap);
                if (auto br = dynamic_cast<IRBrCondStmtNode*>(stmt)) condMap.emplace(br, cfg->name2node[block->label]);
            }
        }        
        for (auto it: defMap) {            
            it.second->accept(this);
        }
        while (!valueQue.empty()) {
            auto var = valueQue.front(); valueQue.pop();            
            auto value = valueMap[var];
            deleted.insert(defMap[var]);
            for (auto stmt: useMap[var]) {
                stmt->replaceValue(var, value);
                useMap[value].insert(stmt);
                stmt->accept(this);                
            }
            useMap.erase(var);
        }
        std::vector<IRBlockNode*> newBlocks;
        for (auto block: node->blocks) {
            if (!deleted.count(block)) newBlocks.push_back(block);
        }
        node->blocks = newBlocks;
        for (auto block: node->blocks) {
            std::vector<IRStmtNode*> stmts;
            for (auto stmt: block->stmts) {
                if (!deleted.count(stmt)) stmts.push_back(stmt);
            }
            block->stmts = stmts;            
        }        
        deleted.clear();
        visited.clear();
        removeBrStmt(cfg->entry);
        newBlocks.clear();
        for (auto block: node->blocks) {
            if (!deleted.count(block)) newBlocks.push_back(block);
        }
        node->blocks = newBlocks;
    }
    void visitProgram(IRProgramNode* node) override {
        for (auto func: node->functions) visitFunction(func);
    }
};

#endif