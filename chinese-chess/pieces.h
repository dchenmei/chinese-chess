#ifndef PIECES_H
#define PIECES_H

#include <string>
using std::string;

namespace chinese_chess
{
	class Piece
	{
	  public:
		Piece (int px, int py, string n, bool r): x(px), y(py), name(n), red(r) {}
		string get_name() { return name; }
		virtual void move(int, int) = 0;

	 protected:
		int x;
		int y;
		string name;
		bool red;
	};

    class General: public Piece
	{
	  public:
		General(int px, int py, bool color): Piece(px, py, "General", color) {}
		void move(int, int);

	  private:
		bool check;	
	};

	class Advisor: public Piece
	{
	  public:
		Advisor(int px, int py, bool color): Piece(px, py, "Advisor", color) {}
		void move(int, int);
	};

	class Elephant: public Piece
	{
	  public:
		Elephant(int px, int py, bool color): Piece(px, py, "Elephant", color) {}
		void move(int, int);
	};

	class Horse: public Piece
	{
	  public:
		Horse(int px, int py, bool color): Piece(px, py, "Horse", color) {}
		void move(int, int);
	};

	class Chariot: public Piece
	{
	  public:
		Chariot(int px, int py, bool color): Piece(px, py, "Chariot",  color) {}
		void move(int, int);
	};

	class Cannon: public Piece
	{
	  public:
		Cannon(int px, int py, bool color): Piece(px, py, "Cannon",  color) {}
		void move(int, int);
	};

	class Soldier: public Piece
	{
      private:
		bool across_river; 

	  public:
		Soldier(int px, int py, bool color): Piece(px, py, "Soldier", color), across_river(false) {}
		void move(int, int);
		void cross_river() { across_river = true; }
	};
}

#endif
