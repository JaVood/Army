#include "../State/State.h"
#include "../Unit/Unit.h"
#include "../Unit/Rogue.h"
#include "../Unit/Soldier.h"
#include "../Unit/Berserker.h"
#include "../Unit/Vampire.h"
#include "../Unit/Werewolf.h"
#include "../Unit/Demon.h"
#include "../SpellCaster/SpellCaster.h"
#include "../SpellCaster/Wizard.h"
#include "../SpellCaster/Healer.h"
#include "../SpellCaster/Priest.h"
#include "../SpellCaster/Warlock.h"
#include "../SpellCaster/Necromancer.h"
#include "catch.hpp"

TEST_CASE( "Test State class" ) {
    State* state = new State("State", 150, 10, 100);

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
    
    SECTION( "State::takeMagicDamage tests" ) {
        state->takeMagicDamage(50);
        REQUIRE( state->getHitPoint() == 100 );

        state->takeMagicDamage(40);
        REQUIRE( state->getHitPoint() == 100-40 );

        state->takeMagicDamage(10);
        REQUIRE( state->getHitPoint() == 100-40-10 );

        state->takeMagicDamage(10);
        REQUIRE( state->getHitPoint() == 100-40-10-10 );
        
        state->takeMagicDamage(100);
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
    
        SECTION( "State::addMP tests" ) {
        state->addManaPoint(50);
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

        soldier->attack(soldier, enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 100 );
        REQUIRE( soldier->getHitPoint() == 1000 - 50 );

        soldier->attack(soldier, enemy);
        soldier->attack(soldier, enemy);
        soldier->attack(soldier, enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 100 - 100 - 100 - 100 );
        REQUIRE( soldier->getHitPoint() == 1000 - 50 - 50 - 50 - 50 );

        enemy->takeDamage(60);

        REQUIRE( enemy->getHitPoint() == 1000 - 100 - 100 - 100 - 100 - 60 );

        try {
            soldier->attack(soldier, enemy);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( enemy->getHitPoint() == 0 );
            REQUIRE( soldier->getHitPoint() == 110 );
        }

        try {
            enemy->attack(enemy, soldier);
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

        soldier->counterAttack(soldier, enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 50 );
        REQUIRE( soldier->getHitPoint() == 1000 );

        soldier->attack(soldier, enemy);
        soldier->attack(soldier, enemy);
        soldier->attack(soldier, enemy);

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

        rogue->attack(rogue, enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 130 );
        REQUIRE( rogue->getHitPoint() == 700 );

        rogue->attack(rogue, enemy);
        rogue->attack(rogue, enemy);
        rogue->attack(rogue, enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 130 - 130 - 130 - 130 );
        REQUIRE( rogue->getHitPoint() == 700 );
    }
    
    SECTION( "Rogue::counter attack tests" ) {
        Soldier* enemy = new Soldier("Enemy");

        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getHitPoint() == 1000 );
        REQUIRE( enemy->getHitPointLimit() == 1000 );
        REQUIRE( enemy->getDamage() == 100 );

        rogue->counterAttack(rogue, enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 65 );
        REQUIRE( rogue->getHitPoint() == 700 );

        rogue->attack(rogue, enemy);
        rogue->attack(rogue, enemy);
        rogue->attack(rogue, enemy);

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

        berserker->attack(berserker, enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 150 );
        REQUIRE( berserker->getHitPoint() == 800 - 50 );

        berserker->attack(berserker, enemy);
        berserker->attack(berserker, enemy);
        berserker->attack(berserker, enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 150 - 150 - 150 - 150 );
        REQUIRE( berserker->getHitPoint() == 800 - 50 - 50 - 50 - 50 );
        
        berserker->addHitPoint(1000);

        enemyrogue->attack(enemyrogue, berserker);

        REQUIRE( enemyrogue->getHitPoint() == 700 );
        REQUIRE( berserker->getHitPoint() == 800 - 130 );

        enemyrogue->attack(enemyrogue, berserker);
        enemyrogue->attack(enemyrogue, berserker);
        enemyrogue->attack(enemyrogue, berserker);

        REQUIRE( enemyrogue->getHitPoint() == 700 );
        REQUIRE( berserker->getHitPoint() == 800 - 130 - 130 - 130 - 130 );
    }
    
    SECTION( "Berserker::counter attack tests" ) {
        Soldier* enemy = new Soldier("Enemy");

        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getHitPoint() == 1000 );
        REQUIRE( enemy->getHitPointLimit() == 1000 );
        REQUIRE( enemy->getDamage() == 100 );

        berserker->counterAttack(berserker, enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 75 );
        REQUIRE( berserker->getHitPoint() == 800 );

        berserker->attack(berserker, enemy);
        berserker->attack(berserker, enemy);
        berserker->attack(berserker, enemy);

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

        REQUIRE( vampire->getIsVampire() == true );
        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getHitPoint() == 1000 );
        REQUIRE( enemy->getHitPointLimit() == 1000 );
        REQUIRE( enemy->getDamage() == 100 );
        
        vampire->takeDamage(50);
        vampire->attack(vampire, enemy);
        
        REQUIRE( enemy->getIsVampire() == true );
        REQUIRE( enemy->getHitPoint() == 1000 - 80 + 20);
        REQUIRE( vampire->getHitPoint() == 1200 - 50 - 50 + 20 );

        vampire->attack(vampire, enemy);
        vampire->attack(vampire, enemy);
        vampire->attack(vampire, enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 80 - 80 - 80);
        REQUIRE( vampire->getHitPoint() == 1200 - 50 - 50 + 20 - 50 + 20 - 50 + 20 - 50 + 20);
    }
    
    SECTION( "Vampire::counter attack tests" ) {
        Soldier* enemy = new Soldier("Enemy");

        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getHitPoint() == 1000 );
        REQUIRE( enemy->getHitPointLimit() == 1000 );
        REQUIRE( enemy->getDamage() == 100 );
        
        vampire->takeDamage(100);
        vampire->counterAttack(vampire, enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 40 );
        REQUIRE( vampire->getHitPoint() == 1200 - 100 + 20 );

        vampire->takeDamage(6000);

        REQUIRE( vampire->getHitPoint() == 0 );
    }
}

