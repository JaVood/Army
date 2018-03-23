#include "Unit.h"

Unit::Unit(const char* title, const char* unitType, int hitPoint, int damage, int manaPoint,  const char* magicType) 
    : state(new State(title, unitType, hitPoint, damage, manaPoint, magicType)) {}
    
Unit::~Unit() {
    delete(this->state);
    delete(this->ability);
}

void Unit::ensureIsAlive() {
    this->state->ensureIsAlive();
}

const char* Unit::getTitle() const {
    return this->state->getTitle();
}

const char* Unit::getUnitType() const {
    return this->state->getUnitType();
}

int Unit::getHitPoint() const {
    return this->state->getHitPoint();
}
int Unit::getHitPointLimit() const {
    return this->state->getHitPointLimit();
}

int Unit::getDamage() const {
    return this->state->getDamage();
}

void Unit::addHitPoint(int hp) {
    return this->state->addHitPoint(hp);
}
void Unit::takeDamage(int dmg) {
    return this->state->takeDamage(dmg);
}

void Unit::transform() {}

void Unit::takeMagicDamage(int dmg) {
    this->state->takeMagicDamage(dmg);
}

void Unit::attack(Unit* enemy) {
    this->ability->attack(enemy);
}

void Unit::counterAttack(Unit* enemy) {
    this->ability->counterAttack(enemy);
}

void Unit::hitPointDrain() {
    this->ability->hitPointDrain();
}

void Unit::setName(const char* title) {
    this->state->setName(title);
}

void Unit::setUnitType(const char* unitType) {
    this->state->setUnitType(unitType);
}

void Unit::setHitPoint(int hp) {
    this->state->setHitPoint(hp);
}

void Unit::setDamage(int dmg) {
    this->state->setDamage(dmg);
}

void Unit::setHitPointLimit(int hp) {
    this->state->setHitPointLimit(hp);
}