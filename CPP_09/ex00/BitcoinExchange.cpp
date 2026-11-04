#include "BitcoinExchange.hpp"
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>

BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) : rates(src.rates)
{
}

BitcoinExchange::~BitcoinExchange(void)
{
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &src)
{
	if (this != &src)
		rates = src.rates;
	return (*this);
}

/* "YYYY-MM-DD" and the day must exist in that month (leap years included) */
bool	BitcoinExchange::isValidDate(std::string const &date)
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	for (size_t i = 0; i < date.size(); i++)
	{
		if (i != 4 && i != 7 && !std::isdigit(static_cast<unsigned char>(date[i])))
			return (false);
	}

	int	year = std::atoi(date.substr(0, 4).c_str());
	int	month = std::atoi(date.substr(5, 2).c_str());
	int	day = std::atoi(date.substr(8, 2).c_str());
	int	daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
		daysInMonth[1] = 29;
	if (month < 1 || month > 12)
		return (false);
	return (day >= 1 && day <= daysInMonth[month - 1]);
}

/* digits, optionally followed by '.' and at least one digit: "3", "1.2", "47115.93" */
bool	BitcoinExchange::isValidNumber(std::string const &str)
{
	size_t	i = 0;

	while (i < str.size() && std::isdigit(static_cast<unsigned char>(str[i])))
		i++;
	if (i == 0)
		return (false);
	if (i < str.size() && str[i] == '.')
	{
		size_t	fractionStart = ++i;

		while (i < str.size() && std::isdigit(static_cast<unsigned char>(str[i])))
			i++;
		if (i == fractionStart)
			return (false);
	}
	return (i == str.size());
}

/* one "date,exchange_rate" line of data.csv */
void	BitcoinExchange::addRate(std::string const &line)
{
	size_t	comma = line.find(',');

	if (comma == std::string::npos
		|| !isValidDate(line.substr(0, comma))
		|| !isValidNumber(line.substr(comma + 1)))
		throw std::runtime_error("bad database line => " + line);
	rates[line.substr(0, comma)] = std::strtod(line.substr(comma + 1).c_str(), NULL);
}

void	BitcoinExchange::loadDatabase(std::string const &filename)
{
	std::ifstream	file(filename.c_str());
	std::string		line;

	if (!file.is_open())
		throw std::runtime_error("could not open database.");
	if (std::getline(file, line) && line != "date,exchange_rate")
		addRate(line);
	while (std::getline(file, line))
		addRate(line);
	if (rates.empty())
		throw std::runtime_error("database is empty.");
}

/* one "date | value" line of the input file */
void	BitcoinExchange::processLine(std::string const &line) const
{
	size_t	separator = line.find(" | ");

	if (separator == std::string::npos)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return ;
	}

	std::string	date = line.substr(0, separator);
	std::string	valueStr = line.substr(separator + 3);

	if (!isValidDate(date))
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return ;
	}
	if (valueStr.size() > 1 && valueStr[0] == '-' && isValidNumber(valueStr.substr(1)))
	{
		std::cout << "Error: not a positive number." << std::endl;
		return ;
	}
	if (!isValidNumber(valueStr))
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return ;
	}

	double	value = std::strtod(valueStr.c_str(), NULL);

	if (value > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return ;
	}

	/* first date strictly after `date`, then one step back = same date or closest lower one */
	std::map<std::string, double>::const_iterator	it = rates.upper_bound(date);

	if (it == rates.begin())
	{
		std::cout << "Error: date before first database entry => " << date << std::endl;
		return ;
	}
	--it;
	/* 10 significant digits: big results keep their decimals and are not shown as 4.71159e+07 */
	std::cout << std::setprecision(10)
		<< date << " => " << value << " = " << value * it->second << std::endl;
}

void	BitcoinExchange::processInput(std::string const &filename) const
{
	std::ifstream	file(filename.c_str());
	std::string		line;

	if (!file.is_open())
		throw std::runtime_error("could not open file.");
	if (std::getline(file, line) && line != "date | value")
		processLine(line);
	while (std::getline(file, line))
		processLine(line);
}
