#include "pieces.h"

using namespace std; // can we do this ???

namespace chinese_chess
{
	// General	
	void General::move(int dx, int dy)
	{
		// Move valid only if:
		// - not outside of box
		// - not in check
		// - not facing the opponenet's general
	}

	// Advisor
	void Advisor::move(int dx, int dy)
	{
		// Move valid only if:
		// - not outside of box
		// - one point diagonally, meaning following combo:
		// 	 * x + 1, y - 1
		// 	 * x + 1, y + 1 
		// 	 * x - 1, y - 1 
		// 	 * x - 1, y + 1 
		
		// TODO: Check that this logic actually works
		if (x == 1 || x == -1 && y == 1 || y == -1)
		{
			x += dx;
			y += dy;
		}
		else
		{
			// TODO: Throw invalid position erro?
		}
		
	}

	// Elephant
	void Elephant:move(int dx, int dy)
	{
		// Move valid only if
		// - not over the river
		// - not blocked by another piece
		// - two points diagonally, meaning following combo:
		// * x + 2, y - 2
		// * x + 2, y + 2
		// * x - 2, y - 2
		// * x - 2, y + 2
	}

	// Horse
	void Horse::move(int dx, int dy)
	{
		// Move valid only if
		// - not block by another piece (cannot jump over other piece)
		// - one point horizontal / verical then one point diagonally
	}
}
