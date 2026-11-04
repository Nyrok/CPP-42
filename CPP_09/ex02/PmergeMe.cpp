#include "PmergeMe.hpp"
#include <algorithm>
#include <cctype>
#include <climits>
#include <ctime>
#include <iostream>
#include <sstream>
#include <stdexcept>

/*
** Ford-Johnson (merge-insertion), same steps for both containers:
**  1. make pairs, the larger element of each pair is a "winner" (a), the smaller is its partner (b)
**  2. sort the winners recursively with the same algorithm
**  3. main chain = b1 a1 a2 ... am (b1 is smaller than a1, so it goes first for free)
**  4. insert b2 b3 ... (and the leftover element if the size is odd) by binary search,
**     in the Jacobsthal order: b3 b2, b5 b4, b11 ... b6, b21 ... b12, ...
**     bi is smaller than ai, so its search stops before ai: with this order every
**     search is done on at most 2^k - 1 elements, which costs at most k comparisons.
**
** The algorithm sorts indexes in `vec` / `deq` (ids) instead of the values themselves:
** that way every winner remembers its own partner, even when some values are equal.
*/

static double	elapsedMicroseconds(std::clock_t start)
{
	return (static_cast<double>(std::clock() - start) * 1000000.0 / CLOCKS_PER_SEC);
}

PmergeMe::PmergeMe(void)
{
}

PmergeMe::PmergeMe(PmergeMe const &src) : vec(src.vec), deq(src.deq)
{
}

PmergeMe::~PmergeMe(void)
{
}

PmergeMe	&PmergeMe::operator=(PmergeMe const &src)
{
	if (this != &src)
	{
		vec = src.vec;
		deq = src.deq;
	}
	return (*this);
}

/* only digits, between 1 and INT_MAX */
int	PmergeMe::parseNumber(std::string const &token)
{
	long	value = 0;

	for (size_t i = 0; i < token.size(); i++)
	{
		if (!std::isdigit(static_cast<unsigned char>(token[i])))
			throw std::invalid_argument("not a positive integer: " + token);
		value = value * 10 + (token[i] - '0');
		if (value > INT_MAX)
			throw std::out_of_range("number too large: " + token);
	}
	if (value == 0)
		throw std::invalid_argument("not a positive integer: " + token);
	return (static_cast<int>(value));
}

/* ========================================================================== */
/*                                std::vector                                 */
/* ========================================================================== */

void	PmergeMe::fillVector(int argc, char **argv)
{
	vec.clear();
	for (int i = 1; i < argc; i++)
	{
		std::istringstream	stream(argv[i]);
		std::string			token;
		size_t				sizeBefore = vec.size();

		while (stream >> token)
			vec.push_back(parseNumber(token));
		if (vec.size() == sizeBefore)
			throw std::invalid_argument("empty argument");
	}
}

void	PmergeMe::sortVector(void)
{
	std::vector<size_t>	chain;
	std::vector<int>	sorted;

	for (size_t id = 0; id < vec.size(); id++)
		chain.push_back(id);
	mergeInsertVector(chain);
	for (size_t i = 0; i < chain.size(); i++)
		sorted.push_back(vec[chain[i]]);
	vec = sorted;
}

/* binary search in mainChain[0, bound), then insert: the classic "binary insertion" */
void	PmergeMe::binaryInsertVector(std::vector<size_t> &mainChain, size_t id, size_t bound)
{
	size_t	low = 0;
	size_t	high = bound;

	while (low < high)
	{
		size_t	middle = low + (high - low) / 2;

		if (vec[id] < vec[mainChain[middle]])
			high = middle;
		else
			low = middle + 1;
	}
	mainChain.insert(mainChain.begin() + low, id);
}

void	PmergeMe::mergeInsertVector(std::vector<size_t> &chain)
{
	if (chain.size() < 2)
		return ;

	/* 1. pairs: partner[winner] = the smaller element it was paired with */
	std::vector<size_t>	winners;
	std::vector<size_t>	partner(vec.size());

	for (size_t i = 0; i + 1 < chain.size(); i += 2)
	{
		size_t	smaller = chain[i];
		size_t	larger = chain[i + 1];

		if (vec[smaller] > vec[larger])
			std::swap(smaller, larger);
		winners.push_back(larger);
		partner[larger] = smaller;
	}

	/* 2. recursion on the winners */
	mergeInsertVector(winners);

	/* 3. main chain: b1 a1 a2 ... am */
	std::vector<size_t>	mainChain;

	mainChain.push_back(partner[winners[0]]);
	mainChain.insert(mainChain.end(), winners.begin(), winners.end());

	/* 4. insert b2 ... bk in Jacobsthal order (bk is the leftover element when the size is odd) */
	size_t	pendCount = winners.size() + chain.size() % 2;
	size_t	previousJacobsthal = 1;
	size_t	currentJacobsthal = 3;

	while (previousJacobsthal < pendCount)
	{
		for (size_t b = std::min(currentJacobsthal, pendCount); b > previousJacobsthal; b--)
		{
			if (b <= winners.size())
			{
				size_t	winner = winners[b - 1];
				size_t	winnerPosition = std::find(mainChain.begin(), mainChain.end(), winner)
					- mainChain.begin();

				binaryInsertVector(mainChain, partner[winner], winnerPosition);
			}
			else
				binaryInsertVector(mainChain, chain.back(), mainChain.size());
		}

		size_t	nextJacobsthal = currentJacobsthal + 2 * previousJacobsthal;

		previousJacobsthal = currentJacobsthal;
		currentJacobsthal = nextJacobsthal;
	}
	chain = mainChain;
}

