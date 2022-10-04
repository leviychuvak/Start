#ifndef NODE_H
#define NODE_H

#include <memory>
#include "date.h"

enum class Comparison
{
	Less,
	LessOrEqual,
	Greater,
	GreaterOrEqual,
	Equal,
	NotEqual
};

enum class LogicalOperator
{
	And,
	Or
};

namespace Nodes {
	class Node
	{
	public:
		virtual ~Node(){}
		virtual bool Evaluate(Date date, std::string event) const = 0;
	};

	class Empty : public Node
	{
	public:
		virtual ~Empty() {}
		bool Evaluate(Date date, std::string event) const override {
			return true;
		}
	};

	class DateComparison : public Node
	{
	private:
		Comparison comparator;
		Date dataEtalon;

	public:
		explicit DateComparison(Comparison comp, Date data)
			:comparator(std::move(comp)), dataEtalon(std::move(data))
		{}
		virtual ~DateComparison() {}
		virtual bool Evaluate(Date date, std::string event) const override;
	};

	class EventComparison : public Node
	{
	private:
		Comparison comparator;
		std::string eventEtalon;

	public:
		explicit EventComparison(Comparison comp, std::string event)
			:comparator(std::move(comp)), eventEtalon(std::move(event))
		{}
		virtual ~EventComparison() {}
		virtual bool Evaluate(Date date, std::string event) const override;
	};

	class LogicalOperation : public Node
	{
	private:
		LogicalOperator logicalOperation;
		std::shared_ptr<Node> leftOperand;
		std::shared_ptr<Node> rightOperand;

	public:
		explicit LogicalOperation(LogicalOperator aLogicalOperator, std::shared_ptr<Node> aLeftOperand,
			std::shared_ptr<Node> aRightOperand)
			:logicalOperation(std::move(aLogicalOperator)), leftOperand(aLeftOperand), rightOperand(aRightOperand)
		{}
		virtual ~LogicalOperation() {}
		virtual bool Evaluate(Date date, std::string event) const override;

	};
}


#endif // !NODE_H




