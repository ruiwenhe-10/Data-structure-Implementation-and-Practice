#ifndef ELF_H
#define ELF_H

using namespace std;

#include "Character.h"


class Elf : public Character {
    public:
    
    Elf(const string &name, double health, double attackStrength, string familyname);
    void attack(Character & ch);
    
    private:
    string familyname;
};







#endif