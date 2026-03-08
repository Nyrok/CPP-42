#include <iostream>

int	main(void)
{
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << "Address of string:\t" << &str << std::endl;
	std::cout << "Address in stringPTR:\t" << stringPTR << std::endl;
	std::cout << "Address in stringREF:\t" << &stringREF << std::endl;

	std::cout << "Value of string:\t" << str << std::endl;
	std::cout << "Value via stringPTR:\t" << *stringPTR << std::endl;
	std::cout << "Value via stringREF:\t" << stringREF << std::endl;

	return (0);
}
