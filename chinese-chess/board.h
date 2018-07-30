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

namespace chinese_chess
{
	/* Board (model)
     *
     * Knows what is going in the board, as in which pieces are where. Receives input from
     * controller (player) and acts as knowledge for view (display).
     */
	class Board
	{
	  public:
		Board();

		// print board (in console)
		void print();

		// move checker's depending on the piece, from the board's perspective
		bool valid_general(shared_ptr<Piece>, int, int, int, int);
		bool valid_advisor(shared_ptr<Piece>, int, int, int, int);
		bool valid_elephant(shared_ptr<Piece>, int, int, int, int);
		bool valid_horse(shared_ptr<Piece>, int, int, int, int);
		bool valid_cannon(shared_ptr<Piece>, int, int, int, int);
		bool valid_chariot(shared_ptr<Piece>, int, int, int, int);

		// move piece at px py by dx dy
		bool move(int, int, int, int);

		// chceck if a coordinate is inside the box for general / advisor
		bool in_box(int, int, bool);

		// check if a coordinate is across the river (in enemy's land)
		bool across_river(int, int, bool);

		// check if a coordinate is inside the board
		bool in_board(int, int);

		// get reference to board
		const vector<vector<shared_ptr<Piece>>>& get_board() { return board; }

	  private:
		const unsigned int width;
		const unsigned int length;
		vector<vector<shared_ptr<Piece>>> board;
	};
}
#endif
