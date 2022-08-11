#ifndef CREATURE_H
#define CREATURE_H

#include <string>
#include <utility>
class Creature
{
protected:
	//structure that storage all information about one single creature
	struct CreatureData
	{
		std::string name;
		char symbol;
		int health;
		int damage;
		int gold;
	};

	CreatureData cd;
public:
	explicit Creature(CreatureData aCreatureData)
		:cd(std::move(aCreatureData))
	{}

	//Getters for all atributes
	const std::string& getName() const { return cd.name; }
	char getSymbol() const { return cd.symbol; }
	int getHealth() const { return cd.health; }
	int getDamage() const { return cd.damage; }
	int getGold() const { return cd.gold; }


	void reduceHealth(int value) { cd.health -= value; }

	bool isDead() const { return cd.health <= 0; }
	
	void addGold(int value) { cd.gold += value; }
};

#endif // !CREATURE_H



