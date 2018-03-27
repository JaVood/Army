#include "Wizard.h"

Wizard::Wizard(const char* title, int hitPoint, int damage, int manaPoint) : SpellCaster(title, hitPoint, damage, manaPoint, true) {
    this->ability = new Ability(this);
    }

Wizard::~Wizard() {}
