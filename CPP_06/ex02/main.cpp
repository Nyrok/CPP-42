#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <exception>
#include <cstdlib>
#include <ctime>

Base	*generate(void)
{
	switch (std::rand() % 3)
	{
		case 0:
			std::cout << "Generated: A" << std::endl;
			return (new A());
		case 1:
			std::cout << "Generated: B" << std::endl;
			return (new B());
		default:
			std::cout << "Generated: C" << std::endl;
			return (new C());
	}
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::exception &e)
	{
	}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::exception &e)
	{
	}
	std::cout << "Unknown" << std::endl;
}

int	main(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	for (int i = 0; i < 5; i++)
	{
		Base	*p = generate();

		std::cout << "identify(pointer):   ";
		identify(p);
		std::cout << "identify(reference): ";
		identify(*p);
		delete p;
		std::cout << std::endl;
	}
	return (0);
}
