#include "Fixed.hpp"

Fixed::Fixed(void) : rawBits(0)
{
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(int const value)
{
	std::cout << "Int constructor called" << std::endl;
	rawBits = value << fractionalBits;
}

Fixed::Fixed(float const value)
{
	std::cout << "Float constructor called" << std::endl;
	rawBits = roundf(value * (1 << fractionalBits));
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&Fixed::operator=(Fixed const &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	rawBits = src.getRawBits();
	return (*this);
}

int	Fixed::getRawBits(void) const
{
	return (rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	rawBits = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)rawBits / (float)(1 << fractionalBits));
}

int	Fixed::toInt(void) const
{
	return (rawBits >> fractionalBits);
}

std::ostream	&operator<<(std::ostream &out, Fixed const &fixed)
{
	out << fixed.toFloat();
	return (out);
}
