#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain constructed" << std::endl;
}

Brain::Brain(Brain const &src)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructed" << std::endl;
}

Brain	&Brain::operator=(Brain const &src)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = src.ideas[i];
	return (*this);
}

std::string	Brain::getIdea(int index) const
{
	return (ideas[index]);
}

void	Brain::setIdea(int index, std::string idea)
{
	ideas[index] = idea;
}
