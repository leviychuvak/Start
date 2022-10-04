#include "date.h"
#include <iomanip>
#include <string>

bool operator<(const Date& left, const Date& right)
{
    return left.toString() < right.toString();
}

bool operator<=(const Date& left, const Date& right)
{
    return !(left > right);
}

bool operator>(const Date& left, const Date& right)
{
    return left.toString() > right.toString();
}

bool operator>=(const Date& left, const Date& right)
{
    return !(left < right);
}

bool operator==(const Date& left, const Date& right)
{
    return left.toString() == right.toString();
}

bool operator!=(const Date& left, const Date& right)
{
    return !(left == right);
}

std::ostream& operator<<(std::ostream& out, const Date& date)
{
    out << std::setfill('0') << std::setw(4) << date.year << "-" 
        << std::setfill('0') << std::setw(2) << date.month << "-" 
        << std::setfill('0') << std::setw(2) << date.day;
    return out;
}

std::string Date::toString() const
{
    return std::to_string(year) + "-" + std::to_string(month) + "-" + std::to_string(day);
}

Date ParseDate(std::istream& is)
{
    int y, m, d;
    is >> y;
    is.ignore();
    is >> m;
    is.ignore();
    is >> d;
    is.ignore();
    return Date(y, m, d);
}
