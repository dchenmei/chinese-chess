#include "display.h"

namespace chinese_chess
{
	void Display::draw_pieces()
	{
		const double radius = 30, board_space = height - (top_border * 2);
		sf::CircleShape shape(radius);
		sf::Texture texture;
		auto b = board->get_board();
		// walk through board and draw the pieces' position w/ offset in mind
		for (uint i = 0; i < b.size(); ++i)
		{
			for (uint j = 0; j < b[i].size(); ++j)
			{
				if (b[i][j])
				{
					// load appropriate image depending on piece
					switch(b[i][j]->get_id())
					{
						case general:
							texture.loadFromFile((b[i][j]->is_red() ? 
												  "graphics/img/general-red.png" :
												  "graphics/img/general-black.png"));
							break;
					
						case advisor:
							texture.loadFromFile((b[i][j]->is_red() ? 
												  "graphics/img/advisor-red.png" :
												  "graphics/img/advisor-black.png"));
							break;
		
						case elephant:
							texture.loadFromFile((b[i][j]->is_red() ? 
												  "graphics/img/elephant-red.png" :
												  "graphics/img/elephant-black.png"));
							break;
						case horse:
							texture.loadFromFile((b[i][j]->is_red() ? 
												  "graphics/img/horse-red.png" :
												  "graphics/img/horse-black.png"));
							break;
						case chariot:
							texture.loadFromFile((b[i][j]->is_red() ? 
												  "graphics/img/chariot-red.png" :
												  "graphics/img/chariot-black.png"));
							break;
						case cannon:
							texture.loadFromFile((b[i][j]->is_red() ? 
												  "graphics/img/cannon-red.png" :
												  "graphics/img/cannon-black.png"));
							break;
						case soldier:
							texture.loadFromFile((b[i][j]->is_red() ? 
												  "graphics/img/soldier-red.png" :
												  "graphics/img/soldier-black.png"));
							break;
		
						default:
							return; // TODO: maybe throw some type of error

					}
					shape.setTexture(&texture);

					// if selected, highlight
					if (b[i][j]->is_selected())
						shape.setFillColor((b[i][j]->is_red() ? 
											sf::Color::Red : 
											sf::Color(128, 128, 128, 255)));
						
					//shape.setOutlineColor((b[i][j]->is_red() ? sf::Color::Red : sf::Color::Black));
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
			sf::RectangleShape cline(sf::Vector2f(board_space / 3, 3));
			cline.setFillColor(sf::Color::Black);

			// "\" 
			cline.rotate(42); // 45 is not straight?
			cline.setPosition((3 * board_space / num_vlines) + left_border, top_border);
			window->draw(cline);
			cline.setPosition((3 * board_space / num_vlines) + left_border, 
									 (7 * board_space / num_hlines) + top_border);
			window->draw(cline);

			// "/"
			cline.rotate(96); // 90 is not straight?
			cline.setPosition((5 * board_space / num_vlines) + left_border, top_border);
			window->draw(cline);
			cline.setPosition((5 * board_space / num_vlines) + left_border, 
									 (7 * board_space / num_hlines) + top_border);
			window->draw(cline);
	}

	void Display::draw()
	{
		sf::Event event;
		if (window->pollEvent(event))
		{
			// close window by clicking "x" 
			if (event.type == sf::Event::Closed)
				window->close();	

		}

		draw_board();
		draw_lines();
		draw_pieces();
		window->display();
	}
}
