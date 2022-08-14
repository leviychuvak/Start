#ifndef TEST12_CIRCLE_H
#define TEST12_CIRCLE_H

#include "Point.h"
#include "Shape.h"

class Circle: public Shape
{
public:
    explicit Circle(const Point &aCenter = Point(0,0,0), double aRadius = 0.0);

    std::ostream &print(std::ostream &out) const override;

    double getRadius() const;

private:
    Point center{};
    double radius{};

};


#endif //TEST12_CIRCLE_H
