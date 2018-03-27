#ifndef WARLOCK_H
#define WARLOCK_H

#include "SpellCaster.h"
#include "../Unit/Demon.h"

class Demon;

#define WARLOCK_HIT_POINT 600
#define WARLOCK_DAMAGE 30
#define WARLOCK_MANA_POINT 500


class Warlock : public SpellCaster {
    public:
        Warlock(const char* title, int hitPoint = WARLOCK_HIT_POINT, int damage = WARLOCK_DAMAGE, int manaPoint = WARLOCK_MANA_POINT);
        virtual ~Warlock();
        
        virtual Demon* summonDemon();
};

#endif //WARLOCK_H
