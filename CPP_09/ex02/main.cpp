#include "PmergeMe.hpp"
#include <exception>
#include <iostream>

int	main(int argc, char **argv)
{
	PmergeMe	sorter;

	if (argc < 2)
	{
		std::cerr << "Error: usage: ./PmergeMe <positive integers>" << std::endl;
		return (1);
	}
	try
	{
		sorter.run(argc, argv);
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
