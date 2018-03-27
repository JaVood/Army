#ifndef VORTEX_H
#define VORTEX_H

#include "Spell.h"
#include "../SpellCaster/SpellCaster.h"

class SpellCaster;

class Vortex : public Spell {
    protected:
        void priestCast(SpellCaster* caster, Unit* enemy, Spell* spell);
        void necromanserCast(SpellCaster* caster, Unit* enemy, Spell* spell);
    public:
        Vortex(std::string spellName="Vortex", int manaCost=50, int actionsPoints=200);
        virtual ~Vortex();

        virtual void cast(SpellCaster* caster, Unit* enemy, Spell* spell);
};

#endif // VORTEX_H