#include "Blackjack.h"

Blackjack::Blackjack() {
	this->deck.shuffleDeck();
}

char Blackjack::getPlayerChoice()
{
	std::cout << "(h) to hit, or (s) to stand: ";
	char choice;
	do
	{
		std::cin >> choice;
	} while (choice != 'h' && choice != 's');

	return choice;
}

bool Blackjack::playBlackjack() {
	int playerTotal = 0;
	int dealerTotal = 0;

	// Дилер получает одну карту
	dealerTotal += deck.dealCard().getCardValue();
	std::cout << "The dealer is showing: " << dealerTotal << '\n';

	// Игрок получает две карты
	playerTotal += deck.dealCard().getCardValue();
	playerTotal += deck.dealCard().getCardValue();

	std::cout << "You have: " << playerTotal << '\n';

	// Если сразу выпало 2 туза
	if (playerTotal > 21)
	{
		return false;
	}

	// Игрок начинает
	while (true)
	{
		char choice = getPlayerChoice();
		if (choice == 's')
			break;

		playerTotal += deck.dealCard().getCardValue();
		std::cout << "You have: " << playerTotal << '\n';

		// Смотрим, не проиграл ли игрок
		if (playerTotal > 21)
			return false;
	}

	// Если игрок не проиграл (у него не больше 21 очка), тогда дилер получает карты до тех пор, пока у него в сумме будет не меньше 17 очков
	while (dealerTotal < 17)
	{
		dealerTotal += deck.dealCard().getCardValue();
		std::cout << "The dealer now has: " << dealerTotal << '\n';
	}

	// Если у дилера больше 21, то он проиграл, а игрок выиграл
	if (dealerTotal > 21)
		return true;

	return (playerTotal >= dealerTotal);
}

bool Blackjack::playAgain()
{
	std::cout << "\n\nDo you want to play again (y/n)? ";
	char choice;
	do
	{
		std::cin >> choice;
	} while (choice != 'y' && choice != 'n');
	std::cout << "\n";

	return choice == 'y' ? true : false;
}

void Blackjack::play() {
	do
	{
		if (this->playBlackjack())
			std::cout << "You win!\n";
		else
			std::cout << "You lose!\n";
	} while (playAgain());
}