#include "Player.h"

Player::Player(const std::string& aName)
	:Creature(CreatureData{ .name = aName, .symbol = '@', .health = 10, .damage = 1, .gold = 0 })
{}

//New level increases health and damage
void Player::levelUp()
{
	++level;
	++cd.damage;
	++cd.health;
}

//To win player needs get 20th level
bool Player::hasWon() const { return level >= 20; }