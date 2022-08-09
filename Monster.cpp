#include "Monster.h"
#include <cstdlib> // for rand() 

// Generate a random number between min and max
int getRandomNumber(int min, int max) 
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	// Evenly distribute the generation of a value from a range
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

Monster::Monster(Type type)
	:Creature(monsterData.at(static_cast<int>(type)).name,
		monsterData.at(static_cast<int>(type)).symbol,
		monsterData.at(static_cast<int>(type)).health,
		monsterData.at(static_cast<int>(type)).damage,
		monsterData.at(static_cast<int>(type)).gold)
{}

std::vector<Monster::MonsterData> Monster::monsterData = {
	{ "dragon", 'D', 20, 4, 100 },
	{ "orc", 'o', 4, 2, 25 },
	{ "slime", 's', 1, 1, 10 }
};

//Returns one random monster from all possible
 Monster::Type Monster::getRandomMonster() {
	return static_cast<Monster::Type>(getRandomNumber(0, static_cast<int>(Monster::Type::MAX_TYPES) - 1));
}