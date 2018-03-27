#ifndef SPELL_CASTER_H
#define SPELL_CASTER_H

#include "../Unit/Unit.h"
#include "../Ability/Ability.h"
#include "../Spell/Spell.h"
#include "../Spell/Vortex.h"
#include "../Spell/BattleHeal.h"
#include <map>

class SpellCaster : public Unit {
    protected:
        std::map<SPELL_ENUM, Spell*>* spellBook;
        bool isBattleMag;
    public:
        SpellCaster(const char* title, int hitPoint, int damage, int manaPoint, bool isBattleMag, bool isUndead=false);
        virtual ~SpellCaster();

        const std::map<SPELL_ENUM, Spell*>& getSpellBook() const;
        int getManaPoint() const;
        int getManaPointLimit() const;
        const bool getIsBattle() const;
        virtual void spendMana(int mp);
        
        virtual void addManaPoint(int mp);
        virtual void castSpell(Unit* other, SPELL_ENUM spell);
};

#endif // SPELL_CASTER_H