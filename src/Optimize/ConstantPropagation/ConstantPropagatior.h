#ifndef CONSTANT_PROPAGATOR_H
#define CONSTANT_PROPAGATOR_H

#include "IRNode.h"
#include <map>
#include <unordered_map>
#include <set>
#include <queue> 
#include <vector>

class ConstantPropagator: public IRBaseVisitor {
private:
    std::unordered_map<IRValueNode*, IRStmtNode*> defMap;
    std::map<IRValueNode*, std::set<IRStmtNode*>> useMap;
    std::map<IRValueNode*, IRValueNode*> valueMap;
    std::queue<IRValueNode*> valueQue;
public:
    void visitBrCondStmt(IRBrCondStmtNode* node) override {}
    void visitBrStmt(IRBrStmtNode* node) override {}
    void visitRetStmt(IRRetStmtNode* node) override {}
    void visitLoadStmt(IRLoadStmtNode* node) override {}
    void visitStoreStmt(IRStoreStmtNode* node) override {}
    void visitCallStmt(IRCallStmtNode* node) override {}
    void visitGetElementPtrStmt(IRGetElementPtrStmtNode* node) override {}
    void visitGlobalVarStmt(IRGlobalVarStmtNode* node) override {}

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
        else if (op == "sdiv") { value->value = lhs->value / rhs->value; }
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
        if (op == "eq") { value->value = lhs->value == rhs->value; }
        else if (op == "ne") { value->value = lhs->value != rhs->value; }
        else if (op == "slt") { value->value = lhs->value < rhs->value; }
        else if (op == "sle") { value->value = lhs->value <= rhs->value; }
        else if (op == "sgt") { value->value = lhs->value > rhs->value; }
        else if (op == "sge") { value->value = lhs->value >= rhs->value; }
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
        bool flag = true;
        IRValueNode* value = nullptr;
        for (auto v: node->values) {
            auto val = v.second;
            if (value == nullptr) value = val;
            if (val == var) continue;
            else if (val != value) {
                flag = false;
                break;
            }
        }
        if (flag) {
            valueMap[var] = value;
            valueQue.push(var);
        }
    }
    

    void visitFunction(IRFunctionNode* node) override {        
        defMap.clear();
        useMap.clear();
        valueMap.clear();
        for (auto block: node->blocks) {
            for (auto stmt: block->stmts) {
                stmt->collectUse(useMap);
                stmt->collectDef(defMap);
            }
        }        
        for (auto it: defMap) {
            it.second->accept(this);
        }

    }
    void visitProgram(IRProgramNode* node) override {
        for (auto func: node->functions) visitFunction(func);
    }
};

#endif