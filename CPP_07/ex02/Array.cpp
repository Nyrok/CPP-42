#ifndef ARRAY_CPP
# define ARRAY_CPP

# include "Array.hpp"

template <typename T>
Array<T>::Array(void) : elements(new T[0]()), length(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : elements(new T[n]()), length(n)
{
}

template <typename T>
Array<T>::Array(Array const &src) : elements(new T[src.length]()), length(src.length)
{
	for (unsigned int i = 0; i < length; i++)
		elements[i] = src.elements[i];
}

template <typename T>
Array<T>::~Array(void)
{
	delete [] elements;
}

template <typename T>
Array<T>	&Array<T>::operator=(Array const &src)
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

template <typename T>
T	&Array<T>::operator[](unsigned int index)
{
	if (index >= length)
		throw typename Array<T>::OutOfBoundsException();
	return (elements[index]);
}

template <typename T>
unsigned int	Array<T>::size(void)
{
	return (length);
}

template <typename T>
Array<T>::OutOfBoundsException::OutOfBoundsException(void)
{
}

template <typename T>
Array<T>::OutOfBoundsException::OutOfBoundsException(OutOfBoundsException const &src)
{
	(void)src;
}

template <typename T>
Array<T>::OutOfBoundsException::~OutOfBoundsException(void) throw()
{
}

template <typename T>
typename Array<T>::OutOfBoundsException	&Array<T>::OutOfBoundsException::operator=(OutOfBoundsException const &src)
{
	(void)src;
	return (*this);
}

template <typename T>
char const	*Array<T>::OutOfBoundsException::what(void) const throw()
{
	return ("index is out of bounds");
}

template <typename T>
std::ostream	&operator<<(std::ostream &o, Array<T> &array)
{
	o << "[";
	for (unsigned int i = 0; i < array.size(); i++)
	{
		o << array[i];
		if (i + 1 < array.size())
			o << ", ";
	}
	o << "]";
	return (o);
}

#endif
