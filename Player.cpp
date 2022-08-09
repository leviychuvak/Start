#include "Player.h"

//New level increases health and damage
void Player::levelUp()
{
	++level;
	++damage;
	++health;
}

//To win player needs get 20th level
bool Player::hasWon() { return level >= 20; }