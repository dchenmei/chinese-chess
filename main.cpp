#include "pieces.h"
#include "board.h"
#include "display.h"
#include "player.h"

using namespace chinese_chess;

int main()
{
	// initialize model, view, controller
	auto b = make_shared<Board>();
	auto d = make_shared<Display>(b);
	auto p = make_shared<Player>(b, d->get_window());

	// run game while window is open and generals are alive
	while (d->window_open() && !b->game_over())
	{
		// b->print(); note: uncomment if need console print
		d->draw();
		p->play();
	}

	// if one general is dead, the game is over, only view not play
	while (d->window_open())
	{
		d->draw();
	}
	
	return 0;
}
