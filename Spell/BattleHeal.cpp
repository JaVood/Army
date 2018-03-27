#include "BattleHeal.h"

BattleHeal::BattleHeal(std::string spellName, int manaCost, int actionPoints) : Spell(spellName, actionPoints, manaCost) {}

BattleHeal::~BattleHeal() {}

void BattleHeal::cast(SpellCaster* caster, Unit* other, Spell* spell) {
    if ( this->getManaCost() < caster->getManaPoint() ) {
        caster->spendMana(this->getManaCost());

        if ( caster->getIsBattle() ) {
            other->addHitPoint(spell->getActionPoints() / 2);
        } else {
            other->addHitPoint(spell->getActionPoints());
        }
    }
}
