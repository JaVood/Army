#include "../State/State.h"
#include "../Unit/Unit.h"
#include "catch.hpp"

TEST_CASE( "Test State class" ) {
    State* state = new State("State", 150,100, 10);

    REQUIRE( state->getTitle() == "State" );
    REQUIRE( state->getHitPoint() == 150 );
    REQUIRE( state->getHitPointLimit() == 150 );
    REQUIRE( state->getManaPoint() == 100 );
    REQUIRE( state->getManaPointLimit() == 100 );
    REQUIRE( state->getDamage() == 10 );
    
    SECTION( "State::takeDamage tests" ) {
        state->takeDamage(50);
        REQUIRE( state->getHitPoint() == 100 );

        state->takeDamage(40);
        REQUIRE( state->getHitPoint() == 100-40 );

        state->takeDamage(10);
        REQUIRE( state->getHitPoint() == 100-40-10 );

        state->takeDamage(10);
        REQUIRE( state->getHitPoint() == 100-40-10-10 );
        
        state->takeDamage(100);
        REQUIRE( state->getHitPoint() == 0 );
    }
    
    
    SECTION( "State::addHP tests" ) {
        state->takeDamage(50);
        REQUIRE( state->getHitPoint() == 100 );

        state->addHitPoint(40);
        REQUIRE( state->getHitPoint() == 140 );

        state->addHitPoint(10);
        REQUIRE( state->getHitPoint() == 150 );

        state->addHitPoint(10);
        REQUIRE( state->getHitPoint() == 150 );
    }
    
    SECTION( "State::Spend mana tests" ) {
        state->spendManaPoint(5);
        REQUIRE( state->getManaPoint() == 100-5 );

        state->spendManaPoint(10);
        REQUIRE( state->getManaPoint() == 100-5-10 );

        state->spendManaPoint(20);
        REQUIRE( state->getManaPoint() == 100-5-10-20 );

        state->spendManaPoint(11);
        REQUIRE( state->getManaPoint() == 100-5-10-20-11 );
        
        state->spendManaPoint(100);
        REQUIRE( state->getManaPoint() == 0 );
    }
    
    SECTION( "State::addMana tests" ) {
        state->spendManaPoint(80);
        REQUIRE( state->getManaPoint() == 100-80 );

        state->addManaPoint(20);
        REQUIRE( state->getManaPoint() == 100-80+20 );

        state->addManaPoint(20);
        REQUIRE( state->getManaPoint() == 100-80+20+20 );

        state->addManaPoint(100);
        REQUIRE( state->getManaPoint() == 100 );
    }
}

TEST_CASE( "Test Unit class" ) {
    Unit* unit = new Unit("Unit", 150, 0, 10);

    REQUIRE( unit->getTitle() == "Unit" );
    REQUIRE( unit->getHitPoint() == 150 );
    REQUIRE( unit->getHitPointLimit() == 150 );
    REQUIRE( unit->getDamage() == 10 );
    
    SECTION( "Unit::takeDamage tests" ) {
        unit->takeDamage(50);
        REQUIRE( unit->getHitPoint() == 100 );

        unit->takeDamage(40);
        REQUIRE( unit->getHitPoint() == 100-40 );

        unit->takeDamage(10);
        REQUIRE( unit->getHitPoint() == 100-40-10 );

        unit->takeDamage(10);
        REQUIRE( unit->getHitPoint() == 100-40-10-10 );
        
        unit->takeDamage(100);
        REQUIRE( unit->getHitPoint() == 0 );
    }
    
    SECTION( "Unit::addHP tests" ) {
        unit->takeDamage(50);
        REQUIRE( unit->getHitPoint() == 100 );

        unit->addHitPoint(40);
        REQUIRE( unit->getHitPoint() == 140 );

        unit->addHitPoint(10);
        REQUIRE( unit->getHitPoint() == 150 );

        unit->addHitPoint(10);
        REQUIRE( unit->getHitPoint() == 150 );
    }
}

TEST_CASE( "Test Ability class" ) {
    Unit* unit = new Unit("Unit", 150, 0, 10);

    REQUIRE( unit->getTitle() == "Unit" );
    REQUIRE( unit->getHitPoint() == 150 );
    REQUIRE( unit->getHitPointLimit() == 150 );
    REQUIRE( unit->getDamage() == 10 );
    
    SECTION( "Ability::attack tests" ) {
        Unit* enemy = new Unit("Enemy", 150, 0, 10);
        
        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getHitPoint() == 150 );
        REQUIRE( enemy->getHitPointLimit() == 150 );
        REQUIRE( enemy->getDamage() == 10 );
        
        REQUIRE( enemy->getHitPoint() == 150 );

        unit->addHitPoint(40);
        REQUIRE( unit->getHitPoint() == 150 );

        unit->addHitPoint(10);
        REQUIRE( unit->getHitPoint() == 150 );

        unit->addHitPoint(10);
        REQUIRE( unit->getHitPoint() == 150 );
    }
}