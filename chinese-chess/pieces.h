#ifndef PIECES_H
#define PIECES_H

namespace chinese_chess
{
	class Piece
	{
	  public:
		Piece (int px, int py, bool r): x(px), y(py), red(r) {}
		virtual void move(int, int) const = 0

	  private:
		int x;
		int y;
		bool red;
	};

    class General: public Piece
	{
	  private:
		bool check;	
	}

	class Advisor: public Piece
	{
	}

	class Elephant: public Piece
	{
	}

	class Horse: public Piece
	{
	}

	class Chariot: public Piece
	{
	}

	class Cannon: public Chariot
	{

	}

	class Soldier: public Piece
	{

	}
}

#endif
