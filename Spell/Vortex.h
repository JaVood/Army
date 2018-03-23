#ifndef VORTEX
#define VORTEX

#include "../Unit/Unit.h"
#include "../SpellCaster/SpellCaster.h"

#define MAGIC_DAMAGE 200
#define MANA_VORTEX_COST 50

class Vortex {
    public:
        Vortex(SpellCaster* unit, Unit* enemy);
        ~Vortex();

        void magicAttack(SpellCaster* unit, Unit* enemy);
};

#endif // VORTEX