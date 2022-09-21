#include "Expression.h"
#include <iostream>
#include <string>

namespace {
    operation getOp() {
        char tCh;
        std::cin >> tCh;
        int tInt;
        std::cin >> tInt;
        std::cin.ignore(32767, '\n');
        return (tCh == '+' || tCh == '-') ? 
            std::make_pair(std::make_pair(tCh, 0), tInt) :
            std::make_pair(std::make_pair(tCh, 1), tInt);
    }
}

void Expression::build()
{
    std::cin >> start;
    std::cin.ignore(32767, '\n');

    int opCount;
    std::cin >> opCount;
    std::cin.ignore(32767, '\n');

    for (size_t i = 0; i < opCount; i++)
    {
        operations.push_back(getOp());
    }
}

void Expression::print()
{
    std::string res{ std::to_string(start) };
    
    for (size_t i = 0; i < operations.size(); ++i)
    {
        auto v = (operations[i].second >= 0) ?
            std::to_string(operations[i].second) :
            "(" + std::to_string(operations[i].second) + ")";
        if (!i) {
            res = res + " " + operations[i].first.first + " " + v;
            continue;
        }
        if (operations[i].first.second > operations[i-1].first.second) res = "(" + res + ")";
        res = res + " " + operations[i].first.first + " " + v;
    }

    std::cout << res << std::endl;
}
