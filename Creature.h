#ifndef CREATURE_H
#define CREATURE_H

#include <string>
class Creature
{
protected:
	std::string name{};
	char symbol{};
	int health{};
	int damage{};
	int gold{};

public:
	Creature(const std::string &aName, char aSymbol, int aHealth, int aDamage, int aGold)
		:name(aName), symbol(aSymbol), health(aHealth), damage(aDamage), gold(aGold)
	{}

	//Getters for all atributes
	const std::string& getName() const	{ return name; }
	char getSymbol() const				{ return symbol; }
	int getHealth() const				{ return health; }
	int getDamage() const				{ return damage; }
	int getGold() const					{ return gold; }


	void reduceHealth(int value) { health -= value; }

	bool isDead() const { return health <= 0; }
	
	void addGold(int value) { gold += value; }
};

#endif // !CREATURE_H



