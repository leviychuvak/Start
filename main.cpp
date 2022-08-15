#include <iostream>
#include <vector>
#include "Circle.h"
#include "Triangle.h"

double getLargestRadius(const std::vector<Shape*> &v) {
    double largestRadius = 0.0;

    for(const auto& shape : v){
        auto* temp = dynamic_cast<Circle*>(shape);
        if (temp && temp->getRadius() > largestRadius)
            largestRadius = temp->getRadius();
    }

    return largestRadius;
}

int main() {
    std::vector<Shape*> v;
    v.push_back(new Circle(Point(1, 2, 3), 7));
    v.push_back(new Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)));
    v.push_back(new Circle(Point(4, 5, 6), 13));
    v.push_back(new Circle(Point(4, 5, 6), 3));

    for (auto i : v) {
        std::cout<<*i<<std::endl;
    }

    std::cout << "\nThe largest radius is: " << getLargestRadius(v) << '\n';

    for (auto i : v) {
        delete i;
    }

    return 0;
}
