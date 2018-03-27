#include "Vortex.h"

Vortex::Vortex(std::string spellName, int manaCost, int actionPoints) : Spell(spellName, actionPoints, manaCost) {}

Vortex::~Vortex() {}

void Vortex::cast(SpellCaster* caster, Unit* enemy, Spell* spell) {
    if ( this->getManaCost() < caster->getManaPoint() ) {
        caster->spendMana(this->getManaCost());
        if ( strcmp(caster->getTitle(), "Priest") == 0 ) {
            this->priestCast(caster, enemy, spell);
        } else if ( strcmp(caster->getTitle(), "Necromanser") == 0 ) {
            this->necromanserCast(caster, enemy, spell);
        } else {
            if ( caster->getIsBattle() ) {
                enemy->takeMagicDamage(spell->getActionPoints());
            } else {
                enemy->takeMagicDamage(spell->getActionPoints() / 2);
                }
            }
        }
}

void Vortex::priestCast(SpellCaster* caster, Unit* enemy, Spell* spell) {
    if ( this->getManaCost() < caster->getManaPoint() ) {
        if ( enemy->getIsUndead() ) {
            enemy->takeMagicDamage(spell->getActionPoints());
        } else {
            enemy->takeMagicDamage(spell->getActionPoints() / 2);
        }
    }
}

void Vortex::necromanserCast(SpellCaster* caster, Unit* enemy, Spell* spell) {
    if ( this->getManaCost() < caster->getManaPoint() ) {
        enemy->takeMagicDamage(spell->getActionPoints());
        // caster->addSubject(enemy);
    }
}
