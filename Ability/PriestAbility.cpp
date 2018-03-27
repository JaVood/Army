#include "PriestAbility.h"

PriestAbility::PriestAbility(Unit* owner): Ability(owner) {}
PriestAbility::~PriestAbility() {}

void PriestAbility::attack(Unit* owner, Unit* enemy) {
    this->owner->ensureIsAlive();
    
    if ( owner->getIsVampire() == true ) {
        owner->addHitPoint(20);
        owner->turnInVampire(enemy);
    }
    if ( owner->getIsWerewolf() == true ) {
        owner->turnInWerewolf(enemy);
    }
    if ( enemy->getIsUndead() ) {
        enemy->takeDamage(this->owner->getDamage()*2);
        enemy->counterAttack(enemy, owner);
    } else {
        enemy->takeDamage(this->owner->getDamage());
        enemy->counterAttack(enemy, owner);
    }
}

void PriestAbility::counterAttack(Unit* owner, Unit* enemy) {
    this->owner->ensureIsAlive();
    
    if ( owner->getIsVampire() == true ) {
        owner->addHitPoint(20);
        owner->turnInVampire(enemy);
    }
    if ( enemy->getIsUndead() ) {
        enemy->takeDamage(this->owner->getDamage());
    } else {
        enemy->takeDamage(this->owner->getDamage()/2);
    }
}
