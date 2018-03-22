#include "SpellCaster.h"

SpellCaster::SpellCaster(const char* title, int hitPoint, int damage, int manaPoint) : Unit(title, hitPoint, damage, manaPoint) {}
    
SpellCaster::~SpellCaster() {
    delete(this->spell);
}

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

void SpellCaster::useSpell(Unit* unit) {
    this->spell->useSpell(Unit* unit);
}

void SpellCaster::vortex(Unit* enemy, int dmg) {
    this->spell->vortex(Unit* enemy, int dmg);
}

void SpellCaster::battleHeal(Unit* friend, int power) {
    this->spell->vortex(Unit* friend, int power);
}

void SpellCaster::summonDemon() {
    this->spell->summonDemon();
}