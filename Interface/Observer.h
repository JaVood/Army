#ifndef OBSERVER_H
#define OBSERVER_H

#include <set>
#include "Subject.h"

class Subject;

class Observer {
    protected:
        std::set<Subject*>* set;

    public:
        Observer();
        virtual ~Observer();

        void addSubject(Subject* another);
        void notifySubjects();
        virtual void update(Subject* another);
};

#endif //OBSERVER_H
