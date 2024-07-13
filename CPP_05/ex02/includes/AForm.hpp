#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include <string>
# include "Bureaucrat.hpp"
class AForm
{
    private:
        std::string _name;
        bool        _signed;
        size_t      _grade_to_sign;
        size_t      _grade_to_exec;
    public:
        //Constructers and Destructers
        AForm(void);
        AForm(std::string name, bool issigned, int grade_to_exec, int grade_to_sign);
        AForm(std::string name, int grade_to_exec, int grade_to_sign);
        AForm(int grade_to_exec, int grade_to_sign);
        AForm(const AForm& other);
        AForm &operator=(const AForm &other);
        ~AForm();

        //Getters and Setters
        size_t  getGradeToSign() const;
        size_t  getGradeToExec() const;
        bool    getSigned() const;
        std::string getName() const;

        //Functions
        virtual void    execute(Bureaucrat const & executer) const = 0;
        void    check_grades(int grade_to_exec, int grade_to_sign);
        void    beSigned(Bureaucrat& buro);
        void    beSigned(const Bureaucrat& buro);
        void    checkReq(Bureaucrat& buro);
        void    checkReq(const Bureaucrat& buro);
        //Execptions
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
std::ostream&	operator<<(std::ostream& output, const AForm *temp);
#endif

