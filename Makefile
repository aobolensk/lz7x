all: main

main: main.o lz77.o lz78.o
	g++ main.o lz77.o lz78.o -o main -std=c++17

lz77.o: lz77.h lz77.cpp
	g++ -c lz77.cpp -std=c++17

lz78.o: lz78.h lz78.cpp
	g++ -c lz78.cpp -std=c++17

main.o: main.cpp
	g++ -c main.cpp -std=c++17

clean:
	rm -rf *.o main
