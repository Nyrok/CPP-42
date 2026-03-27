#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	std::cout << "--- Array of animals ---" << std::endl;
	const Animal*	animals[4];
	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << std::endl;
	std::cout << "--- Sounds ---" << std::endl;
	for (int i = 0; i < 4; i++)
		animals[i]->makeSound();

	std::cout << std::endl;
	std::cout << "--- Deep copy test ---" << std::endl;
	Dog	original;
	original.makeSound();
	Dog	copy(original);
	copy.makeSound();

	std::cout << std::endl;
	std::cout << "--- Deleting animals ---" << std::endl;
	for (int i = 0; i < 4; i++)
		delete animals[i];

	return (0);
}
