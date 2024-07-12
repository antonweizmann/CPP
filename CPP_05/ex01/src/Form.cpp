#include "Form.hpp"

void    Form::check_grades()
{
     if (_grade_to_exec > 150)
    {
        throw GradeTooLowException();
        std::cerr << "Grade too low, instead set to 150" << std::endl;
        _grade_to_exec = 150;
    }
    else if (_grade_to_exec < 1)
    {
        throw GradeTooHighException();
        std::cerr << "Grade too high, instead set to 1" << std::endl;
        _grade_to_exec = 1;
    }
    if (_grade_to_sign > 150)
    {
        throw GradeTooLowException();
        std::cerr << "Grade too low, instead set to 150" << std::endl;
        _grade_to_sign = 150;
    }
    else if (_grade_to_sign < 1)
    {
        throw GradeTooHighException();
        std::cerr << "Grade too high, instead set to 1" << std::endl;
        _grade_to_sign = 1;
    }
}
// Default constructor
Form::Form(void) : _name("Default Form"), _signed(false), _grade_to_sign(150), _grade_to_exec(150)
{
    std::cout << "Form Default constructor called" << std::endl;
    return ;
}

Form::Form(std::string name, bool issigned, int grade_to_exec, int grade_to_sign) : _name(name), _signed(issigned), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec)
{
    std::cout << "Form Default constructor called" << std::endl;
    check_grades();
    return ;
}

Form::Form(std::string name, int grade_to_exec, int grade_to_sign) : _name(name), _signed(false), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec)
{
    std::cout << "Form Default constructor called" << std::endl;
    check_grades();
    return ;
}
Form::Form(int grade_to_exec, int grade_to_sign) : _name("Default Form"), _signed(false), _grade_to_sign(grade_to_sign), _grade_to_exec(grade_to_exec)
{
    std::cout << "Form Default constructor called" << std::endl;
    check_grades();
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

void    Form::beSigned(Bureaucrat buro)
{
    try
    {
        if (buro.getGrade() > _grade_to_sign)
            throw GradeTooLowException();
        _signed = true;
    }
    catch(const GradeTooLowException & e)
    {
        std::cerr << e.what() << std::endl;
        throw Bureaucrat::GradeTooLowException();
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

std::ostream&	operator<<(std::ostream& output, const Form *temp)
{
    output << temp->getName() << ", singed status: " << temp->getSigned() << ", grade_to_sign: " << temp->getGradeToSign() << ", grade_to_exec: " << temp->getGradeToExec() << std::endl;
    return output;
}
