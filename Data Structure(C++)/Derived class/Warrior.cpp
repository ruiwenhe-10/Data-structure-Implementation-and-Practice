#include<iostream>

using namespace std;

#include "Warrior.h"
#include "Character.h"

Warrior::Warrior(const string &name, const double health, double attackStrength, string allegiance) 
    : Character(WARRIOR, name, health, attackStrength), allegiance(allegiance)
    {}
    
void Warrior::attack(Character & ch) {
    if (WARRIOR == ch.getType()) {
        Warrior &opp = dynamic_cast<Warrior &>(ch);
        if (this->allegiance == opp.allegiance) {
              cout << "Warrior " << this->getName() <<" does not attack Warrior " << opp.getName() << "." << endl;                    // Warrior Jane does not attack Warrior Arthur.
              cout << "They share an allegiance with " << this->allegiance << "." << endl;                                                                                     // They share an allegiance with King George.
        }
        else {
        cout << "Warrior " << this->getName() << " attacks " << ch.getName() << " --- SLASH!!" << endl;
        cout << ch.getName() << " takes " << (this->health / MAX_HEALTH) * this->attackStrength << " damage." << endl;
        ch.damage((this->health / MAX_HEALTH) * this->attackStrength);
        }
    }
    else {
        // Warrior Bob attacks Arthur --- SLASH!!
        // Arthur takes 4 damage.
        cout << "Warrior " << this->getName() << " attacks " << ch.getName() << " --- SLASH!!" << endl;
        cout << ch.getName() << " takes " << (this->health / MAX_HEALTH) * this->attackStrength << " damage." << endl;
        ch.damage((this->health / MAX_HEALTH) * this->attackStrength);
    }
    return;
}