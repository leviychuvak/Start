#ifndef MONSTER_H
#define MONSTER_H

#include <array>
#include "Creature.h"
class Monster :
    public Creature
{
public:
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
	static const std::array<CreatureData, static_cast<size_t>(Type::MAX_TYPES)> monsterData;

public:
	explicit Monster(Type type);

	static Monster getRandomMonster();
};

#endif // !MONSTER_H



