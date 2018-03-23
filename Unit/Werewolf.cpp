#include "Werewolf.h"

Werewolf::Werewolf(const char* title, const char* unitType, int hitPoint, int damage): 
    Unit(title, unitType, hitPoint, damage) {
        this->ability = new Ability(this);
    }

Werewolf::~Werewolf() {}

void Werewolf::transform() {
    this->ensureIsAlive();
    Unit::setName("Wolf");
    Unit::setDamage(200);
    Unit::setHitPoint(Unit::getHitPoint());
    Unit::setHitPointLimit(1300);

}
