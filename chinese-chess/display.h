#ifndef DISPLAY_H
#define DISPLAY_H

#include <SFML/Graphics.hpp>
#include "board.h"

namespace chinese_chess
{
	class Display
	{
	  public:
		Display(Board b): board(b) {}
		void init();

	  private:
		const sf::Color brown = sf::Color(206, 92, 0, 255);
 		const sf::Color wood = sf::Color(252, 175, 62, 255);
		const int width = 800;
		const int height = 800;
		const int top_border = 50;
		const int left_border = 50;
		Board board;
	};
}

#endif
