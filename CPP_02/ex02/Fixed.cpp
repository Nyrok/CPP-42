#include "Fixed.hpp"

Fixed::Fixed(void) : rawBits(0)
{
}

Fixed::Fixed(int const value)
{
	rawBits = value << fractionalBits;
}

Fixed::Fixed(float const value)
{
	rawBits = roundf(value * (1 << fractionalBits));
}

Fixed::Fixed(Fixed const &src)
{
	*this = src;
}

Fixed::~Fixed(void)
{
}

Fixed	&Fixed::operator=(Fixed const &src)
{
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

bool	Fixed::operator>(Fixed const &rhs) const
{
	return (rawBits > rhs.getRawBits());
}

bool	Fixed::operator<(Fixed const &rhs) const
{
	return (rawBits < rhs.getRawBits());
}

bool	Fixed::operator>=(Fixed const &rhs) const
{
	return (rawBits >= rhs.getRawBits());
}

bool	Fixed::operator<=(Fixed const &rhs) const
{
	return (rawBits <= rhs.getRawBits());
}

bool	Fixed::operator==(Fixed const &rhs) const
{
	return (rawBits == rhs.getRawBits());
}

bool	Fixed::operator!=(Fixed const &rhs) const
{
	return (rawBits != rhs.getRawBits());
}

Fixed	Fixed::operator+(Fixed const &rhs) const
{
	Fixed	result;

	result.setRawBits(rawBits + rhs.getRawBits());
	return (result);
}

Fixed	Fixed::operator-(Fixed const &rhs) const
{
	Fixed	result;

	result.setRawBits(rawBits - rhs.getRawBits());
	return (result);
}

Fixed	Fixed::operator*(Fixed const &rhs) const
{
	Fixed	result;

	result.setRawBits((long)rawBits * rhs.getRawBits() >> fractionalBits);
	return (result);
}

Fixed	Fixed::operator/(Fixed const &rhs) const
{
	Fixed	result;

	result.setRawBits(((long)rawBits << fractionalBits) / rhs.getRawBits());
	return (result);
}

Fixed	&Fixed::operator++(void)
{
	rawBits++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp(*this);

	rawBits++;
	return (tmp);
}

Fixed	&Fixed::operator--(void)
{
	rawBits--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp(*this);

	rawBits--;
	return (tmp);
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed const	&Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed const	&Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return (a);
	return (b);
}

std::ostream	&operator<<(std::ostream &out, Fixed const &fixed)
{
	out << fixed.toFloat();
	return (out);
}
