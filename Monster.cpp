#include "Monster.h"


Monster::Monster(MonsterType type, std::string name, int health)
	:type(type), name(name), health(health)
{}

std::string Monster::getTypeString() const {
	switch (this->type)
	{
	case Dragon: return "dragon";
	case Goblin: return "goblin";
	case Ogre: return "ogre";
	case Orc: return "orc";
	case Skeleton: return "skeleton";
	case Troll: return "troll";
	case Vampire: return "vampire";
	case Zombie: return "zombie";
	default: return " ";
	}

	return " ";
}

void Monster::print() const {
	std::cout << this->name << " is the " << this->getTypeString() << " that has " <<
		this->health << " health points.\n";
}