#ifndef WIZARD_H
#define WIZARD_H

#include "SpellCaster.h"
#include "../Ability/Ability.h"
#include "../Spell/BattleHeal.h"
#include "../Spell/Vortex.h"


#define WIZARD_HIT_POINT 600
#define WIZARD_DAMAGE 50
#define WIZARD_UNIT_TYPE "Alive"
#define WIZARD_MANA_POINT 500
#define WIZARD_MAGIC_TYPE "Magician"

class Wizard : public SpellCaster {
    protected:
        BattleHeal* battleHeal;
        Vortex* vortex;
    public:
        Wizard(const char* title, const char* unitType = WIZARD_UNIT_TYPE, int hitPoint = WIZARD_HIT_POINT, int damage = WIZARD_DAMAGE, int manaPoint = WIZARD_MANA_POINT, const char* magicType = WIZARD_MAGIC_TYPE);
        virtual ~Wizard();
        
        virtual void heal(Unit* patient);
        virtual void useBattleSpell(Unit* enemy);
};

#endif // WIZARD_H