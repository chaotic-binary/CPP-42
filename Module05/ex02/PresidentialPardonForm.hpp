#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "Form.hpp"

class PresidentialPardonForm : public Form
{
public:
	PresidentialPardonForm(std::string const &target);
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	~PresidentialPardonForm();
	PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);

	virtual void	execute(Bureaucrat const & executor) const;

private:
	PresidentialPardonForm();
	const std::string _target;
};

#endif
