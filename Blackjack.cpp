#include "Blackjack.h"
#include <iostream>

Blackjack::Blackjack() {
	deck.shuffleDeck();
}

char Blackjack::getPlayerChoice() const
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

	deck.shuffleDeck();
	int playerTotal = 0;
	int dealerTotal = 0;

	// Dealer gets one card
	dealerTotal += deck.dealCard().getCardValue();
	std::cout << "The dealer is showing: " << dealerTotal << '\n';

	// Player gets two cards
	playerTotal += deck.dealCard().getCardValue();
	playerTotal += deck.dealCard().getCardValue();

	std::cout << "You have: " << playerTotal << '\n';

	// If 2 aces immediately fell out
	if (playerTotal > 21)
	{
		return false;
	}

	// Player starts
	while (true)
	{
		char choice = getPlayerChoice();
		if (choice == 's')
			break;

		playerTotal += deck.dealCard().getCardValue();
		std::cout << "You have: " << playerTotal << '\n';

		// Check, if the player has lost
		if (playerTotal > 21)
			return false;
	}

	// If the player hasn't lost (he has not more than 21 points), then the dealer receives cards until he has a total of at least 17 points
	while (dealerTotal < 17)
	{
		dealerTotal += deck.dealCard().getCardValue();
		std::cout << "The dealer now has: " << dealerTotal << '\n';
	}

	// If the dealer has more than 21, then he lost, and the player won
	if (dealerTotal > 21)
		return true;

	return (playerTotal >= dealerTotal);
}

bool Blackjack::playAgain() const
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
		if (playBlackjack())
			std::cout << "You win!\n";
		else
			std::cout << "You lose!\n";
	} while (playAgain());
}