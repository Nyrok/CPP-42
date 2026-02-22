#include <iostream>
#include "Contact.hpp"

#ifndef __PHONEBOOK_H__
# define __PHONEBOOK_H__

class PhoneBook
{
	private:
		Contact		contacts[8];
		int			contactSize;

	public:
		PhoneBook();
		void		addContact(Contact contact);
		void		displayContacts(void);
		int			getContactSize(void);
		Contact		getContactAt(int index);
};

#endif