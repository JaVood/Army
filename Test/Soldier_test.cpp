#include "catch.hpp"
#include "../Unit/Soldier.h"

TEST_CASE( "Test Soldier class" ) {
    Soldier* soldier = new Soldier("Soldier");

    REQUIRE( soldier->getTitle() == "Soldier" );
    REQUIRE( soldier->getHitPoint() == 1000 );
    REQUIRE( soldier->getHitPointLimit() == 1000 );
    REQUIRE( soldier->getDamage() == 100 );
    
    SECTION( "Soldier::takeDamage tests" ) {
        int damage = 10;
        int iterations = soldier->getHitPoint() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            soldier->takeDamage(damage);
            int expectedHP = soldier->getHitPointLimit() - damage * i;
            REQUIRE( soldier->getHitPoint() == expectedHP );
        }

        try {
            soldier->takeDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( soldier->getHitPoint() == 0 );
        }

        try {
            soldier->addHitPoint(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( soldier->getHitPoint() == 0 );
        }
    }
    
    SECTION( "Soldier::takeMagicDamage tests" ) {
        int damage = 10;
        int iterations = soldier->getHitPoint() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            soldier->takeMagicDamage(damage);
            int expectedHP = soldier->getHitPointLimit() - damage * i;
            REQUIRE( soldier->getHitPoint() == expectedHP );
        }

        try {
            soldier->takeMagicDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( soldier->getHitPoint() == 0 );
        }

        try {
            soldier->addHitPoint(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( soldier->getHitPoint() == 0 );
        }
    }
    SECTION( "Soldier::addHitPoint tests" ) {
        soldier->takeDamage(50);
        REQUIRE( soldier->getHitPoint() == 950 );

        soldier->addHitPoint(40);
        REQUIRE( soldier->getHitPoint() == 990 );

        soldier->addHitPoint(10);
        REQUIRE( soldier->getHitPoint() == 1000 );

        soldier->addHitPoint(10);
        REQUIRE( soldier->getHitPoint() == 1000 );
    }
    
    SECTION( "Soldier::attack tests" ) {
        Soldier* enemy = new Soldier("Enemy");

        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getHitPoint() == 1000 );
        REQUIRE( enemy->getHitPointLimit() == 1000 );
        REQUIRE( enemy->getDamage() == 100 );

        soldier->attack(enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 100 );
        REQUIRE( soldier->getHitPoint() == 1000 - 50 );

        soldier->attack(enemy);
        soldier->attack(enemy);
        soldier->attack(enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 100 - 100 - 100 - 100 );
        REQUIRE( soldier->getHitPoint() == 1000 - 50 - 50 - 50 - 50 );

        enemy->takeDamage(60);

        REQUIRE( enemy->getHitPoint() == 1000 - 100 - 100 - 100 - 100 - 60 );

        try {
            soldier->attack(enemy);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( enemy->getHitPoint() == 0 );
            REQUIRE( soldier->getHitPoint() == 110 );
        }

        try {
            enemy->attack(soldier);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( enemy->getHitPoint() == 0 );
            REQUIRE( soldier->getHitPoint() == 110 );
        }
    }
    
    SECTION( "Soldier::counter attack tests" ) {
        Soldier* enemy = new Soldier("Enemy");

        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getHitPoint() == 1000 );
        REQUIRE( enemy->getHitPointLimit() == 1000 );
        REQUIRE( enemy->getDamage() == 100 );

        soldier->counterAttack(enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 50 );
        REQUIRE( soldier->getHitPoint() == 1000 );

        soldier->attack(enemy);
        soldier->attack(enemy);
        soldier->attack(enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 50 - 100 - 100 - 100 );
        REQUIRE( soldier->getHitPoint() == 1000 - 50 - 50 - 50 );

        enemy->takeDamage(6000);

        REQUIRE( enemy->getHitPoint() == 0 );
    }
}