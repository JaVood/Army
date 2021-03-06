#ifndef BERSERKER_H
#define BERSERKER_H

#include "Unit.h"
#include "../Ability/Ability.h"

#define BERSERKER_HIT_POINT 800
#define BERSERKER_DAMAGE 150

class Berserker : public Unit {
    public:
        Berserker(const char* title, int hitPoint = BERSERKER_HIT_POINT, int damage = BERSERKER_DAMAGE);
        virtual ~Berserker();
        
        virtual void takeMagicDamage(int dmg);
};

#endif // BERSERKER_H