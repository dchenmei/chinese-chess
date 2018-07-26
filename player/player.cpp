#include "player.h"

namespace chinese_chess
{
	void Player::play()
	{	
		bool prev_pressed = false, pressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
		if (pressed && !prev_pressed)
		{
			sf::Vector2i pos = sf::Mouse::getPosition(*window);
			cout << pos.x << " " << pos.y << endl;
	
			// valid click if:
			// - inside window
			// - inside board area
			cout << pos_to_coord(pos).x << " " << pos_to_coord(pos).y <<  endl;
		}

		prev_pressed = pressed; // if 
	}

	sf::Vector2i Player::pos_to_coord(sf::Vector2i pos)
	{
		// TODO: temp hardcode constants
		const int board_x_min = 50, board_y_min = 50, board_x_max = 750, board_y_max = 750;
		//const int river_top = 362, river_bottom = 437;
		const int pos_x = pos.x, pos_y = pos.y;
		
		// TODO: ignore river checking because it might be too sensitive
		// if not in boara or between riverd, return (-1, -1)
		if ((pos_x > board_x_max || pos_x < board_x_min 
			|| pos_y > board_y_max || pos_y < board_y_min)) //|| (pos_y > river_top && pos_y < river_bottom))
		{
			return sf::Vector2i(-1, -1);
		}

		// TODO: document the math
		// else convert to coordinates
		int new_x = ((pos_x - 50) * 9) / 700;
		int new_y = ((pos_y - 50) * 8) / 700;
		return sf::Vector2i(new_x, new_y);	
	}
}
