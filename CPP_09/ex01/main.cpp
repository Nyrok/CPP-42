#include "RPN.hpp"
#include <exception>
#include <iostream>

int	main(int argc, char **argv)
{
	RPN	rpn;

	if (argc != 2)
	{
		std::cerr << "Error: usage: ./RPN \"<inverted Polish expression>\"" << std::endl;
		return (1);
	}
	try
	{
		std::cout << rpn.evaluate(argv[1]) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
