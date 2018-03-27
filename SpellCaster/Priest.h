#ifndef PRIEST_H
#define PRIEST_H

#include "SpellCaster.h"
#include "../Ability/PriestAbility.h"

#define PRIEST_HIT_POINT 700
#define PRIEST_DAMAGE 40
#define PRIEST_MANA_POINT 500

class Priest : public SpellCaster {
    protected:
        BattleHeal* battleHeal;
        Vortex* vortex;
    public:
        Priest(const char* title, int hitPoint = PRIEST_HIT_POINT, int damage = PRIEST_DAMAGE, int manaPoint = PRIEST_MANA_POINT);
        virtual ~Priest();
};

#endif // PRIEST_H