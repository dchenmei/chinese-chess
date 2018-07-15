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
	
		if ((dx * dy != 1 && dx * dy != -1) || abs(dx) != 1 || abs(dy) != 1)
			return false;

		x += dx;
		y += dy;
		return true;
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
		if (dx != dy || abs(dx) != 2 || abs(dy) != 2)
			return false;

		x += dx;
		y += dy;
		return true;
	}

	// Horse
	bool Horse::move(int dx, int dy)
	{
		// Move valid only if
		// - not block by another piece (cannot jump over other piece) -- checked by board
		// - one point horizontal / verical then one point diagonally
		// 	 * can also be viewed as two points (u, d, l, r) * two directions
		// 8 possible combinations

		// TODO: Double check this logic
		if (abs(dx - dy) != 1)
			return false;

		x += dx;
		y += dy;
		return true;
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

	// Soldier
	bool Soldier::move(int dx, int dy)
	{
		// Not valid if 
		// - two directions at a time
		// - moving backwards
		// - moving horizontally before crossing river
		if ((!dx && dy) || dx < 0 || (!across_river && dy))
			return false;

		x += dx;
		y += dy;
		return true;
	}
}
