#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include <memory>
#include "board.h"

using std::shared_ptr;

namespace chinese_chess
{
	/* Player (controller)
     *
     * Has knowledge of the player side of the game, e.g which turn and what piece to
     * select and move. Input from user is passed to the Board (model).
     */
	class Player
	{
		public:
			// Create player given a model and view (board and window)
			Player(shared_ptr<Board> b, shared_ptr<sf::RenderWindow> w) : window(w), board(b), red_turn(true), selected(false) {}

			// Walkthrough one turn / sequence of the game. 
			void play();

		private:

			// Given coordinates from graphic window, return approx. board position
			// if the coordinate is valid
			sf::Vector2i pos_to_coord(sf::Vector2i);

			shared_ptr<sf::RenderWindow> window;	
			shared_ptr<Board> board;
			bool red_turn;
			shared_ptr<Piece> selected;
	};
}
#endif
