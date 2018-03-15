all: test.out

test.out: main.o StateTest.o State.o
	g++ -o test.out main.o StateTest.o State.o

State.o:
	g++ -c ../State/State.cpp

StateTest.o:
	g++ -std=c++11 -c StateTest.cpp

main.o:
	g++ -std=c++11 -c main.cpp

clean:
	rm -f *.o