#include "Berserker.h"

Berserker::Berserker(const char* title, int hitPoint, int damage): 
    Unit(title, hitPoint, damage) {}

Berserker::~Berserker() {}

void Berserker::takeMagicDamage(int dmg) {
}