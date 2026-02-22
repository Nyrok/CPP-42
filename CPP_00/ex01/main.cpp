#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "utils.hpp"
#include <iostream>
#include <cstdlib>

int main(void)
{
	std::string	cmd;
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;
	std::string	index;
	int			i;
	PhoneBook	phoneBook;

	do
	{
		std::cout << '>';
		if (!std::getline(std::cin, cmd))
			break ;
		if (cmd == "ADD")
		{
			Contact contact;
			std::cout << "First Name: ";
			if (!std::getline(std::cin, firstName))
				break ;
			contact.setFirstName(firstName);
			std::cout << "Last Name: ";
			if (!std::getline(std::cin, lastName))
				break ;
			contact.setLastName(lastName);
			std::cout << "Nickname: ";
			if (!std::getline(std::cin, nickname))
				break ;
			contact.setNickname(nickname);
			std::cout << "Phone number: ";
			if (!std::getline(std::cin, phoneNumber))
				break ;
			contact.setPhoneNumber(phoneNumber);
			std::cout << "Darkest Secret: ";
			if (!std::getline(std::cin, darkestSecret))
				break ;
			contact.setDarkestSecret(darkestSecret);
			if (!firstName.size() \
			|| !lastName.size() \
			|| !nickname.size() \
			|| !phoneNumber.size() \
			|| !darkestSecret.size())
			{
				std::cout << "Error: One of the fields are empty!" << std::endl;
				continue ;
			}
			phoneBook.addContact(contact);
			std::cout << "Contact added in phonebook!" << std::endl;
		}
		else if (cmd == "SEARCH")
		{
			phoneBook.displayContacts();
			std::cout << "Select index: ";
			if (!std::getline(std::cin, index))
				break ;
			i = ft_atoi(index.c_str());
			if (i == -1 || i >= phoneBook.getContactSize())
			{
				std::cout << "The index provided is invalid." << std::endl;
				continue ;
			}
			Contact contact = phoneBook.getContactAt(i);
			contact.displayFullInformations();
		}
	} while (cmd != "EXIT");
	return (0);
}
