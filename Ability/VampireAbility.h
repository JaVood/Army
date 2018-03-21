#ifndef VAMPIRE_ABILITY
#define VAMPIRE_ABILITY

#include "Ability.h"

class VampireAbility : public Ability {
    public:
        VampireAbility(Unit* owner);
        virtual ~VampireAbility();
        
        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);
        virtual void hitPointDrain();
};


#endif // VAMPIRE_ABILITY
