#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <cstddef>
# include <deque>
# include <string>
# include <vector>

class PmergeMe
{
	private:
		std::vector<int>	vec;
		std::deque<int>		deq;

		static int	parseNumber(std::string const &token);

		void	fillVector(int argc, char **argv);
		void	sortVector(void);
		void	mergeInsertVector(std::vector<size_t> &chain);
		void	binaryInsertVector(std::vector<size_t> &mainChain, size_t id, size_t bound);
		void	printVector(std::string const &label) const;

		void	fillDeque(int argc, char **argv);
		void	sortDeque(void);
		void	mergeInsertDeque(std::deque<size_t> &chain);
		void	binaryInsertDeque(std::deque<size_t> &mainChain, size_t id, size_t bound);

	public:
		PmergeMe(void);
		PmergeMe(PmergeMe const &src);
		~PmergeMe(void);

		PmergeMe	&operator=(PmergeMe const &src);

		void	run(int argc, char **argv);
};

#endif
