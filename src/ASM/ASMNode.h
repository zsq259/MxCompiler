#ifndef ASM_NODE_H
#define ASM_NODE_H
#include <string>
#include <vector>

class ASMNode {
public:
    ASMNode() = default;
    virtual ~ASMNode() = default;
    virtual std::string to_string() = 0;
};

class ASMGlobalVarStmtNode: public ASMNode {
public:
    bool is_string = false;
    std::string name, value;
    explicit ASMGlobalVarStmtNode(std::string name_, std::string value_, bool is_string_): 
        name(name_), value(value_), is_string(is_string_) {}
    std::string to_string() override;
};

class ASMFunctionNode: public ASMNode {
public:
    
    std::string to_string() override;
};

class ASMDataSectionNode: public ASMNode {
public:
    std::vector<ASMGlobalVarStmtNode*> globalVarStmts;

    std::string to_string() override;
};

class ASMTextSectionNode: public ASMNode {
public:
    std::vector<ASMFunctionNode*> functions;
    std::string to_string() override;
};

class ASMProgramNode: public ASMNode {
public:
    ASMDataSectionNode* data;
    ASMTextSectionNode* text;
    
    explicit ASMProgramNode(ASMDataSectionNode* data_, ASMTextSectionNode* text_): data(data_), text(text_) {}
    std::string to_string() override;
};

#endif