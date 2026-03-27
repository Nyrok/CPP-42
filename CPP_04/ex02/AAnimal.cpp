#include "AAnimal.hpp"

AAnimal::AAnimal(void) : type("AAnimal")
{
	std::cout << "AAnimal constructed" << std::endl;
}

AAnimal::AAnimal(AAnimal const &src)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = src;
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructed" << std::endl;
}

AAnimal	&AAnimal::operator=(AAnimal const &src)
{
	std::cout << "AAnimal copy assignment operator called" << std::endl;
	type = src.type;
	return (*this);
}

std::string	AAnimal::getType(void) const
{
	return (type);
}
