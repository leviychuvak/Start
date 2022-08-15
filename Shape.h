#ifndef TEST12_SHAPE_H
#define TEST12_SHAPE_H

#include <iostream>

class Shape {
public:
    virtual std::ostream& print(std::ostream &out) const = 0;
    virtual ~Shape() = default;
};

std::ostream& operator<<(std::ostream &out, const Shape &shape);

#endif //TEST12_SHAPE_H
