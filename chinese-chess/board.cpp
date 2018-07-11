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
	
	bool Board::valid_general(shared_ptr<Piece> p, int px, int py, int dx, int dy)
	{
		// Condition I: stays in the box
		if (!in_box(p->get_x() + dx , p->get_y() + dy, p->is_red()))
			return false;
				
		// Condition II: not facing the other general
		// for each spot vertically, if piece found good but if general found bad
		for (int cy = py - 1; cy > -1; --cy)
		{
			// found a piece
			if (board[px][cy])
			{
				// found the general
				if (board[px][cy]->get_name() == "General")
					return false;
					// otherwise okay
				else
					break;
			} 
		}
	
		// TODO
		// Condition III: not in check
		// for each opposing piece, generate all possible moves and see if they correspond
		// with the desired location
		
		// nothing wrong
		return true;
	}

	bool Board::valid_advisor(shared_ptr<Piece> p, int px, int py, int dx, int dy)
	{
		// Condition I: stays in the box
		return in_box(p->get_x() + dx , p->get_y() + dy, p->is_red());
	}

	bool Board::valid_elephant(shared_ptr<Piece> p, int px, int py, int dx, int dy)
	{
		// Condition I: not across the river
		if (across_river(p->get_x() + dx, p->get_y() + dy, p->is_red()))
			return;

		// Condition II: not blocked by other pieces
			// TODO: missing implementation

	}

	void Board::move(int px, int py, int dx, int dy)	
	{
		// check if there is a piece at px py
		if (!board[px][py])
			return; // maybe throw error or bubble it

		
		// check if in board
		if (!in_board(px + dx, py + dy))
			return;

		#if 0
		// check if friendly piece in the way
		if (board[px + dx][py + dy] && (board[px][py]->is_red() == board[px + dx][py + dy]->is_red() ))
			return;
		#endif


		shared_ptr<Piece> p = board[px][py];
		string name = p->get_name();


		if (name == "General")
		{

			// nothing found no general okay too

			// Condition III: not in check?? TODO

			p->move(dx, dy); // update piece side
						
			// update board side (this only happens if no error happens on piece side)
			
			// If there is a piece == kill
			if (board[px + dx][py + dy])
			{
				board[px + dx][py + dy] = nullptr; // no need to delete shared_ptr
			}
			board[px + dx][py + dy] = board[px][py];
			board[px][py] = nullptr;
		}
	
		else if (name == "Advisor")
		{
			p->move(dx, dy);

			if (board[px + dx][py + dy])
			{
				board[px + dx][py + dy] = nullptr; // no need to delete shared_ptr
			}
			board[px + dx][py + dy] = board[px][py];
			board[px][py] = nullptr;
		}

		else if (name == "Elephant")
		{
		
			p->move(dx, dy);
			if (board[px + dx][py + dy])
			{
				board[px + dx][py + dy] = nullptr; // no need to delete shared_ptr
			}
			board[px + dx][py + dy] = board[px][py];
		}
	
		else if (name == "Horse")
		{
			// TODO: missing implementation
		}

		else if (name == "Cannon")
		{
			// If a capture is about to happen, there must be one piece in between
			if (board[px + dx][py + dy])
			{
				// TODO: how do you check this, what if the dx and dy were invalid	
			}
		}
		
		// chariot and soldiers don't have any special exceptions
		else
		{
			p->move(dx, dy); 
			if (board[px + dx][py + dy])
			{
				board[px + dx][py + dy] = nullptr;
			}
			board[px + dx][py + dy] = board[px][py];
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
