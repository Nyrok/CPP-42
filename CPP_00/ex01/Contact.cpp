#include "Contact.hpp"

void	Contact::displayInlineInformations(void)
{
	std::string	fields[3] = {firstName, lastName, nickname};
	for (int i = 0; i < 3; i++)
	{
		if (fields[i].size() > 10)
			std::cout << fields[i].substr(0, 9) << '.';
		else
			std::cout << std::string(10 - fields[i].size(), ' ') << fields[i];
		if (i < 2)
			std::cout << '|';
	}
	std::cout << std::endl;
}

void	Contact::displayFullInformations(void)
{
	std::cout << "[CONTACT INFOS]" << std::endl;
	std::cout << "First Name:\t" << firstName << std::endl;
	std::cout << "Last Name:\t" << lastName << std::endl;
	std::cout << "Nickname:\t" << nickname << std::endl;
	std::cout << "Phone Number:\t" << phoneNumber << std::endl;
	std::cout << "Darkest Secret:\t" << darkestSecret << std::endl;
	std::cout << std::endl;
}

void	Contact::setFirstName(std::string arg)
{
	firstName = arg;
}

void	Contact::setLastName(std::string arg)
{
	lastName = arg;
}

void	Contact::setNickname(std::string arg)
{
	nickname = arg;
}

void	Contact::setPhoneNumber(std::string arg)
{
	phoneNumber = arg;
}

void	Contact::setDarkestSecret(std::string arg)
{
	darkestSecret = arg;
}
