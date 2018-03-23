#ifndef PRIEST_H
#define PRIEST_H

#include "SpellCaster.h"
#include "../Ability/PriestAbility.h"
#include "../Spell/BattleHeal.h"
#include "../Spell/Vortex.h"


#define PRIEST_HIT_POINT 700
#define PRIEST_DAMAGE 40
#define PRIEST_UNIT_TYPE "Alive"
#define PRIEST_MANA_POINT 500
#define PRIEST_MAGIC_TYPE "Priest"

class Priest : public SpellCaster {
    protected:
        BattleHeal* battleHeal;
        Vortex* vortex;
    public:
        Priest(const char* title, const char* unitType = PRIEST_UNIT_TYPE, int hitPoint = PRIEST_HIT_POINT, int damage = PRIEST_DAMAGE, int manaPoint = PRIEST_MANA_POINT, const char* magicType = PRIEST_MAGIC_TYPE);
        virtual ~Priest();
        
        virtual void heal(Unit* patient);
        virtual void useBattleSpell(Unit* enemy);
};

#endif // PRIEST_H