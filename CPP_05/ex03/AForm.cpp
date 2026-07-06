#include "AForm.hpp"

AForm::AForm(void) : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
	std::cout << "AForm constructed" << std::endl;
}

AForm::AForm(std::string const &name, int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	std::cout << "AForm constructed" << std::endl;
}

AForm::AForm(AForm const &src)
	: name(src.name), isSigned(src.isSigned),
		gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm(void)
{
	std::cout << "AForm destructed" << std::endl;
}

AForm	&AForm::operator=(AForm const &src)
{
	std::cout << "AForm copy assignment operator called" << std::endl;
	if (this != &src)
		isSigned = src.isSigned;
	return (*this);
}

std::string	AForm::getName(void) const
{
	return (name);
}

bool	AForm::getIsSigned(void) const
{
	return (isSigned);
}

int	AForm::getGradeToSign(void) const
{
	return (gradeToSign);
}

int	AForm::getGradeToExecute(void) const
{
	return (gradeToExecute);
}

void	AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw AForm::GradeTooLowException();
	isSigned = true;
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (!isSigned)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > gradeToExecute)
		throw AForm::GradeTooLowException();
	executeAction();
}

const char	*AForm::GradeTooHighException::what(void) const throw()
{
	return ("grade is too high");
}

const char	*AForm::GradeTooLowException::what(void) const throw()
{
	return ("grade is too low");
}

const char	*AForm::FormNotSignedException::what(void) const throw()
{
	return ("form is not signed");
}

std::ostream	&operator<<(std::ostream &out, AForm const &form)
{
	out << form.getName() << ", form status: "
		<< (form.getIsSigned() ? "signed" : "not signed")
		<< ", grade required to sign: " << form.getGradeToSign()
		<< ", grade required to execute: " << form.getGradeToExecute() << ".";
	return (out);
}
