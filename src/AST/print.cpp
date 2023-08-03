#include <iostream>
#include <cstdio>
#include <cstring>
#include "ASTNode.h"
using std::cout;

void ASTProgramNode::print() {
    for (auto &child: children) child->print(), cout << '\n';   
}