#include "Demon.h"

Demon::Demon(Unit* owner, const char* title, int hitPoint, int damage) : Soldier(title, hitPoint, damage), owner(owner) {}

Demon::~Demon() {
    // this->update(this);
}

void Demon::ensureHisOwner(Unit* enemy) {
    if ( enemy == this->owner ) {
        throw UnitCantAttackHisOwnerException();
    }
}

void Demon::attack(Unit* attacker, Unit* enemy) {
    ensureHisOwner(enemy);
    
    Unit::attack(this, enemy);
}

void Demon::counterAttack(Unit* attacker, Unit* enemy) {
    ensureHisOwner(enemy);

    Unit::counterAttack(attacker, enemy);
}
