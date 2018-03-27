#include "RogueAbility.h"

RogueAbility::RogueAbility(Unit* owner): Ability(owner) {}
RogueAbility::~RogueAbility() {}

void RogueAbility::attack(Unit* owner, Unit* enemy) {
    this->owner->ensureIsAlive();
    enemy->takeDamage(this->owner->getDamage());
}