#include "display.h"

namespace chinese_chess
{
	void Display::draw_pieces()
	{
		const double radius = 30, board_space = height - (top_border * 2);
		sf::CircleShape shape(radius);
		auto b = board.get_board();
		// walk through board and draw the pieces' position w/ offset in mind
		for (uint i = 0; i < b.size(); ++i)
		{
			for (uint j = 0; j < b[i].size(); ++j)
			{
				if (b[i][j])
				{
					shape.setFillColor((b[i][j]->is_red() ? sf::Color::Red : sf::Color::Black));
					double x = (j * board_space / num_vlines) + left_border;
					double y  = (i * board_space / num_hlines) + top_border;
					shape.setPosition(x - radius, y - radius);
					window->draw(shape);
				}
			}
		}
	}
	
	void Display::draw_board()
	{
		// Background Color
		window->clear(brown);

		// Board 
		sf::RectangleShape rectangle(sf::Vector2f(width - (left_border * 2), height - (top_border * 2)));
		rectangle.setPosition(left_border, top_border);
		rectangle.setFillColor(wood);
		rectangle.setOutlineThickness(3);
		rectangle.setOutlineColor(sf::Color::Black);
		window->draw(rectangle);

	}

	void Display::draw_lines()
	{
			double board_space = height - (top_border * 2);

			// note:
			// Because lines only serve visual purposes, object reuse is okay

			// horizontal lines
			sf::RectangleShape hline(sf::Vector2f(height - (top_border * 2), 3));
			hline.setFillColor(sf::Color::Black);
			for (int i = 1; i <= num_hlines; ++i)
			{
				hline.setPosition(left_border, (i * (board_space / num_hlines)) + top_border);
				window->draw(hline);
			}

			// vertical lines
			// TODO: 2.2 does not matter because it dictate the length, not position
			sf::RectangleShape vline(sf::Vector2f((width - (2.2 * board_space / num_hlines)) / 2, 3));
			vline.setFillColor(sf::Color::Black);
			vline.rotate(90);
			for (int i = 1; i < num_vlines; ++i)
			{
				// top-half
				vline.setPosition((i * (board_space) / num_vlines) + left_border, top_border);
				window->draw(vline);

				// bottom half
				vline.setPosition((i * (board_space) / num_vlines) + left_border, 
									(5 * (board_space / num_hlines)) + top_border);
				window->draw(vline);
			}

			// cross lines

			// top
			sf::RectangleShape cline_one(sf::Vector2f(board_space / 3, 3));
			cline_one.setFillColor(sf::Color::Black);
			cline_one.setPosition((3 * board_space / num_vlines) + left_border, top_border);
			cline_one.rotate(45);
			window->draw(cline_one);

			sf::RectangleShape cline_two(sf::Vector2f(board_space / 3, 3));
			cline_two.setFillColor(sf::Color::Black);
			cline_two.setPosition((5 * board_space / num_vlines) + left_border, top_border);
			cline_two.rotate(135);
			window->draw(cline_two);

			// bottom
			sf::RectangleShape cline_three(sf::Vector2f(board_space / 3, 3));
			cline_three.setFillColor(sf::Color::Black);
			cline_three.setPosition((3 * board_space / num_vlines) + left_border, 
									 (7 * board_space / num_hlines) + top_border);
			cline_three.rotate(45);
			window->draw(cline_three);

			sf::RectangleShape cline_four(sf::Vector2f(board_space / 3, 3));
			cline_four.setFillColor(sf::Color::Black);
			cline_four.setPosition((5 * board_space / num_vlines) + left_border, 
									 (7 * board_space / num_hlines) + top_border);
			cline_four.rotate(135);
			window->draw(cline_four);
	}

	void Display::init()
	{
		while (window->isOpen())
		{
			sf::Event event;
			while (window->pollEvent(event))	
			{
				// close window by clicking "x" 
				if (event.type == sf::Event::Closed)
					window->close();	

				// if click and move and valid, redraw the piece
			}

			draw_board();
			draw_lines();
			draw_pieces();

			window->display();
		}
	}
}
