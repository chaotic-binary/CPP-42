#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
class Form;
# include "Bureaucrat.hpp"

class Form
{
public:
	Form(std::string const &name, int const signGrade, int const execGrade);
	Form(const Form &copy);
	~Form();
	Form &operator=(const Form &copy);

	void				beSigned(Bureaucrat const &bureaucrat);

	std::string const	&getName(void) const;
	bool				isSigned(void) const;
	int					getSignGrade(void) const;
	int					getExecGrade(void) const;

	class GradeTooHighException: public std::exception
	{
		virtual const char* what() const throw();
	};
	class GradeTooLowException: public std::exception
	{
		virtual const char* what() const throw();
	};
	class FormAlreadySignedException: public std::exception
	{
		virtual const char* what() const throw();
	};

private:
	Form();
	const std::string 	_name;
	bool				_signed;
	const int			_signGrade;
	const int			_execGrade;
	void				_check_grade(int signGrade, int execGrade);
};

std::ostream &operator<<(std::ostream &os, Form const &form);

#endif
