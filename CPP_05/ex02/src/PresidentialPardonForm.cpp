#include "PresidentialPardonForm.hpp"
// Default constructor
PresidentialPardonForm::PresidentialPardonForm(void) : _target("non existent"), AForm("PresidentialPardonForm", 5, 25)
{
    std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : _target(target), AForm("PresidentialPardonForm", 5, 25)
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

