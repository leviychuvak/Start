#include "Circle.h"

Circle::Circle(const Point aCenter, double aRadius)
    : center(std::move(aCenter)), radius(aRadius)
{}

std::ostream &Circle::print(std::ostream &out) const {
    out<<"Circle("<<center<<", radius "<<radius<<")";
    return out;
}

double Circle::getRadius() const {
    return radius;
}
