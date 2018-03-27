#include "Werewolf.h"

Werewolf::Werewolf(const char* title, int hitPoint, int damage): 
    Unit(title, hitPoint, damage, 0, false, false, true) {}

Werewolf::~Werewolf() {}
