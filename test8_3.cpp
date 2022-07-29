#include <iostream>
#include <ctime> // для time()
#include <cstdlib> // для rand() и srand()
#include "Monster.h"
#include "MonsterGenerator.h"

int main()
{
	srand(static_cast<unsigned int>(time(0))); // используем системные часы в качестве стартового значения
	rand(); // пользователям Visual Studio: делаем сброс первого случайного числа

	Monster m = MonsterGenerator::generateMonster();
	m.print();

    system("pause");
    return 0;
}
