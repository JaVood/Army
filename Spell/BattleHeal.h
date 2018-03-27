#ifndef BATTLE_HEAL_H
#define BATTLE_HEAL_H

#include "Spell.h"
#include "../SpellCaster/SpellCaster.h"

class SpellCaster;

class BattleHeal : public Spell {
    public:
        BattleHeal(std::string spellName="BattleHeal", int manaCost=30, int actionsPoints=100);
        virtual ~BattleHeal();

        virtual void cast(SpellCaster* caster, Unit* other, Spell* spell);
};
#endif // BATTLE_HEAL_H