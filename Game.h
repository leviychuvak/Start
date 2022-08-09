#ifndef GAME_H
#define GAME_H

class Player;
class Monster;

class Game
{
private:
	//Using agregation because player isn't a part of game and Game doesn't control time of life of Player
	Player& player;

private:
	bool fightMonster();
	bool attackMonster(Monster& monster);
	bool attackPlayer(Monster& monster);
	bool tryToFled() const;

public:
	explicit Game(Player& aPlayer);
	void play();
};

#endif // !GAME_H



