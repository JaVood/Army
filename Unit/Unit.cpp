#include "Unit.h"

Unit::Unit(const char* title, int hitPoint, int damage, int manaPoint) 
    : state(new State(title, hitPoint, damage, manaPoint)) {}
    
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