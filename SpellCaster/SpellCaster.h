#ifndef SPELL_CASTER_H
#define SPELL_CASTER_H

#include "../State/State.h"
#include "../Unit/Unit.h"
#include "../Ability/Ability.h"
#include "../Spell/Spell.h"

class Spell;

class SpellCaster {
    protected:
        State* state;
        Ability* ability;
        Spell* spell;
        
    public:
        SpellCaster(const char* title, int hitPoint, int damage, int manaPoint );
        virtual~SpellCaster();
        
        int getManaPoint() const;
        int getManaPointLimit() const;
        
        virtual void setManaPoint(int mp);
        virtual void spendMana(int mp);
        virtual void addManaPoint(int mp);
        virtual void setManaPointLimit(int mp);
        virtual void useSpell(Unit* unit);
        virtual void vortex(Unit* enemy, int dmg);
        virtual void battleHeal(Unit* friend, int power);
        virtual void summonDemon();
};

#endif // SPELL_CASTER_H