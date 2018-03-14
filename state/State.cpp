#include "State.h"

State::State(const char* title, int hitPoint, int damage) {
    this->title = title;
    this->hitPoint = hitPoint;
    this->HitPointLimit = hitPointLimit;
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

int State::getDamage() const {
    return this->damage;
}

void State::addHitPoints(int hp) {
    this->ensureIsAlive();
    
    int limit = this->hitPoint + hp;
    if ( limit > this->hitPointLimit ) {
        this->hitPoint = this->hitPointLimit;
    }
    this->hitPoint = limit;
}

void State::_takeDamage(int dmg) {
    this->ensureIsAlive();
    
    if ( dmg > this->hitPoint ) {
        this->hitPoint = 0;
    }
    this->hitPoint -= dmg;
}

void State::takeDamage(int dmg) {
    this->_takeDamage(int dmg);
}

void State::_takeMagicDamage(int dmg) {
    this->ensureIsAlive();
    
    if ( dmg > this->hitPoint ) {
        this->hitPoint = 0;
    }
    this->hitPoint -= dmg;
}

void State::takeMagicDamage(int dmg) {
    this->_takeMagicDamage(int dmg);
}