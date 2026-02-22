#include <iostream>

#ifndef __CONTACT_H__
# define __CONTACT_H__

class Contact
{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickname;
		std::string	phoneNumber;
		std::string	darkestSecret;
	
	public:
		void	setFirstName(std::string arg);
		void	setLastName(std::string arg);
		void	setNickname(std::string arg);
		void	setPhoneNumber(std::string arg);
		void	setDarkestSecret(std::string arg);
		void	displayInlineInformations(void);
		void	displayFullInformations(void);
};

#endif