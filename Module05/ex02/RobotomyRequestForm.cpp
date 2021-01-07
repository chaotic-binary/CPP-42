#include "RobotomyRequestForm.hpp"

/*RobotomyRequestForm::RobotomyRequestForm() {}*/

RobotomyRequestForm::RobotomyRequestForm(std::string const & target) \
	: Form("Robotomy Request", 72, 45), _target(target)
{

}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) \
	: Form(copy), _target(copy._target)
{}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
{
	Form::operator=(copy);
	*(const_cast<std::string*>(&_target)) = copy._target;
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	Form::execute(executor);
	std::cout << "* BZZZZ VZHVZHVZH BZZZZ *" << std::endl;
	if ((rand() % 100) > 50)
		std::cout << this->_target << " robotomized successfully" << std::endl;
	else
		std::cout << this->_target << " robotomization failed" << std::endl;
}
