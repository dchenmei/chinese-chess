#include "board.h"

namespace chinese_chess
{
	Board::Board(): width(9), length(10), board(length, vector<shared_ptr<Piece>>(width))
	{
	#if 0
    	// Base line: general, advisor, elephant, horse, chariot
    	
		// Chariots
		board[0][0] = Chariot(0, 0, false);
		board[0][width - 1] = Chariot(0, width - 1, false);
		board[length - 1][0] = Chariot(length - 1, 0, true);
		board[length - 1][width - 1] = Chariot(length - 1, width - 1, true);

		// Horses
		board[0][1] = Horse(0, 1, false);
		board[0][width - 2] = Horse(0, width - 2, false);
		board[length - 1][1] = Horse(length - 1, 1, true);
		board[length - 1][width - 2] = Horse(length - 1, width - 2, true);

		// Elephants
		board[0][2] = Elephant(0, 2, false);
		board[0][width - 3] = Elephant(0, width - 3, false);
		board[length - 1][2] = Elephant(length - 1, 2, true);
		board[length - 1][width - 3] = Elephant(length - 1, width - 2, true);

        // Advisor
		board[0][3] = Advisor(0, 3, false);
		board[0][width - 4] = Advisor(0, width - 4, false);
		board[length - 1][3] = Advisor(length - 1, 3, true);
		board[length - 1][width - 4] = Advisor(length - 1, width - 4, true);

		// General
		board[0][4] = General(0, 4, false);
		board[length - 1][width - 5] = General(length - 1, width - 5, true);
		
		// Second to front line: cannons
		for (int black = 2, red = length - 3, i = 1; i < width; i += 6)
		{
			board[black][i] = Cannon(black, i, false);
			board[red][i] = Cannon(red, i, true);
		}

		// Front line: soldiers
		for (int black = 3, red = length - 4, i = 0; i < width; i += 2)
		{
			board[black][i] = Soldier(black, i, false);
			board[red][i] = Soldier(red, i, true);
		}
	#endif
	}
}
