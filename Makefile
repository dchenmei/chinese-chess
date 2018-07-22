all: clean main

main: main-compile
	g++ main.o pieces.o board.o display.o -o app -lsfml-graphics -lsfml-window -lsfml-system

main-compile: 
	g++ -c -std=c++11 -Wall main.cpp pieces.cpp board.cpp display.cpp 

clean:
	rm app main.o pieces.o board.o display.o 
