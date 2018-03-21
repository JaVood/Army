all: test.out

test.out: main.o State_Unit_test.o State.o Ability.o Unit.o
	g++ -o test.out main.o State_Unit_test.o State.o Ability.o Unit.o

State.o:
	g++ -c ../State/State.cpp

Ability.o:
	g++ -c ../Ability/Ability.cpp

Unit.o:
	g++ -c ../Unit/Unit.cpp

State_Unit_test.o:
	g++ -std=c++11 -c State_Unit_test.cpp

main.o:
	g++ -std=c++11 -c main.cpp

clean:
	rm -f *.o


# make && make clean && ./test.out