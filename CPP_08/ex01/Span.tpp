#ifndef SPAN_TPP
# define SPAN_TPP

# include "Span.hpp"

template <typename InputIterator>
void	Span::addRange(InputIterator first, InputIterator last)
{
	if (static_cast<unsigned long>(std::distance(first, last)) > maxSize - numbers.size())
		throw std::out_of_range("not enough space left in Span");
	numbers.insert(numbers.end(), first, last);
}

#endif
