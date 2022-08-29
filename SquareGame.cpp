#include "SquareGame.h"

#include <iostream>
#include <string_view>
#include <algorithm> //for std::min_element
#include <cmath> //for std::abs()

namespace {
	// Generate a random number between min and max
	int getRandomNumber(int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
		// Evenly distribute the generation of a value from a range
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}

	int getInt(std::string_view request = "") {
		while (true) // the loop continues until the user enters the correct value
		{
			if(!request.empty())
				std::cout << request;
			int a{};
			std::cin >> a;

			// Checking for previous extraction
			if (std::cin.fail()) // if the previous extraction failed,
			{
				std::cin.clear(); // then return cin to 'normal' mode
				std::cin.ignore(32767, '\n'); // and remove the values of the previous input from the input buffer
				std::cout << "Oops, that input is invalid.  Please try again.\n";
			}
			else
			{
				std::cin.ignore(32767, '\n'); // removing extra charecters

				return a;
			}
		}
	}
}

void SquareGame::initializeNumbers(int start, int count) {
	int randBias = getRandomNumber(MIN_BIAS, MAX_BIAS);

	for (size_t i = 0; i < count; ++i, ++start)
	{
		m_numbers.push_back(start * start * randBias);
	}
	std::cout << "I generated " << count << " square numbers. Do you know what each number is after multiplying it by " << randBias << "?" << std::endl;
}

bool SquareGame::tryToGuess() {
	//get user input
	int guess{ getInt() };

	//trying to find user's number
	auto gPtr{ std::find_if(m_numbers.begin(), m_numbers.end(),
		[guess](int number) {
			return guess == number;
		}) };

	//if number was found
	if (gPtr != m_numbers.end()) {
		m_numbers.erase(gPtr); //erase number from the range

		//if it was the last number in the range
		if (m_numbers.size() > 0)
			std::cout << "Nice! " << m_numbers.size() << " number(s) left." << std::endl;
		else std::cout << "Nice! You found all numbers, good job!" << std::endl;

		return true;
	}
	//if number was not found
	else
	{
		std::cout << guess << " is wrong!";

		//looking for the nearest number in range to user's number
		auto nearest{ std::min_element(m_numbers.begin(), m_numbers.end(),
		[guess](const auto& lhs, const auto& rhs)
		{
			return std::abs(guess - lhs) < std::abs(guess - rhs);
		}
		) };
		//if the nearest number does not differ by more than 4 units from user's number
		if (std::abs(guess - *nearest) <= MAX_DEVITATION) std::cout << "Try " << *nearest << " next time.";
		std::cout << std::endl;
	}

	return false;

	
}

void SquareGame::play() {

	int startValue = { getInt("Start where? ") };

	int count = { getInt("How many? ") };

	initializeNumbers(startValue, count);

	while (m_numbers.size() > 0) {
		if (!tryToGuess()) break;
	}
}