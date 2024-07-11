#include "Form.hpp"

// Default constructor
Form::Form(void) : _name("Default Form"), _signed(false), _grade_to_exec(150), _grade_to_sign(150)
{
    std::cout << "Form Default constructor called" << std::endl;
    return ;
}

Form::Form(std::string name, bool issigned, int grade_to_exec, int grade_to_sign) : _name(name), _signed(issigned), _grade_to_exec(grade_to_exec), _grade_to_sign(grade_to_sign)
{
    std::cout << "Form Default constructor called" << std::endl;
     if (_grade_to_exec > 150 || _grade_to_sign > 150)
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
Form::Form(const Form &other)
{
    std::cout << "Form Copy constructor called" << std::endl;
    *this = other;
    return ;
}

// Assignment operator overload
Form &Form::operator=(const Form &other)
{
    std::cout << "Form Assignment operator called" << std::endl;
    if (this != &other)
    {
        _signed = other._signed;
        _name = other._name;
        _grade_to_exec = other._grade_to_exec;
        _grade_to_sign = other._grade_to_sign;
    }
    return (*this);
}
// Destructor
Form::~Form(void)
{
    std::cout << "Form Destructor called" << std::endl;
    return ;
}

size_t  Form::getGradeToExec() const
{
    return _grade_to_exec;
}

size_t  Form::getGradeToSign() const
{
    return _grade_to_sign;
}

bool    Form::getSigned() const
{
    return _signed;
}

std::string Form::getName() const
{
    return _name;
}

void    Form::beSigned(Bureaucrat* buro)
{
    try
    {
        if (buro->getGrade() > _grade_to_sign)
            throw GradeTooLowException();
        _signed = true;
    }
    catch(const Form::GradeTooLowException & e)
    {
        std::cerr << e.what() << std::endl;
    }
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low!");
}
