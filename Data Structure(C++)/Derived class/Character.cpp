#include<iostream>

using namespace std;

#include "Character.h"

//  protected:
//     HeroType type;
//     string name;
//     double health;
//     double attackStrength;

Character::Character(HeroType type, const string &name, double health, double attackStrength) 
    : type(type), name(name), health(health), attackStrength(attackStrength)
    {}
    
HeroType Character::getType() const {
    return type;
}

const string & Character::getName() const {
    return name;
}

int Character::getHealth() const {
    return health;
}

void Character::setHealth(double h) {
    this->health = h;
    return;
}

void Character::damage(double d) {
    this->health = this->health - d;
    return;
}

bool Character::isAlive() const {
    if (getHealth() > 0) {
        return true;
    }
    else {
        return false;
    }
}
