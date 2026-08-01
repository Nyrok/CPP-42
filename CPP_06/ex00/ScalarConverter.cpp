#include "ScalarConverter.hpp"
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cctype>
#include <climits>

void	ScalarConverter::printChar(double value)
{
	if (value != value || value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

void	ScalarConverter::printInt(double value)
{
	if (value != value || value < static_cast<double>(INT_MIN) || value > static_cast<double>(INT_MAX))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void	ScalarConverter::printFloat(double value)
{
	float	f = static_cast<float>(value);

	if (f != f)
		std::cout << "float: nanf" << std::endl;
	else if (f == std::numeric_limits<float>::infinity())
		std::cout << "float: +inff" << std::endl;
	else if (f == -std::numeric_limits<float>::infinity())
		std::cout << "float: -inff" << std::endl;
	else if (f > -1e18f && f < 1e18f && f == static_cast<float>(static_cast<long>(f)))
	{
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		std::cout.unsetf(std::ios::fixed);
		std::cout.precision(6);
	}
	else
		std::cout << "float: " << f << "f" << std::endl;
}

void	ScalarConverter::printDouble(double value)
{
	if (value != value)
		std::cout << "double: nan" << std::endl;
	else if (value == std::numeric_limits<double>::infinity())
		std::cout << "double: +inf" << std::endl;
	else if (value == -std::numeric_limits<double>::infinity())
		std::cout << "double: -inf" << std::endl;
	else if (value > -1e18 && value < 1e18 && value == static_cast<double>(static_cast<long>(value)))
	{
		std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
		std::cout.unsetf(std::ios::fixed);
		std::cout.precision(6);
	}
	else
		std::cout << "double: " << value << std::endl;
}

void	ScalarConverter::convert(std::string const &literal)
{
	double	value;
	char	*end;

	if (literal == "nan" || literal == "nanf")
		value = std::numeric_limits<double>::quiet_NaN();
	else if (literal == "inf" || literal == "+inf" || literal == "inff" || literal == "+inff")
		value = std::numeric_limits<double>::infinity();
	else if (literal == "-inf" || literal == "-inff")
		value = -std::numeric_limits<double>::infinity();
	else if (literal.length() == 1 && !std::isdigit(literal[0]))
		value = static_cast<double>(literal[0]);
	else if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
		value = static_cast<double>(literal[1]);
	else
	{
		value = std::strtod(literal.c_str(), &end);
		if (end == literal.c_str() || (*end != '\0' && !(*end == 'f' && *(end + 1) == '\0')))
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return ;
		}
	}
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}
