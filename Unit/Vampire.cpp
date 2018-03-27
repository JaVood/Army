#include "Vampire.h"

Vampire::Vampire(const char* title, int hitPoint, int damage): 
    Unit(title, hitPoint, damage, 0, true, true, false) {}

Vampire::~Vampire() {}
