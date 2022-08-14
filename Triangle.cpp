#include "Triangle.h"

std::ostream& Triangle::print(std::ostream &out) const {
    out << "Triangle(" << firstP << ", " << secondP << ", " << thirdP << ")";
    return out;
}

Triangle::Triangle(const Point aFirst, const Point aSecond, const Point aThird)
    :firstP(std::move(aFirst)), secondP(std::move(aSecond)), thirdP(std::move(aThird))
{}
