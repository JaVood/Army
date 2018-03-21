#include "../State/State.h"
#include "../Unit/Unit.h"
#include "../Unit/Rogue.h"
#include "../Unit/Soldier.h"
#include "../Unit/Berserker.h"
#include "../Unit/Vampire.h"
#include "catch.hpp"

TEST_CASE( "Test State class" ) {
    State* state = new State("State", 150,10, 100);

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
    Unit* unit = new Unit("Unit", 150, 10);

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
    Unit* unit = new Unit("Unit", 150, 10);

    REQUIRE( unit->getTitle() == "Unit" );
    REQUIRE( unit->getHitPoint() == 150 );
    REQUIRE( unit->getHitPointLimit() == 150 );
    REQUIRE( unit->getDamage() == 10 );
    
    SECTION( "Ability::attack tests" ) {
        Unit* enemy = new Unit("Enemy", 150, 10);
        
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

TEST_CASE( "Test Berserker class" ) {
    Berserker* berserker = new Berserker("Berserker");

    REQUIRE( berserker->getTitle() == "Berserker" );
    REQUIRE( berserker->getHitPoint() == 800 );
    REQUIRE( berserker->getHitPointLimit() == 800 );
    REQUIRE( berserker->getDamage() == 150 );
    
    SECTION( "Berserker::takeDamage tests" ) {
        int damage = 10;
        int iterations = berserker->getHitPoint() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            berserker->takeDamage(damage);
            int expectedHP = berserker->getHitPointLimit() - damage * i;
            REQUIRE( berserker->getHitPoint() == expectedHP );
        }

        try {
            berserker->takeDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( berserker->getHitPoint() == 0 );
        }

        try {
            berserker->addHitPoint(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( berserker->getHitPoint() == 0 );
        }
    }
    
    SECTION( "Berserker::takeMagicDamage tests" ) {
        
        berserker->takeMagicDamage(50);
        REQUIRE( berserker->getHitPoint() == 800 );
        berserker->takeMagicDamage(50);
        REQUIRE( berserker->getHitPoint() == 800 );
        berserker->takeMagicDamage(50);
        REQUIRE( berserker->getHitPoint() == 800 );
        berserker->takeMagicDamage(50);
        REQUIRE( berserker->getHitPoint() == 800 );
        berserker->takeMagicDamage(50);
        REQUIRE( berserker->getHitPoint() == 800 );
    }
    SECTION( "Berserker::addHitPoint tests" ) {
        berserker->takeDamage(50);
        REQUIRE( berserker->getHitPoint() == 750 );

        berserker->addHitPoint(40);
        REQUIRE( berserker->getHitPoint() == 790 );

        berserker->addHitPoint(10);
        REQUIRE( berserker->getHitPoint() == 800 );

        berserker->addHitPoint(10);
        REQUIRE( berserker->getHitPoint() == 800 );
    }
    
    SECTION( "Berserker::attack tests" ) {
        Soldier* enemy = new Soldier("Enemy");
        Rogue* enemyrogue = new Rogue("Enemyrogue");

        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getHitPoint() == 1000 );
        REQUIRE( enemy->getHitPointLimit() == 1000 );
        REQUIRE( enemy->getDamage() == 100 );
        REQUIRE( enemyrogue->getTitle() == "Enemyrogue" );
        REQUIRE( enemyrogue->getHitPoint() == 700 );
        REQUIRE( enemyrogue->getHitPointLimit() == 700 );
        REQUIRE( enemyrogue->getDamage() == 130 );

        berserker->attack(enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 150 );
        REQUIRE( berserker->getHitPoint() == 800 - 50 );

        berserker->attack(enemy);
        berserker->attack(enemy);
        berserker->attack(enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 150 - 150 - 150 - 150 );
        REQUIRE( berserker->getHitPoint() == 800 - 50 - 50 - 50 - 50 );
        
        berserker->addHitPoint(1000);

        enemyrogue->attack(berserker);

        REQUIRE( enemyrogue->getHitPoint() == 700 );
        REQUIRE( berserker->getHitPoint() == 800 - 130 );

        enemyrogue->attack(berserker);
        enemyrogue->attack(berserker);
        enemyrogue->attack(berserker);

        REQUIRE( enemyrogue->getHitPoint() == 700 );
        REQUIRE( berserker->getHitPoint() == 800 - 130 - 130 - 130 - 130 );
    }
    
    SECTION( "Berserker::counter attack tests" ) {
        Soldier* enemy = new Soldier("Enemy");

        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getHitPoint() == 1000 );
        REQUIRE( enemy->getHitPointLimit() == 1000 );
        REQUIRE( enemy->getDamage() == 100 );

        berserker->counterAttack(enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 75 );
        REQUIRE( berserker->getHitPoint() == 800 );

        berserker->attack(enemy);
        berserker->attack(enemy);
        berserker->attack(enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 75 - 150 - 150 - 150 );
        REQUIRE( berserker->getHitPoint() == 800 - 50 - 50 - 50 );

        berserker->takeDamage(6000);

        REQUIRE( berserker->getHitPoint() == 0 );
    }
}

