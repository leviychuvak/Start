#ifndef AVERAGE_H
#define AVERAGE_H

#include <iostream>

class Average
{
private:
	int32_t m_sum = 0;		//Sum of numbers
	int8_t m_counter = 0;	//Count of numbers

private:
	int calculateAverage() const;

public:
	Average() :m_sum(0), m_counter(0) {}

	Average& operator+=(int aNumber);

	friend std::ostream& operator<<(std::ostream& out, const Average& average);

};

#endif // !AVERAGE_H

