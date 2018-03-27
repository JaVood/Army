#ifndef SUBJECT_H
#define SUBJECT_H

#include <set>
#include "Observer.h"

class Observer;
class Subject {
    protected:
        std::set<Observer*>* observerList;

    public:
        Subject();
        virtual ~Subject();

        void attach(Observer* another);
        void detach(Observer* another);
        void notify();
};

#endif // SUBJECT_H
