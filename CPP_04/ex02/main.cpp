#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int	main(void)
{
	std::cout << "--- Abstract class test (AAnimal cannot be instantiated) ---" << std::endl;
	const AAnimal*	j = new Dog();
	const AAnimal*	i = new Cat();

	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;
	i->makeSound();
	j->makeSound();

	std::cout << std::endl;
	std::cout << "--- Array of animals ---" << std::endl;
	const AAnimal*	animals[4];
	for (int k = 0; k < 4; k++)
	{
		if (k < 2)
			animals[k] = new Dog();
		else
			animals[k] = new Cat();
	}

	std::cout << std::endl;
	std::cout << "--- Deleting animals ---" << std::endl;
	for (int k = 0; k < 4; k++)
		delete animals[k];

	delete j;
	delete i;

	return (0);
}
