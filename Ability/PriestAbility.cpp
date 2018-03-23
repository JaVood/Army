#include "PriestAbility.h"

PriestAbility::PriestAbility(Unit* owner): Ability(owner) {}
PriestAbility::~PriestAbility() {}

void PriestAbility::attack(Unit* enemy) {
    this->owner->ensureIsAlive();
    
    if ( strcmp(enemy->getUnitType(), "Undead") == 0 ) {
        enemy->takeDamage(this->owner->getDamage()*2);
        enemy->counterAttack(this->owner);
        return;
    }
    enemy->takeDamage(this->owner->getDamage());
    enemy->counterAttack(this->owner);
}

void PriestAbility::counterAttack(Unit* enemy) {
    this->owner->ensureIsAlive();
    
    if ( strcmp(enemy->getUnitType(), "Undead") == 0 ) {
        enemy->takeDamage(this->owner->getDamage());
        return;
    }
    enemy->takeDamage(this->owner->getDamage()/2);
}
