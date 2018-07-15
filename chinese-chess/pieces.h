#ifndef PIECES_H
#define PIECES_H

#include <string>
using std::string;

/* IDs for piece types
 * 0 - general
 * 1 - advisor
 * 2 - elephant
 * 3 - horse
 * 4 - chariot
 * 5 - cannon
 * 6 - solider
 */
namespace chinese_chess
{
	enum PieceID
	{
		general,
		advisor,
		elephant,
		horse,
		chariot,
		cannon,	
		soldier
	};

	class Piece
	{
	  public:
		Piece (int i, int px, int py, string n, bool r): id(i), x(px), y(py), name(n), red(r) {}
		string get_name() { return name; }
		int get_x() { return x; }
		int get_y() { return y; }
		bool is_red() { return red; }
		virtual void move(int, int) = 0;

	 protected:
		int id;
		int x;
		int y;
		string name;
		bool red;
	};

    class General: public Piece
	{
	  public:
		General(int px, int py, bool color): Piece(general, px, py, "General", color) {}
		void move(int, int);

	  private:
		bool check;	
	};

	class Advisor: public Piece
	{
	  public:
		Advisor(int px, int py, bool color): Piece(advisor, px, py, "Advisor", color) {}
		void move(int, int);
	};

	class Elephant: public Piece
	{
	  public:
		Elephant(int px, int py, bool color): Piece(elephant, px, py, "Elephant", color) {}
		void move(int, int);
	};

	class Horse: public Piece
	{
	  public:
		Horse(int px, int py, bool color): Piece(horse, px, py, "Horse", color) {}
		void move(int, int);
	};

	class Chariot: public Piece
	{
	  public:
		Chariot(int px, int py, bool color): Piece(chariot, px, py, "Chariot",  color) {}
		void move(int, int);
	};

	class Cannon: public Piece
	{
	  public:
		Cannon(int px, int py, bool color): Piece(cannon, px, py, "Cannon",  color) {}
		void move(int, int);
	};

	class Soldier: public Piece
	{
      private:
		bool across_river; 

	  public:
		Soldier(int px, int py, bool color): Piece(soldier, px, py, "Soldier", color), across_river(false) {}
		void move(int, int);
		void cross_river() { across_river = true; }
	};
}

#endif
