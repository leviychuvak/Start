#include "FixedPoint.h"

FixedPoint::FixedPoint(int16_t aInt, int8_t aFract)
	: m_integerPart(aInt), m_fractionalPart(aFract)
{
	//Handling the case when the decimal part is more than 99
	if (aFract > 99) {
		m_integerPart += aFract / 99;
		m_fractionalPart = aFract % 99;
	}

	//When  one or both parts is negative the whole number must be negative
	if (m_integerPart < 0 || m_fractionalPart < 0) {
		if (m_integerPart > 0) m_integerPart = -m_integerPart;
		if (m_fractionalPart > 0) m_fractionalPart = -m_fractionalPart;
 	}
}

FixedPoint::FixedPoint(double fp)
	:m_integerPart(static_cast<int16_t>(fp)),									//Use type casting to discard the fractional part
	m_fractionalPart(static_cast<int8_t>(round((fp - m_integerPart) * 100)))	//Use round() to get rid of the rounding error
{}

FixedPoint::operator double() const{
	return m_integerPart + static_cast<double>(m_fractionalPart) / 100;
}

std::ostream& operator<<(std::ostream& out, const FixedPoint& fp) {
	out << static_cast<double>(fp);

	return out;
}

std::istream& operator>>(std::istream& in, FixedPoint& fp) {
	double input{};
	in >> input;
	fp = FixedPoint(input);

	return in;
}

bool operator==(const FixedPoint& fp1, const FixedPoint& fp2) {
	return (fp1.m_integerPart == fp2.m_integerPart && fp1.m_fractionalPart == fp2.m_fractionalPart);
}

FixedPoint operator+(const FixedPoint& fp1, const FixedPoint& fp2) {
	return FixedPoint(static_cast<double>(fp1) + static_cast<double>(fp2));
}

FixedPoint operator-(const FixedPoint& fp) {
	return FixedPoint(-fp.m_integerPart, -fp.m_fractionalPart);
}

void SomeTest()
{
	std::cout << std::boolalpha;
	std::cout << (FixedPoint(0.75) + FixedPoint(1.23) == FixedPoint(1.98)) << '\n'; // оба значения положительные, никакого переполнения
	std::cout << (FixedPoint(0.75) + FixedPoint(1.50) == FixedPoint(2.25)) << '\n'; // оба значения положительные, переполнение
	std::cout << (FixedPoint(-0.75) + FixedPoint(-1.23) == FixedPoint(-1.98)) << '\n'; // оба значения отрицательные, никакого переполнения
	std::cout << (FixedPoint(-0.75) + FixedPoint(-1.50) == FixedPoint(-2.25)) << '\n'; // оба значения отрицательные, переполнение
	std::cout << (FixedPoint(0.75) + FixedPoint(-1.23) == FixedPoint(-0.48)) << '\n'; // второе значение отрицательное, никакого переполнения
	std::cout << (FixedPoint(0.75) + FixedPoint(-1.50) == FixedPoint(-0.75)) << '\n'; // второе значение отрицательное, возможно переполнение
	std::cout << (FixedPoint(-0.75) + FixedPoint(1.23) == FixedPoint(0.48)) << '\n'; // первое значение отрицательное, никакого переполнения
	std::cout << (FixedPoint(-0.75) + FixedPoint(1.50) == FixedPoint(0.75)) << '\n'; // первое значение отрицательное, возможно переполнение
}