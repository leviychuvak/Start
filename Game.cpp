#include <iostream>

#include "Game.h"
#include "Player.h"
#include "Monster.h"

Game::Game(Player& aPlayer)
	:player(aPlayer)
{}

void Game::play() {
	//The game continues until the player wins or dies
	while (!player.hasWon() && fightMonster())
	{}

	if(player.hasWon()) std::cout << "You won the game with " << player.getGold() << " gold!\n";
}

//Returns true if player killed monster or successfuly fleded and false if player dies
bool Game::fightMonster()
{
	//Generate one random monster
	Monster monster = Monster::getRandomMonster();

	std::cout << "\n\nYou have encountered a " << monster.getName() << " (" << monster.getSymbol() << ")." << std::endl;
	char choise{};

	//The fight continues until player or monster dies or player fleds
	while (true)
	{
		//Player choose the action
		do
		{
			std::cout << "(R)un or (F)ight: ";
			std::cin >> choise;
			std::cin.ignore(32767, '\n');
		} while (choise != 'r' && choise != 'f');

		switch (choise)
		{
		case 'r':
			//Player tries to fled
			if (tryToFled()) 
			{
				//Player doesn't fight with monster
				std::cout << "You successfully fled.";
				return true;
			}
			else
			{
				//The escape failed
				if (attackPlayer(monster)) 
				{
					return false;
				}
			}
			break;
		case 'f':
			//First the player attacks, then the monster
			if (attackMonster(monster))
			{
				return true;
			}
			if (attackPlayer(monster)) 
			{
				return false;
			}
			break;
		default:
			break;
		}
	}
	
}

//Returns true if player kills monster and returns false in other cases
bool Game::attackMonster(Monster& monster)
{
	//Monster gets damage
	monster.reduceHealth(player.getDamage());
	std::cout << "You hit the " << monster.getName() << " for " << player.getDamage() << " damage." << std::endl;
	
	//If monster dies player wins the fight
	if (monster.isDead())
	{
		std::cout << "You killed the " << monster.getName() << "." << std::endl;
		player.levelUp();
		player.addGold(monster.getGold());
		std::cout << "You are now level " << player.getLevel() << ".\n";
		std::cout << "You found " << monster.getGold() << " gold.\n";
		
		return true;
	}

	//If monster doesn' die the fight continues
	return false;
}

//Returns true if monster kills player and returns false in other cases
bool Game::attackPlayer( Monster& monster)
{
	//Player gets damage
	player.reduceHealth(monster.getDamage());
	std::cout << "The " << monster.getName() << " hit you for " << monster.getDamage() << "." << std::endl;
	
	//If player dies he loose the fight
	if (player.isDead())
	{
		std::cout << "You died at level " << player.getLevel() << " and with " << player.getGold() << " gold." << std::endl;
		std::cout << "Too bad you can't take it with you!" << std::endl;
		return true;
	}

	//If player doesn' die the fight continues
	return false;
}

//Trying to feld with chanse 50/50
bool Game::tryToFled() const{
	return rand() % 2;
}