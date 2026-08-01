#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &src);
		~ScalarConverter(void);

		ScalarConverter	&operator=(ScalarConverter const &src);

		static void	printChar(double value);
		static void	printInt(double value);
		static void	printFloat(double value);
		static void	printDouble(double value);

	public:
		static void	convert(std::string const &literal);
};

#endif
