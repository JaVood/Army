#include "Spell.h"

Spell::Spell(std::string spellName, int actionPoints, int manaCost) : spellName(spellName), actionPoints(actionPoints), manaCost(manaCost) {}

Spell::~Spell() {} 

const int Spell::getManaCost() const {
    return this->manaCost;
}

const int Spell::getActionPoints() const {
    return this->actionPoints;
}

const std::string& Spell::getSpellName() const {
    return this->spellName;
}

void Spell::cast(SpellCaster* caster, Unit* other, Spell* spell) {
    spell->cast(caster, other, spell);
}
