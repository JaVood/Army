#ifndef ROGUE_H
#define ROGUE_H

#include "Unit.h"
#include "../Ability/RogueAbility.h"

#define ROGUE_HIT_POINT 700
#define ROGUE_DAMAGE 130


class Rogue : public Unit {
    public:
        Rogue(const char* title, int hitPoint = ROGUE_HIT_POINT, int damage = ROGUE_DAMAGE);
        virtual ~Rogue();
};

#endif // ROGUE_H
