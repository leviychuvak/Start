#include "Triangle.h"

Triangle::Triangle(const Point &aFirst, const Point &aSecond, const Point &aThird)
    : firstP(aFirst), secondP(aSecond), thirdP(aThird)
{}

std::ostream& Triangle::print(std::ostream &out) const {
    out << "Triangle(" << firstP << ", " << secondP << ", " << thirdP << ")";
    return out;
}
