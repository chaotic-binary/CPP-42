#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string & name, int grade) \
	: _name(name)
{
	_check_grade(grade);
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) \
	: _name(copy._name), _grade(copy._grade)
{
	_check_grade(copy._grade);
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy)
{
	if (this == &copy)
		return (*this);
	_check_grade(copy._grade);
	*(const_cast<std::string*>(&_name)) = copy._name;
	this->_grade = copy._grade;
	return (*this);
}

std::string const	&Bureaucrat::getName(void) const
{
	return (this->_name);
}

int 				Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void				Bureaucrat::decGrade()
{
	if ((this->_grade + 1) > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = this->_grade + 1;
}

void				Bureaucrat::incGrade()
{
	if ((this->_grade - 1) < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade = this->_grade - 1;
}

const char*			Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat's grade is  too high";
}

const char*			Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat's grade is too low";
}

void				Bureaucrat::_check_grade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

void				Bureaucrat::signForm(Form & form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signs " << form.getName() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << this->_name << " cannot sign " << form.getName() << " because ";
		std::cerr << e.what() << std::endl;
	}
}

void				Bureaucrat::executeForm(Form const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executes " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " cannot execute " << form.getName() << " because ";
		std::cerr << e.what() << std::endl;
	}
}

std::ostream		&operator<<(std::ostream & os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << "'s grade: " << bureaucrat.getGrade() << std::endl;
	return (os);
}