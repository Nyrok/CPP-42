#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <iostream>
# include <string>

template <typename T>
class Array
{
	private:
		T				*elements;
		unsigned int	length;

	public:
		Array(void);
		Array(unsigned int n);
		Array(Array const &src);
		~Array(void);

		Array	&operator=(Array const &src);

		T				&operator[](unsigned int index);
		T const			&operator[](unsigned int index) const;
		unsigned int	size(void) const;

		class OutOfBoundsException : public std::exception
		{
			public:
				OutOfBoundsException(void);
				OutOfBoundsException(OutOfBoundsException const &src);
				~OutOfBoundsException(void) throw();

				OutOfBoundsException	&operator=(OutOfBoundsException const &src);

				char const	*what(void) const throw();
		};
};

template <typename T>
std::ostream	&operator<<(std::ostream &o, Array<T> const &array);

# include "Array.cpp"

#endif
