#include "pieces.h"

using namespace std; // can we do this ???

namespace chinese_chess
{
	// General	
	bool General::move(int dx, int dy)
	{
		// Move valid only if:
		// - not outside of box (check by board)
		// - not in check (check by board)
		// - not facing the opponenet's general (check by board)
		// - up down left right with distance of one
		
		// violate move if:
		// attempt diagonal move
		// attempt move distance greater than one
		if ((dx && dy) || (abs(dx) != 1 && abs(dy) != 1))
			return false;

		x += dx;
		y += dy;
		return true;
	}

	void General::gen_moves()
	{
		// possible moves (not affected by color):
		// one up, one down, one left, one right
		moves.push_back(make_pair(x + 1, y));
		moves.push_back(make_pair(x - 1, y));
		moves.push_back(make_pair(x, y + 1));
		moves.push_back(make_pair(x, y - 1));
	}

	// Advisor
	bool Advisor::move(int dx, int dy)
	{
		// Move valid only if:
		// - not outside of box (checked by board)
		// - one point diagonally, meaning following combo:
		// 	 * x + 1, y - 1
		// 	 * x + 1, y + 1 
		// 	 * x - 1, y - 1 
		// 	 * x - 1, y + 1 
	
		if (abs(dx) != abs(dy) || abs(dx) != 1 || abs(dy) != 1)
			return false;

		x += dx;
		y += dy;
		return true;
	}

	void Advisor::gen_moves()
	{
		// possible moves (not affected by color):
		// four diagonals by one
		moves.push_back(make_pair(x + 1, y + 1));
		moves.push_back(make_pair(x - 1, y - 1));
		moves.push_back(make_pair(x + 1, y - 1));
		moves.push_back(make_pair(x - 1, y + 1));
	}

	// Elephant
	bool Elephant::move(int dx, int dy)
	{
		// Move valid only if
		// - not over the river (checked by board)
		// - not blocked by another piece (checked by board)
		// - two points diagonally, meaning following combo:
		// * x + 2, y - 2
		// * x + 2, y + 2
		// * x - 2, y - 2
		// * x - 2, y + 2
		if (abs(dx) != abs(dy) || abs(dx) != 2 || abs(dy) != 2)
			return false;

		x += dx;
		y += dy;
		return true;
	}

	void Elephant::gen_moves()
	{
		// possible moves (not affected by color):
		// four diagonals by two
		moves.push_back(make_pair(x + 2, y + 2));
		moves.push_back(make_pair(x - 2, y - 2));
		moves.push_back(make_pair(x + 2, y - 2));
		moves.push_back(make_pair(x - 2, y + 2));
	}

	// Horse
	bool Horse::move(int dx, int dy)
	{
		// Move valid only if
		// - not block by another piece (cannot jump over other piece) -- checked by board
		// - one point horizontal / verical then one point diagonally
		// 	 * can also be viewed as two points (u, d, l, r) * two directions

		// Intuition:
		// - if moving up or down, absolute of left or right is always 1
		// - if moving left or right, absolute of up or down is always 1
		// - thus eight possibilities are: (x +- 2, y +- 1) and (x +-1, y +- 2)

		// Only possibilities
		if ((abs(dx) == 2 && abs(dy) == 1) || (abs(dx) == 1 && abs(dy) == 2))
		{
			x += dx;
			y += dy;
			return true;
		}

		// not within the combinations
		return false;
	}

	void Horse::gen_moves()
	{
		// possible moves (not affected by color):
		// for each orthogonal direction, you can also have two more diagonals
		
		// uo
		moves.push_back(make_pair(x - 2, y + 1));
		moves.push_back(make_pair(x - 2, y - 1));
		
		// down
		moves.push_back(make_pair(x + 2, y + 1));
		moves.push_back(make_pair(x + 2, y - 1));
		
		// left
		moves.push_back(make_pair(x + 1, y - 2));
		moves.push_back(make_pair(x - 1, y - 2));

		// right
		moves.push_back(make_pair(x + 1, y + 2));
		moves.push_back(make_pair(x - 1, y + 2));
	}

	// Chariot
	bool Chariot::move(int dx, int dy)
	{
		// Only one direction moves allowed
		if (dx && dy)
			return false;

		x += dx;
		y += dy;
		return true;
	}

	void Chariot::gen_moves()
	{
		// possible moves (not affected by color):
		// all the way to end of board up down left and right
	}

	// Cannon
	// TODO: refactor to chariot because same implementation
	bool Cannon::move(int dx, int dy)
	{
		if (dx && dy)
			return false;

		x += dx;
		y += dy;	
		return true;
	}

	void Cannon::gen_moves()
	{
		// possible moves (not affected by color):
		// all the way to end of board up down left and right
		// and also possible jumps for takeover
	}

	// Soldier
	bool Soldier::move(int dx, int dy)
	{
		// Not valid if:
				
		// moving horizontally before crossing river
		if (!across_river && dy != 0)
			return false;

		// moving backwards
		if ((red && dx > 0) || (!red && dx < 0))
			return false;

		// more than one direction at a time
		if (dx && dy)
			return false;

		// moves are more than one point
		if (abs(dx) != 1 && abs(dy) != 1) // TODO: check
			return false;

		// Else we are good to go:
		x += dx;
		y += dy;
		return true;
	}

	void Soldier::gen_moves()
	{
		// possible moves (some affected by color):
		// up (depends on color)
		if (red)
			moves.push_back(make_pair(x - 1, y));
		else
			moves.push_back(make_pair(x + 1, y));

		// left and right if across river
		if (across_river)
		{
			moves.push_back(make_pair(x, y - 1));	
			moves.push_back(make_pair(x, y + 1));
		}
	}
}
