#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	std::string	str;
	int			i;

	if (argc == 1)
		str = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		str = "";
		i = 1;
		while (i < argc)
		{
			str += argv[i];
			i++;
			if (i < argc)
				str += ' ';
		}
	}
	for (int i = 0; i < str.length(); i++)
	{
		str[i] = std::toupper(str[i]);
	}
	std::cout << str << std::endl;
	return (0);
}
