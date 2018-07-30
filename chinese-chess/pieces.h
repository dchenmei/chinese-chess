#ifndef PIECES_H
#define PIECES_H

#include <string>
#include <algorithm>
#include <utility>
using std::string;
using std::abs;
using std::pair;

namespace chinese_chess
{
	/* Enum IDs for piece types
	 * 0 - general
	 * 1 - advisor
	 * 2 - elephant
	 * 3 - horse
	 * 4 - chariot
	 * 5 - cannon
	 * 6 - solider
	 */
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

	/*
 	 * Piece (part of the model) 
 	 * Knows how a piece operates and what moves are valid from the piece's perspective.
 	 *
 	 */
	class Piece
	{
	  public:
		Piece (int i, int px, int py, string n, bool r): id(i), x(px), y(py), name(n), red(r), selected(false) {}
		string get_name() { return name; }
		int get_id() { return id; }
		int get_x() { return x; }
		int get_y() { return y; }
		bool is_red() { return red; }
		bool is_selected() { return selected; }
		void select() { selected = !selected; }
		virtual bool move(int, int) = 0;

	 protected:
		int id;
		int x;
		int y;
		string name;
		bool red;
		bool selected;
	};

    class General: public Piece
	{
	  public:
		General(int px, int py, bool color): Piece(general, px, py, "General", color) {}
		bool move(int, int);

	  private:
		bool check;	
	};

	class Advisor: public Piece
	{
	  public:
		Advisor(int px, int py, bool color): Piece(advisor, px, py, "Advisor", color) {}
		bool move(int, int);
	};

	class Elephant: public Piece
	{
	  public:
		Elephant(int px, int py, bool color): Piece(elephant, px, py, "Elephant", color) {}
		bool move(int, int);
	};

	class Horse: public Piece
	{
	  public:
		Horse(int px, int py, bool color): Piece(horse, px, py, "Horse", color) {}
		bool move(int, int);
	};

	class Chariot: public Piece
	{
	  public:
		Chariot(int px, int py, bool color): Piece(chariot, px, py, "Chariot",  color) {}
		bool move(int, int);
	};

	class Cannon: public Piece
	{
	  public:
		Cannon(int px, int py, bool color): Piece(cannon, px, py, "Cannon",  color) {}
		bool move(int, int);
	};

	class Soldier: public Piece
	{
      private:
		bool across_river; 

	  public:
		Soldier(int px, int py, bool color): Piece(soldier, px, py, "Soldier", color), across_river(false) {}
		bool move(int, int);
		void cross_river() { across_river = true; }
	};
}

#endif
