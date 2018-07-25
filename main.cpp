#include "pieces.h"
#include "board.h"
#include "display.h"
#include "player.h"

using namespace chinese_chess;

int main()
{
	auto b = make_shared<Board>();
	auto d = make_shared<Display>(b);
	auto p = make_shared<Player>(b, d->get_window());

	// run game while window is open basically
	while (d->window_open())
	{
		// b->print(); note: uncomment if need console print
		d->init();
		p->play();
	}
	
	return 0;
}
