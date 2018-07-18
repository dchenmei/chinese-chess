#include "display.h"

namespace chinese_chess
{
	void Display::init()
	{
		sf::RenderWindow window(sf::VideoMode(width, height), "Chinese Chess");
		sf::RectangleShape rectangle(sf::Vector2f(width - (top_border * 2), height - (left_border * 2)));
		rectangle.setPosition(left_border, top_border);
		rectangle.setFillColor(wood);

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
			window.display();
		}
	}
}
