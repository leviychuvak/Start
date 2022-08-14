#include <iostream>
#include <vector>
#include "Circle.h"
#include "Triangle.h"

double getLargestRadius(std::vector<Shape*> v){
    double largestRadius = 0.0;

    for (int i = 0; i < v.size(); ++i) {
        Circle* temp = dynamic_cast<Circle*>(v[i]);
        if (temp && temp->getRadius() > largestRadius){
            largestRadius = temp->getRadius();
        }
    }

    return largestRadius;
}

int main() {
    std::vector<Shape*> v;
    v.push_back(new Circle(Point(1, 2, 3), 7));
    v.push_back(new Triangle(Point(1, 2, 3), Point(4, 5, 6), Point(7, 8, 9)));
    v.push_back(new Circle(Point(4, 5, 6), 13));
    v.push_back(new Circle(Point(4, 5, 6), 3));

    for (int i = 0; i < v.size(); ++i) {
        std::cout<<*v[i]<<std::endl;
    }

    std::cout << "\nThe largest radius is: " << getLargestRadius(v) << '\n'; // реализуйте эту функцию

    for (int i = 0; i < v.size(); ++i) {
        delete v[i];
    }

    return 0;
}
