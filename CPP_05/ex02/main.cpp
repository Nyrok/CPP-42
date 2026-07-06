#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	std::srand(std::time(NULL));

	std::cout << "--- Execute unsigned form ---" << std::endl;
	try
	{
		Bureaucrat				boss("Boss", 1);
		ShrubberyCreationForm	shrubbery("home");

		boss.executeForm(shrubbery);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "--- Sign and execute ShrubberyCreationForm ---" << std::endl;
	try
	{
		Bureaucrat				boss("Boss", 1);
		ShrubberyCreationForm	shrubbery("home");

		boss.signForm(shrubbery);
		boss.executeForm(shrubbery);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "--- Sign and execute RobotomyRequestForm ---" << std::endl;
	try
	{
		Bureaucrat			boss("Boss", 1);
		RobotomyRequestForm	robotomy("Bender");

		boss.signForm(robotomy);
		boss.executeForm(robotomy);
		boss.executeForm(robotomy);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "--- Sign and execute PresidentialPardonForm ---" << std::endl;
	try
	{
		Bureaucrat				boss("Boss", 1);
		PresidentialPardonForm	pardon("Arthur Dent");

		boss.signForm(pardon);
		boss.executeForm(pardon);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "--- Executor grade too low ---" << std::endl;
	try
	{
		Bureaucrat				boss("Boss", 1);
		Bureaucrat				clerk("Clerk", 140);
		ShrubberyCreationForm	shrubbery("garden");

		boss.signForm(shrubbery);
		clerk.executeForm(shrubbery);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return (0);
}
