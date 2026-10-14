#include "Span.hpp"
#include <climits>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>

static void	subjectTest(void)
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

static void	exceptionTests(void)
{
	Span	sp(2);

	try
	{
		sp.shortestSpan();
	}
	catch (std::exception &e)
	{
		std::cout << "empty: " << e.what() << std::endl;
	}
	sp.addNumber(1);
	try
	{
		sp.longestSpan();
	}
	catch (std::exception &e)
	{
		std::cout << "one number: " << e.what() << std::endl;
	}
	sp.addNumber(2);
	try
	{
		sp.addNumber(3);
	}
	catch (std::exception &e)
	{
		std::cout << "addNumber when full: " << e.what() << std::endl;
	}

	std::vector<int>	tooBig(5, 0);
	Span				small(3);

	try
	{
		small.addRange(tooBig.begin(), tooBig.end());
	}
	catch (std::exception &e)
	{
		std::cout << "addRange too big: " << e.what()
			<< " (size still " << small.size() << ")" << std::endl;
	}
}

static void	extremesTest(void)
{
	Span	sp(2);

	sp.addNumber(INT_MIN);
	sp.addNumber(INT_MAX);
	std::cout << "shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "longest: " << sp.longestSpan() << std::endl;
}

static void	bigTest(unsigned int n)
{
	std::vector<int>	values(n);
	Span				sp(n);

	std::generate(values.begin(), values.end(), std::rand);
	sp.addRange(values.begin(), values.end());
	std::cout << "size: " << sp.size() << std::endl;
	std::cout << "shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "longest: " << sp.longestSpan() << std::endl;
}

static void	copyTest(void)
{
	std::list<int>	lst;

	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(35);

	Span	original(4);

	original.addRange(lst.begin(), lst.end());

	Span	copy(original);
	Span	assigned;

	assigned = original;
	original.addNumber(11);
	std::cout << "original shortest: " << original.shortestSpan() << std::endl;
	std::cout << "copy shortest: " << copy.shortestSpan() << std::endl;
	std::cout << "assigned shortest: " << assigned.shortestSpan() << std::endl;
}

int	main(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	subjectTest();

	std::cout << std::endl << "--- Exceptions ---" << std::endl;
	exceptionTests();

	std::cout << std::endl << "--- INT_MIN / INT_MAX ---" << std::endl;
	extremesTest();

	std::cout << std::endl << "--- 10000 numbers ---" << std::endl;
	bigTest(10000);

	std::cout << std::endl << "--- 1000000 numbers ---" << std::endl;
	bigTest(1000000);

	std::cout << std::endl << "--- Copy / assignment (filled from std::list) ---" << std::endl;
	copyTest();
	return (0);
}