void	PmergeMe::printVector(std::string const &label) const
{
	std::cout << label;
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << " " << vec[i];
	std::cout << std::endl;
}

/* ========================================================================== */
/*                                 std::deque                                 */
/* ========================================================================== */

void	PmergeMe::fillDeque(int argc, char **argv)
{
	deq.clear();
	for (int i = 1; i < argc; i++)
	{
		std::istringstream	stream(argv[i]);
		std::string			token;
		size_t				sizeBefore = deq.size();

		while (stream >> token)
			deq.push_back(parseNumber(token));
		if (deq.size() == sizeBefore)
			throw std::invalid_argument("empty argument");
	}
}

void	PmergeMe::sortDeque(void)
{
	std::deque<size_t>	chain;
	std::deque<int>		sorted;

	for (size_t id = 0; id < deq.size(); id++)
		chain.push_back(id);
	mergeInsertDeque(chain);
	for (size_t i = 0; i < chain.size(); i++)
		sorted.push_back(deq[chain[i]]);
	deq = sorted;
}

void	PmergeMe::binaryInsertDeque(std::deque<size_t> &mainChain, size_t id, size_t bound)
{
	size_t	low = 0;
	size_t	high = bound;

	while (low < high)
	{
		size_t	middle = low + (high - low) / 2;

		if (deq[id] < deq[mainChain[middle]])
			high = middle;
		else
			low = middle + 1;
	}
	mainChain.insert(mainChain.begin() + low, id);
}

void	PmergeMe::mergeInsertDeque(std::deque<size_t> &chain)
{
	if (chain.size() < 2)
		return ;

	/* 1. pairs: partner[winner] = the smaller element it was paired with */
	std::deque<size_t>	winners;
	std::deque<size_t>	partner(deq.size());

	for (size_t i = 0; i + 1 < chain.size(); i += 2)
	{
		size_t	smaller = chain[i];
		size_t	larger = chain[i + 1];

		if (deq[smaller] > deq[larger])
			std::swap(smaller, larger);
		winners.push_back(larger);
		partner[larger] = smaller;
	}

	/* 2. recursion on the winners */
	mergeInsertDeque(winners);

	/* 3. main chain: b1 a1 a2 ... am */
	std::deque<size_t>	mainChain;

	mainChain.push_back(partner[winners[0]]);
	mainChain.insert(mainChain.end(), winners.begin(), winners.end());

	/* 4. insert b2 ... bk in Jacobsthal order (bk is the leftover element when the size is odd) */
	size_t	pendCount = winners.size() + chain.size() % 2;
	size_t	previousJacobsthal = 1;
	size_t	currentJacobsthal = 3;

	while (previousJacobsthal < pendCount)
	{
		for (size_t b = std::min(currentJacobsthal, pendCount); b > previousJacobsthal; b--)
		{
			if (b <= winners.size())
			{
				size_t	winner = winners[b - 1];
				size_t	winnerPosition = std::find(mainChain.begin(), mainChain.end(), winner)
					- mainChain.begin();

				binaryInsertDeque(mainChain, partner[winner], winnerPosition);
			}
			else
				binaryInsertDeque(mainChain, chain.back(), mainChain.size());
		}

		size_t	nextJacobsthal = currentJacobsthal + 2 * previousJacobsthal;

		previousJacobsthal = currentJacobsthal;
		currentJacobsthal = nextJacobsthal;
	}
	chain = mainChain;
}

/* ========================================================================== */

void	PmergeMe::run(int argc, char **argv)
{
	std::clock_t	start;
	double			vectorTime;
	double			dequeTime;

	/* the time covers the data management (parsing into the container) and the sort */
	start = std::clock();
	fillVector(argc, argv);
	vectorTime = elapsedMicroseconds(start);

	printVector("Before:");

	start = std::clock();
	sortVector();
	vectorTime += elapsedMicroseconds(start);

	start = std::clock();
	fillDeque(argc, argv);
	sortDeque();
	dequeTime = elapsedMicroseconds(start);

	printVector("After: ");
	std::cout << "Time to process a range of " << vec.size()
		<< " elements with std::vector : " << vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << deq.size()
		<< " elements with std::deque  : " << dequeTime << " us" << std::endl;
}
