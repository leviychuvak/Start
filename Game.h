#ifndef GAME_H
#define GAME_H


#include "Player.h"
#include "Monster.h"

class Game
{
private:
	//Using agregation because player isn't a part of game and Game doesn't control time of life of Player
	Player& player;

private:
	bool fightMonster();
	bool attackMonster(Monster& monster);
	bool attackPlayer(Monster& monster);
	bool tryToFled();

public:
	Game(Player &aPlayer )
		:player(aPlayer)
	{}

	void play();
};

#endif // !GAME_H



