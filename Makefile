all: main

main: main.o lz77.o lz78.o
	$(CXX) main.o lz77.o lz78.o -o main -std=c++17

lz77.o: lz77.h lz77.cpp
	$(CXX) -c lz77.cpp -std=c++17

lz78.o: lz78.h lz78.cpp
	$(CXX) -c lz78.cpp -std=c++17

main.o: main.cpp
	$(CXX) -c main.cpp -std=c++17

clean:
	rm -rf *.o main