TEST_CASE( "Test Vampire class" ) {
    Vampire* vampire = new Vampire("Dracula");

    REQUIRE( vampire->getTitle() == "Dracula" );
    REQUIRE( vampire->getHitPoint() == 1200 );
    REQUIRE( vampire->getHitPointLimit() == 1200 );
    REQUIRE( vampire->getDamage() == 80 );
    
    SECTION( "Vampire::takeDamage tests" ) {
        vampire->takeDamage(50);
        REQUIRE( vampire->getHitPoint() == 1200 - 50 );

        vampire->takeDamage(40);
        REQUIRE( vampire->getHitPoint() == 1200 - 40 - 50 );

        vampire->takeDamage(10);
        REQUIRE( vampire->getHitPoint() == 1200 - 40 - 10 - 50 );
        
        vampire->takeDamage(1200);
        REQUIRE( vampire->getHitPoint() == 0 );

    }
    
    SECTION( "Vampire::takeMagicDamage tests" ) {
        int damage = 10;
        int iterations = vampire->getHitPoint() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            vampire->takeMagicDamage(damage);
            int expectedHP = vampire->getHitPointLimit() - damage * i;
            REQUIRE( vampire->getHitPoint() == expectedHP );
        }

        try {
            vampire->takeMagicDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( vampire->getHitPoint() == 0 );
        }

        try {
            vampire->addHitPoint(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( vampire->getHitPoint() == 0 );
        }
    }
    SECTION( "Vampire::addHitPoint tests" ) {
        vampire->takeDamage(50);
        REQUIRE( vampire->getHitPoint() == 1150 );

        vampire->addHitPoint(40);
        REQUIRE( vampire->getHitPoint() == 1190 );

        vampire->addHitPoint(10);
        REQUIRE( vampire->getHitPoint() == 1200 );

        vampire->addHitPoint(10);
        REQUIRE( vampire->getHitPoint() == 1200 );
    }
    
    SECTION( "Vampire::attack tests" ) {
        Soldier* enemy = new Soldier("Enemy");

        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getHitPoint() == 1000 );
        REQUIRE( enemy->getHitPointLimit() == 1000 );
        REQUIRE( enemy->getDamage() == 100 );
        
        vampire->takeDamage(50);
        vampire->attack(enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 80 );
        REQUIRE( vampire->getHitPoint() == 1200 - 50 - 50 + 20 );

        vampire->attack(enemy);
        vampire->attack(enemy);
        vampire->attack(enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 80 - 80 - 80 - 80 );
        REQUIRE( vampire->getHitPoint() == 1200 - 50 - 50 + 20 - 50 + 20 - 50 + 20 - 50 + 20);
    }
    
    SECTION( "Vampire::counter attack tests" ) {
        Soldier* enemy = new Soldier("Enemy");

        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getHitPoint() == 1000 );
        REQUIRE( enemy->getHitPointLimit() == 1000 );
        REQUIRE( enemy->getDamage() == 100 );
        
        vampire->takeDamage(100);
        vampire->counterAttack(enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 40 );
        REQUIRE( vampire->getHitPoint() == 1200 - 100 + 20 );

        vampire->takeDamage(6000);

        REQUIRE( vampire->getHitPoint() == 0 );
    }
}