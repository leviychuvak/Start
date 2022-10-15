#include "node.h"

template <typename T>
bool compare(Comparison comparator, const T& etalon, const T& comparable)
{
    switch (comparator)
    {
    case Comparison::Less:              return comparable < etalon;
    case Comparison::LessOrEqual:       return comparable <= etalon;
    case Comparison::Greater:           return comparable > etalon;
    case Comparison::GreaterOrEqual:    return comparable >= etalon;
    case Comparison::Equal:             return comparable == etalon;
    case Comparison::NotEqual:          return comparable != etalon;
    default:
        break;
    }

    throw std::logic_error("Something went wrong, unknown comparator in ComparisonNode::Evaluate");
}


bool nodes::LogicalOperation::Evaluate(Date date, std::string event) const
{
    switch (logicalOperation)
    {
    case LogicalOperator::And:
        return leftOperand->Evaluate(date, event) && rightOperand->Evaluate(date, event);
    case LogicalOperator::Or:
        return leftOperand->Evaluate(date, event) || rightOperand->Evaluate(date, event);
    default:
        break;
    }

    throw std::logic_error("Something went wrong, unknown logicalOperation in LogicalOperationNode::Evaluate");
}

bool nodes::EventComparison::Evaluate([[maybe_unused]] Date date, std::string event) const
{
    return compare(comparator, eventEtalon, event);
}

bool nodes::DateComparison::Evaluate(Date date, [[maybe_unused]] std::string event) const
{
    return  compare(comparator, dataEtalon, date);
}
