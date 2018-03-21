#include "Ability.h"

Ability::Ability(Unit* master): master(master) {}
Ability::~Ability() {}

void Ability::attack(Unit* enemy) {
    this->master->ensureIsAlive();
    enemy->takeDamage(this->master->getDamage());
    enemy->counterAttack(this->master);
}

void Ability::counterAttack(Unit* enemy) {
    this->master->ensureIsAlive();
    enemy->takeDamage(this->master->getDamage()/2);
    
}