TEST_CASE( "Test Werewolf class" ) {
    Werewolf* werewolf = new Werewolf("Werewolf");

    REQUIRE( werewolf->getTitle() == "Werewolf" );
    REQUIRE( werewolf->getHitPoint() == 900 );
    REQUIRE( werewolf->getHitPointLimit() == 900 );
    REQUIRE( werewolf->getDamage() == 100 );
    
    SECTION( "Werewolf::takeDamage tests" ) {
        werewolf->takeDamage(50);
        REQUIRE( werewolf->getHitPoint() == 850 );

        werewolf->takeDamage(40);
        REQUIRE( werewolf->getHitPoint() == 810 );

        werewolf->takeDamage(10);
        REQUIRE( werewolf->getHitPoint() == 800 );

        werewolf->takeDamage(10);
        REQUIRE( werewolf->getHitPoint() == 790 );
        
        werewolf->takeDamage(1000);
        REQUIRE( werewolf->getHitPoint() == 0 );
    }
    
    SECTION( "Werewolf::addHP tests" ) {
        werewolf->takeDamage(50);
        REQUIRE( werewolf->getHitPoint() == 850 );

        werewolf->addHitPoint(40);
        REQUIRE( werewolf->getHitPoint() == 890 );

        werewolf->addHitPoint(10);
        REQUIRE( werewolf->getHitPoint() == 900 );

        werewolf->addHitPoint(10);
        REQUIRE( werewolf->getHitPoint() == 900 );
    }
    
    SECTION( "Werewolf::takeMagicDamage tests" ) {
        
        werewolf->takeMagicDamage(50);
        REQUIRE( werewolf->getHitPoint() == 900 - 50 );
        werewolf->takeMagicDamage(50);
        REQUIRE( werewolf->getHitPoint() == 900 - 50 - 50 );
        werewolf->takeMagicDamage(50);
        REQUIRE( werewolf->getHitPoint() == 900 - 50 - 50 - 50 );
        werewolf->takeMagicDamage(50);
        REQUIRE( werewolf->getHitPoint() == 900 - 50 - 50 - 100 );
        werewolf->takeMagicDamage(50);
        REQUIRE( werewolf->getHitPoint() == 900 - 50 - 50 - 150);
    }
    
    SECTION( "Werewolf::set tests" ) {
        
        werewolf->setName("Doggy");
        REQUIRE( werewolf->getTitle() == "Doggy" );
        werewolf->setDamage(50);
        REQUIRE( werewolf->getDamage() == 50 );
        werewolf->setHitPoint(50);
        REQUIRE( werewolf->getHitPoint() == 50 );
        REQUIRE( werewolf->getHitPointLimit() == 900);
        werewolf->setHitPointLimit(70);
        REQUIRE( werewolf->getHitPointLimit() == 70);
    }
    
    SECTION( "Werewolf::transform tests" ) {
        
        werewolf->transformInToWolf();
        REQUIRE( werewolf->getTitle() == "Wolf" );
        REQUIRE( werewolf->getHitPoint() == 900 );
        REQUIRE( werewolf->getHitPointLimit() == 1300 );
        REQUIRE( werewolf->getDamage() == 200 );
        
        werewolf->takeDamage(50);
        REQUIRE( werewolf->getHitPoint() == 850 );

        werewolf->takeDamage(40);
        REQUIRE( werewolf->getHitPoint() == 810 );

        werewolf->takeDamage(10);
        REQUIRE( werewolf->getHitPoint() == 800 );

        werewolf->takeDamage(10);
        REQUIRE( werewolf->getHitPoint() == 790 );
        
        werewolf->takeDamage(50);
        REQUIRE( werewolf->getHitPoint() == 740 );

        werewolf->addHitPoint(40);
        REQUIRE( werewolf->getHitPoint() == 780 );

        werewolf->addHitPoint(10);
        REQUIRE( werewolf->getHitPoint() == 790 );

        werewolf->addHitPoint(1000);
        REQUIRE( werewolf->getHitPoint() == 1300 );
        
        werewolf->takeMagicDamage(450);
        REQUIRE( werewolf->getHitPoint() == 900 - 50 );
        werewolf->takeMagicDamage(50);
        REQUIRE( werewolf->getHitPoint() == 900 - 50 - 50 );
        werewolf->takeMagicDamage(50);
        REQUIRE( werewolf->getHitPoint() == 900 - 50 - 50 - 50 );
        werewolf->takeMagicDamage(50);
        REQUIRE( werewolf->getHitPoint() == 900 - 50 - 50 - 100 );
        werewolf->takeMagicDamage(50);
        REQUIRE( werewolf->getHitPoint() == 900 - 50 - 50 - 150);
    }
    
    SECTION( "Werewolf::attack tests" ) {
        Soldier* enemy = new Soldier("Enemy");

        REQUIRE( werewolf->getIsWerewolf() == true );
        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getHitPoint() == 1000 );
        REQUIRE( enemy->getHitPointLimit() == 1000 );
        REQUIRE( enemy->getDamage() == 100 );
        
        werewolf->attack(werewolf, enemy);
        
        REQUIRE( enemy->getIsWerewolf() == true );
        REQUIRE( enemy->getHitPoint() == 1000 - 100);
        REQUIRE( werewolf->getHitPoint() == 900 - 50);

        enemy->transformInToWolf();
        REQUIRE( enemy->getTitle() == "Wolf" );
        REQUIRE( enemy->getHitPoint() == 900 );
        REQUIRE( enemy->getHitPointLimit() == 1300 );
        REQUIRE( enemy->getDamage() == 200 );
    }
    
}

