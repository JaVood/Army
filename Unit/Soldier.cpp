#include "Soldier.h"

Soldier::Soldier(const char* title, const char* unitType, int hitPoint, int damage): 
    Unit(title, unitType, hitPoint, damage) {
        this->ability = new Ability(this);
    }

Soldier::~Soldier() {}