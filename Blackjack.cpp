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

	// ����� �������� ���� �����
	dealerTotal += deck.dealCard().getCardValue();
	std::cout << "The dealer is showing: " << dealerTotal << '\n';

	// ����� �������� ��� �����
	playerTotal += deck.dealCard().getCardValue();
	playerTotal += deck.dealCard().getCardValue();

	std::cout << "You have: " << playerTotal << '\n';

	// ���� ����� ������ 2 ����
	if (playerTotal > 21)
	{
		return false;
	}

	// ����� ��������
	while (true)
	{
		char choice = getPlayerChoice();
		if (choice == 's')
			break;

		playerTotal += deck.dealCard().getCardValue();
		std::cout << "You have: " << playerTotal << '\n';

		// �������, �� �������� �� �����
		if (playerTotal > 21)
			return false;
	}

	// ���� ����� �� �������� (� ���� �� ������ 21 ����), ����� ����� �������� ����� �� ��� ���, ���� � ���� � ����� ����� �� ������ 17 �����
	while (dealerTotal < 17)
	{
		dealerTotal += deck.dealCard().getCardValue();
		std::cout << "The dealer now has: " << dealerTotal << '\n';
	}

	// ���� � ������ ������ 21, �� �� ��������, � ����� �������
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