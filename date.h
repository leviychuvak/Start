#pragma once
#include <iostream>

class Date
{
private:
	int year;
	int month;
	int day;

public:
	Date(int y = 0, int m = 0, int d = 0)
		:year(y), month(m), day(d)
	{}
	std::string toString() const;

	friend std::ostream& operator<< (std::ostream& out, const Date& date);

	friend bool operator<(const Date& left, const Date& right);
	friend bool operator<=(const Date& left, const Date& right);
	friend bool operator>(const Date& left, const Date& right);
	friend bool operator>=(const Date& left, const Date& right);
	friend bool operator==(const Date& left, const Date& right);
	friend bool operator!=(const Date& left, const Date& right);
};

 Date ParseDate(std::istream& is);