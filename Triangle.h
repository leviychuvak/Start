#ifndef TEST12_TRIANGLE_H
#define TEST12_TRIANGLE_H

#include "Shape.h"
#include "Point.h"

class Triangle: public Shape
{
public:
    explicit Triangle(Point aFirst = Point(),
                      Point aSecond = Point(),
                      Point aThird = Point());

    std::ostream &print(std::ostream &out) const override;

private:
    Point firstP{};
    Point secondP{};
    Point thirdP{};

};


#endif //TEST12_TRIANGLE_H
