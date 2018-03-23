#ifndef HEALER_H
#define HEALER_H

#include "SpellCaster.h"
#include "../Ability/Ability.h"
#include "../Spell/BattleHeal.h"
#include "../Spell/Vortex.h"


#define HEALER_HIT_POINT 600
#define HEALER_DAMAGE 30
#define HEALER_UNIT_TYPE "Alive"
#define HEALER_MANA_POINT 500
#define HEALER_MAGIC_TYPE "Healer"

class Healer : public SpellCaster {
    protected:
        BattleHeal* battleHeal;
        Vortex* vortex;
    public:
        Healer(const char* title, const char* unitType = HEALER_UNIT_TYPE, int hitPoint = HEALER_HIT_POINT, int damage = HEALER_DAMAGE, int manaPoint = HEALER_MANA_POINT, const char* magicType = HEALER_MAGIC_TYPE);
        virtual ~Healer();
        
        virtual void heal(Unit* patient);
        virtual void useBattleSpell(Unit* enemy);
};

#endif // HEALER_H