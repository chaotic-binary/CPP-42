#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include "Form.hpp"

class ShrubberyCreationForm : public Form
{
public:
	ShrubberyCreationForm(std::string const &target);
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);

	virtual void	execute(Bureaucrat const & executor) const;

	class OpenFileException: public std::exception
	{
		virtual const char* what() const throw();
	};

private:
	ShrubberyCreationForm();
	static const std::string _trees[3];
};

#endif
