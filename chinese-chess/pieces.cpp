#include "pieces.h"

using namespace std; // can we do this ???

namespace chinese_chess
{
	// General	
	void General::move(int dx, int dy)
	{
		// Move valid only if:
		// - not outside of box (check by board)
		// - not in check (check by board)
		// - not facing the opponenet's general (check by board)
		if (!dx != !dy) // basically up down left right but with limited range
		{
			x += dx;	
			y += dy;
		}
	}

	// Advisor
	void Advisor::move(int dx, int dy)
	{
		// Move valid only if:
		// - not outside of box (checked by board)
		// - one point diagonally, meaning following combo:
		// 	 * x + 1, y - 1
		// 	 * x + 1, y + 1 
		// 	 * x - 1, y - 1 
		// 	 * x - 1, y + 1 
	
		// TODO: Check that this logic actually works
		if (dx * dy == -1 || dx * dy)
		{
			x += dx;
			y += dy;
		}
	}

	// Elephant
	void Elephant::move(int dx, int dy)
	{
		// Move valid only if
		// - not over the river (checked by board)
		// - not blocked by another piece (checked by board)
		// - two points diagonally, meaning following combo:
		// * x + 2, y - 2
		// * x + 2, y + 2
		// * x - 2, y - 2
		// * x - 2, y + 2
		if ((dx == 2 || dx == -2) && (dy == 2 || dy == -2))
		{
			x += dx;
			y += dy;
		}
	}

	// Horse
	void Horse::move(int dx, int dy)
	{
		// Move valid only if
		// - not block by another piece (cannot jump over other piece) -- checked by board
		// - one point horizontal / verical then one point diagonally
		// 8 possible combinations

	}

	// Chariot
	void Chariot::move(int dx, int dy)
	{
		// Only one direction moves allowed
		if (!dx != !dy)
		{
			x += dx;
			y += dy;
		}
	}

	// Cannon
	void Cannon::move(int dx, int dy)
	{
	}

	// Soldier
	void Soldier::move(int dx, int dy)
	{
		// validate that the move is valid
		if ((!dx && dy) || (across_river && (dx || -dx)))
		{
			x += dx;
			y += dy;
		}

		// invalid move
		// TODO: throw error
	}
}
