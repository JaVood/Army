#ifndef STATE_H
#define STATE_H

#include <iostream>
#include "../Exception/Exceptions.h"

class State {
    protected:
        const char* title;
        int hitPoint;
        int hitPointLimit;
        int manaPoint;
        int manaPointLimit;
        int damage;
        
        void _takeDamage(int dmg);
        void _takeMagicDamage(int dmg);
        
    public:
        State(const char* title, int hitPoint, int damage, int manaPoint = 0);
        virtual ~State();
        
        void ensureIsAlive();
        
        const char* getTitle() const;
        int getHitPoint() const;
        int getHitPointLimit() const;
        int getManaPoint() const;
        int getManaPointLimit() const;
        int getDamage() const;
        
        void addHitPoint(int hp);
        void addManaPoint(int mp);
        void takeDamage(int dmg);
        void takeMagicDamage(int dmg);
        void spendMana(int mp);
        void setName(const char* title);
        void setHitPoint(int hp);
        void setManaPoint(int mp);
        void setDamage(int dmg);
        void setHitPointLimit(int hp);
        void setManaPointLimit(int mp);
};

#endif // STATE_H
