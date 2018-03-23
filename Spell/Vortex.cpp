#include "Vortex.h"

Vortex::Vortex(SpellCaster* wizard, Unit* enemy) {
    wizard->ensureIsAlive();
    enemy->ensureIsAlive();

    this->magicAttack(wizard, enemy);
}
Vortex::~Vortex() {}

void Vortex::magicAttack(SpellCaster* wizard, Unit* enemy) {
    if ( wizard->getManaPoint() < MANA_VORTEX_COST ) {
        return;
    }
    
    if ( strcmp(wizard->getMagicType(), "Priest") == 0 && strcmp(enemy->getUnitType(), "Undead") == 0 ) {
        wizard->spendMana(MANA_VORTEX_COST);
        enemy->takeMagicDamage(MAGIC_DAMAGE);
        return;
    }
    
    if ( strcmp(wizard->getMagicType(), "Healer") == 0 || strcmp(wizard->getMagicType(), "Priest") == 0 ) {
        wizard->spendMana(MANA_VORTEX_COST);
        enemy->takeMagicDamage(MAGIC_DAMAGE/2);
        return;
    }

    wizard->spendMana(MANA_VORTEX_COST);
    enemy->takeMagicDamage(MAGIC_DAMAGE);
}