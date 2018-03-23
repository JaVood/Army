#ifndef BATTLE_HEAL
#define BATTLE_HEAL

#include "../Unit/Unit.h"
#include "../SpellCaster/SpellCaster.h"

#define HEAL 100
#define MANA_BATTLE_HEAL_COST 30

class BattleHeal {
    public:
        BattleHeal(SpellCaster* unit, Unit* patient);
        ~BattleHeal();

        void heal(SpellCaster* unit, Unit* patient);
};

#endif // BATTLE_HEAL