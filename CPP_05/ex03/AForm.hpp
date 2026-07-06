#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeToSign;
		const int			gradeToExecute;

	protected:
		virtual void		executeAction(void) const = 0;

	public:
		AForm(void);
		AForm(std::string const &name, int gradeToSign, int gradeToExecute);
		AForm(AForm const &src);
		virtual ~AForm(void);

		AForm		&operator=(AForm const &src);

		std::string	getName(void) const;
		bool		getIsSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExecute(void) const;
		void		beSigned(Bureaucrat const &bureaucrat);
		void		execute(Bureaucrat const &executor) const;

		class GradeTooHighException : public std::exception
		{
			public:
				const char	*what(void) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char	*what(void) const throw();
		};

		class FormNotSignedException : public std::exception
		{
			public:
				const char	*what(void) const throw();
		};
};

std::ostream	&operator<<(std::ostream &out, AForm const &form);

#endif
