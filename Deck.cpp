#include "Deck.h"

Deck::Deck()
{
	for (int i = 0; i < Card::MAX_RANKS; i++)
	{
		for (int j = 0; j < Card::MAX_SUITS; j++)
		{
			m_deck[Card::MAX_SUITS * i + j] = Card(static_cast<Card::CardRank>(i), static_cast<Card::CardSuit>(j));
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
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); // используем static, так как это значение нужно вычислить единожды
	// Равномерно распределяем вычисление значения из нашего диапазона
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

void Deck::printDeck() const
{
	for (const auto& card : m_deck)
	{
		card.printCard();
		std::cout << ' ';
	}

	std::cout << '\n';
}

void Deck::shuffleDeck()
{
	// Перебираем каждую карту в колоде
	for (int index = 0; index < 52; ++index)
	{
		// Выбираем любую случайную карту
		int swapIndex = getRandomNumber(0, 51);
		// Меняем местами с нашей текущей картой
		swapCard(this->m_deck[index], this->m_deck[swapIndex]);
	}
	this->m_cardIndex = 0;
}

const Card& Deck::dealCard() {
	assert(this->m_cardIndex < 52 || "Deck is empty!!!");
	return this->m_deck[m_cardIndex++];
}