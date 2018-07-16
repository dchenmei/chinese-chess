#include "display.h"

namespace chinese_chess
{
	void Display::init()
	{
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))	
			{
				if (event.type == sf::Event::Closed)
					window.close();	
			}

			window.clear();
			window.display();
		}
	}
}
