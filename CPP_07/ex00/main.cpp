#include "whatever.hpp"
#include <iostream>
#include <string>

int	main(void)
{
	int	a = 2;
	int	b = 3;

	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

	std::string	c = "chaine1";
	std::string	d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

	std::cout << std::endl;
	std::cout << "--- Equal values return the second one ---" << std::endl;

	int	x = 42;
	int	y = 42;

	std::cout << "min address is y: " << (&::min(x, y) == &y) << std::endl;
	std::cout << "max address is y: " << (&::max(x, y) == &y) << std::endl;
	return (0);
}
