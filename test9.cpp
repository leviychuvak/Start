#include <iostream>
#include <cassert>
#include "Average.h"
#include "IntArray.h"
#include "FixedPoint.h"

void task2() {
	Average avg;

	avg += 5;
	std::cout << avg << '\n'; // 5 / 1 = 5

	avg += 9;
	std::cout << avg << '\n'; // (5 + 9) / 2 = 7

	avg += 19;
	std::cout << avg << '\n'; // (5 + 9 + 19) / 3 = 11

	avg += -9;
	std::cout << avg << '\n'; // (5 + 9 + 19 - 9) / 4 = 6

	(avg += 7) += 11; // выполнение цепочки операций
	std::cout << avg << '\n'; // (5 + 9 + 19 - 9 + 7 + 11) / 6 = 7

	Average copy = avg;
	std::cout << copy << '\n';
}

void task3() {
	IntArray a = fillArray();
	std::cout << a << '\n';

	IntArray b(1);
	a = a;
	b = a;

	std::cout << b << '\n';
}

void task4() {
	SomeTest();

	FixedPoint a(-0.48);
	std::cout << a << '\n';

	std::cout << -a << '\n';

	std::cout << "Enter a number: "; // введите 5.678
	std::cin >> a;

	std::cout << "You entered: " << a << '\n';
}

int main()
{
	//task2();

	//task3();

	task4();

	return 0;
}
