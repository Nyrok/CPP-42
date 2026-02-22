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
	PhoneBook*	phoneBook = new PhoneBook;

	do
	{
		std::cout << '>';
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
		{
			Contact* contact = new Contact;
			std::cout << "First Name: ";
			std::getline(std::cin, firstName);
			contact->setFirstName(firstName);
			std::cout << "Last Name: ";
			std::getline(std::cin, lastName);
			contact->setLastName(lastName);
			std::cout << "Nickname: ";
			std::getline(std::cin, nickname);
			contact->setNickname(nickname);
			std::cout << "Phone number: ";
			std::getline(std::cin, phoneNumber);
			contact->setPhoneNumber(phoneNumber);
			std::cout << "Darkest Secret: ";
			std::getline(std::cin, darkestSecret);
			contact->setDarkestSecret(darkestSecret);
			if (!firstName.size() \
			|| !lastName.size() \
			|| !nickname.size() \
			|| !phoneNumber.size() \
			|| !darkestSecret.size())
			{
				delete contact;
				std::cout << "Error: One of the fields are empty!" << std::endl;
				continue ;
			}
			phoneBook->addContact(contact);
			std::cout << "Contact added in phonebook!" << std::endl;
		}
		else if (cmd == "SEARCH")
		{
			phoneBook->displayContacts();
			std::cout << "Select index: ";
			std::getline(std::cin, index);
			i = ft_atoi(index.c_str());
			if (i == -1 || i >= phoneBook->getContactSize())
			{
				std::cout << "The index provided is invalid." << std::endl;
				continue ;
			}
			Contact* contact = phoneBook->getContactAt(i);
			contact->displayFullInformations();
		}
	} while (cmd != "EXIT");
	delete phoneBook;
	return (0);
}