TEST_CASE( "Test SpellCaster class" ) {
    SpellCaster* spellCaster = new SpellCaster("SpellCaster",1000, 100, 1000, false);

    REQUIRE( spellCaster->getTitle() == "SpellCaster" );
    REQUIRE( spellCaster->getHitPoint() == 1000 );
    REQUIRE( spellCaster->getHitPointLimit() == 1000 );
    REQUIRE( spellCaster->getDamage() == 100 );
    REQUIRE( spellCaster->getManaPoint() == 1000 );
    REQUIRE( spellCaster->getManaPointLimit() == 1000 );
    
    SECTION( "SpellCaster::takeDamage tests" ) {
        int damage = 10;
        int iterations = spellCaster->getHitPoint() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            spellCaster->takeDamage(damage);
            int expectedHP = spellCaster->getHitPointLimit() - damage * i;
            REQUIRE( spellCaster->getHitPoint() == expectedHP );
        }

        try {
            spellCaster->takeDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( spellCaster->getHitPoint() == 0 );
        }

        try {
            spellCaster->addHitPoint(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( spellCaster->getHitPoint() == 0 );
        }
    }
    
    SECTION( "SpellCaster::takeMagicDamage tests" ) {
        int damage = 10;
        int iterations = spellCaster->getHitPoint() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            spellCaster->takeMagicDamage(damage);
            int expectedHP = spellCaster->getHitPointLimit() - damage * i;
            REQUIRE( spellCaster->getHitPoint() == expectedHP );
        }

        try {
            spellCaster->takeMagicDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( spellCaster->getHitPoint() == 0 );
        }

        try {
            spellCaster->addHitPoint(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( spellCaster->getHitPoint() == 0 );
        }
    }
    SECTION( "SpellCaster::addHitPoint tests" ) {
        spellCaster->takeDamage(50);
        REQUIRE( spellCaster->getHitPoint() == 950 );

        spellCaster->addHitPoint(40);
        REQUIRE( spellCaster->getHitPoint() == 990 );

        spellCaster->addHitPoint(10);
        REQUIRE( spellCaster->getHitPoint() == 1000 );

        spellCaster->addHitPoint(10);
        REQUIRE( spellCaster->getHitPoint() == 1000 );
    }
    
    SECTION( "SpellCaster::attack tests" ) {
        Soldier* enemy = new Soldier("Enemy");

        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getHitPoint() == 1000 );
        REQUIRE( enemy->getHitPointLimit() == 1000 );
        REQUIRE( enemy->getDamage() == 100 );

        spellCaster->attack(spellCaster, enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 100 );
        REQUIRE( spellCaster->getHitPoint() == 1000 - 50 );

        spellCaster->attack(spellCaster, enemy);
        spellCaster->attack(spellCaster, enemy);
        spellCaster->attack(spellCaster, enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 100 - 100 - 100 - 100 );
        REQUIRE( spellCaster->getHitPoint() == 1000 - 50 - 50 - 50 - 50 );

        enemy->takeDamage(60);

        REQUIRE( enemy->getHitPoint() == 1000 - 100 - 100 - 100 - 100 - 60 );

        try {
            spellCaster->attack(spellCaster, enemy);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( enemy->getHitPoint() == 0 );
            REQUIRE( spellCaster->getHitPoint() == 110 );
        }

        try {
            enemy->attack(spellCaster, spellCaster);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( enemy->getHitPoint() == 0 );
            REQUIRE( spellCaster->getHitPoint() == 110 );
        }
    }
    
    SECTION( "SpellCaster::counter attack tests" ) {
        Soldier* enemy = new Soldier("Enemy");

        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getHitPoint() == 1000 );
        REQUIRE( enemy->getHitPointLimit() == 1000 );
        REQUIRE( enemy->getDamage() == 100 );

        spellCaster->counterAttack(spellCaster, enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 50 );
        REQUIRE( spellCaster->getHitPoint() == 1000 );

        spellCaster->attack(spellCaster, enemy);
        spellCaster->attack(spellCaster, enemy);
        spellCaster->attack(spellCaster, enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 50 - 100 - 100 - 100 );
        REQUIRE( spellCaster->getHitPoint() == 1000 - 50 - 50 - 50 );

        enemy->takeDamage(6000);

        REQUIRE( enemy->getHitPoint() == 0 );
    }
    
    SECTION( "SpellCaster::spend mana tests" ) {
        spellCaster->spendMana(50);
        REQUIRE( spellCaster->getManaPoint() == 1000 - 50 );
        REQUIRE( spellCaster->getHitPoint() == 1000 );

        spellCaster->spendMana(50);
        spellCaster->spendMana(50);
        spellCaster->spendMana(50);

        REQUIRE( spellCaster->getManaPoint() == 1000 - 50 - 50 - 100 );
    }
    
    SECTION( "SpellCaster::add mana tests" ) {
        spellCaster->spendMana(500);
        REQUIRE( spellCaster->getManaPoint() == 1000 - 500 );
        spellCaster->addManaPoint(50);
        REQUIRE( spellCaster->getManaPoint() == 550 );
    }
    
    SECTION( "SpellCaster::spell tests" ) {
        Soldier* enemy = new Soldier("Enemy");
        
        spellCaster->castSpell(enemy, VORTEX);
        REQUIRE( spellCaster->getManaPoint() == 1000 - 50);
        REQUIRE( enemy->getHitPoint() == 1000 - 100);
        spellCaster->castSpell(enemy, BATTLEHEAL);
        REQUIRE( spellCaster->getManaPoint() == 1000 - 80);
        REQUIRE( enemy->getHitPoint() == 1000);
    }
}

