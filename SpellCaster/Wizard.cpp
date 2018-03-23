#include "Wizard.h"

Wizard::Wizard(const char* title, const char* unitType, int hitPoint, int damage, int manaPoint, const char* magicType) : SpellCaster(title, unitType, hitPoint, damage, manaPoint, magicType) {
    this->ability = new Ability(this);
    }

Wizard::~Wizard() {}

void Wizard::heal(Unit* patient) {
    this->battleHeal = new BattleHeal(this, patient);
}

void Wizard::useBattleSpell(Unit* enemy) {
    this->vortex = new Vortex(this, enemy);
}