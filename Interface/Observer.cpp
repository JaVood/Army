#include "Observer.h"

Observer::Observer() : set(new std::set<Subject*>()) {}

Observer::~Observer() {
    this->notifySubjects();
}

void Observer::addSubject(Subject* another) {
    this->set->insert(another);
    another->attach(this);
}

void Observer::notifySubjects() {
    std::set<Subject*>::iterator it;

    for ( it = set->begin(); it != set->end(); it++ ) {
        Subject* subj = *it;

        subj->detach(this);
    }
}

void Observer::update(Subject* another) {
    std::set<Subject*>::iterator it = set->find(another);
    if ( it != set->end() ) {
        set->erase(it);
    }
}