#include "../State/State.h"
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