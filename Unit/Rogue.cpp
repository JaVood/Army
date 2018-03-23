#include "Rogue.h"

Rogue::Rogue(const char* title, const char* unitType, int hitPoint, int damage): 
    Unit(title, unitType, hitPoint, damage) {
        this->ability = new RogueAbility(this);
    }

Rogue::~Rogue() {}