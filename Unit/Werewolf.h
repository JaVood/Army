#ifndef WEREWOLF_H
#define WEREWOLF_H

#include "Unit.h"
#include "../Ability/Ability.h"

#define WEREWOLF_HIT_POINT 900
#define WEREWOLF_DAMAGE 100

class Werewolf : public Unit {
    public:
        Werewolf(const char* title, int hitPoint = WEREWOLF_HIT_POINT, int damage = WEREWOLF_DAMAGE);
        virtual ~Werewolf();
        
        virtual void transform();
};

#endif // WEREWOLF_H