#include "State.h"

State::State(const char* title, const char* unitType, int hitPoint, int damage, int manaPoint,  const char* magicType) {
    this->title = title;
    this->unitType = unitType;
    this->magicType = magicType;
    this->hitPoint = hitPoint;
    this->manaPoint = manaPoint;
    this->manaPointLimit = manaPoint;
    this->hitPointLimit = hitPoint;
    this->damage = damage;
}
State::~State() {}

void State::ensureIsAlive() {
    if ( this->hitPoint == 0 ) {
        throw OutOfHitPointsException();
    }
}

const char* State::getTitle() const {
    return this->title;
}

const char* State::getUnitType() const {
    return this->unitType;
}

const char* State::getMagicType() const {
    return this->magicType;
}

int State::getHitPoint() const {
    return this->hitPoint;
}

int State::getHitPointLimit() const {
    return this->hitPointLimit;
}

int State::getManaPoint() const {
    return this->manaPoint;
}

int State::getManaPointLimit() const {
    return this->manaPointLimit;
}

int State::getDamage() const {
    return this->damage;
}

void State::spendMana(int mp) {
    this->ensureIsAlive();
    
    this->manaPoint -= mp;
}

void State::addHitPoint(int hp) {
    this->ensureIsAlive();
    
    int limit = this->hitPoint + hp;
    if ( limit > this->hitPointLimit ) {
        this->hitPoint = this->hitPointLimit;
        return;
    }
    this->hitPoint = limit;
}

void State::addManaPoint(int mp) {
    this->ensureIsAlive();
    
    int limit = this->manaPoint + mp;
    if ( limit > this->manaPointLimit ) {
        this->manaPoint = this->manaPointLimit;
        return;
    }
    this->manaPoint = limit;
}

void State::_takeDamage(int dmg) {
    this->ensureIsAlive();
    
    if ( dmg > this->hitPoint ) {
        this->hitPoint = 0;
        return;
    }
    this->hitPoint -= dmg;
}

void State::takeDamage(int dmg) {
    this->_takeDamage(dmg);
}

void State::_takeMagicDamage(int dmg) {
    this->ensureIsAlive();
    
    if ( dmg > this->hitPoint ) {
        this->hitPoint = 0;
        return;
    }
    this->hitPoint -= dmg;
}

void State::takeMagicDamage(int dmg) {
    this->_takeMagicDamage(dmg);
}

void State::setName(const char* title){
    this->title = title;
}

void State::setUnitType(const char* unitType){
    this->unitType = unitType;
}

void State::setHitPoint(int hp) {
    this->hitPoint = hp;
}

void State::setManaPoint(int mp) {
    this->manaPoint = mp;
}

void State::setDamage(int dmg) {
    this->damage = dmg;
}

void State::setHitPointLimit(int hp) {
    this->hitPointLimit = hp;
    if ( this->hitPoint > this->hitPointLimit) {
        this->setHitPoint(this->hitPointLimit);
    }
}

void State::setManaPointLimit(int mp) {
    this->manaPointLimit = mp;
}