#include "PhoneBook.hpp"
#include "utils.hpp"
#include <sstream>

PhoneBook::PhoneBook()
{
	contactSize = 0;
}

PhoneBook::~PhoneBook()
{
	for (int i = 0; i < contactSize; i++)
	{
		delete contacts[i];
	}
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
			std::cout << fields[i] << std::string(10 - fields[i].size(), ' ');
		if (i < 3)
			std::cout << '|';
	}
	std::cout << std::endl;
	while (i < contactSize)
	{
		std::cout << i << std::string(10 - countDigits(i), ' ') << '|';
		contacts[i]->displayInlineInformations();
		i++;
	}
}

void	PhoneBook::addContact(Contact* contact)
{
	if (contactSize == 7)
	{
		for (int i = 1; i < 8; i++)
		{
			contacts[i - 1] = contacts[i];
		}
		contacts[contactSize] = contact;
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

Contact*	PhoneBook::getContactAt(int index)
{
	return contacts[index];
}