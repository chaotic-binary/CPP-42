#include "PresidentialPardonForm.hpp"

/*PresidentialPardonForm::PresidentialPardonForm() {}*/

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
	: Form("Presidential Pardon", 25, 5, target)
{}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) \
	: Form(copy)
{}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	Form::operator=(copy);
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	Form::execute(executor);
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox.\n";
}