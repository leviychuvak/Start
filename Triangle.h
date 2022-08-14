#ifndef TEST12_TRIANGLE_H
#define TEST12_TRIANGLE_H

#include "Shape.h"
#include "Point.h"

class Triangle: public Shape
{
public:
    explicit Triangle(const Point &aFirst = Point(0,0,0),
                    const Point &aSecond = Point(0,0,0),
                    const Point &aThird = Point(0,0,0));

    std::ostream &print(std::ostream &out) const override;

private:
    Point firstP{};
    Point secondP{};
    Point thirdP{};

};


#endif //TEST12_TRIANGLE_H
