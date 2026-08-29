#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template <typename T>
class Array
{
	private:
		T				*elements;
		unsigned int	length;

	public:
		Array(void) : elements(new T[0]()), length(0)
		{
		}

		Array(unsigned int n) : elements(new T[n]()), length(n)
		{
		}

		Array(Array const &src) : elements(new T[src.length]()), length(src.length)
		{
			for (unsigned int i = 0; i < length; i++)
				elements[i] = src.elements[i];
		}

		~Array(void)
		{
			delete [] elements;
		}

		Array	&operator=(Array const &src)
		{
			if (this != &src)
			{
				delete [] elements;
				elements = new T[src.length]();
				length = src.length;
				for (unsigned int i = 0; i < length; i++)
					elements[i] = src.elements[i];
			}
			return (*this);
		}

		T	&operator[](unsigned int index)
		{
			if (index >= length)
				throw Array::OutOfBoundsException();
			return (elements[index]);
		}

		T const	&operator[](unsigned int index) const
		{
			if (index >= length)
				throw Array::OutOfBoundsException();
			return (elements[index]);
		}

		unsigned int	size(void) const
		{
			return (length);
		}

		class OutOfBoundsException : public std::exception
		{
			public:
				OutOfBoundsException(void)
				{
				}

				OutOfBoundsException(OutOfBoundsException const &src)
				{
					(void)src;
				}

				~OutOfBoundsException(void) throw()
				{
				}

				OutOfBoundsException	&operator=(OutOfBoundsException const &src)
				{
					(void)src;
					return (*this);
				}

				const char	*what(void) const throw()
				{
					return ("index is out of bounds");
				}
		};
};

#endif
