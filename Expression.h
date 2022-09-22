#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <vector>
#include <utility>



class Expression
{
public:    
    struct ArefmeticOperation
    {
        char _operator;
        int _priority;
        int _value;
    };

    void build();
    void print() const;

private:
    int start;
    std::vector<ArefmeticOperation> operations;

};

#endif // !EXPRESSION_H




