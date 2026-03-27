#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	private:
		std::string	ideas[100];

	public:
		Brain(void);
		Brain(Brain const &src);
		~Brain(void);

		Brain		&operator=(Brain const &src);

		std::string	getIdea(int index) const;
		void		setIdea(int index, std::string idea);
};

#endif
