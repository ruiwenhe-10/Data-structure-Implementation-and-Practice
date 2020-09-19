#ifndef WARRIOR_H
#define WARRIOR_H

using namespace std;

#include "Character.h"

class Warrior : public Character {
    
public:    

    Warrior(const string &name, const double MAX_HEALTH, double attackStrength, string allegiance);
    void attack(Character & ch);
    
private:    
    string allegiance;
    
};















































#endif