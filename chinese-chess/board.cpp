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
		for (unsigned int black = 2, red = length - 3, i = 1; i < width; i += 6)
		{
			board[black][i] = make_shared<Cannon>(black, i, false);
			board[red][i] = make_shared<Cannon>(red, i, true);
		}

		// Front line: soldiers
		for (unsigned int black = 3, red = length - 4, i = 0; i < width; i += 2)
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
			return false;

		// Condition II: not blocked by other pieces
		int nx = (dx < 0 ? px + dx + 1 : px + dx - 1);
		int ny = (dy < 0 ? py + dy + 1 : py + dy - 1);
		
		if (board[nx][ny])
			return false;

		return true;
	}

	bool Board::valid_horse(shared_ptr<Piece> p, int px, int py, int dx, int dy)
	{
		// Condition I: not obstructed by another piece
		// if dy > dx that means moving left or right first
		// if dx > dy that means moving up or down first
		// if moving up first, check if one up is obstructed vv for down
		// if moving right, check if one right is obstructed vv for left
		if (dy > dx)	
			return (dy < 0 && !board[px][py - 1]) || !board[px][py + 1];
		else
			return (dx < 0 && !board[px - 1][py]) || !board[px + 1][py];
	}

	// TODO: totally gotta refactor this
	bool Board::valid_chariot(shared_ptr<Piece> p, int px, int py, int dx, int dy)
	{
		// Condition: no piece in between current position and destination, and move in one direction
		if (dx && dy)
		{
			return false;
		}
		else if (dx)	
		{
			for (int i = px + 1; i < px + dx; ++i)
			{
				if (board[i][py]) return false;
			}
		}
		else
		{
			for (int i = py + 1; i < py + dy; ++i)
			{
				if (board[px][i]) return false;
			}
		}

		return true;
	}

	bool Board::valid_cannon(shared_ptr<Piece> p, int px, int py, int dx, int dy)
	{
		// cannot move diagonally
		if (dx && dy)
			return false;

		// if a capture was to happen, must leap over something
		if (board[px + dx][py + dy])
		{
			// capture vertically
			if (dx)
			{
				for (int i = px + 1; i < px + dx; ++i)
				{
					if (board[i][py]) return true;
				}	
			}
			else
			{
				for (int i = py + 1; i < py + dy; ++i)
				{
					if (board[px][i]) return true;
				}
			}

			return false; // capture did not happen
		} 

		// if no capture then it should be treated like a chariot
		return valid_chariot(p, px, py, dx, dy);
	}

	// TODO: maybe the responsibility of this check should be on the piece
	bool Board::valid_soldier(shared_ptr<Piece> p, int px, int py, int dx, int dy)
	{
		// cannot go backwards ever
		return dx >= 0;
	}

	void Board::move(int px, int py, int dx, int dy)	
	{
		// check if there is a piece at px py
		if (!board[px][py])
			return; // maybe throw error or bubble it
		
		// check if next position is in board
		if (!in_board(px + dx, py + dy))
			return;

		// check if friendly piece in the way
		if (board[px + dx][py + dy] && (board[px][py]->is_red() == board[px + dx][py + dy]->is_red() ))
			return;

		// get the actual piece
		shared_ptr<Piece> p = board[px][py];
		int id = p->get_id();

		switch(id)
		{
			case general:
				if (valid_general(p, px, py, dx, dy)) break;
				return;
			case advisor:
				if (valid_advisor(p, px, py, dx, dy)) break;
				return;
			case elephant:
				if (valid_elephant(p, px, py, dx, dy)) break;
				return;
			case horse:
				if (valid_horse(p, px, py, dx, dy)) break;
				return;
			case chariot:
				if (valid_chariot(p, px, py, dx, dy)) break;
				return;
			case cannon:
				if (valid_cannon(p, px, py, dx, dy)) break;
				return;
			case soldier:
     			if (valid_soldier(p, px, py, dx, dy)) break;
				return;
			default:
				return; // cop out move, maybe a better error handling?
		}

		// update board side (after piece side is validated)
		// * reference piece in new position (kills enemy piece if any due to smart ptr)
		// * resets the original position
		if (p->move(dx, dy))
		{
			board[px + dx][py + dy] = board[px][py];
			board[px][py] = nullptr;
		}

		// if piece side move failed, don't do anything
		// maybe throw error is a better idea?
	}

	bool Board::in_box(int px, int py, bool red)
	{
		return py >= 3 && py <= 5 &&    
			   ((red && px >= 7 && px <= 9) ||
				 (px >= 0 && px <= 2));
	}

	bool Board::across_river(int px, int py, bool red)
	{
		return (red && px < 5) || px > 4;
	}

	bool Board::in_board(int px, int py)
	{
		return px > -1 && px < 9 && py > -1 && py < 10;
	}
}
