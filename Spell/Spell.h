#ifndef SPELL_H
#define SPELL_H

#include "../Unit/Unit.h"
#include "../SpellCaster/SpellCaster.h"

class SpellCaster;

class Spell {
    protected:
        Unit* owner;

    public:
        Spell(Unit* owner);
        virtual ~Spell();
        
        virtual void useSpell(Unit* unit);
        virtual void vortex(Unit* enemy, int dmg);
        virtual void battleHeal(Unit* friend, int power);
        virtual void summonDemon();
};

#endif // SPELL_H