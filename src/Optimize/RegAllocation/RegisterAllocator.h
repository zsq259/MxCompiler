#ifndef RegisterAllocator_h
#define RegisterAllocator_h

#include "Register.h"
#include "LivenessAnalysiser.h"

class RegisterAllocator {
private:
    PhysicalRegister x[32];
    std::map<std::string, PhysicalRegister*> name2reg;
public:
    RegisterAllocator() {
        x[0].name = "zero";
        x[1].name = "ra";
        x[2].name = "sp";
        x[3].name = "gp";
        x[4].name = "tp";
        x[5].name = "t0";
        x[6].name = "t1";
        x[7].name = "t2";
        x[8].name = "s0";
        x[9].name = "s1";
        for (int i = 10; i <= 17; ++i) x[i].name = "a" + std::to_string(i - 10);
        for (int i = 18; i <= 27; ++i) x[i].name = "s" + std::to_string(i - 18 + 2);
        for (int i = 28; i <= 31; ++i) x[i].name = "t" + std::to_string(i - 28 + 3);
        for (int i = 0; i < 32; ++i) name2reg[x[i].name] = &x[i];
        for (int i = 0; i < 32; ++i) name2reg["x" + std::to_string(i)] = &x[i];
    }
    Register* getReg(const std::string &name) {
        return name2reg[name];
    }
    

};


#endif