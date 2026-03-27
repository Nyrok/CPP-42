#include "Animal.hpp"

Animal::Animal(void) : type("Animal")
{
	std::cout << "Animal constructed" << std::endl;
}

Animal::Animal(Animal const &src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructed" << std::endl;
}

Animal	&Animal::operator=(Animal const &src)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	type = src.type;
	return (*this);
}

void	Animal::makeSound(void) const
{
	std::cout << "..." << std::endl;
}

std::string	Animal::getType(void) const
{
	return (type);
}
