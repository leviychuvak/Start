#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include "Circle.h"
#include "Triangle.h"

double getLargestRadius(const std::vector<Shape*> &v) {

    auto max = std::max_element(v.begin(), v.end(), [](auto lhs, auto rhs) {
        auto* temp1 = dynamic_cast<Circle*>(lhs);
        auto* temp2 = dynamic_cast<Circle*>(rhs);
        return temp1 && temp2 && temp1->getRadius() < temp2->getRadius();
    });

    auto largestRadius = dynamic_cast<Circle*>(*max);
    assert(largestRadius != nullptr && "vector does not contain references to Circle objects");

    return largestRadius->getRadius();
}

int main() {
    std::vector<Shape*> v;
    v.push_back(new Circle(Point(1, 2, 3), 7));
    v.push_back(new Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)));
    v.push_back(new Circle(Point(4, 5, 6), 13));
    v.push_back(new Circle(Point(4, 5, 6), 3));
    v.push_back(new Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)));
    v.push_back(new Circle(Point(4, 5, 6), 20));
    v.push_back(new Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)));

    for (auto i : v) {
        std::cout<<*i<<std::endl;
    }

    std::cout << "\nThe largest radius is: " << getLargestRadius(v) << '\n';

    for (auto i : v) {
        delete i;
    }

    return 0;
}
