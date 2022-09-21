#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <vector>
#include <utility>

using aOperator = std::pair<char, int>;
using operation = std::pair<aOperator, int>;

class Expression
{
public:
    
    void build();

    void print();

private:
    int start;
    std::vector<operation> operations;
};

#endif // !EXPRESSION_H




