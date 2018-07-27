#include "player.h"

namespace chinese_chess
{
	void Player::play()
	{	
		bool pressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);
		if (pressed)
		{
			sf::Vector2i pos = sf::Mouse::getPosition(*window);
	
			// valid click if:
			// - inside window
			// - inside board area
			sf::Vector2i coord = pos_to_coord(pos);

			// invalid
			if (coord.x == -1 && coord.y == -1)
				return;
		
			auto b = board->get_board();
			// if there is a piece
			// TODO: check to prevent selecting enemy piece
			// only one select at a time unless unselecting a piece

			// Proceed only if piece is valid and of the right color
			if (b[coord.y][coord.x] && (b[coord.y][coord.x]->is_red() == red_turn))
			{
				if (b[coord.y][coord.x]->is_selected() || !selected)
				{
					b[coord.y][coord.x]->select();
					selected = !selected;
				}
			}
		}
	}

	sf::Vector2i Player::pos_to_coord(sf::Vector2i pos)
	{
		// TODO: temp hardcode constants
		// note: they don't match up coordinates because sensitivity bug
		const int board_x_min = 40, board_y_min = 40, board_x_max = 760, board_y_max = 760;
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
		int new_x = ((pos_x - 50) * 8) / 700;
		int new_y = ((pos_y - 50) * 9) / 700;
		return sf::Vector2i(new_x, new_y);	
	}
}
