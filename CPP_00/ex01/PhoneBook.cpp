#include "PhoneBook.hpp"
#include "utils.hpp"
#include <sstream>

PhoneBook::PhoneBook()
{
	contactSize = 0;
}

void	PhoneBook::displayContacts(void)
{
	int					i = 0;
	std::stringstream	ss;

	std::string	fields[4] = {"index", "first name", "last name", "nickname"};
	for (int i = 0; i < 4; i++)
	{
		if (fields[i].size() > 10)
			std::cout << fields[i].substr(0, 10);
		else
			std::cout << std::string(10 - fields[i].size(), ' ') << fields[i];
		if (i < 3)
			std::cout << '|';
	}
	std::cout << std::endl;
	while (i < contactSize)
	{
		std::cout << std::string(10 - countDigits(i), ' ') << i << '|';
		contacts[i].displayInlineInformations();
		i++;
	}
}

void	PhoneBook::addContact(Contact contact)
{
	if (contactSize == 8)
	{
		for (int i = 1; i < 8; i++)
		{
			contacts[i - 1] = contacts[i];
		}
		contacts[7] = contact;
	}
	else
	{
		contacts[contactSize] = contact;
		contactSize++;
	}
}

int	PhoneBook::getContactSize(void)
{
	return contactSize;
}

Contact	PhoneBook::getContactAt(int index)
{
	return contacts[index];
}
