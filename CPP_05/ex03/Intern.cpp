#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{
	std::cout << "Intern constructed" << std::endl;
}

Intern::Intern(Intern const &src)
{
	(void)src;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern::~Intern(void)
{
	std::cout << "Intern destructed" << std::endl;
}

Intern	&Intern::operator=(Intern const &src)
{
	std::cout << "Intern copy assignment operator called" << std::endl;
	(void)src;
	return (*this);
}

AForm	*Intern::createShrubberyCreationForm(std::string const &target) const
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::createRobotomyRequestForm(std::string const &target) const
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::createPresidentialPardonForm(std::string const &target) const
{
	return (new PresidentialPardonForm(target));
}

AForm	*Intern::makeForm(std::string const &formName, std::string const &target) const
{
	std::string	names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm		*(Intern::*creators[3])(std::string const &) const = {
		&Intern::createShrubberyCreationForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm};

	for (int i = 0; i < 3; i++)
	{
		if (names[i] == formName)
		{
			AForm	*form = (this->*creators[i])(target);

			std::cout << "Intern creates " << form->getName() << std::endl;
			return (form);
		}
	}
	std::cout << "Intern couldn't create form because " << formName << " does not exist" << std::endl;
	return (NULL);
}
