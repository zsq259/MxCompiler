#ifndef REGISTER_H
#define REGISTER_H
#include <string>
#include <vector>
#include <map>

class Register {
public:
    std::string name;
    int id;
    std::string to_string() { return name; }
};

class PhysicalRegister : public Register {
    
};

class VirtualRegister : public Register {
    
};


#endif