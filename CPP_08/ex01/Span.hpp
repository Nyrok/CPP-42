#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <iterator>
# include <stdexcept>
# include <vector>

class Span
{
	private:
		unsigned int		maxSize;
		std::vector<int>	numbers;

	public:
		Span(void);
		Span(unsigned int n);
		Span(Span const &src);
		~Span(void);

		Span	&operator=(Span const &src);

		void			addNumber(int number);
		template <typename InputIterator>
		void			addRange(InputIterator first, InputIterator last);
		long			shortestSpan(void) const;
		long			longestSpan(void) const;
		unsigned int	size(void) const;
};

# include "Span.tpp"

#endif
