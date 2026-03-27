#include "Cat.hpp"

Cat::Cat(void)
{
	type = "Cat";
	brain = new Brain();
	std::cout << "Cat constructed" << std::endl;
}

Cat::Cat(Cat const &src) : Animal(src)
{
	std::cout << "Cat copy constructor called" << std::endl;
	brain = new Brain(*src.brain);
}

Cat::~Cat(void)
{
	delete brain;
	std::cout << "Cat destructed" << std::endl;
}

Cat	&Cat::operator=(Cat const &src)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &src)
	{
		Animal::operator=(src);
		*brain = *src.brain;
	}
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow!" << std::endl;
}
