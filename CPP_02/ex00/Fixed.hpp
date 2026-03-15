#ifndef __FIXED_H__
# define __FIXED_H__

# include <iostream>

class Fixed
{
	private:
		int					rawBits;
		static const int	fractionalBits = 8;

	public:
		Fixed(void);
		Fixed(Fixed const &src);
		~Fixed(void);

		Fixed	&operator=(Fixed const &src);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
