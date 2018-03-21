#include "Berserker.h"

Berserker::Berserker(const char* title, int hitPoint, int damage): 
    Unit(title, hitPoint, damage) {
        this->ability = new Ability(this);
    }

Berserker::~Berserker() {}

void Berserker::takeMagicDamage(int dmg) {
}