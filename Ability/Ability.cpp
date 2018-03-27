#include "Ability.h"

Ability::Ability(Unit* owner): owner(owner) {}

Ability::~Ability() {}

void Ability::attack(Unit* owner, Unit* enemy) {
    owner->ensureIsAlive();
    enemy->takeDamage(owner->getDamage());
    if ( owner->getIsVampire() == true ) {
        owner->addHitPoint(20);
        owner->turnInVampire(enemy);
    }
    if ( owner->getIsWerewolf() == true ) {
        owner->turnInWerewolf(enemy);
    }
    enemy->counterAttack(enemy,owner);
}

void Ability::counterAttack(Unit* owner, Unit* enemy) {
    owner->ensureIsAlive();
    enemy->takeDamage(owner->getDamage() / 2);
    if ( owner->getIsVampire() == true ) {
        owner->addHitPoint(20);
        owner->turnInVampire(enemy);
    }
}
