#ifndef ABILITY_H
#define ABILITY_H

#include "../Unit/Unit.h"

class Unit;

class Ability {
    protected:
        Unit* owner;

    public:
        Ability(Unit* owner);
        virtual ~Ability();
        
        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);
};

#endif // ABILITY_H