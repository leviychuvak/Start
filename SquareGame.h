#ifndef SQUAREGAME_H
#define SQUAREGAME_H

#include <vector>

class SquareGame
{
private:
	std::vector<int> m_numbers{};
	static constexpr size_t MAX_BIAS = 4;
	static constexpr size_t MIN_BIAS = 2;
	static constexpr size_t MAX_DEVITATION = 4;

private:
	void initializeNumbers(int start, int count);

	bool tryToGuess();

public:
	void play();

	SquareGame() = default;
};


#endif // !SQUAREGAME_H

