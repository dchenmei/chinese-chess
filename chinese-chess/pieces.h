#ifndef PIECES_H
#define PIECES_H

namespace chinese_chess
{
	class Piece
	{
	  public:
		Piece (int px, int py, bool r): x(px), y(py), red(r) {}
		virtual void move(int, int) = 0;

	  private:
		int x;
		int y;
		bool red;
	};

    class General: public Piece
	{
	  public:
		General(int px, int py, bool color): Piece(px, py, color) {}
		void move(int, int);

	  private:
		bool check;	
	};

	class Advisor: public Piece
	{
	  public:
		Advisor(int px, int py, bool color): Piece(px, py, color) {}
		void move(int, int);
	};

	class Elephant: public Piece
	{
	  public:
		Elephant(int px, int py, bool color): Piece(px, py, color) {}
		void move(int, int);
	};

	class Horse: public Piece
	{
	  public:
		Horse(int px, int py, bool color): Piece(px, py, color) {}
		void move(int, int);
	};

	class Chariot: public Piece
	{
	  public:
		Chariot(int px, int py, bool color): Piece(px, py, color) {}
		void move(int, int);
	};

	class Cannon: public Chariot
	{
	  public:
		Cannon(int px, int py, bool color): Chariot(px, py, color) {}
		void move(int, int);
	};

	class Soldier: public Piece
	{
	  public:
		Soldier(int px, int py, bool color): Piece(px, py, color) {}
		void move(int, int);
	};
}

#endif
