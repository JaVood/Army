#include "SpellCaster.h"

SpellCaster::SpellCaster(const char* title, const char* unitType, int hitPoint, int damage, int manaPoint, const char* magicType) : Unit(title, unitType, hitPoint, damage, manaPoint, magicType) {
    this->ability = new Ability(this);
}
    
SpellCaster::~SpellCaster() {}

int SpellCaster::getManaPoint() const {
    return this->state->getManaPoint();
}

int SpellCaster::getManaPointLimit() const {
    return this->state->getManaPointLimit();
}

void SpellCaster::setManaPoint(int mp) {
    this->state->setManaPoint(mp);
}

void SpellCaster::addManaPoint(int mp) {
    this->state->addManaPoint(mp);
}

void SpellCaster::setManaPointLimit(int mp) {
    this->state->setManaPointLimit(mp);
}

void SpellCaster::spendMana(int mp) {
    this->state->spendMana(mp);
}

const char* SpellCaster::getMagicType() const {
    return this->state->getMagicType();
}

void SpellCaster::heal(Unit* patient) {}

void SpellCaster::useBattleSpell(Unit* enemy) {}