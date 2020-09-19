#ifndef WIZARD_H
#define WIZARD_H

using namespace std;

#include "Character.h"




class Wizard : public Character {
    public:
    
    Wizard(const string &name, double health, double attackStrength, int rank);
    void attack(Character & ch);
    
    private:
    int rank;
};

















#endif