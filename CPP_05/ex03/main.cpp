#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	std::srand(std::time(NULL));

	std::cout << "--- Intern creates RobotomyRequestForm ---" << std::endl;
	try
	{
		Intern	someRandomIntern;
		AForm	*rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf)
		{
			Bureaucrat	boss("Boss", 1);

			boss.signForm(*rrf);
			boss.executeForm(*rrf);
			delete rrf;
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "--- Intern creates ShrubberyCreationForm ---" << std::endl;
	try
	{
		Intern	intern;
		AForm	*form;

		form = intern.makeForm("shrubbery creation", "home");
		if (form)
		{
			std::cout << *form << std::endl;
			delete form;
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "--- Intern creates PresidentialPardonForm ---" << std::endl;
	try
	{
		Intern	intern;
		AForm	*form;

		form = intern.makeForm("presidential pardon", "Arthur Dent");
		if (form)
		{
			std::cout << *form << std::endl;
			delete form;
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "--- Intern creates unknown form ---" << std::endl;
	try
	{
		Intern	intern;
		AForm	*form;

		form = intern.makeForm("coffee making", "office");
		if (!form)
			std::cout << "No form was created" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return (0);
}
