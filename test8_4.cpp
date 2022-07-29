#include "Blackjack.h"

int main()
{
	srand(static_cast<unsigned int>(time(0))); // используем системные часы в качестве стартового значения
	rand(); // пользователям Visual Studio: делаем сброс первого случайного числа

	Blackjack game;

	game.play();

	system("pause");
	return 0;
}
