#include "State.h"

State::State(const char* title, int hitPoint, int damage, int manaPoint) {
    this->title = title;
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

void State::takeDamage(int dmg) {
    this->ensureIsAlive();
    
    if ( dmg > this->hitPoint ) {
        this->hitPoint = 0;
        return;
    }
    this->hitPoint -= dmg;
}

void State::takeMagicDamage(int dmg) {
    this->ensureIsAlive();
    
    if ( dmg > this->hitPoint ) {
        this->hitPoint = 0;
        return;
    }
    this->hitPoint -= dmg;
}

void State::setName(const char* title){
    this->title = title;
}

void State::setHitPoint(int hp) {
    this->hitPoint = hp;
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

void State::spendMana(int mp) {
    this->ensureIsAlive();
    
    this->manaPoint -= mp;
}