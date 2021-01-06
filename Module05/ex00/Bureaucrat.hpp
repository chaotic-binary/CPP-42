#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
public:
	Bureaucrat(const std::string & name, int grade);
	Bureaucrat(const Bureaucrat &copy);
	~Bureaucrat();
	Bureaucrat &operator=(const Bureaucrat &copy);

	const std::string & getName() const;
	int					getGrade() const;
	void				incGrade();
	void				decGrade();

	class GradeTooHighException: public std::exception
	{
		virtual const char* what() const throw();
	};

	class GradeTooLowException: public std::exception
	{
		virtual const char* what() const throw();
	};

private:
	Bureaucrat();
	const std::string 	_name;
	int					_grade;
	void				_check_grade(int grade);
};

std::ostream	&operator<<(std::ostream & os, const Bureaucrat & bureaucrat);

#endif
