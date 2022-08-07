#include "Average.h"
#include <cassert>

int Average::calculateAverage() const {
	assert(m_counter > 0 && "No elements!!!"); //Check for emptiness 
	return m_sum / m_counter;
}

Average& Average::operator+=(const int aNumber) {
	m_sum += aNumber;	//Add number to total sum
	++m_counter;		//increment counter
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Average& average) {
	out << average.calculateAverage();
	return out;
}