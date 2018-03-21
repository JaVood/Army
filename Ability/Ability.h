#ifndef ABILITY_H
#define ABILITY_H

#include "../Unit/Unit.h"

class Unit;

class Ability {
    protected:
        Unit* master;
        
    public:
        Ability(Unit* master);
        virtual ~Ability();
        
        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);
};

#endif // ABILITY_H
