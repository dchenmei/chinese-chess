#include "display.h"

namespace chinese_chess
{
	void Display::init()
	{
		sf::RenderWindow window(sf::VideoMode(width, height), "Chinese Chess");

		// Board overlay or physically actual board
		sf::RectangleShape rectangle(sf::Vector2f(width - (left_border * 2), height - (top_border * 2)));
		rectangle.setPosition(left_border, top_border);
		rectangle.setFillColor(wood);
		rectangle.setOutlineThickness(3);
		rectangle.setOutlineColor(sf::Color::Black);

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))	
			{
				if (event.type == sf::Event::Closed)
					window.close();	
			}

			window.clear(brown);
			window.draw(rectangle);

			// lines

			double board_space = height - (top_border * 2);
			double num_hlines = 9; // TODO: make this clear that one line is overlayed
			double num_vlines = 8;
			for (int i = 1; i <= num_hlines; ++i)
			{
				// horizontal
				sf::RectangleShape hline(sf::Vector2f(height - (top_border * 2), 3));
				hline.setFillColor(sf::Color::Black);
				hline.setPosition(left_border, (i * (board_space / num_hlines)) + top_border);
				window.draw(hline);
			}

			for (int i = 1; i < num_vlines; ++i)
			{
				// vertical top
				// TODO: why 2.2
				sf::RectangleShape vline(sf::Vector2f((width - (2.2 * board_space / num_hlines)) / 2, 3));
				vline.setFillColor(sf::Color::Black);
				vline.setPosition((i * (board_space) / num_vlines) + left_border, top_border);
				vline.rotate(90);
				window.draw(vline);

				// vertical bottom
				sf::RectangleShape vline_b(sf::Vector2f((width - (2.2 * board_space / num_hlines)) / 2, 3));
				vline_b.setFillColor(sf::Color::Black);
				vline_b.setPosition((i * (board_space) / num_vlines) + left_border, 
									(5 * (board_space / num_hlines)) + top_border);
				vline_b.rotate(90);
				window.draw(vline_b);
			}

			// cross lines

			// top
			sf::RectangleShape cline_one(sf::Vector2f(board_space / 3, 3));
			cline_one.setFillColor(sf::Color::Black);
			cline_one.setPosition((3 * board_space / num_vlines) + left_border, top_border);
			cline_one.rotate(45);
			window.draw(cline_one);

			sf::RectangleShape cline_two(sf::Vector2f(board_space / 3, 3));
			cline_two.setFillColor(sf::Color::Black);
			cline_two.setPosition((5 * board_space / num_vlines) + left_border, top_border);
			cline_two.rotate(135);
			window.draw(cline_two);

			// bottom
			sf::RectangleShape cline_three(sf::Vector2f(board_space / 3, 3));
			cline_three.setFillColor(sf::Color::Black);
			cline_three.setPosition((3 * board_space / num_vlines) + left_border, 
									 (7 * board_space / num_hlines) + top_border);
			cline_three.rotate(45);
			window.draw(cline_three);

			sf::RectangleShape cline_four(sf::Vector2f(board_space / 3, 3));
			cline_four.setFillColor(sf::Color::Black);
			cline_four.setPosition((5 * board_space / num_vlines) + left_border, 
									 (7 * board_space / num_hlines) + top_border);
			cline_four.rotate(135);
			window.draw(cline_four);

			window.display();
		}
	}
}