TEST_CASE( "Wizard class" ) {
    Wizard* wizard = new Wizard("Wizard");

    REQUIRE( wizard->getTitle() == "Wizard" );
    REQUIRE( wizard->getHitPoint() == 600 );
    REQUIRE( wizard->getHitPointLimit() == 600 );
    REQUIRE( wizard->getDamage() == 50 );
    REQUIRE( wizard->getManaPoint() == 500 );
    REQUIRE( wizard->getManaPointLimit() == 500 );
    
    SECTION( "Wizard::takeDamage tests" ) {
        int damage = 10;
        int iterations = wizard->getHitPoint() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            wizard->takeDamage(damage);
            int expectedHP = wizard->getHitPointLimit() - damage * i;
            REQUIRE( wizard->getHitPoint() == expectedHP );
        }

        try {
            wizard->takeDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( wizard->getHitPoint() == 0 );
        }

        try {
            wizard->addHitPoint(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( wizard->getHitPoint() == 0 );
        }
    }
    
    SECTION( "Wizard::takeMagicDamage tests" ) {
        int damage = 10;
        int iterations = wizard->getHitPoint() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            wizard->takeMagicDamage(damage);
            int expectedHP = wizard->getHitPointLimit() - damage * i;
            REQUIRE( wizard->getHitPoint() == expectedHP );
        }

        try {
            wizard->takeMagicDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( wizard->getHitPoint() == 0 );
        }

        try {
            wizard->addHitPoint(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( wizard->getHitPoint() == 0 );
        }
    }
    SECTION( "Wizard::addHitPoint tests" ) {
        wizard->takeDamage(50);
        REQUIRE( wizard->getHitPoint() == 550 );

        wizard->addHitPoint(40);
        REQUIRE( wizard->getHitPoint() == 590 );

        wizard->addHitPoint(10);
        REQUIRE( wizard->getHitPoint() == 600 );

        wizard->addHitPoint(10);
        REQUIRE( wizard->getHitPoint() == 600 );
    }
    
    SECTION( "Wizard::attack tests" ) {
        Soldier* enemy = new Soldier("Enemy");

        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getHitPoint() == 1000 );
        REQUIRE( enemy->getHitPointLimit() == 1000 );
        REQUIRE( enemy->getDamage() == 100 );

        wizard->attack(wizard, enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 50 );
        REQUIRE( wizard->getHitPoint() == 600 - 50 );

        wizard->attack(wizard, enemy);
        wizard->attack(wizard, enemy);
        wizard->attack(wizard, enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 50 - 50 - 50 - 50 );
        REQUIRE( wizard->getHitPoint() == 600 - 50 - 50 - 50 - 50 );

        try {
            wizard->attack(wizard, enemy);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( enemy->getHitPoint() == 0 );
            REQUIRE( wizard->getHitPoint() == 110 );
        }

        try {
            enemy->attack(enemy, wizard);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( enemy->getHitPoint() == 0 );
            REQUIRE( wizard->getHitPoint() == 110 );
        }
    }
    
    SECTION( "Wizard::counter attack tests" ) {
        Soldier* enemy = new Soldier("Enemy");

        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getHitPoint() == 1000 );
        REQUIRE( enemy->getHitPointLimit() == 1000 );
        REQUIRE( enemy->getDamage() == 100 );

        wizard->counterAttack(wizard, enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 25 );
        REQUIRE( wizard->getHitPoint() == 600 );

        wizard->attack(wizard, enemy);
        wizard->attack(wizard, enemy);
        wizard->attack(wizard, enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 25 - 50 - 50 - 50 );
        REQUIRE( wizard->getHitPoint() == 600 - 50 - 50 - 50 );

        wizard->takeDamage(6000);

        REQUIRE( wizard->getHitPoint() == 0 );
    }
    
    SECTION( "Wizard::spend mana tests" ) {
        wizard->spendMana(50);
        REQUIRE( wizard->getManaPoint() == 500 - 50 );

        wizard->spendMana(50);
        wizard->spendMana(50);
        wizard->spendMana(50);

        REQUIRE( wizard->getManaPoint() == 500 - 50 - 50 - 100 );
    }
    
    SECTION( "Wizard::add mana tests" ) {
        wizard->spendMana(200);
        REQUIRE( wizard->getManaPoint() == 500 - 200 );
        wizard->addManaPoint(50);
        REQUIRE( wizard->getManaPoint() == 350 );
        wizard->addManaPoint(500);
        REQUIRE( wizard->getManaPoint() == 500 );
    }

    SECTION( "Wizard::heal tests" ) {
        Soldier* dude = new Soldier("Dude");
        
        dude->takeDamage(200);
        REQUIRE( dude->getHitPoint() == 1000 - 200 );
        wizard->castSpell(dude, BATTLEHEAL);
        REQUIRE( dude->getHitPoint() == 1000 - 200 + 50);
        REQUIRE( wizard->getManaPoint() == 500 - 30 );
        wizard->castSpell(dude, BATTLEHEAL);
        wizard->castSpell(dude, BATTLEHEAL);
        wizard->castSpell(dude, BATTLEHEAL);
        wizard->castSpell(dude, BATTLEHEAL);
        REQUIRE( dude->getHitPoint() == 1000);
        REQUIRE( wizard->getManaPoint() == 500 - 30 - 60 - 60);
        dude->takeDamage(100);
        wizard->spendMana(480);
        wizard->castSpell(dude, BATTLEHEAL);
        REQUIRE( dude->getHitPoint() == 900);
   }
    
    SECTION( "Wizard::magic damage tests" ) {
        Soldier* enemy = new Soldier("Enemy");
        
        wizard->castSpell(enemy, VORTEX);
        REQUIRE( enemy->getHitPoint() == 1000 - 200);
        REQUIRE( wizard->getManaPoint() == 500 - 50 );
        wizard->castSpell(enemy, VORTEX);
        wizard->castSpell(enemy, VORTEX);
        wizard->castSpell(enemy, VORTEX);
        wizard->castSpell(enemy, VORTEX);
        REQUIRE( enemy->getHitPoint() == 0);
        REQUIRE( wizard->getManaPoint() == 500 - 50 - 100 - 100);
        wizard->addHitPoint(100);
        REQUIRE( wizard->getHitPoint() == 600);
    }
}

