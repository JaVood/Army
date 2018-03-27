#ifndef PRIEST_ABILITY
#define PRIEST_ABILITY

#include "Ability.h"

class PriestAbility : public Ability {
    public:
        PriestAbility(Unit* owner);
        virtual ~PriestAbility();
        
        virtual void attack(Unit* owner, Unit* enemy);
        virtual void counterAttack(Unit* owner, Unit* enemy);
};


#endif // PRIEST_ABILITY
