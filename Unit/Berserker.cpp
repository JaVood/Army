#include "Berserker.h"

Berserker::Berserker(const char* title, const char* unitType, int hitPoint, int damage): 
    Unit(title, unitType, hitPoint, damage) {
        this->ability = new Ability(this);
    }

Berserker::~Berserker() {}

void Berserker::takeMagicDamage(int dmg) {
}