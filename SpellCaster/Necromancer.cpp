#include "Necromancer.h"

Necromancer::Necromancer(const char* title, int hitPoint, int damage, int manaPoint) : SpellCaster(title, hitPoint, damage, manaPoint, true, true) {
    this->ability = new Ability(this);
    }

Necromancer::~Necromancer() {}

void Necromancer::attack(Unit* enemy) {
    Unit::attack(this, enemy);

    this->addSubject(enemy);
}

void Necromancer::update(Subject* enemy) {
    Observer::update(enemy);

    this->addHitPoint(this->getDamage());
}