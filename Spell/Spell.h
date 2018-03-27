#ifndef SPELL_H
#define SPELL_H

#include "../Exception/Exceptions.h"
#include "../Unit/Unit.h"
#include <iostream>

class SpellCaster;

enum SPELL_ENUM {
    VORTEX,
    BATTLEHEAL
};

class Spell {
    protected:
        int actionPoints;
        int manaCost;
        std::string spellName;
        
    public:
        Spell(std::string spellName, int actionPoints, int manaCost);
        virtual ~Spell();
        
        const int getManaCost() const;
        const int getActionPoints() const;
        const std::string& getSpellName() const;

        virtual void cast(SpellCaster* caster, Unit* other, Spell* spell) = 0;
};

#endif //SPELL_H
