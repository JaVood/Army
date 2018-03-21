#include "Vampire.h"

Vampire::Vampire(const char* title, int hitPoints, int damage): 
    Unit(title, hitPoints, damage) {
        this->ability = new VampireAbility(this);
    }

Vampire::~Vampire() {}
