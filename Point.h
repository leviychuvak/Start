#ifndef TEST12_POINT_H
#define TEST12_POINT_H

#include <iostream>

class Point
{
private:
    double x{};
    double y{};
    double z{};

public:
    explicit Point(double aX = 0.0, double aY = 0.0, double aZ = 0.0)
        :x(aX), y(aY), z(aZ)
    {}

    friend std::ostream& operator<<(std::ostream &out, const Point &p);
};


#endif //TEST12_POINT_H
