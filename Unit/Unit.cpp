#include "Unit.h"

Unit::Unit(const char* title, int hitPoint, int damage, int manaPoint, bool isUndead, bool isVampire, bool isWerewolf) : state(new State(title, hitPoint, damage, manaPoint)) {
    this->ability = new Ability(this);
    this->isUndead = isUndead;
    this->isWerewolf = isWerewolf;
    this->isVampire = isVampire;
}
    
Unit::~Unit() {
    delete this->state;
    delete this->ability;
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

const bool Unit::getIsUndead() const {
    return this->isUndead;
}

int Unit::getDamage() const {
    return this->state->getDamage();
}

const bool Unit::getIsWerewolf() const {
    return this->isWerewolf;
}

const bool Unit::getIsVampire() const {
    return this->isVampire;
}

void Unit::addHitPoint(int hp) {
    return this->state->addHitPoint(hp);
}
void Unit::takeDamage(int dmg) {
    return this->state->takeDamage(dmg);
}

void Unit::transformInToWolf() {
    this->ensureIsAlive();
    this->setName("Wolf");
    this->setDamage(200);
    this->setHitPoint(getHitPoint());
    this->setHitPointLimit(1300);
}

void Unit::takeMagicDamage(int dmg) {
    this->state->takeMagicDamage(dmg);
}

void Unit::attack(Unit* owner, Unit* enemy) {
    this->ability->attack(this, enemy);
}

void Unit::counterAttack(Unit* owner, Unit* enemy) {
    this->ability->counterAttack(this, enemy);
}

void Unit::turnInVampire(Unit* enemy) {
    if ( !(enemy->getIsVampire()) && !(enemy->getIsWerewolf()) && this->getIsVampire() ) {
        enemy->isVampire = true;
        enemy->isUndead = true;
    }
}

void Unit::turnInWerewolf(Unit* enemy) {
    if ( !(enemy->getIsVampire()) && !(enemy->getIsWerewolf()) && this->getIsWerewolf() ) {
        enemy->isWerewolf = true;
    }
}
void Unit::setName(const char* title) {
    this->state->setName(title);
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