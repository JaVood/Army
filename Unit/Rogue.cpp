#include "Rogue.h"

Rogue::Rogue(const char* title, int hitPoint, int damage): 
    Unit(title, hitPoint, damage) {
        this->ability = new RogueAbility(this);
    }

Rogue::~Rogue() {}