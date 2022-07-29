#ifndef DECK_H
#define DECK_H


#include <array>
#include "Card.h"

class Deck
{
private:
	static constexpr size_t MAX_CARD_COUNT = 52;
	std::array<Card, MAX_CARD_COUNT> mDeck;
	int m_cardIndex = 0;
	
private:
	static void swapCard(Card& a, Card& b);

	// Generate random number between min and max (inclusive).
	// Supposed, that srand() has been called
	static int getRandomNumber(int min, int max);

public:
	Deck();

	void printDeck() const;

	void shuffleDeck();

	const Card& dealCard();
};

#endif // !DECK_H



