#include "Intern.hpp"

// Default constructor
Intern::Intern(void)
{
    std::cout << "Intern Default constructor called" << std::endl;
    return ;
}

// Copy constructor
Intern::Intern(const Intern &src)
{
    std::cout << "Intern Copy constructor called" << std::endl;
    *this = src;
    return ;
}

// Assignment operator overload
Intern &Intern::operator=(const Intern &src)
{
    std::cout << "Intern Assignment operator called" << std::endl;
    if (this != &src)
    {

    }
    return (*this);
}

// Destructor
Intern::~Intern(void)
{
    std::cout << "Intern Destructor called" << std::endl;
    return ;
}

AForm* createPresidentialForm(std::string target)
{
    std::cout << "Intern creates PresidentialPardonForm" << std::endl;
    return new PresidentialPardonForm(target);
}

AForm* createRobotomyForm(std::string target)
{
    std::cout << "Intern creates RobotomyRequestForm" << std::endl;
    return new RobotomyRequestForm(target);
}
AForm* createShrubberyForm(std::string target)
{
    std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(std::string form_name, std::string target)
{
    std::string form_names[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
    AForm*(* form_pointers[])(std::string) = {createPresidentialForm, createRobotomyForm, createShrubberyForm};
    for (int i = 0; i < 3; i++)
    {
        if (form_name == form_names[i])
            return form_pointers[i](target);
    }
    std::cout << "Intern did not find a Form called: " << form_name << std::endl;
    return NULL;
}
