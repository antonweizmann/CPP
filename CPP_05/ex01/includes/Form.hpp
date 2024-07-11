#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <string>
# include "Bureaucrat.hpp"
class Form
{
    private:
        std::string _name;
        bool        _signed;
        size_t      _grade_to_sign;
        size_t      _grade_to_exec;
    public:
        Form(void);
        Form(const Form& other);
        Form &operator=(const Form &other);
        ~Form();
        size_t  getGradeToSign() const;
        size_t  getGradeToExec() const;
        bool    getSigned() const;
        std::string getName() const;

        void    beSigned(Bureaucrat* buro);

        class   GradeTooHighException: public std::exception
        {
            public:
                const char* what() const throw();
        };
        class   GradeTooLowException: public std::exception
        {
            public:
                const char* what() const throw();
        };
};
std::ostream&	operator<<(std::ostream& output, const Form *temp);
#endif

