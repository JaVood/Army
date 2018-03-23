#ifndef VAMPIRE_H
#define VAMPIRE_H

#include "Unit.h"
#include "../Ability/VampireAbility.h"

#define VAMPIRE_HIT_POINT 1200
#define VAMPIRE_DAMAGE 80
#define VAMPIRE_TYPE "Undead"

class Vampire : public Unit {
    public:
        Vampire(const char* title, const char* unitType = VAMPIRE_TYPE,int hitPoint = VAMPIRE_HIT_POINT, int damage = VAMPIRE_DAMAGE);
        virtual ~Vampire();
};

#endif // VAMPIRE_H