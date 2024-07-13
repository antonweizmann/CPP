#include "ShrubberyCreationForm.hpp"

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm(void) : _target("non existent"), AForm("ShrubberyCreationForm", 137, 145)
{
    std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : _target(target), AForm("ShrubberyCreationForm", 137, 145)
{
    std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
    return ;
}
ShrubberyCreationForm::ShrubberyCreationForm(void) : _target("non existent"), AForm("ShrubberyCreationForm", 137, 145)
{
    std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
    return ;
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src)
{
    std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
    *this = src;
    return ;
}

// Assignment operator overload
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
    std::cout << "ShrubberyCreationForm Assignment operator called" << std::endl;
    if (this != &src)
    {

    }
    return (*this);
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
    return ;
}

