#pragma once
#include "Monster.h"

class MonsterGenerator
{
private:
	// Генерируем случайное число между min и max (включительно).
	// Предполагается, что srand() уже был вызван 
	static int getRandomNumber(int min, int max);

public:
	static Monster generateMonster();
};

