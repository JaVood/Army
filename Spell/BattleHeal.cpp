#include "BattleHeal.h"

BattleHeal::BattleHeal(SpellCaster* doctor, Unit* patient) {
    doctor->ensureIsAlive();
    patient->ensureIsAlive();

    this->heal(doctor, patient);
}
BattleHeal::~BattleHeal() {}

void BattleHeal::heal(SpellCaster* doctor, Unit* patient) {
    if ( doctor->getManaPoint() < MANA_BATTLE_HEAL_COST ) {
        return;
    }
    if ( strcmp(doctor->getMagicType(), "Magician") == 0 ) {
        doctor->spendMana(MANA_BATTLE_HEAL_COST);
        patient->addHitPoint(HEAL/2);
        return;
    }

    doctor->spendMana(MANA_BATTLE_HEAL_COST);
    patient->addHitPoint(HEAL);
}