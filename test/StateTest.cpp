#include "../State/State.h"
#include "catch.hpp"

TEST_CASE( "Test State class" ) {
    State* state = new State("State", 150, 10);

    REQUIRE( state->getTitle() == "State" );
    REQUIRE( state->getHitPoint() == 150 );
    REQUIRE( state->getHitPointLimit() == 150 );
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

        state->addHitPoints(40);
        REQUIRE( state->getHitPoint() == 140 );

        state->addHitPoints(10);
        REQUIRE( state->getHitPoint() == 150 );

        state->addHitPoints(10);
        REQUIRE( state->getHitPoint() == 150 );
    }
}