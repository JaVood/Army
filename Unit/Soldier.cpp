#include "Soldier.h"

Soldier::Soldier(const char* title, int hitPoint, int damage): 
    Unit(title, hitPoint, damage) {
        this->ability = new Ability(this);
    }

Soldier::~Soldier() {}