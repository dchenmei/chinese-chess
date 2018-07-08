#include "board.h"

namespace chinese_chess
{
	Board::Board(): width(9), length(10), board(length, vector<shared_ptr<Piece>>(width))
	{
    	// Base line: general, advisor, elephant, horse, chariot
    	
		// Chariots
		board[0][0] = make_shared<Chariot>(0, 0, false);
		board[0][width - 1] = make_shared<Chariot>(0, width - 1, false);
		board[length - 1][0] = make_shared<Chariot>(length - 1, 0, true);
		board[length - 1][width - 1] = make_shared<Chariot>(length - 1, width - 1, true);

		// Horses
		board[0][1] = make_shared<Horse>(0, 1, false);
		board[0][width - 2] = make_shared<Horse>(0, width - 2, false);
		board[length - 1][1] = make_shared<Horse>(length - 1, 1, true);
		board[length - 1][width - 2] = make_shared<Horse>(length - 1, width - 2, true);

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
	
	void Board::print()
	{
		for (auto line : board)
		{
			for (auto piece : line)
			{
				if (piece != nullptr)
					cout << piece->get_name() << " ";
				else
					cout << "NONE ";
			}
			cout << endl;
		}
	}

	bool Board::in_box(int px, int py, bool red)
	{
		return px >= 3 && px <= 5 &&    
			   ((red && py >= 7 && py <= 9) ||
				 (py >= 0 && py <= 2));
	}

	bool Board::across_river(int px, int py, bool red)
	{
		return red && py < 5 || py > 4;
	}

	bool Board::in_board(int px, int py)
	{
		return px > -1 && px < 9 && py > -1 && py < 10;
	}
}
