#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <iostream>
# include <string>
# include "AForm.hpp"
class ShrubberyCreationForm : public AForm
{
    private:
        std::string _target;
    public:
        //Constructers and Destructers
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm& src);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
        ~ShrubberyCreationForm();

        //Getters and Setters
        std::string& getTarget();

        //Functions
        void    execute(Bureaucrat const & executer);
};

#endif

