#include "Form.hpp"

Form::Form(void) : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
	std::cout << "Form constructed" << std::endl;
}

Form::Form(std::string const &name, int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form constructed" << std::endl;
}

Form::Form(Form const &src)
	: name(src.name), isSigned(src.isSigned),
		gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form(void)
{
	std::cout << "Form destructed" << std::endl;
}

Form	&Form::operator=(Form const &src)
{
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &src)
		isSigned = src.isSigned;
	return (*this);
}

std::string	Form::getName(void) const
{
	return (name);
}

bool	Form::getIsSigned(void) const
{
	return (isSigned);
}

int	Form::getGradeToSign(void) const
{
	return (gradeToSign);
}

int	Form::getGradeToExecute(void) const
{
	return (gradeToExecute);
}

void	Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw Form::GradeTooLowException();
	isSigned = true;
}

const char	*Form::GradeTooHighException::what(void) const throw()
{
	return ("grade is too high");
}

const char	*Form::GradeTooLowException::what(void) const throw()
{
	return ("grade is too low");
}

std::ostream	&operator<<(std::ostream &out, Form const &form)
{
	out << form.getName() << ", form status: "
		<< (form.getIsSigned() ? "signed" : "not signed")
		<< ", grade required to sign: " << form.getGradeToSign()
		<< ", grade required to execute: " << form.getGradeToExecute() << ".";
	return (out);
}
