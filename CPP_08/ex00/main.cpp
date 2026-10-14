#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <iterator>

template <typename T>
void	search(T &container, int value)
{
	try
	{
		typename T::iterator	it = ::easyfind(container, value);

		std::cout << "found " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << value << ": " << e.what() << std::endl;
	}
}

int	main(void)
{
	std::cout << "--- std::vector ---" << std::endl;
	std::vector<int>	vec;

	for (int i = 0; i < 10; i++)
		vec.push_back(i * 2);
	search(vec, 4);
	search(vec, 18);
	search(vec, 5);

	std::cout << std::endl;
	std::cout << "--- Iterator points into the container ---" << std::endl;
	std::vector<int>::iterator	it = ::easyfind(vec, 6);

	*it = 42;
	std::cout << "vec[3] after *it = 42: " << vec[3] << std::endl;

	std::cout << std::endl;
	std::cout << "--- First occurrence ---" << std::endl;
	std::list<int>	lst;

	lst.push_back(1);
	lst.push_back(7);
	lst.push_back(3);
	lst.push_back(7);
	std::cout << "distance from begin: "
		<< std::distance(lst.begin(), ::easyfind(lst, 7)) << std::endl;
	search(lst, 8);

	std::cout << std::endl;
	std::cout << "--- std::deque ---" << std::endl;
	std::deque<int>	deq;

	deq.push_back(-5);
	deq.push_front(10);
	search(deq, -5);
	search(deq, 0);

	std::cout << std::endl;
	std::cout << "--- Empty container ---" << std::endl;
	std::vector<int>	empty;

	search(empty, 0);

	std::cout << std::endl;
	std::cout << "--- Const container ---" << std::endl;
	std::vector<int> const	constVec(vec);

	try
	{
		std::vector<int>::const_iterator	cit = ::easyfind(constVec, 42);

		std::cout << "found " << *cit << std::endl;
		::easyfind(constVec, 100);
	}
	catch (std::exception &e)
	{
		std::cout << "100: " << e.what() << std::endl;
	}
	return (0);
}
