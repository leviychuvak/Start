#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"
class Player :
    public Creature
{
private:
    int level{ 1 }; //Starting value

public:
    Player(const std::string& aName = "Player")
        :Creature(aName, '@', 10, 1, 0)
    {}

    int getLevel() const { return level; }

    void levelUp();
    bool hasWon();

};

#endif // !PLAYER_H



