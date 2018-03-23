#include "Priest.h"

Priest::Priest(const char* title, const char* unitType, int hitPoint, int damage, int manaPoint, const char* magicType) : SpellCaster(title, unitType, hitPoint, damage, manaPoint, magicType) {
    this->ability = new PriestAbility(this);
    }

Priest::~Priest() {}

void Priest::heal(Unit* patient) {
    this->battleHeal = new BattleHeal(this, patient);
}

void Priest::useBattleSpell(Unit* enemy) {
    this->vortex = new Vortex(this, enemy);
}