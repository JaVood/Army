#ifndef UNIT_H
#define UNIT_H

#include "../State/State.h"
#include "../Ability/Ability.h"
#include "../Interface/Observer.h"
#include "../Interface/Subject.h"

class Ability;

class Unit : public Observer, public Subject {
    protected:
        State* state;
        Ability* ability;
        bool isUndead;
        bool isWerewolf;
        bool isVampire;

    public:
        Unit(const char* title, int hitPoint, int damage, int manaPoint = 0, bool isUndead=false, bool isVampire=false, bool isWerewolf=false);
        virtual~Unit();
        
        void ensureIsAlive();

        const char* getTitle() const;
        int getHitPoint() const;
        int getHitPointLimit() const;
        const bool getIsUndead() const;
        int getDamage() const;
        const bool getIsWerewolf() const;
        const bool getIsVampire() const;

        void addHitPoint(int hp);
        void takeDamage(int dmg);

        
        virtual void transformInToWolf();
        virtual void takeMagicDamage(int dmg);
        virtual void attack(Unit* owner, Unit* enemy);
        virtual void counterAttack(Unit* owner, Unit* enemy);
        virtual void turnInVampire(Unit* enemy);
        virtual void turnInWerewolf(Unit* enemy);
        void setName(const char* title);
        void setHitPoint(int hp);
        void setDamage(int dmg);
        void setHitPointLimit(int hp);
};

#endif // UNIT_H