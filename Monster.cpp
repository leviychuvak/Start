#include "Monster.h"
#include <cstdlib> // for rand() 

namespace {
	// Generate a random number between min and max
	int getRandomNumber(int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
		// Evenly distribute the generation of a value from a range
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}

	int toInt(Monster::Type type) { return static_cast<int>(type); }
	Monster::Type toType(int index) { return static_cast<Monster::Type>(index); }
}


Monster::Monster(Type type)
	:Creature(monsterData.at(toInt(type)))
{}

constexpr std::array<Monster::CreatureData, static_cast<size_t>(Monster::Type::MAX_TYPES)> Monster::monsterData = {
	CreatureData{.name = "dragon", .symbol = 'D', .health = 20, .damage = 4, .gold = 100},
	CreatureData{.name = "orc", .symbol = 'o', .health = 4, .damage = 2, .gold = 25},
	CreatureData{.name = "slime", .symbol = 's', .health = 1, .damage = 1, .gold = 10}
};

//Returns one random monster from all possible
Monster Monster::getRandomMonster() {
	return Monster(toType(getRandomNumber(0, toInt(Type::MAX_TYPES) - 1)));
}