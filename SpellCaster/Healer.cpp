#include "Healer.h"

Healer::Healer(const char* title, const char* unitType, int hitPoint, int damage, int manaPoint, const char* magicType) : SpellCaster(title, unitType, hitPoint, damage, manaPoint, magicType) {
    this->ability = new Ability(this);
    }

Healer::~Healer() {}

void Healer::heal(Unit* patient) {
    this->battleHeal = new BattleHeal(this, patient);
}

void Healer::useBattleSpell(Unit* enemy) {
    this->vortex = new Vortex(this, enemy);
}