#ifndef STATE_H
#define STATE_H

#include <iostream>
#include "../Exception/Exceptions.h"

class State {
    protected:
        const char* title;
        int hitPoint;
        int hitPointLimit;
        int damage;
        
        void _takeDamage(int dmg);
        void _takeMagicDamage(int dmg);
        
    public:
        State(const char* title, int hitPoint, int damage);
        virtual ~State();
        
        void ensureIsAlive();
        
        const char* getTitle() const;
        int getHitPoint() const;
        int getHitPointLimit() const;
        int getDamage() const;
        
        void addHitPoints(int hp);
        void takeDamage(int dmg);
        void takeMagicDamage(int dmg);
};

#endif // STATE_h
