#ifndef RPN_HPP
# define RPN_HPP

# include <list>
# include <stack>
# include <string>

class RPN
{
	private:
		std::stack<int, std::list<int> >	operands;

		static bool	isOperand(std::string const &token);
		static bool	isOperator(std::string const &token);
		static int	applyOperator(char op, int left, int right);

	public:
		RPN(void);
		RPN(RPN const &src);
		~RPN(void);

		RPN	&operator=(RPN const &src);

		int	evaluate(std::string const &expression);
};

#endif
