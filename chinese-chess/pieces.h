#ifndef PIECES_H
#define PIECES_H

namespace chinese_chess
{
	class Piece
	{
	  public:
		virtual void move()
		{

		}
		

	  private:
		int x;
		int y;
	};

	class General : public Piece
	{


	};

	class Advisor : public Piece
	{

	};

	class Elephant : public Piece
	{

	};

	class Horse : public Piece
	{

	};

	class Chariot : public Piece
	{

	};

	class Cannon : public Chariot
	{

	};

	class Soldier : public Piece
	{

	};
}

#endif
