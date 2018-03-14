#include "catch.hpp"
#include "../State/State.h"

TEST_CASE( "Test State class" ) {
    State* state = new State('dede', 150, 10);

    REQUIRE( state->getHitPoint() == 150 );
    REQUIRE( state->getHitPointLimit() == 150 );
    
    SECTION( "State::takeDamage tests" ) {
        state->takeDamage(50);
        REQUIRE( state->getHitPoint() == 100 );

        state->takeDamage(40);
        REQUIRE( state->getHitPoint() == 140 );

        state->takeDamage(10);
        REQUIRE( state->getHitPoint() == 150 );

        state->takeDamage(10);
        REQUIRE( state->getHitPoint() == 150 );
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