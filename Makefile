all: main

main: main.o lz78.o
	g++ main.o lz78.o -o main

lz78.o: lz78.h lz78.cpp
	g++ -c lz78.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -rf *.o main
