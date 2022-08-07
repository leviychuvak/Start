#ifndef FIXEDPOINT_H
#define FIXEDPOINT_H

#include <cstdint>
#include <iostream>

class FixedPoint
{
private:
	int16_t m_integerPart{ 0 };
	int8_t m_fractionalPart{ 0 };
public:
	explicit FixedPoint(int16_t aInt = 0, int8_t aFract = 0);
	explicit FixedPoint(double fp);

	int16_t getIntegerPart() const;
	int8_t getFractionalPart() const;

	operator double() const;

	friend std::ostream& operator<<(std::ostream& out, const FixedPoint& fp);
	friend std::istream& operator>>(std::istream& in, FixedPoint& fp);
	friend FixedPoint operator-(const FixedPoint& fp);
};

void SomeTest();

#endif // !FIXEDPOINT_H



