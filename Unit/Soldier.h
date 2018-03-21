#ifndef SOLDIER_H
#define SOLDIER_H

#include "Unit.h"
#include "../Ability/Ability.h"

#define SOLDIER_HIT_POINT 1000
#define SOLDIER_DAMAGE 100

class Soldier : public Unit {
    public:
        Soldier(const char* title, int hitPoint = SOLDIER_HIT_POINT, int damage = SOLDIER_DAMAGE);
        virtual ~Soldier();
};

#endif // SOLDIER_H