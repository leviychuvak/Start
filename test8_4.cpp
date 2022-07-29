#include "Blackjack.h"
#include <ctime> // for time()

int main()
{
	srand(static_cast<unsigned int>(time(0))); // use system clock for starting value
	rand(); //  Visual Studio users: reset the first random number
	Blackjack game;

	game.play();

	system("pause");
	return 0;
}
