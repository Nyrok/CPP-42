#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	a("Alice");
	ClapTrap	b("Bob");

	a.attack("Bob");
	b.takeDamage(0);
	b.attack("Alice");
	a.takeDamage(0);

	a.beRepaired(5);

	// Drain energy
	for (int i = 0; i < 10; i++)
		a.attack("Bob");

	// No energy left
	a.attack("Bob");
	a.beRepaired(1);

	// Take lethal damage
	b.takeDamage(100);
	b.attack("Alice");
	b.beRepaired(1);
	b.takeDamage(1);

	return (0);
}
