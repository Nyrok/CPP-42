#include "RPN.hpp"
#include <cctype>
#include <climits>
#include <sstream>
#include <stdexcept>

RPN::RPN(void)
{
}

RPN::RPN(RPN const &src) : operands(src.operands)
{
}

RPN::~RPN(void)
{
}

RPN	&RPN::operator=(RPN const &src)
{
	if (this != &src)
		operands = src.operands;
	return (*this);
}

bool	RPN::isOperand(std::string const &token)
{
	return (token.size() == 1 && std::isdigit(static_cast<unsigned char>(token[0])));
}

bool	RPN::isOperator(std::string const &token)
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

int	RPN::applyOperator(char op, int left, int right)
{
	long	result;

	if (op == '+')
		result = static_cast<long>(left) + right;
	else if (op == '-')
		result = static_cast<long>(left) - right;
	else if (op == '*')
		result = static_cast<long>(left) * right;
	else
	{
		if (right == 0)
			throw std::runtime_error("division by zero");
		result = static_cast<long>(left) / right;
	}
	if (result < INT_MIN || result > INT_MAX)
		throw std::runtime_error("result out of int range");
	return (static_cast<int>(result));
}

int	RPN::evaluate(std::string const &expression)
{
	std::istringstream	stream(expression);
	std::string			token;

	while (!operands.empty())
		operands.pop();
	while (stream >> token)
	{
		if (isOperand(token))
			operands.push(token[0] - '0');
		else if (isOperator(token))
		{
			if (operands.size() < 2)
				throw std::runtime_error("not enough operands for '" + token + "'");

			int	right = operands.top();

			operands.pop();

			int	left = operands.top();

			operands.pop();
			operands.push(applyOperator(token[0], left, right));
		}
		else
			throw std::runtime_error("invalid token '" + token + "'");
	}
	if (operands.size() != 1)
		throw std::runtime_error("invalid expression");
	return (operands.top());
}
