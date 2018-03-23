all: test.out

test.out: main.o Test.o State.o Ability.o RogueAbility.o VampireAbility.o PriestAbility.o Unit.o Soldier.o Rogue.o Berserker.o Vampire.o Werewolf.o SpellCaster.o Wizard.o Vortex.o BattleHeal.o Healer.o Priest.o
	g++ -o test.out main.o Test.o State.o Ability.o RogueAbility.o VampireAbility.o PriestAbility.o Unit.o Soldier.o Rogue.o Berserker.o Vampire.o Werewolf.o SpellCaster.o Wizard.o Vortex.o BattleHeal.o Healer.o Priest.o

State.o:
	g++ -c ../State/State.cpp
	
Ability.o:
	g++ -c ../Ability/Ability.cpp

RogueAbility.o:
	g++ -c ../Ability/RogueAbility.cpp

VampireAbility.o:
	g++ -c ../Ability/VampireAbility.cpp

PriestAbility.o:
	g++ -c ../Ability/PriestAbility.cpp

Unit.o:
	g++ -c ../Unit/Unit.cpp

Rogue.o:
	g++ -c ../Unit/Rogue.cpp

Soldier.o:
	g++ -c ../Unit/Soldier.cpp

Berserker.o:
	g++ -c ../Unit/Berserker.cpp

Vampire.o:
	g++ -c ../Unit/Vampire.cpp

Werewolf.o:
	g++ -c ../Unit/Werewolf.cpp

SpellCaster.o:
	g++ -c ../SpellCaster/SpellCaster.cpp

Wizard.o:
	g++ -c ../SpellCaster/Wizard.cpp

Healer.o:
	g++ -c ../SpellCaster/Healer.cpp

Priest.o:
	g++ -c ../SpellCaster/Priest.cpp

Vortex.o:
	g++ -c ../Spell/Vortex.cpp

BattleHeal.o:
	g++ -c ../Spell/BattleHeal.cpp

Test.o:
	g++ -std=c++11 -c Test.cpp

main.o:
	g++ -std=c++11 -c main.cpp

clean:
	rm -f *.o


# make && make clean && ./test.out