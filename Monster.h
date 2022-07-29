#pragma once
#include <iostream>
class Monster
{
public:
    enum MonsterType
    {
        Dragon,
        Goblin,
        Ogre,
        Orc,
        Skeleton,
        Troll,
        Vampire,
        Zombie,
        MAX_MONSTER_TYPES
    };

private:
    MonsterType type;
    std::string name;
    int health;

    std::string getTypeString() const;

public:
    Monster(MonsterType type, std::string name, int health);
    void print() const;
};

