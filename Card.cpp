#include "Card.h"
#include <iostream>

Card::Card(CardRank rank, CardSuit suit)
	: m_rank(rank), m_suit(suit)
{}

void Card::printCard() const
{
	switch (m_rank)
	{
	case CardRank::RANK_2:		std::cout << '2'; break;
	case CardRank::RANK_3:		std::cout << '3'; break;
	case CardRank::RANK_4:		std::cout << '4'; break;
	case CardRank::RANK_5:		std::cout << '5'; break;
	case CardRank::RANK_6:		std::cout << '6'; break;
	case CardRank::RANK_7:		std::cout << '7'; break;
	case CardRank::RANK_8:		std::cout << '8'; break;
	case CardRank::RANK_9:		std::cout << '9'; break;
	case CardRank::RANK_10:		std::cout << 'T'; break;
	case CardRank::RANK_JACK:	std::cout << 'J'; break;
	case CardRank::RANK_QUEEN:	std::cout << 'Q'; break;
	case CardRank::RANK_KING:	std::cout << 'K'; break;
	case CardRank::RANK_ACE:	std::cout << 'A'; break;
	}

	switch (m_suit)
	{
	case CardSuit::SUIT_CLUB:		std::cout << 'C'; break;
	case CardSuit::SUIT_DIAMOND:	std::cout << 'D'; break;
	case CardSuit::SUIT_HEART:		std::cout << 'H'; break;
	case CardSuit::SUIT_SPADE:		std::cout << 'S'; break;
	}
}

int Card::getCardValue() const
{
	switch (m_rank)
	{
	case CardRank::RANK_2:		return 2;
	case CardRank::RANK_3:		return 3;
	case CardRank::RANK_4:		return 4;
	case CardRank::RANK_5:		return 5;
	case CardRank::RANK_6:		return 6;
	case CardRank::RANK_7:		return 7;
	case CardRank::RANK_8:		return 8;
	case CardRank::RANK_9:		return 9;
	case CardRank::RANK_10:		return 10;
	case CardRank::RANK_JACK:	return 10;
	case CardRank::RANK_QUEEN:	return 10;
	case CardRank::RANK_KING:	return 10;
	case CardRank::RANK_ACE:	return 11;
	}

	return 0;
}