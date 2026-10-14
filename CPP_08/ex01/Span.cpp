#include "Span.hpp"
#include <numeric>

Span::Span(void) : maxSize(0)
{
}

Span::Span(unsigned int n) : maxSize(n)
{
}

Span::Span(Span const &src) : maxSize(src.maxSize), numbers(src.numbers)
{
}

Span::~Span(void)
{
}

Span	&Span::operator=(Span const &src)
{
	if (this != &src)
	{
		maxSize = src.maxSize;
		numbers = src.numbers;
	}
	return (*this);
}

void	Span::addNumber(int number)
{
	if (numbers.size() >= maxSize)
		throw std::out_of_range("Span is full");
	numbers.push_back(number);
}

long	Span::shortestSpan(void) const
{
	if (numbers.size() < 2)
		throw std::logic_error("not enough numbers to find a span");

	std::vector<long>	sorted(numbers.begin(), numbers.end());
	std::vector<long>	gaps(sorted.size());

	std::sort(sorted.begin(), sorted.end());
	std::adjacent_difference(sorted.begin(), sorted.end(), gaps.begin());
	return (*std::min_element(gaps.begin() + 1, gaps.end()));
}

long	Span::longestSpan(void) const
{
	if (numbers.size() < 2)
		throw std::logic_error("not enough numbers to find a span");

	long	min = *std::min_element(numbers.begin(), numbers.end());
	long	max = *std::max_element(numbers.begin(), numbers.end());

	return (max - min);
}

unsigned int	Span::size(void) const
{
	return (numbers.size());
}
