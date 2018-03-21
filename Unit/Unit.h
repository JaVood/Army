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
        Unit(const char* title, int hitPoint, int manaPoint, int damage);
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
};

#endif // UNIT_H