#include <iostream>
#include <string>
#include <cstdlib> // for rand() and srand()
#include <ctime> // for time()
#include "Game.h"
#include "Player.h"
#include "Monster.h"

int main()
{
	srand(static_cast<unsigned int>(time(0))); // set system clock value as start number
	rand(); // discard the first result

	std::cout << "Enter your name: ";
	std::string playerName;
	std::cin >> playerName;

	Player p(playerName);
	std::cout << "Welcome, " << p.getName() << ".\n";

	Game game(p);

	game.play();

	system("pause");
	return 0;
}