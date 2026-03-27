#include "Dog.hpp"

Dog::Dog(void)
{
	type = "Dog";
	brain = new Brain();
	std::cout << "Dog constructed" << std::endl;
}

Dog::Dog(Dog const &src) : AAnimal(src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	brain = new Brain(*src.brain);
}

Dog::~Dog(void)
{
	delete brain;
	std::cout << "Dog destructed" << std::endl;
}

Dog	&Dog::operator=(Dog const &src)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &src)
	{
		AAnimal::operator=(src);
		*brain = *src.brain;
	}
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Woof!" << std::endl;
}
