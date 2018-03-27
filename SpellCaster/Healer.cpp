#include "Healer.h"

Healer::Healer(const char* title, int hitPoint, int damage, int manaPoint) : SpellCaster(title, hitPoint, damage, manaPoint, false) {
    this->ability = new Ability(this);
    }

Healer::~Healer() {}
