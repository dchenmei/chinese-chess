#ifndef PIECES_H
#define PIECES_H

namespace chinese_chess
{
	class Piece
	{
	  public:
		Piece (int px, int py, bool r): x(px), y(py), red(r) {}
		virtual void move(int, int) const = 0;

	  private:
		int x;
		int y;
		bool red;
	};

    class General: public Piece
	{
	  public:
		void move(int, int);

	  private:
		bool check;	
	};

	class Advisor: public Piece
	{
	  public:
		void move(int, int);
	};

	class Elephant: public Piece
	{
	  public:
		void move(int, int);
	};

	class Horse: public Piece
	{
	  public:
		void move(int, int);
	};

	class Chariot: public Piece
	{
	  public:
		void move(int, int);
	};

	class Cannon: public Chariot
	{
	  public:
		void move(int, int);
	};

	class Soldier: public Piece
	{
	  public:
		void move(int, int);
	};
}

#endif
