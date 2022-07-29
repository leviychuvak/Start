#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Deck.h"

class Blackjack
{
private:
	Deck deck;

	char getPlayerChoice();

	bool playBlackjack();

	bool playAgain();

public:
	Blackjack();

	void play();
};

#endif // !BLACKJACK_H



