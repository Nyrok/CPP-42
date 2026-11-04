#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	rates;

		static bool	isValidDate(std::string const &date);
		static bool	isValidNumber(std::string const &str);
		void		addRate(std::string const &line);
		void		processLine(std::string const &line) const;

	public:
		BitcoinExchange(void);
		BitcoinExchange(BitcoinExchange const &src);
		~BitcoinExchange(void);

		BitcoinExchange	&operator=(BitcoinExchange const &src);

		void	loadDatabase(std::string const &filename);
		void	processInput(std::string const &filename) const;
};

#endif
