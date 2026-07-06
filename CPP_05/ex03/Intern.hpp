#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern
{
	private:
		AForm	*createShrubberyCreationForm(std::string const &target) const;
		AForm	*createRobotomyRequestForm(std::string const &target) const;
		AForm	*createPresidentialPardonForm(std::string const &target) const;

	public:
		Intern(void);
		Intern(Intern const &src);
		~Intern(void);

		Intern	&operator=(Intern const &src);

		AForm	*makeForm(std::string const &formName, std::string const &target) const;
};

#endif
