#include<iostream>
using namespace std;

#include "Character.h"
#include "Wizard.h"


Wizard::Wizard(const string &name, double health, double attackStrength, int rank)
    :Character(WIZARD, name, health, attackStrength), rank(rank)
    {}
    
void Wizard::attack(Character & ch) {
    if (WIZARD == ch.getType()) {
    Wizard &opp = dynamic_cast<Wizard &>(ch);
    cout << "Wizard " << this->getName() << " attacks " << ch.getName() << " --- POOF!!" << endl;
    cout << ch.getName() << " takes " << this->attackStrength * (static_cast<double>(this->rank) / opp.rank) << " damage." << endl; 
    ch.damage(this->attackStrength * (static_cast<double>(this->rank) / opp.rank));
    }
    else {
    cout << "Wizard " << this->getName() << " attacks " << ch.getName() << " --- POOF!!" << endl;
    cout << ch.getName() << " takes " << this->attackStrength << " damage." << endl;
    ch.damage(this->attackStrength);
    }
}