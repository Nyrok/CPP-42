#include "iter.hpp"
#include <iostream>
#include <string>

template <typename T>
void	print(T const &element)
{
	std::cout << element << std::endl;
}

static void	increment(int &n)
{
	n++;
}

int	main(void)
{
	std::cout << "--- Int array ---" << std::endl;
	int	numbers[5] = {1, 2, 3, 4, 5};

	::iter(numbers, 5, print<int>);

	std::cout << std::endl;
	std::cout << "--- Non-const function (increment) ---" << std::endl;
	::iter(numbers, 5, increment);
	::iter(numbers, 5, print<int>);

	std::cout << std::endl;
	std::cout << "--- String array ---" << std::endl;
	std::string	words[3] = {"tuturu", "tature", "tutere"};

	::iter(words, 3, print<std::string>);

	std::cout << std::endl;
	std::cout << "--- Const int array ---" << std::endl;
	int const	constants[3] = {42, 21, 84};

	::iter(constants, 3, print<int>);
	return (0);
}
