#include "Warlock.h"

Warlock::Warlock(const char* title, int hitPoint, int damage, int manaPoint) : SpellCaster(title, hitPoint, damage, manaPoint, true) {
    this->ability = new Ability(this);
    }
    
Warlock::~Warlock() {}

Demon* Warlock::summonDemon() {
    if ( this->getHitPoint() > 0 ) {
        Demon* demon = new Demon(this);

        // this->addSubject(temp);

        return demon;
    } else {
        throw OutOfHitPointsException();
    }
}
