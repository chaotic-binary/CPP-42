#include "PresidentialPardonForm.hpp"

/*PresidentialPardonForm::PresidentialPardonForm() {}*/

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
	: Form("Presidential Pardon", 25, 5), _target(target)
{}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) \
	: Form(copy), _target(copy._target)
{}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &copy)
{
	Form::operator=(copy);
	*(const_cast<std::string*>(&_target)) = copy._target;
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	Form::execute(executor);
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox.\n";
}