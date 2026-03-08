#include <iostream>

#ifndef __ZOMBIE_H__
# define __ZOMBIE_H__

class Zombie
{
	private:
		std::string	name;

	public:
		Zombie(void);
		~Zombie(void);
		void	setName(std::string name);
		void	announce(void);
};

Zombie*	zombieHorde(int N, std::string name);

#endif
