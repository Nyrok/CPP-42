#include "Bureaucrat.hpp"

int	main(void)
{
	std::cout << "--- Valid bureaucrat ---" << std::endl;
	try
	{
		Bureaucrat	bob("Bob", 2);

		std::cout << bob << std::endl;
		bob.incrementGrade();
		std::cout << bob << std::endl;
		bob.incrementGrade();
		std::cout << "This line should not be printed" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "--- Grade too high at construction ---" << std::endl;
	try
	{
		Bureaucrat	overachiever("Overachiever", 0);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "--- Grade too low at construction ---" << std::endl;
	try
	{
		Bureaucrat	slacker("Slacker", 151);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "--- Decrement below lowest grade ---" << std::endl;
	try
	{
		Bureaucrat	joe("Joe", 150);

		std::cout << joe << std::endl;
		joe.decrementGrade();
		std::cout << "This line should not be printed" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "--- Copy and assignment ---" << std::endl;
	try
	{
		Bureaucrat	original("Original", 42);
		Bureaucrat	copy(original);
		Bureaucrat	assigned("Assigned", 100);

		assigned = original;
		std::cout << copy << std::endl;
		std::cout << assigned << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return (0);
}
