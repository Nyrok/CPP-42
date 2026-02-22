#include "utils.hpp"

int		countDigits(int n)
{
	int count = 0;

	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		count++;
	}

	return count;
}

int	ft_atoi(std::string str)
{
	int	result = 0;

	if (str.size() == 0)
		return (-1);
	for (int i = 0; i < (int)str.size(); i++)
	{
		if (!std::isdigit(str[i]))
			return (-1);
		result *= 10;
		result += str[i] - '0';
	}
	return (result);
}