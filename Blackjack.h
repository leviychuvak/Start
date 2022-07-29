#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Deck.h"

class Blackjack
{
private:
	Deck deck;

private:
	char getPlayerChoice() const;

	bool playBlackjack();

	bool playAgain() const;

public:
	Blackjack();

	void play();
};

#endif // !BLACKJACK_H



