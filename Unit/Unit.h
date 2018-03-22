#ifndef UNIT_H
#define UNIT_H

#include "../State/State.h"
#include "../Ability/Ability.h"

class Ability;

class Unit {
    protected:
        State* state;
        Ability* ability;
        
    public:
        Unit(const char* title, int hitPoint, int damage, int manaPoint = 0);
        virtual~Unit();
        
        void ensureIsAlive();

        const char* getTitle() const;
        int getHitPoint() const;
        int getHitPointLimit() const;
        int getDamage() const;

        void addHitPoint(int hp);
        void takeDamage(int dmg);

        virtual void transform();
        virtual void takeMagicDamage(int dmg);
        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);
        virtual void hitPointDrain();
        virtual void setHitPoint(int hp);
        virtual void setName(const char* title);
        virtual void setDamage(int dmg);
        virtual void setHitPointLimit(int hp);
};

#endif // UNIT_H