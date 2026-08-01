#include "ScalarConverter.hpp"
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <cmath>

static bool	isPseudoLiteral(std::string const &literal)
{
	return (literal == "nan" || literal == "nanf"
		|| literal == "+inf" || literal == "+inff"
		|| literal == "-inf" || literal == "-inff");
}

static bool	isCharLiteral(std::string const &literal)
{
	if (literal.length() == 1 && !std::isdigit(literal[0]))
		return (true);
	return (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'');
}

static bool	isIntLiteral(std::string const &literal)
{
	char	*end;

	std::strtol(literal.c_str(), &end, 10);
	return (end != literal.c_str() && *end == '\0');
}

static bool	isFloatLiteral(std::string const &literal)
{
	char	*end;

	std::strtod(literal.c_str(), &end);
	return (end != literal.c_str() && *end == 'f' && *(end + 1) == '\0');
}

static bool	isDoubleLiteral(std::string const &literal)
{
	char	*end;

	std::strtod(literal.c_str(), &end);
	return (end != literal.c_str() && *end == '\0');
}

static void	printChar(double value)
{
	if (value != value || value < 0 || value > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

static void	printInt(double value)
{
	if (value != value || value < static_cast<double>(INT_MIN) || value > static_cast<double>(INT_MAX))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
}

static void	printFloat(double value)
{
	float	f = static_cast<float>(value);

	if (f != f)
		std::cout << "float: nanf" << std::endl;
	else if (f == std::numeric_limits<float>::infinity())
		std::cout << "float: +inff" << std::endl;
	else if (f == -std::numeric_limits<float>::infinity())
		std::cout << "float: -inff" << std::endl;
	else if (std::floor(f) == f)
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
}

static void	printDouble(double value)
{
	if (value != value)
		std::cout << "double: nan" << std::endl;
	else if (value == std::numeric_limits<double>::infinity())
		std::cout << "double: +inf" << std::endl;
	else if (value == -std::numeric_limits<double>::infinity())
		std::cout << "double: -inf" << std::endl;
	else if (std::floor(value) == value)
		std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
	else
		std::cout << "double: " << value << std::endl;
}

void	ScalarConverter::convert(std::string const &literal)
{
	double	value;

	if (isPseudoLiteral(literal))
	{
		if (literal[0] == 'n')
			value = std::numeric_limits<double>::quiet_NaN();
		else if (literal[0] == '-')
			value = -std::numeric_limits<double>::infinity();
		else
			value = std::numeric_limits<double>::infinity();
	}
	else if (isCharLiteral(literal))
	{
		if (literal.length() == 3)
			value = static_cast<double>(literal[1]);
		else
			value = static_cast<double>(literal[0]);
	}
	else if (isIntLiteral(literal))
		value = static_cast<double>(std::strtol(literal.c_str(), NULL, 10));
	else if (isFloatLiteral(literal))
		value = static_cast<double>(static_cast<float>(std::strtod(literal.c_str(), NULL)));
	else if (isDoubleLiteral(literal))
		value = std::strtod(literal.c_str(), NULL);
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}
