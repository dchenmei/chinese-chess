#include "pieces.h"

namespace chinese_chess
{
	// General	
	bool General::move(int dx, int dy)
	{
		// bad move if:
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
		// bad move if:
		// outside of box
		// attempt move distance greather than one
		if (abs(dx) != abs(dy) || abs(dx) != 1 || abs(dy) != 1)
			return false;

		x += dx;
		y += dy;
		return true;
	}

	// Elephant
	bool Elephant::move(int dx, int dy)
	{
		// bad move if:
		// not diagonal
		// diagonal but not distance of two
		if (abs(dx) != abs(dy) || abs(dx) != 2 || abs(dy) != 2)
			return false;

		x += dx;
		y += dy;
		return true;
	}

	// Horse
	bool Horse::move(int dx, int dy)
	{
		// Intuition:
		// - if moving up or down, absolute of left or right is always 1
		// - if moving left or right, absolute of up or down is always 1
		// - thus eight possibilities are: (x +- 2, y +- 1) and (x +-1, y +- 2)

		if ((abs(dx) == 2 && abs(dy) == 1) || (abs(dx) == 1 && abs(dy) == 2))
		{
			x += dx;
			y += dy;
			return true;
		}

		// bad move if:
		// not within the eight possible combos
		return false;
	}

	// Chariot
	bool Chariot::move(int dx, int dy)
	{
		// bad move if:
		// more than one direction at a time
		if (dx && dy)
			return false;

		x += dx;
		y += dy;
		return true;
	}

	// TODO: refactor into same method as Chariot::move
	// Cannon
	bool Cannon::move(int dx, int dy)
	{
		// bad move if:
		// more than one direction at a time
		if (dx && dy)
			return false;

		x += dx;
		y += dy;	
		return true;
	}

	// Soldier
	bool Soldier::move(int dx, int dy)
	{
		// Bad move if:
				
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
		if (abs(dx) != 1 && abs(dy) != 1) 
			return false;

		x += dx;
		y += dy;
		return true;
	}
}
