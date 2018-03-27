#ifndef WIZARD_H
#define WIZARD_H

#include "SpellCaster.h"

#define WIZARD_HIT_POINT 600
#define WIZARD_DAMAGE 50
#define WIZARD_MANA_POINT 500

class Wizard : public SpellCaster {
    protected:
    public:
        Wizard(const char* title, int hitPoint = WIZARD_HIT_POINT, int damage = WIZARD_DAMAGE, int manaPoint = WIZARD_MANA_POINT);
        virtual ~Wizard();
};

#endif // WIZARD_H