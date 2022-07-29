#include <iostream>
#include "MonsterGenerator.h"

int MonsterGenerator::getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); // ���������� static, ��� ��� ��� �������� ����� ��������� ��������
	// ���������� ������������ ���������� �������� �� ������ ���������
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

Monster MonsterGenerator::generateMonster() {
	static std::string s_names[6]{ "Peter", "Tom", "Victor", "Sam", "Tony", "Joe" };
	return Monster(static_cast<Monster::MonsterType>(getRandomNumber(0, Monster::MAX_MONSTER_TYPES)),
					s_names[getRandomNumber(0, 5)],
					getRandomNumber(1, 100));
}