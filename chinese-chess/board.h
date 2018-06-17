#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include "pieces.h"
#include "player.h"

using std::vector;

// TODO
// - alias unsigned ints

namespace chinese_chess
{
	class Board
	{
	  public:
		Board();

		Piece at(int x, int y);
		Piece remove(int x, int y);


	  private:

		unsigned int width;
		unsigned int length;
		vector<vector<Piece>> board;
	};
}
#endif
