#include "Subject.h"

Subject::Subject() : observerList(new std::set<Observer*>()) {}

Subject::~Subject() {}

void Subject::attach(Observer* another) {
    this->observerList->insert(another);
}

void Subject::detach(Observer* another) {
    std::set<Observer*>::iterator it = observerList->find(another);

    if ( it != observerList->end() ) {
        observerList->erase(it);
    }
}

void Subject::notify() {
    std::set<Observer*>::iterator it;

    for ( it = observerList->begin(); it != observerList->end(); it++ ) {
        Observer* obs = *it;

        obs->update(this);
    }
}