#include "Spell.h"

Spell::Spell(Unit* owner): owner(owner) {}
Spell::~Spell() {}

void Spell::useSpell(Unit* unit) {
    
}

void Spell::vortex(Unit* enemy, int dmg) {}

void Spell::battleHeal(Unit* friend, int power) {}

void Spell::summonDemon() {}