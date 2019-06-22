all: main

main: main.o lz77.o lz78.o
	g++ main.o lz77.o lz78.o -o main

lz77.o: lz77.h lz77.cpp
	g++ -c lz77.cpp

lz78.o: lz78.h lz78.cpp
	g++ -c lz78.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -rf *.o main
