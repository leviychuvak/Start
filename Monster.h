#ifndef MONSTER_H
#define MONSTER_H

#include <vector>
#include "Creature.h"
class Monster :
    public Creature
{
public:
	//structure that storage all information about one single monster
	struct MonsterData
	{
		std::string name;
		char symbol;
		int health;
		int damage;
		int gold;
	};

	//Types of monsters
	enum class Type
	{
		DRAGON,
		ORC,
		SLIME,
		MAX_TYPES
	};

private:
	//Vector that storage information about all monsters
	static std::vector<MonsterData> monsterData;

public:
	Monster(Type type);

	static Type getRandomMonster();
};

int getRandomNumber(int min, int max);

#endif // !MONSTER_H



