#ifndef __FIXED_H__
# define __FIXED_H__

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					rawBits;
		static const int	fractionalBits = 8;

	public:
		Fixed(void);
		Fixed(int const value);
		Fixed(float const value);
		Fixed(Fixed const &src);
		~Fixed(void);

		Fixed	&operator=(Fixed const &src);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		bool	operator>(Fixed const &rhs) const;
		bool	operator<(Fixed const &rhs) const;
		bool	operator>=(Fixed const &rhs) const;
		bool	operator<=(Fixed const &rhs) const;
		bool	operator==(Fixed const &rhs) const;
		bool	operator!=(Fixed const &rhs) const;

		Fixed	operator+(Fixed const &rhs) const;
		Fixed	operator-(Fixed const &rhs) const;
		Fixed	operator*(Fixed const &rhs) const;
		Fixed	operator/(Fixed const &rhs) const;

		Fixed	&operator++(void);
		Fixed	operator++(int);
		Fixed	&operator--(void);
		Fixed	operator--(int);

		static Fixed		&min(Fixed &a, Fixed &b);
		static Fixed const	&min(Fixed const &a, Fixed const &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static Fixed const	&max(Fixed const &a, Fixed const &b);
};

std::ostream	&operator<<(std::ostream &out, Fixed const &fixed);

#endif
