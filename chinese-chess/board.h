#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>
#include <iostream>
#include "pieces.h"

using std::vector;
using std::shared_ptr;
using std::dynamic_pointer_cast;
using std::make_shared;
using std::cout;
using std::endl;

// TODO
// - alias unsigned ints

namespace chinese_chess
{
	class Board
	{
	  public:
		Board();

		/* 
		Piece at(int x, int y);
		Piece remove(int x, int y);
		*/
		
		// prints all the board pieces
		void print();

		// move checker's depending on the piece
		bool valid_general(shared_ptr<Piece>, int, int, int, int);
		bool valid_advisor(shared_ptr<Piece>, int, int, int, int);
		bool valid_elephant(shared_ptr<Piece>, int, int, int, int);
		bool valid_horse(shared_ptr<Piece>, int, int, int, int);
		bool valid_cannon(shared_ptr<Piece>, int, int, int, int);
		bool valid_chariot(shared_ptr<Piece>, int, int, int, int);
		bool valid_soldier(shared_ptr<Piece>, int, int, int, int);

		// move piece at px py by dx dy
		bool move(int, int, int, int);

		// EZ Check functions useful for pieces to validate their move
		bool in_box(int, int, bool);

		// across river if:
		// 	* red and on black side (y < 5)
		// 	* black and on red side (y > 4)			
		bool across_river(int, int, bool);

		// piece is in board if:
		//  * it goes beyond the edges of the board (9x10 dimension)
		//  note: counting is from 0
		bool in_board(int, int);

		// in board method adjusted by width and height
		bool in_board(double, double, double, double);

		// get reference to board
		const vector<vector<shared_ptr<Piece>>>& get_board() { return board; }

	  private:
		const unsigned int width;
		const unsigned int length;
		vector<vector<shared_ptr<Piece>>> board;
	};
}
#endif
