#include <SFML/Graphics.hpp>
#include "board.h"
#include <memory>

using std::shared_ptr;

namespace chinese_chess
{
	class Display
	{
	  public:
		Display(Board b): board(b), window(sf::VideoMode(width, height), "WInDOW") {}
		void init();

	  private:
		const int width = 800;
		const int height = 600;
		Board board;
		sf::RenderWindow window;
	};
}
