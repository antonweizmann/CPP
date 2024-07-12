#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <string>

class Form;

class Bureaucrat
{
    private:
        std::string _name;
        size_t         _grade;
    public:
        Bureaucrat(void);
        Bureaucrat(std::string name);
        Bureaucrat(std::string name, size_t grade);
        Bureaucrat(size_t grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();
        size_t         getGrade() const;
        std::string getName() const;
        void        incrementGrade();
        void        decrementGrade();
        void    signForm(Form form) const;
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

std::ostream&	operator<<(std::ostream& output, const Bureaucrat *temp);
#endif

