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
			//window.draw(line);
			double board_space = height - (top_border * 2);
			double num_lines = 9; // TODO: make this clear that one line is overlayed
			for (int i = 1; i <= num_lines; ++i)
			{
				sf::RectangleShape line(sf::Vector2f(width - (left_border * 2), 3));
				line.setFillColor(sf::Color::Black);
				line.setPosition(left_border, (i * (board_space / num_lines)) + top_border);
				window.draw(line);
			}

			window.display();
		}
	}
}
