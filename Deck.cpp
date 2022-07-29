#include "Deck.h"
#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <cassert>

Deck::Deck()
{
	for (int i = 0; i < static_cast<int>(Card::CardRank::MAX_RANKS); ++i)
	{
		for (int j = 0; j < static_cast<int>(Card::CardSuit::MAX_SUITS); ++j)
		{
			mDeck[static_cast<int>(Card::CardSuit::MAX_SUITS) * i + j] = Card(static_cast<Card::CardRank>(i), static_cast<Card::CardSuit>(j));
		}
	}
}

void Deck::swapCard(Card& a, Card& b)
{
	Card temp = a;
	a = b;
	b = temp;
}

int Deck::getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); // use static, because this value should be calculated only once
	// Evenly distribute the calculation of a value from our range
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void Deck::printDeck() const
{
	for (const auto& card : mDeck)
	{
		card.printCard();
		std::cout << ' ';
	}

	std::cout << std::endl;
}

void Deck::shuffleDeck()
{
	// Look over each card in the deck
	for (int index = 0; index < MAX_CARD_COUNT; ++index)
	{
		// Choose any random card
		int swapIndex = getRandomNumber(0, 51);
		// Swap with our current card
		swapCard(mDeck[index], mDeck[swapIndex]);
	}
	m_cardIndex = 0;
}

const Card& Deck::dealCard() {
	assert(m_cardIndex < MAX_CARD_COUNT || "Deck is empty!!!");
	return mDeck[m_cardIndex++];
}