#ifndef DEMON_H
#define DEMON_H

#include "Soldier.h"

#define DEMON_HIT_POINT 900
#define DEMON_DAMAGE 150

class Demon : public Soldier {
    protected:
        Unit* owner;

        void ensureHisOwner(Unit* enemy);

    public:
        Demon(Unit* owner,const char* title = "Demon", int hitPoint = DEMON_HIT_POINT, int damage = DEMON_DAMAGE);
        virtual ~Demon();

        virtual void attack(Unit* attacker, Unit* enemy);
        virtual void counterAttack(Unit* attacker, Unit* enemy);
};

#endif // DEMON_H
