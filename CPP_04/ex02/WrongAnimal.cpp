#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
	std::cout << "WrongAnimal constructed" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructed" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &src)
{
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	type = src.type;
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "I am the WrongAnimal!" << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (type);
}
