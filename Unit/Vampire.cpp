#include "Vampire.h"

Vampire::Vampire(const char* title, int hitPoint, int damage): 
    Unit(title, hitPoint, damage) {
        this->ability = new VampireAbility(this);
    }

Vampire::~Vampire() {}
