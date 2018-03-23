#include "Vampire.h"

Vampire::Vampire(const char* title, const char* unitType, int hitPoint, int damage): 
    Unit(title, unitType, hitPoint, damage) {
        this->ability = new VampireAbility(this);
    }

Vampire::~Vampire() {}
