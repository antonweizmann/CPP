#include "PresidentialPardonForm.hpp"
// Default constructor
PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 5, 25), _target("non existent")
{
    std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 5, 25), _target(target)
{
    std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
    return ;
}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src)
{
    std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
    *this = src;
    return ;
}

// Assignment operator overload
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
    std::cout << "PresidentialPardonForm Assignment operator called" << std::endl;
    if (this != &src)
    {

    }
    return (*this);
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "PresidentialPardonForm Destructor called" << std::endl;
    return ;
}

void    PresidentialPardonForm::action() const
{
    std::cout << _target << "has been pardoned by Zaphlod Beeblebrox" << std::endl;
}

std::string& PresidentialPardonForm::getTarget(void)
{
    return _target;
}
