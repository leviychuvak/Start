#include <iostream>
#include "Pair1.h"
#include "Pair.h"
#include "StringValuePair.h"

void task1(){
    Pair1<int> p1(6, 9);
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
}

void task2(){
    Pair<int, double> p1(6, 7.8);
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair<double, int> p2(3.4, 5);
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
}

void task3(){
    StringValuePair<int> svp1("Amazing", 7);
    std::cout << "Pair: " << svp1.first() << ' ' << svp1.second() << '\n';

    const StringValuePair<double> svp2("Cool", 9.75);
    std::cout << "Pair: " << svp2.first() << ' ' << svp2.second() << '\n';
}

int main() {

    task1();

    task2();

    task3();

    return 0;
}