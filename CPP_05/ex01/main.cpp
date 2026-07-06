#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	std::cout << "--- Form with invalid grade ---" << std::endl;
	try
	{
		Form	invalid("Invalid Form", 0, 151);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "--- Successful signing ---" << std::endl;
	try
	{
		Bureaucrat	boss("Boss", 1);
		Form		taxForm("Tax Form", 50, 25);

		std::cout << taxForm << std::endl;
		boss.signForm(taxForm);
		std::cout << taxForm << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "--- Failed signing (grade too low) ---" << std::endl;
	try
	{
		Bureaucrat	intern("Intern", 150);
		Form		topSecret("Top Secret", 1, 1);

		std::cout << topSecret << std::endl;
		intern.signForm(topSecret);
		std::cout << topSecret << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "--- Signing at exact required grade ---" << std::endl;
	try
	{
		Bureaucrat	clerk("Clerk", 50);
		Form		requestForm("Request Form", 50, 25);

		clerk.signForm(requestForm);
		std::cout << requestForm << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return (0);
}
