#include "Form.hpp"

/*Form::Form() {}*/

Form::Form(std::string const &name, const int  signGrade, const int execGrade) \
	:	_name(name), \
		_signed(false), \
		_signGrade(signGrade), \
		_execGrade(execGrade)
{
	_check_grade(signGrade, execGrade);
}

Form::~Form() {}

Form::Form(const Form &copy)\
	:	_name(copy._name), \
		_signed(copy._signed), \
		_signGrade(copy._signGrade), \
		_execGrade(copy._execGrade)

{
	_check_grade(copy._signGrade, copy._execGrade);
}

Form	&Form::operator=(const Form &copy)
{
	if (this == &copy)
		return (*this);
	_check_grade(copy._signGrade, copy._execGrade);
	*(const_cast<std::string*>(&_name)) = copy._name;
	*(const_cast<int*>(&_signGrade)) = copy._signGrade;
	*(const_cast<int*>(&_execGrade)) = copy._execGrade;
	this->_signed = copy._signed;
	return (*this);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form: Grade too High";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form: Grade too Low";
}

const char* Form::FormAlreadySignedException::what() const throw()
{
	return "Form: The Form is already signed";
}

std::string const &Form::getName(void) const
{
	return (this->_name);
}

bool Form::isSigned(void) const
{
	return (this->_signed);
}

int Form::getSignGrade(void) const
{
	return (this->_signGrade);
}

int Form::getExecGrade(void) const
{
	return (this->_execGrade);
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (this->_signed)
		throw Form::FormAlreadySignedException();
	else if (bureaucrat.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

void Form::_check_grade(int signGrade, int execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &os, Form const &form)
{
	os << "Form " << form.getName() << ": " \
		<< ((form.isSigned()) ? "Signed" : "Not signed") \
		<< ", to Sign: " << form.getSignGrade() \
		<< ", to Execute: " << form.getExecGrade() << std::endl;
	return (os);
}