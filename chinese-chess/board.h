#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>
#include "pieces.h"

using std::vector;
using std::shared_ptr;
using std::make_shared;

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

		// valid move from the board's perspective
		bool valid_move(int, int, bool);

	  private:
		const unsigned int width;
		const unsigned int length;
		vector<vector<shared_ptr<Piece>>> board;
	};
}
#endif
