all: test.out

test.out: main.o Soldier_test.o State.o Ability.o Unit.o Soldier.o
	g++ -o test.out main.o Soldier_test.o State.o Ability.o Unit.o Soldier.o

State.o:
	g++ -c ../State/State.cpp

Ability.o:
	g++ -c ../Ability/Ability.cpp

Unit.o:
	g++ -c ../Unit/Unit.cpp

Soldier.o:
	g++ -c ../Unit/Soldier.cpp

Soldier_test.o:
	g++ -std=c++11 -c Soldier_test.cpp

main.o:
	g++ -std=c++11 -c main.cpp

clean:
	rm -f *.o


# make && make clean && ./test.out