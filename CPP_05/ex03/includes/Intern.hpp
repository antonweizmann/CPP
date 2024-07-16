#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include <string>
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "AForm.hpp"
class Intern
{
    public:
        //Constructers and Destructers
        Intern(void);
        Intern(const Intern& src);
        Intern &operator=(const Intern &src);
        ~Intern();

        //Getters and Setters

        //Functions
        AForm* makeForm(std::string form, std::string target);
        //Execptions
};

#endif

