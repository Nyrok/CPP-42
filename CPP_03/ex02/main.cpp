#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	a("Clappy");
	ScavTrap	b("Scavvy");
	FragTrap	c("Fraggy");

	a.attack("Scavvy");
	b.attack("Fraggy");
	c.attack("Clappy");

	a.takeDamage(30);
	b.takeDamage(30);
	c.takeDamage(30);

	a.beRepaired(5);
	b.beRepaired(5);
	c.beRepaired(5);

	b.guardGate();
	c.highFivesGuys();

	return (0);
}
