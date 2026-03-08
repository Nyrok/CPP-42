#include <iostream>

#ifndef __WEAPON_H__
# define __WEAPON_H__

class Weapon
{
	private:
		std::string	type;

	public:
		Weapon(std::string type);
		const std::string&	getType(void) const;
		void				setType(std::string type);
};

#endif
