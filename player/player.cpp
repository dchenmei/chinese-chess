#include "player.h"

namespace chinese_chess
{
	void Player::play()
	{	
		bool pressed = sf::Mouse::isButtonPressed(sf::Mouse::Left); // get click if any

		// process click
		if (pressed)
		{
			// get position and convert it to board coordinates
			sf::Vector2i pos = sf::Mouse::getPosition(*window);
			sf::Vector2i coord = pos_to_coord(pos);

			// invalid coordinate, invalidate current click
			if (coord.x == -1 && coord.y == -1)
				return;
		
			// Proceed only if coordinate is valid
			auto b = board->get_board(); // reference of board vector 

			// A piece exist in coordinate and is correct color for current turn
			if (b[coord.y][coord.x] && (b[coord.y][coord.x]->is_red() == red_turn))
			{
				// Select again if:
				// - not selected
				// - double click (unselect)
				if (b[coord.y][coord.x]->is_selected() || !selected)
				{
					b[coord.y][coord.x]->select();
	
					// if currently selected, remember the piece
					selected = b[coord.y][coord.x]->is_selected() ? b[coord.y][coord.x] : nullptr;
				}
			}
			else if (selected) // time to move if a piece is selected 
			{
				int x = selected->get_x(), y = selected->get_y();
				bool moved = board->move(x, y, coord.y - x, coord.x - y); // pass move to board
					
				// if move successful, reset select and switch turns
				if (moved)
				{
					selected->select();
					selected = nullptr;
					red_turn = !red_turn;
				}
			}

			// else not a valid move
		}
	}

	sf::Vector2i Player::pos_to_coord(sf::Vector2i pos)
	{
		// TODO: Derive constants from board (model) instead of hardcoding
		const int board_x_min = 40, board_y_min = 40, board_x_max = 760, board_y_max = 760;
		const int pos_x = pos.x, pos_y = pos.y;
		
		// if selection is outside of board, then return (-1, -1)
		if ((pos_x > board_x_max || pos_x < board_x_min || pos_y > board_y_max || pos_y < board_y_min)) 
		{
			return sf::Vector2i(-1, -1);
		}

		// TODO: same as above
		// else convert to coordinates
		int new_x = ((pos_x - 50) * 8) / 700;
		int new_y = ((pos_y - 50) * 9) / 700;
		return sf::Vector2i(new_x, new_y);	
	}
}
