#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	a("Alice");
	ScavTrap	b("Bob");

	a.attack("Bob");
	b.takeDamage(20);
	b.beRepaired(10);
	a.guardGate();

	// Test energy drain
	for (int i = 0; i < 50; i++)
		b.attack("Alice");
	b.attack("Alice");

	// Test lethal damage
	a.takeDamage(200);
	a.attack("Bob");

	return (0);
}
