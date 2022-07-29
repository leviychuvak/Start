#pragma once
#include "Monster.h"

class MonsterGenerator
{
private:
	// ���������� ��������� ����� ����� min � max (������������).
	// ��������������, ��� srand() ��� ��� ������ 
	static int getRandomNumber(int min, int max);

public:
	static Monster generateMonster();
};

