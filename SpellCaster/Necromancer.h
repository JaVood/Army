#ifndef NECROMANCER_H
#define NECROMANCER_H

#include "SpellCaster.h"

#define NECROMANCER_HIT_POINT 600
#define NECROMANCER_DAMAGE 50
#define NECROMANCER_MANA_POINT 500

class Necromancer : public SpellCaster {
    protected:
    public:
        Necromancer(const char* title, int hitPoint = NECROMANCER_HIT_POINT, int damage = NECROMANCER_DAMAGE, int manaPoint = NECROMANCER_MANA_POINT);
        virtual ~Necromancer();
        
        virtual void attack(Unit* enemy);
        virtual void update(Subject* enemy);
};

#endif // NECROMANCER_H