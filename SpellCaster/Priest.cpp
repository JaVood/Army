#include "Priest.h"

Priest::Priest(const char* title, int hitPoint, int damage, int manaPoint) : SpellCaster(title, hitPoint, damage, manaPoint, false) {
    this->ability = new PriestAbility(this);
    }

Priest::~Priest() {}
