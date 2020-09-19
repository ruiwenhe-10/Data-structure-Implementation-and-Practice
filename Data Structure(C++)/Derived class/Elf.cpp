#include<iostream>
using namespace std;

#include "Character.h"
#include "Elf.h"

Elf::Elf(const string &name, double health, double attackStrength, string familyname)
    :Character(ELF, name, health, attackStrength), familyname(familyname)
    {}
    
void Elf::attack(Character & ch) {
    if (ELF == ch.getType()) {
        Elf &opp = dynamic_cast<Elf &>(ch);
        if (this->familyname == opp.familyname) {
              cout << "Elf " << this->getName() <<" does not attack Elf " << opp.getName() << "." << endl;                    // Elf Jane does not attack Elf Arthur.
              cout << "They are both members of the " << this->familyname << " family." << endl;                                                                                     // They share an familyname with King George.
        
            return;
        }
        else {
        cout << "Elf " << this->getName() << " shoots an arrow at " << ch.getName() << " --- TWANG!!" << endl;
        cout << ch.getName() << " takes " << (this->health / MAX_HEALTH) * this->attackStrength << " damage." << endl;
        ch.damage(this->health / MAX_HEALTH * this->attackStrength);
        }
    }
    else {
        // Elf Bob attacks Arthur --- TWANG!!
        // Arthur takes 4 damage.
        cout << "Elf " << this->getName() << " shoots an arrow at " << ch.getName() << " --- TWANG!!" << endl;
        cout << ch.getName() << " takes " << (this->health / MAX_HEALTH) * this->attackStrength << " damage." << endl;
        ch.damage(this->health / MAX_HEALTH * this->attackStrength);
    }
}