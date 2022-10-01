#include "Expression.h"
#include <iostream>
#include <string>

namespace {
    int getInt() {
        int t;
        std::cin >> t;
        std::cin.ignore(32767, '\n');
        return t;
    }

    Expression::ArefmeticOperation getOp() {
        //get an arithmetic operator
        char tCh;
        std::cin >> tCh;
        //get a second operand of operation
        int tInt;
        std::cin >> tInt;
        std::cin.ignore(32767, '\n');

        if (tCh == '+' || tCh == '-')
            return {._operator = tCh, ._priority = 0, ._value = tInt };
        if (tCh == '*' || tCh == '/')
            return { ._operator = tCh, ._priority = 1, ._value = tInt };
       
        throw std::logic_error("Something went wrong, unknown arithmetic operator was given");
    }
}

void Expression::build()
{
    start = getInt();
    int opCount = getInt();

    for (size_t i = 0; i < opCount; i++)
    {
        operations.push_back(getOp());
    }
}

void Expression::print() const
{
    std::string res{ std::to_string(start) };
    
    for (size_t i = 0; i < operations.size(); ++i)
    {
        const auto& [iOperator, iPriority, iValue] = operations[i];

        //check if second operand of current operation is negative number take it in brackets
        auto v = (operations[i]._value >= 0) ?
            std::to_string(iValue) :
            "(" + std::to_string(iValue) + ")";

        //if it`s first operation in range
        if (!i) {
            res = res + " " + iOperator + " " + v;
            continue;
        }

        //if previous operation has lower priority take first operand(which can be expression) in brackets
        if (iPriority > operations[i-1]._priority) res = "(" + res + ")";

        res = res + " " + iOperator + " " + v;
    }

    std::cout << res << std::endl;
}