TEST_CASE( "Healer class" ) {
    Healer* healer = new Healer("Healer");

    REQUIRE( healer->getTitle() == "Healer" );
    REQUIRE( healer->getHitPoint() == 600 );
    REQUIRE( healer->getHitPointLimit() == 600 );
    REQUIRE( healer->getDamage() == 30 );
    REQUIRE( healer->getManaPoint() == 500 );
    REQUIRE( healer->getManaPointLimit() == 500 );
    
    SECTION( "Healer::takeDamage tests" ) {
        int damage = 10;
        int iterations = healer->getHitPoint() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            healer->takeDamage(damage);
            int expectedHP = healer->getHitPointLimit() - damage * i;
            REQUIRE( healer->getHitPoint() == expectedHP );
        }

        try {
            healer->takeDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( healer->getHitPoint() == 0 );
        }

        try {
            healer->addHitPoint(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( healer->getHitPoint() == 0 );
        }
    }
    
    SECTION( "Healer::takeMagicDamage tests" ) {
        int damage = 10;
        int iterations = healer->getHitPoint() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            healer->takeMagicDamage(damage);
            int expectedHP = healer->getHitPointLimit() - damage * i;
            REQUIRE( healer->getHitPoint() == expectedHP );
        }

        try {
            healer->takeMagicDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( healer->getHitPoint() == 0 );
        }

        try {
            healer->addHitPoint(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( healer->getHitPoint() == 0 );
        }
    }
    SECTION( "Healer::addHitPoint tests" ) {
        healer->takeDamage(50);
        REQUIRE( healer->getHitPoint() == 550 );

        healer->addHitPoint(40);
        REQUIRE( healer->getHitPoint() == 590 );

        healer->addHitPoint(10);
        REQUIRE( healer->getHitPoint() == 600 );

        healer->addHitPoint(10);
        REQUIRE( healer->getHitPoint() == 600 );
    }
    
    SECTION( "Healer::attack tests" ) {
        Soldier* enemy = new Soldier("Enemy");

        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getHitPoint() == 1000 );
        REQUIRE( enemy->getHitPointLimit() == 1000 );
        REQUIRE( enemy->getDamage() == 100 );

        healer->attack(healer, enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 30 );
        REQUIRE( healer->getHitPoint() == 600 - 50 );

        healer->attack(healer, enemy);
        healer->attack(healer, enemy);
        healer->attack(healer, enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 30 - 30 - 30 - 30 );
        REQUIRE( healer->getHitPoint() == 600 - 50 - 50 - 50 - 50 );
    }
    
    SECTION( "Healer::counter attack tests" ) {
        Soldier* enemy = new Soldier("Enemy");

        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getHitPoint() == 1000 );
        REQUIRE( enemy->getHitPointLimit() == 1000 );
        REQUIRE( enemy->getDamage() == 100 );

        healer->counterAttack(healer, enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 15 );
        REQUIRE( healer->getHitPoint() == 600 );

        healer->attack(healer, enemy);
        healer->attack(healer, enemy);
        healer->attack(healer, enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 15 - 30 - 30 - 30 );
        REQUIRE( healer->getHitPoint() == 600 - 50 - 50 - 50 );

        healer->takeDamage(6000);

        REQUIRE( healer->getHitPoint() == 0 );
    }
    
    SECTION( "Healer::spend mana tests" ) {
        healer->spendMana(50);
        REQUIRE( healer->getManaPoint() == 500 - 50 );

        healer->spendMana(50);
        healer->spendMana(50);
        healer->spendMana(50);

        REQUIRE( healer->getManaPoint() == 500 - 50 - 50 - 100 );
    }
    
    SECTION( "Healer::add mana tests" ) {
        healer->spendMana(200);
        REQUIRE( healer->getManaPoint() == 500 - 200 );
        healer->addManaPoint(50);
        REQUIRE( healer->getManaPoint() == 350 );
        healer->addManaPoint(500);
        REQUIRE( healer->getManaPoint() == 500 );
    }

    SECTION( "Healer::heal tests" ) {
        Soldier* dude = new Soldier("Dude");
        
        dude->takeDamage(200);
        REQUIRE( dude->getHitPoint() == 1000 - 200 );
        healer->castSpell(dude, BATTLEHEAL);
        REQUIRE( dude->getHitPoint() == 1000 - 200 + 100);
        REQUIRE( healer->getManaPoint() == 500 - 30 );
        healer->castSpell(dude, BATTLEHEAL);
        healer->castSpell(dude, BATTLEHEAL);
        REQUIRE( dude->getHitPoint() == 1000);
        REQUIRE( healer->getManaPoint() == 500 - 30 - 60);
        dude->takeDamage(100);
        healer->spendMana(480);
        healer->castSpell(dude, BATTLEHEAL);
        REQUIRE( dude->getHitPoint() == 900);
   }
    
    SECTION( "Healer::magic damage tests" ) {
        Soldier* enemy = new Soldier("Enemy");
        
        healer->castSpell(enemy, VORTEX);
        REQUIRE( enemy->getHitPoint() == 1000 - 100);
        REQUIRE( healer->getManaPoint() == 500 - 50 );
        healer->castSpell(enemy, VORTEX);
        healer->castSpell(enemy, VORTEX);
        healer->castSpell(enemy, VORTEX);
        healer->castSpell(enemy, VORTEX);
        REQUIRE( enemy->getHitPoint() == 500);
        REQUIRE( healer->getManaPoint() == 500 - 50 - 100 - 100);
        healer->addHitPoint(100);
        REQUIRE( healer->getHitPoint() == 600);
    }
}

