#include "AForm.hpp"

void    AForm::check_grades(int grade_to_exec, int grade_to_sign)
{
     if (grade_to_exec > 150)
    {
        throw GradeTooLowException();
        std::cerr << "Grade too low, instead set to 150" << std::endl;
        grade_to_exec = 150;
    }
    else if (grade_to_exec < 1)
    {
        throw GradeTooHighException();
        std::cerr << "Grade too high, instead set to 1" << std::endl;
        grade_to_exec = 1;
    }
    else
        _grade_to_exec = grade_to_exec;
    if (grade_to_sign > 150)
    {
        throw GradeTooLowException();
        std::cerr << "Grade too low, instead set to 150" << std::endl;
        grade_to_sign = 150;
    }
    else if (grade_to_sign < 1)
    {
        throw GradeTooHighException();
        std::cerr << "Grade too high, instead set to 1" << std::endl;
        grade_to_sign = 1;
    }
    else
        _grade_to_sign = grade_to_sign;
}
// Default constructor
AForm::AForm(void) : _name("Default AForm"), _signed(false), _grade_to_sign(150), _grade_to_exec(150)
{
    std::cout << "AForm Default constructor called" << std::endl;
    return ;
}

AForm::AForm(std::string name, bool issigned, int grade_to_exec, int grade_to_sign) : _name(name), _signed(issigned)
{
    std::cout << "AForm Full constructor called" << std::endl;
    check_grades(grade_to_exec, grade_to_sign);
    return ;
}

AForm::AForm(std::string name, int grade_to_exec, int grade_to_sign) : _name(name), _signed(false)
{
    std::cout << "AForm No Signed constructor called" << std::endl;
    check_grades(grade_to_exec, grade_to_sign);
    return ;
}
AForm::AForm(int grade_to_exec, int grade_to_sign) : _name("Default AForm"), _signed(false)
{
    std::cout << "AForm Grades constructor called" << std::endl;
    check_grades(grade_to_exec, grade_to_sign);
    return ;
}

// Copy constructor
AForm::AForm(const AForm &other)
{
    std::cout << "AForm Copy constructor called" << std::endl;
    *this = other;
    return ;
}

// Assignment operator overload
AForm &AForm::operator=(const AForm &other)
{
    std::cout << "AForm Assignment operator called" << std::endl;
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
AForm::~AForm(void)
{
    std::cout << "AForm Destructor called" << std::endl;
    return ;
}

size_t  AForm::getGradeToExec() const
{
    return _grade_to_exec;
}

size_t  AForm::getGradeToSign() const
{
    return _grade_to_sign;
}

bool    AForm::getSigned() const
{
    return _signed;
}

std::string AForm::getName() const
{
    return _name;
}

void    AForm::beSigned(Bureaucrat& buro)
{
    try
    {
        if (buro.getGrade() > _grade_to_sign)
            throw GradeTooLowException();
        _signed = true;
    }
    catch(const GradeTooLowException & e)
    {
        throw Bureaucrat::GradeTooLowException();
    }
}

void    AForm::beSigned(const Bureaucrat& buro)
{
    try
    {
        if (buro.getGrade() > _grade_to_sign)
            throw GradeTooLowException();
        _signed = true;
    }
    catch(const GradeTooLowException & e)
    {
        throw Bureaucrat::GradeTooLowException();
    }
}

void    AForm::checkReq(Bureaucrat& buro)
{
    try
    {
        if (buro.getGrade() > _grade_to_exec)
            throw GradeTooLowException();
    }
    catch(const GradeTooLowException & e)
    {
        throw Bureaucrat::GradeTooLowException();
    }
}

void    AForm::execute(const Bureaucrat& buro) const
{
    try
    {
        if (buro.getGrade() > _grade_to_exec)
            throw GradeTooLowException();
        if (_signed == false)
            throw FormNotSignedException();
        action();
    }
    catch(const GradeTooLowException & e)
    {
        throw Bureaucrat::GradeTooLowException();
    }
}
const char* AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too low!");
}
const char* AForm::FormNotSignedException::what() const throw()
{
    return ("Form not signed!");
}

std::ostream&	operator<<(std::ostream& output, const AForm *temp)
{
    output << temp->getName() << ", singed status: " << temp->getSigned() << ", grade_to_sign: " << temp->getGradeToSign() << ", grade_to_exec: " << temp->getGradeToExec() << std::endl;
    return output;
}
