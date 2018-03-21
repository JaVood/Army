#include "VampireAbility.h"

VampireAbility::VampireAbility(Unit* owner): Ability(owner) {}
VampireAbility::~VampireAbility() {}

void VampireAbility::attack(Unit* enemy) {
    this->owner->ensureIsAlive();
    enemy->takeDamage(this->owner->getDamage());
    enemy->counterAttack(this->owner);
    this->owner->hitPointDrain();
}

void VampireAbility::counterAttack(Unit* enemy) {
    this->owner->ensureIsAlive();
    enemy->takeDamage(this->owner->getDamage() / 2);
    this->owner->hitPointDrain();
}

void VampireAbility::hitPointDrain() {
    this->owner->ensureIsAlive();
    this->owner->addHitPoint(this->owner->getDamage() / 4);
}