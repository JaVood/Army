#ifndef HEALER_H
#define HEALER_H

#include "SpellCaster.h"

#define HEALER_HIT_POINT 600
#define HEALER_DAMAGE 30
#define HEALER_MANA_POINT 500

class Healer : public SpellCaster {
    protected:
    public:
        Healer(const char* title, int hitPoint = HEALER_HIT_POINT, int damage = HEALER_DAMAGE, int manaPoint = HEALER_MANA_POINT);
        virtual ~Healer();
};

#endif // HEALER_H