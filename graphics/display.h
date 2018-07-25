#ifndef DISPLAY_H
#define DISPLAY_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "board.h"

using std::shared_ptr;
using std::make_shared;

namespace chinese_chess
{
	class Display
	{
	  public:
		Display(shared_ptr<Board> b): window(make_shared<sf::RenderWindow>(sf::VideoMode(width, height), "Chinese Chess")), board(b) {}
		void draw();
		shared_ptr<sf::RenderWindow> get_window() { return window; }
		bool window_open() { return window->isOpen(); }

	  private:
		void draw_pieces();
		void draw_board();
		void draw_lines();

		const sf::Color brown = sf::Color(206, 92, 0, 255);
 		const sf::Color wood = sf::Color(252, 175, 62, 255);
		const sf::Color bamboo = sf::Color(254, 218, 164, 255);
		const double width = 800;
		const double height = 800;
		const double top_border = 50;
		const double left_border = 50;
		const double num_hlines = 9; // one line is covered by the bottom border (so 9 not 8)
		const double num_vlines = 8;
		shared_ptr<sf::RenderWindow> window;
		shared_ptr<Board> board;
	};
}

#endif