TEST_CASE( "Priest class" ) {
    Priest* priest = new Priest("Priest");

    REQUIRE( priest->getTitle() == "Priest" );
    REQUIRE( priest->getHitPoint() == 700 );
    REQUIRE( priest->getHitPointLimit() == 700 );
    REQUIRE( priest->getDamage() == 40 );
    REQUIRE( priest->getManaPoint() == 500 );
    REQUIRE( priest->getManaPointLimit() == 500 );
    
    SECTION( "Priest::takeDamage tests" ) {
        int damage = 10;
        int iterations = priest->getHitPoint() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            priest->takeDamage(damage);
            int expectedHP = priest->getHitPointLimit() - damage * i;
            REQUIRE( priest->getHitPoint() == expectedHP );
        }

        try {
            priest->takeDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( priest->getHitPoint() == 0 );
        }

        try {
            priest->addHitPoint(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( priest->getHitPoint() == 0 );
        }
    }
    
    SECTION( "Priest::takeMagicDamage tests" ) {
        int damage = 10;
        int iterations = priest->getHitPoint() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            priest->takeMagicDamage(damage);
            int expectedHP = priest->getHitPointLimit() - damage * i;
            REQUIRE( priest->getHitPoint() == expectedHP );
        }

        try {
            priest->takeMagicDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( priest->getHitPoint() == 0 );
        }

        try {
            priest->addHitPoint(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( priest->getHitPoint() == 0 );
        }
    }
    SECTION( "Priest::addHitPoint tests" ) {
        priest->takeDamage(50);
        REQUIRE( priest->getHitPoint() == 650 );

        priest->addHitPoint(40);
        REQUIRE( priest->getHitPoint() == 690 );

        priest->addHitPoint(10);
        REQUIRE( priest->getHitPoint() == 700 );

        priest->addHitPoint(10);
        REQUIRE( priest->getHitPoint() == 700 );
    }
    
    SECTION( "Priest::attack tests" ) {
        Soldier* enemy = new Soldier("Enemy");

        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getHitPoint() == 1000 );
        REQUIRE( enemy->getHitPointLimit() == 1000 );
        REQUIRE( enemy->getDamage() == 100 );

        priest->attack(priest, enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 40 );
        REQUIRE( priest->getHitPoint() == 700 - 50 );

        priest->attack(priest, enemy);
        priest->attack(priest, enemy);
        priest->attack(priest, enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 40 - 40 - 40 - 40 );
        REQUIRE( priest->getHitPoint() == 700 - 50 - 50 - 50 - 50 );

        try {
            priest->attack(priest, enemy);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( enemy->getHitPoint() == 0 );
            REQUIRE( priest->getHitPoint() == 110 );
        }

        try {
            enemy->attack(enemy, priest);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( enemy->getHitPoint() == 0 );
            REQUIRE( priest->getHitPoint() == 110 );
        }
    }
    
    SECTION( "Priest::counter attack tests" ) {
        Soldier* enemy = new Soldier("Enemy");

        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getHitPoint() == 1000 );
        REQUIRE( enemy->getHitPointLimit() == 1000 );
        REQUIRE( enemy->getDamage() == 100 );

        priest->counterAttack(priest, enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 20 );
        REQUIRE( priest->getHitPoint() == 700 );

        priest->attack(priest, enemy);
        priest->attack(priest, enemy);
        priest->attack(priest, enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 20 - 40 - 40 - 40 );
        REQUIRE( priest->getHitPoint() == 700 - 50 - 50 - 50 );

        priest->takeDamage(6000);

        REQUIRE( priest->getHitPoint() == 0 );
    }
    
    SECTION( "Priest::spend mana tests" ) {
        priest->spendMana(50);
        REQUIRE( priest->getManaPoint() == 500 - 50 );

        priest->spendMana(50);
        priest->spendMana(50);
        priest->spendMana(50);

        REQUIRE( priest->getManaPoint() == 500 - 50 - 50 - 100 );
    }
    
    SECTION( "Priest::add mana tests" ) {
        priest->spendMana(200);
        REQUIRE( priest->getManaPoint() == 500 - 200 );
        priest->addManaPoint(50);
        REQUIRE( priest->getManaPoint() == 350 );
        priest->addManaPoint(500);
        REQUIRE( priest->getManaPoint() == 500 );
    }

    SECTION( "Priest::heal tests" ) {
        Soldier* dude = new Soldier("Dude");
        
        dude->takeDamage(200);
        REQUIRE( dude->getHitPoint() == 1000 - 200 );
        priest->castSpell(dude, BATTLEHEAL);
        REQUIRE( dude->getHitPoint() == 1000 - 200 + 100);
        REQUIRE( priest->getManaPoint() == 500 - 30 );
        priest->castSpell(dude, BATTLEHEAL);
        priest->castSpell(dude, BATTLEHEAL);
        REQUIRE( dude->getHitPoint() == 1000);
        REQUIRE( priest->getManaPoint() == 500 - 30 - 60);
        dude->takeDamage(100);
        priest->spendMana(480);
        priest->castSpell(dude, BATTLEHEAL);
        REQUIRE( dude->getHitPoint() == 900);
   }
    
    SECTION( "Priest::magic damage tests" ) {
        Soldier* enemy = new Soldier("Enemy");
        
        priest->castSpell(enemy, VORTEX);
        REQUIRE( enemy->getHitPoint() == 1000 - 100);
        REQUIRE( priest->getManaPoint() == 500 - 50 );
        priest->castSpell(enemy, VORTEX);
        priest->castSpell(enemy, VORTEX);
        priest->castSpell(enemy, VORTEX);
        priest->castSpell(enemy, VORTEX);
        REQUIRE( enemy->getHitPoint() == 500);
        REQUIRE( priest->getManaPoint() == 500 - 50 - 100 - 100);
        priest->addHitPoint(100);
        REQUIRE( priest->getHitPoint() == 700);
    }
    
    SECTION( "Priest::attack tests" ) {
        Vampire* enemy = new Vampire("Dracula");

        REQUIRE( enemy->getTitle() == "Dracula" );
        REQUIRE( enemy->getHitPoint() == 1200 );
        REQUIRE( enemy->getHitPointLimit() == 1200 );
        REQUIRE( enemy->getDamage() == 80 );

        priest->attack(priest, enemy);
        REQUIRE( priest->getIsVampire() == true );

        REQUIRE( enemy->getHitPoint() == 1200 - 80 + 20 );
        REQUIRE( priest->getHitPoint() == 700 - 40 );

        priest->attack(priest, enemy);
        priest->attack(priest, enemy);
        priest->attack(priest, enemy);

        REQUIRE( enemy->getHitPoint() == 1200 - 80 - 80 - 80 - 80 + 80);
        REQUIRE( priest->getHitPoint() == 700 - 40 - 40 - 40 - 40 + 60);
    }
    
    SECTION( "Priest::counter attack tests" ) {
        Vampire* enemy = new Vampire("Dracula");

        REQUIRE( enemy->getTitle() == "Dracula" );
        REQUIRE( enemy->getHitPoint() == 1200 );
        REQUIRE( enemy->getHitPointLimit() == 1200 );
        REQUIRE( enemy->getDamage() == 80 );

        priest->counterAttack(priest, enemy);

        REQUIRE( enemy->getHitPoint() == 1200 - 40 );
        REQUIRE( priest->getHitPoint() == 700 );

        priest->attack(priest, enemy);
        priest->attack(priest, enemy);
        priest->attack(priest, enemy);

        REQUIRE( enemy->getHitPoint() == 1200 - 40 - 80 - 80 - 80 + 60);
        REQUIRE( priest->getHitPoint() == 700 - 40 - 40 - 40 + 40);
    }
    
    SECTION( "Priest::damage undead tests" ) {
        Vampire* enemy = new Vampire("Enemy");
        
        priest->castSpell(enemy, VORTEX);
        REQUIRE( enemy->getHitPoint() == 1200 - 200);
        REQUIRE( priest->getManaPoint() == 500 - 50 );
        priest->castSpell(enemy, VORTEX);
        priest->castSpell(enemy, VORTEX);
        priest->castSpell(enemy, VORTEX);
        priest->castSpell(enemy, VORTEX);
        REQUIRE( enemy->getHitPoint() == 200);
        priest->castSpell(enemy, VORTEX);
        REQUIRE( priest->getManaPoint() == 500 - 50 - 100 - 100 - 50);
    }
}

