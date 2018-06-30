#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>
#include "pieces.h"

using std::vector;
using std::shared_ptr;

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
		bool in_box(int px, int py, bool red)
		{

		}

		bool across_river(int px, int py, bool red)
		{

		}

		bool in_board(int px, int py)
		{

		}

		bool valid_move(int px, int py, bool red)
		{

		}

	  private:
		const unsigned int width;
		const unsigned int length;
		vector<vector<shared_ptr<Piece>>> board;
	};
}
#endif
