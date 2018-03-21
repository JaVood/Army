#include "Berserker.h"

Berserker::Berserker(const char* title, int hitPoints, int damage): 
    Unit(title, hitPoints, damage) {
        this->ability = new Ability(this);
    }

Berserker::~Berserker() {}

void Berserker::takeMagicDamage(int dmg) {
}