TEST_CASE( "Warlock class" ) {
    Warlock* warlock = new Warlock("Warlock");

    REQUIRE( warlock->getTitle() == "Warlock" );
    REQUIRE( warlock->getHitPoint() == 600 );
    REQUIRE( warlock->getHitPointLimit() == 600 );
    REQUIRE( warlock->getDamage() == 30 );
    REQUIRE( warlock->getManaPoint() == 500 );
    REQUIRE( warlock->getManaPointLimit() == 500 );
    
    SECTION( "Warlock::takeDamage tests" ) {
        int damage = 10;
        int iterations = warlock->getHitPoint() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            warlock->takeDamage(damage);
            int expectedHP = warlock->getHitPointLimit() - damage * i;
            REQUIRE( warlock->getHitPoint() == expectedHP );
        }

        try {
            warlock->takeDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( warlock->getHitPoint() == 0 );
        }

        try {
            warlock->addHitPoint(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( warlock->getHitPoint() == 0 );
        }
    }
    
    SECTION( "Warlock::takeMagicDamage tests" ) {
        int damage = 10;
        int iterations = warlock->getHitPoint() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            warlock->takeMagicDamage(damage);
            int expectedHP = warlock->getHitPointLimit() - damage * i;
            REQUIRE( warlock->getHitPoint() == expectedHP );
        }

        try {
            warlock->takeMagicDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( warlock->getHitPoint() == 0 );
        }

        try {
            warlock->addHitPoint(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( warlock->getHitPoint() == 0 );
        }
    }
    SECTION( "Warlock::addHitPoint tests" ) {
        warlock->takeDamage(50);
        REQUIRE( warlock->getHitPoint() == 550 );

        warlock->addHitPoint(40);
        REQUIRE( warlock->getHitPoint() == 590 );

        warlock->addHitPoint(10);
        REQUIRE( warlock->getHitPoint() == 600 );

        warlock->addHitPoint(10);
        REQUIRE( warlock->getHitPoint() == 600 );
    }
    
    SECTION( "Warlock::attack tests" ) {
        Soldier* enemy = new Soldier("Enemy");

        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getHitPoint() == 1000 );
        REQUIRE( enemy->getHitPointLimit() == 1000 );
        REQUIRE( enemy->getDamage() == 100 );

        warlock->attack(warlock, enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 30 );
        REQUIRE( warlock->getHitPoint() == 600 - 50 );

        warlock->attack(warlock, enemy);
        warlock->attack(warlock, enemy);
        warlock->attack(warlock, enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 30 - 30 - 30 - 30 );
        REQUIRE( warlock->getHitPoint() == 600 - 50 - 50 - 50 - 50 );

        try {
            warlock->attack(warlock, enemy);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( enemy->getHitPoint() == 0 );
            REQUIRE( warlock->getHitPoint() == 110 );
        }

        try {
            enemy->attack(enemy, warlock);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( enemy->getHitPoint() == 0 );
            REQUIRE( warlock->getHitPoint() == 110 );
        }
    }
    
    SECTION( "Warlock::counter attack tests" ) {
        Soldier* enemy = new Soldier("Enemy");

        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getHitPoint() == 1000 );
        REQUIRE( enemy->getHitPointLimit() == 1000 );
        REQUIRE( enemy->getDamage() == 100 );

        warlock->counterAttack(warlock, enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 15 );
        REQUIRE( warlock->getHitPoint() == 600 );

        warlock->attack(warlock, enemy);
        warlock->attack(warlock, enemy);
        warlock->attack(warlock, enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 15 - 30 - 30 - 30 );
        REQUIRE( warlock->getHitPoint() == 600 - 50 - 50 - 50 );

        warlock->takeDamage(6000);

        REQUIRE( warlock->getHitPoint() == 0 );
    }
    
    SECTION( "Warlock::spend mana tests" ) {
        warlock->spendMana(50);
        REQUIRE( warlock->getManaPoint() == 500 - 50 );

        warlock->spendMana(50);
        warlock->spendMana(50);
        warlock->spendMana(50);

        REQUIRE( warlock->getManaPoint() == 500 - 50 - 50 - 100 );
    }
    
    SECTION( "Warlock::add mana tests" ) {
        warlock->spendMana(200);
        REQUIRE( warlock->getManaPoint() == 500 - 200 );
        warlock->addManaPoint(50);
        REQUIRE( warlock->getManaPoint() == 350 );
        warlock->addManaPoint(500);
        REQUIRE( warlock->getManaPoint() == 500 );
    }

    SECTION( "Warlock::heal tests" ) {
        Soldier* dude = new Soldier("Dude");
        
        dude->takeDamage(200);
        REQUIRE( dude->getHitPoint() == 1000 - 200 );
        warlock->castSpell(dude, BATTLEHEAL);
        REQUIRE( dude->getHitPoint() == 1000 - 200 + 50);
        REQUIRE( warlock->getManaPoint() == 500 - 30 );
        warlock->castSpell(dude, BATTLEHEAL);
        warlock->castSpell(dude, BATTLEHEAL);
        warlock->castSpell(dude, BATTLEHEAL);
        warlock->castSpell(dude, BATTLEHEAL);
        REQUIRE( dude->getHitPoint() == 1000);
        REQUIRE( warlock->getManaPoint() == 500 - 30 - 60 - 60);
        dude->takeDamage(100);
        warlock->spendMana(480);
        warlock->castSpell(dude, BATTLEHEAL);
        REQUIRE( dude->getHitPoint() == 900);
   }
    
    SECTION( "Warlock::magic damage tests" ) {
        Soldier* enemy = new Soldier("Enemy");
        
        warlock->castSpell(enemy, VORTEX);
        REQUIRE( enemy->getHitPoint() == 1000 - 200);
        REQUIRE( warlock->getManaPoint() == 500 - 50 );
        warlock->castSpell(enemy, VORTEX);
        warlock->castSpell(enemy, VORTEX);
        warlock->castSpell(enemy, VORTEX);
        warlock->castSpell(enemy, VORTEX);
        REQUIRE( enemy->getHitPoint() == 0);
        REQUIRE( warlock->getManaPoint() == 500 - 50 - 100 - 100);
        warlock->addHitPoint(100);
        REQUIRE( warlock->getHitPoint() == 600);
    }
    
    SECTION( "Warlock::demon damage tests" ) {
        Demon* demon = warlock->summonDemon();
        
        REQUIRE( demon->getTitle() == "Demon" );
        REQUIRE( demon->getHitPoint() == 900 );
        REQUIRE( demon->getHitPointLimit() == 900 );
        REQUIRE( demon->getDamage() == 150 );
        
        Soldier* enemy = new Soldier("Enemy");

        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getHitPoint() == 1000 );
        REQUIRE( enemy->getHitPointLimit() == 1000 );
        REQUIRE( enemy->getDamage() == 100 );

        demon->attack(demon, enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 150 );
        REQUIRE( demon->getHitPoint() == 900 - 50 );

        demon->attack(demon, enemy);
        demon->attack(demon, enemy);
        demon->attack(demon, enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 150 - 150 - 150 - 150 );
        REQUIRE( demon->getHitPoint() == 900 - 50 - 50 - 50 - 50 );
    }
}

