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
        State(const char* title, int hitPoint, int manaPoint, int damage);
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
        void spendManaPoint(int mp);
        void takeDamage(int dmg);
        void takeMagicDamage(int dmg);
};

#endif // STATE_H
