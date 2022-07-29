#ifndef DECK_H
#define DECK_H

#include <array>
#include <ctime> // для time()
#include <cstdlib> // для rand() и srand()
#include <cassert>
#include "Card.h"

class Deck
{
private:
	std::array<Card, 52> m_deck;
	int m_cardIndex = 0;

	static void swapCard(Card& a, Card& b);

	// Генерируем случайное число между min и max (включительно).
	// Предполагается, что srand() уже был вызван
	static int getRandomNumber(int min, int max);

public:
	Deck();

	void printDeck() const;

	void shuffleDeck();

	const Card& dealCard();
};

#endif // !DECK_H



