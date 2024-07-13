#include "Bureaucrat.hpp"
#include "AForm.hpp"

// Default constructor
Bureaucrat::Bureaucrat(void) : _name("Default Bureaucrat"), _grade(150)
{
    std::cout << "Bureaucrat Default constructor called" << std::endl;
    return ;
}

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(150)
{
    std::cout << "Bureaucrat Name constructor called" << std::endl;
    return ;
}

Bureaucrat::Bureaucrat(std::string name, size_t grade) : _name(name), _grade(grade)
{
    std::cout << "Bureaucrat Name and Grade constructor called" << std::endl;
    if (_grade > 150)
    {
        throw GradeTooLowException();
        std::cerr << "Grade too low, instead set to 150" << std::endl;
        _grade = 150;
    }
    if (_grade < 1)
    {
        throw GradeTooHighException();
        std::cerr << "Grade too high, instead set to 1" << std::endl;
        _grade = 1;
    }
    return ;
}

Bureaucrat::Bureaucrat(size_t grade) : _name("Default Bureaucrat"), _grade(grade)
{
    std::cout << "Bureaucrat Grade constructor called" << std::endl;
    if (_grade > 150)
    {
        throw GradeTooLowException();
        std::cerr << "Grade too low, instead set to 150" << std::endl;
        _grade = 150;
    }
    if (_grade < 1)
    {
        throw GradeTooHighException();
        std::cerr << "Grade too high, instead set to 1" << std::endl;
        _grade = 1;
    }
    return ;
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    std::cout << "Bureaucrat Copy constructor called" << std::endl;
    *this = other;
    return ;
}

// Assignment operator overload
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Bureaucrat Assignment operator called" << std::endl;
    if (this != &other)
    {
        _grade = other._grade;
        _name = other._name;
    }
    return (*this);
}

// Destructor
Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Bureaucrat Destructor called" << std::endl;
    return ;
}

size_t Bureaucrat::getGrade() const
{
    return _grade;
}

std::string Bureaucrat::getName() const
{
    return _name;
}

void    Bureaucrat::incrementGrade()
{
    try
    {
        if (_grade == 1)
            throw GradeTooHighException();
        _grade -= 1;
        std::cout << "Incremented grade of " << _name << std::endl;
    }
    catch (const GradeTooHighException& e)
    {
       std::cerr << "Incrementing grade of " << _name << "failed: " << e.what() << std::endl;
    }
}

void    Bureaucrat::signForm(AForm& form) const
{
    try
    {
        if (form.getSigned() == true)
            throw std::exception();
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch(const GradeTooLowException& e)
    {
        std::cerr << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
    catch(const std::exception& b)
    {
        std::cerr << form.getName() << " is already signed." << std::endl;
    }

}

void    Bureaucrat::decrementGrade()
{
    try
    {
        if (_grade == 150)
            throw GradeTooLowException();
        _grade += 1;
        std::cout << "Decremented grade of " << _name << std::endl;
    }
    catch (const GradeTooLowException& e)
    {
       std::cerr << "Decrementing grade of " << _name << " failed: " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low!");
}

std::ostream&	operator<<(std::ostream& output, const Bureaucrat *temp)
{
    output << temp->getName() << ", bureaucrat grade " << temp->getGrade() << std::endl;
    return (output);
}
