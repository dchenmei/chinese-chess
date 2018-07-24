#ifndef PLAYER_H
#define PLAYER_H
// controller class that receives input 
#include "board.h"
#include <SFML/Graphics.hpp>
#include <memory>

using std::shared_ptr;

namespace chinese_chess
{
	class Player
	{
		public:
			Player(std::shared_ptr<chinese_chess::Board> b) : board(b), red_turn(true) {}
			//Player(shared_ptr<Board> b, shared_ptr<sf::RenderWindow> w) : window(w), board(b), red_turn(true) {}
			void play();

		private:
			shared_ptr<sf::RenderWindow> window;	
			shared_ptr<Board> board;
			bool red_turn;
	};
}
#endif
