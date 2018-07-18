#ifndef DISPLAY_H
#define DISPLAY_H

#include <SFML/Graphics.hpp>
#include "board.h"

namespace chinese_chess
{
	class Display
	{
	  public:
		Display(Board b): board(b) {}
		void init();

	  private:
		const int width = 800;
		const int height = 600;
		Board board;
	};
}

#endif
