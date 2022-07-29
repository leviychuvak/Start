#include "Monster.h"

Monster::Monster(MonsterType aType, std::string aName, int aHealth)
	:type(aType), name(std::move(aName)), health(aHealth)
{}

std::string Monster::getTypeString() const {
	switch (this->type)
	{
	case MonsterType::Dragon: return "dragon";
	case MonsterType::Goblin: return "goblin";
	case MonsterType::Ogre: return "ogre";
	case MonsterType::Orc: return "orc";
	case MonsterType::Skeleton: return "skeleton";
	case MonsterType::Troll: return "troll";
	case MonsterType::Vampire: return "vampire";
	case MonsterType::Zombie: return "zombie";
	default: return " ";
	}

	return " ";
}

void Monster::print() const {
	std::cout << this->name << " is the " << this->getTypeString() << " that has " <<
		this->health << " health points.\n";
}