#ifndef SPELL_CASTER_H
#define SPELL_CASTER_H

#include "../Unit/Unit.h"
#include "../Ability/Ability.h"

class SpellCaster : public Unit {
    public:
        SpellCaster(const char* title, const char* unitType, int hitPoint, int damage, int manaPoint,  const char* magicType);
        virtual ~SpellCaster();
        
        int getManaPoint() const;
        int getManaPointLimit() const;
        const char* getMagicType() const;
        
        virtual void setManaPoint(int mp);
        virtual void spendMana(int mp);
        virtual void addManaPoint(int mp);
        virtual void setManaPointLimit(int mp);
        virtual void heal(Unit* patient);
        virtual void useBattleSpell(Unit* enemy);
};

#endif // SPELL_CASTER_H