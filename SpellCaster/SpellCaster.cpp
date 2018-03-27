#include "SpellCaster.h"

SpellCaster::SpellCaster(const char* title, int hitPoint, int damage, int manaPoint, bool isBattle, bool isUndead) : Unit(title, hitPoint, damage, manaPoint, isUndead, false, false) {
    this->ability = new Ability(this);
    this->spellBook = new std::map<SPELL_ENUM, Spell*>();
    this->spellBook->insert(std::pair<SPELL_ENUM, Spell*>(VORTEX, new Vortex()));
    this->spellBook->insert(std::pair<SPELL_ENUM, Spell*>(BATTLEHEAL, new BattleHeal()));
    this->isBattleMag = isBattle;
}
    
SpellCaster::~SpellCaster() {
    std::map<SPELL_ENUM, Spell*>::iterator it;

    for ( it = this->spellBook->begin(); it != this->spellBook->end(); it++ ) {
        delete it->second;
    }

    delete spellBook;
}

int SpellCaster::getManaPoint() const {
    return this->state->getManaPoint();
}

int SpellCaster::getManaPointLimit() const {
    return this->state->getManaPointLimit();
}

const std::map<SPELL_ENUM, Spell*>& SpellCaster::getSpellBook() const {
    return *(this->spellBook);
}

const bool SpellCaster::getIsBattle() const {
    return this->isBattleMag;
}

void SpellCaster::addManaPoint(int mp) {
    this->state->addManaPoint(mp);
}

void SpellCaster::spendMana(int mp) {
    this->state->spendMana(mp);
}

void SpellCaster::castSpell(Unit* other, SPELL_ENUM spell) {
    std::map<SPELL_ENUM, Spell*>::iterator it = this->spellBook->find(spell);

    it->second->Spell::cast(this, other, it->second);
}
