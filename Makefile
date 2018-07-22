CXX = g++
CXXFLAGS = -std=c++11 -Wall
SFML-FLAGS = -lsfml-graphics -lsfml-window -lsfml-system
INC = -I chinese-chess -I graphics -I player


all: clean main

main: main.o pieces.o board.o display.o 
	$(CXX) $(CXXFLAGS) main.o pieces.o board.o display.o -o main  $(SFML-FLAGS)

main.o:
	$(CXX) $(CXXFLAGS) $(INC) -c main.cpp

pieces.o:
	$(CXX) $(CXXFLAGS) $(INC) -c chinese-chess/pieces.cpp

board.o:
	$(CXX) $(CXXFLAGS) $(INC) -c chinese-chess/board.cpp

display.o:
	$(CXX) $(CXXFLAGS) $(INC) -c graphics/display.cpp

clean:
	rm main main.o pieces.o board.o display.o 