TEST_CASE( "Necromancer class" ) {
    Necromancer* necromancer = new Necromancer("Necromancer");

    REQUIRE( necromancer->getTitle() == "Necromancer" );
    REQUIRE( necromancer->getHitPoint() == 600 );
    REQUIRE( necromancer->getHitPointLimit() == 600 );
    REQUIRE( necromancer->getDamage() == 50 );
    REQUIRE( necromancer->getManaPoint() == 500 );
    REQUIRE( necromancer->getManaPointLimit() == 500 );
    
    SECTION( "Necromancer::takeDamage tests" ) {
        int damage = 10;
        int iterations = necromancer->getHitPoint() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            necromancer->takeDamage(damage);
            int expectedHP = necromancer->getHitPointLimit() - damage * i;
            REQUIRE( necromancer->getHitPoint() == expectedHP );
        }

        try {
            necromancer->takeDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( necromancer->getHitPoint() == 0 );
        }

        try {
            necromancer->addHitPoint(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( necromancer->getHitPoint() == 0 );
        }
    }
    
    SECTION( "Necromancer::takeMagicDamage tests" ) {
        int damage = 10;
        int iterations = necromancer->getHitPoint() / damage;

        for ( int i = 1; i <= iterations; i++ ) {
            necromancer->takeMagicDamage(damage);
            int expectedHP = necromancer->getHitPointLimit() - damage * i;
            REQUIRE( necromancer->getHitPoint() == expectedHP );
        }

        try {
            necromancer->takeMagicDamage(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( necromancer->getHitPoint() == 0 );
        }

        try {
            necromancer->addHitPoint(damage);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( necromancer->getHitPoint() == 0 );
        }
    }
    SECTION( "Necromancer::addHitPoint tests" ) {
        necromancer->takeDamage(50);
        REQUIRE( necromancer->getHitPoint() == 550 );

        necromancer->addHitPoint(40);
        REQUIRE( necromancer->getHitPoint() == 590 );

        necromancer->addHitPoint(10);
        REQUIRE( necromancer->getHitPoint() == 600 );

        necromancer->addHitPoint(10);
        REQUIRE( necromancer->getHitPoint() == 600 );
    }
    
    SECTION( "Necromancer::attack tests" ) {
        Soldier* enemy = new Soldier("Enemy");

        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getHitPoint() == 1000 );
        REQUIRE( enemy->getHitPointLimit() == 1000 );
        REQUIRE( enemy->getDamage() == 100 );

        necromancer->attack(enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 50 );
        REQUIRE( necromancer->getHitPoint() == 600 - 50 );

        necromancer->attack(enemy);
        necromancer->attack(enemy);
        necromancer->attack(enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 50 - 50 - 50 - 50 );
        REQUIRE( necromancer->getHitPoint() == 600 - 50 - 50 - 50 - 50 );

        try {
            necromancer->attack(enemy);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( enemy->getHitPoint() == 0 );
            REQUIRE( necromancer->getHitPoint() == 110 );
        }

        try {
            enemy->attack(enemy, necromancer);
        } catch ( OutOfHitPointsException obj ) {
            REQUIRE( enemy->getHitPoint() == 0 );
            REQUIRE( necromancer->getHitPoint() == 110 );
        }
    }
    
    SECTION( "Necromancer::counter attack tests" ) {
        Soldier* enemy = new Soldier("Enemy");

        REQUIRE( enemy->getTitle() == "Enemy" );
        REQUIRE( enemy->getHitPoint() == 1000 );
        REQUIRE( enemy->getHitPointLimit() == 1000 );
        REQUIRE( enemy->getDamage() == 100 );

        necromancer->counterAttack(necromancer, enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 25 );
        REQUIRE( necromancer->getHitPoint() == 600 );

        necromancer->attack(enemy);
        necromancer->attack(enemy);
        necromancer->attack(enemy);

        REQUIRE( enemy->getHitPoint() == 1000 - 25 - 50 - 50 - 50 );
        REQUIRE( necromancer->getHitPoint() == 600 - 50 - 50 - 50 );

        necromancer->takeDamage(6000);

        REQUIRE( necromancer->getHitPoint() == 0 );
    }
    
    SECTION( "Necromancer::spend mana tests" ) {
        necromancer->spendMana(50);
        REQUIRE( necromancer->getManaPoint() == 500 - 50 );

        necromancer->spendMana(50);
        necromancer->spendMana(50);
        necromancer->spendMana(50);

        REQUIRE( necromancer->getManaPoint() == 500 - 50 - 50 - 100 );
    }
    
    SECTION( "Necromancer::add mana tests" ) {
        necromancer->spendMana(200);
        REQUIRE( necromancer->getManaPoint() == 500 - 200 );
        necromancer->addManaPoint(50);
        REQUIRE( necromancer->getManaPoint() == 350 );
        necromancer->addManaPoint(500);
        REQUIRE( necromancer->getManaPoint() == 500 );
    }

    SECTION( "Necromancer::heal tests" ) {
        Soldier* dude = new Soldier("Dude");
        
        dude->takeDamage(200);
        REQUIRE( dude->getHitPoint() == 1000 - 200 );
        necromancer->castSpell(dude, BATTLEHEAL);
        REQUIRE( dude->getHitPoint() == 1000 - 200 + 50);
        REQUIRE( necromancer->getManaPoint() == 500 - 30 );
        necromancer->castSpell(dude, BATTLEHEAL);
        necromancer->castSpell(dude, BATTLEHEAL);
        necromancer->castSpell(dude, BATTLEHEAL);
        necromancer->castSpell(dude, BATTLEHEAL);
        REQUIRE( dude->getHitPoint() == 1000);
        REQUIRE( necromancer->getManaPoint() == 500 - 30 - 60 - 60);
        dude->takeDamage(100);
        necromancer->spendMana(480);
        necromancer->castSpell(dude, BATTLEHEAL);
        REQUIRE( dude->getHitPoint() == 900);
   }
    
    SECTION( "Necromancer::magic damage tests" ) {
        Soldier* enemy = new Soldier("Enemy");
        
        necromancer->castSpell(enemy, VORTEX);
        REQUIRE( enemy->getHitPoint() == 1000 - 200);
        REQUIRE( necromancer->getManaPoint() == 500 - 50 );
        necromancer->castSpell(enemy, VORTEX);
        necromancer->castSpell(enemy, VORTEX);
        necromancer->castSpell(enemy, VORTEX);
        necromancer->castSpell(enemy, VORTEX);
        REQUIRE( enemy->getHitPoint() == 0);
        REQUIRE( necromancer->getManaPoint() == 500 - 50 - 100 - 100);
        necromancer->addHitPoint(100);
        REQUIRE( necromancer->getHitPoint() == 600);
    }
    
        SECTION( "Necromancer:: tests" ) {
        Soldier* enemy = new Soldier("Enemy");
        
        necromancer->castSpell(enemy, VORTEX);
        necromancer->attack(enemy);
        necromancer->attack(enemy);
        REQUIRE( enemy->getHitPoint() == 1000 - 200 - 100);
        REQUIRE( necromancer->getManaPoint() == 500 - 50 );
        REQUIRE( necromancer->getHitPoint() == 500);
        necromancer->castSpell(enemy, VORTEX);
        necromancer->castSpell(enemy, VORTEX);
        necromancer->castSpell(enemy, VORTEX);
        necromancer->castSpell(enemy, VORTEX);
        REQUIRE( enemy->getHitPoint() == 0);
        necromancer->update(enemy);
        REQUIRE( necromancer->getHitPoint() == 550);
    }
}

