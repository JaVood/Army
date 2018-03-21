#include "Rogue.h"

Rogue::Rogue(const char* title, int hitPoints, int damage): 
    Unit(title, hitPoints, damage) {
        this->ability = new RogueAbility(this);
    }

Rogue::~Rogue() {}