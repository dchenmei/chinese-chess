#include "board.h"

using namespace std;

namespace chinese_chess
{
	Board::Board(): width(9), length(10), board(length, vector<vector<int>(width))
	{
    	// Base line: general, advisor, elephant, horse, chariot
    	
		// Chariots
		board[0][0] = make_shared<Chariot>(0, 0, false);
		board[0][width - 1] = make_shared<Chariot>(0, width - 1, false);
		board[length - 1][0] = make_shared<Chariot>(length - 1, 0, true);
		board[length - 1][width - 1] = make_shared<Chariot>(lenght - 1, width - 1, true);

		// Horses
		board[0][1] = make_shared<Chariot>(0, 1, false);
		board[0][width - 2] = make_shared<Chariot>(0, width - 2, false);
		board[length - 1][1] = make_shared<Chariot>(length - 1, 1, true);
		board[length - 1][width - 2] = make_shared<Chariot>(length - 1, width - 2, true);

		// Elephants
		board[0][2] = make_shared<Elephant>(0, 2, false);
		board[0][width - 3] = make_shared<Elephant>(0, width - 3, false);
		board[length - 1][2] = make_shared<Elephant>(length - 1, 2, true);
		board[length - 1][width - 3] = make_shared<Elephant>(length - 1, width - 2, true);

        // Advisor
		board[0][3] = make_shared<Advisor>(0, 3, false);
		board[0][width - 4] = make_shared<Advisor>(0, width - 4, false);
		board[length - 1][3] = make_shared<Advisor>(length - 1, 3, true);
		board[length - 1][width - 4] = make_shared<Advisor>(length - 1, width - 4, true);

		// General
		board[0][4] = make_shared<General>(0, 4, false);
		board[length - 1][width - 5] = make_shared<General>(length - 1, width - 5, true);
		
		// Second to front line: cannons
		for (int black = 2, red = length - 3, i = 1; i < width; i += 6)
		{
			board[black][i] = make_shared<Cannon>(black, i, false);
			board[red][i] = make_shared<Cannon>(red, i, true);
		}

		// Front line: soldiers
		for (int black = 3, red = length - 4, i = 0; i < width; i += 2)
		{
			board[black][i] = make_shared<Soldier>(black, i, false);
			board[red][i] = make_shared<Soldier>(red, i, true);
		}
	}

	
}
