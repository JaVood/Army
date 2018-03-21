#include "Soldier.h"

Soldier::Soldier(const char* title, int hitPoints, int damage): 
    Unit(title, hitPoints, damage) {
        this->ability = new Ability(this);
    }

Soldier::~Soldier() {}