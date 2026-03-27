#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	type = "WrongCat";
	std::cout << "WrongCat constructed" << std::endl;
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal(src)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = src;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructed" << std::endl;
}

WrongCat	&WrongCat::operator=(WrongCat const &src)
{
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	WrongAnimal::operator=(src);
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Wrong Meow!" << std::endl;
}
