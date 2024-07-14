#include "RobotomyRequestForm.hpp"

// Default constructor
RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 45, 72),  _target("non existent")
{
    std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 45, 72), _target(target)
{
    std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
    return ;
}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src)
{
    std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
    *this = src;
    return ;
}

// Assignment operator overload
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
    std::cout << "RobotomyRequestForm Assignment operator called" << std::endl;
    if (this != &src)
    {

    }
    return (*this);
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "RobotomyRequestForm Destructor called" << std::endl;
    return ;
}

void    RobotomyRequestForm::action(void) const
{
    std::cout << "Drrrrrr Drrrr Drrr (Some Drilling Noises)" << std::endl;
    switch (rand() % 2)
    {
        case 0:
            std::cout << _target << " has been robotomized succesfully." << std::endl;
            break;
        case 1:
            std::cout << "robotomy failed." << std::endl;
            break;
    }
}

std::string& RobotomyRequestForm::getTarget(void)
{
    return _target;
}
