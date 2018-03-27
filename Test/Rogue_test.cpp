#include "catch.hpp"
#include "../Unit/Rogue.h"
#include "../Unit/Soldier.h"

TEST_CASE( "Test Rogue class" ) {
    Rogue* rogue = new Rogue("Rogue");

    REQUIRE( rogue->getTitle() == "Rogue" );
    REQUIRE( rogue->getHitPoint() == 700 );
    REQUIRE( rogue->getHitPointLimit() == 700 );
    REQUIRE( rogue->getDamage() == 130 );
    
    SECTION( "Rogue::takeDamage tests" ) {
        int damage = 10;
        int iterations = rogue->getHitPoint() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            rogue->takeDamage(damage);
            int expectedHP = rogue->getHitPointLimit() - damage * i;
            REQUIRE( rogue->getHitPoint() == expectedHP );
        }

        try {
            rogue->takeDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( rogue->getHitPoint() == 0 );
        }

        try {
            rogue->addHitPoint(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( rogue->getHitPoint() == 0 );
        }
    }
    
    SECTION( "Rogue::takeMagicDamage tests" ) {
        int damage = 10;
        int iterations = rogue->getHitPoint() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            rogue->takeMagicDamage(damage);
            int expectedHP = rogue->getHitPointLimit() - damage * i;
            REQUIRE( rogue->getHitPoint() == expectedHP );
        }

        try {
            rogue->takeMagicDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( rogue->getHitPoint() == 0 );
        }

        try {
            rogue->addHitPoint(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( rogue->getHitPoint() == 0 );
        }
    }
    SECTION( "Rogue::addHitPoint tests" ) {
        rogue->takeDamage(50);
        REQUIRE( rogue->getHitPoint() == 650 );

        rogue->addHitPoint(40);
        REQUIRE( rogue->getHitPoint() == 690 );

        rogue->addHitPoint(10);
        REQUIRE( rogue->getHitPoint() == 700 );

        rogue->addHitPoint(10);
        REQUIRE( rogue->getHitPoint() == 700 );
    }
    
    SECTION( "Rogue::attack tests" ) {
        Soldier* enemy = new Soldier("Enemy");

        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getHitPoint() == 1000 );
        REQUIRE( enemy->getHitPointLimit() == 1000 );
        REQUIRE( enemy->getDamage() == 100 );

        rogue->attack(enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 130 );
        REQUIRE( rogue->getHitPoint() == 700 );

        rogue->attack(enemy);
        rogue->attack(enemy);
        rogue->attack(enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 130 - 130 - 130 - 130 );
        REQUIRE( rogue->getHitPoint() == 700 );
    }
    
    SECTION( "Rogue::counter attack tests" ) {
        Soldier* enemy = new Soldier("Enemy");

        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getHitPoint() == 1000 );
        REQUIRE( enemy->getHitPointLimit() == 1000 );
        REQUIRE( enemy->getDamage() == 100 );

        rogue->counterAttack(enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 65 );
        REQUIRE( rogue->getHitPoint() == 700 );

        rogue->attack(enemy);
        rogue->attack(enemy);
        rogue->attack(enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 65 - 130 - 130 - 130 );
        REQUIRE( rogue->getHitPoint() == 700 );

        rogue->takeDamage(6000);

        REQUIRE( rogue->getHitPoint() == 0 );
    }
}