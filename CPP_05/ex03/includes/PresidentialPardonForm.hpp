#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include <iostream>
# include <string>
# include "AForm.hpp"
class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;
        void    action(void) const;
    public:
        //Constructers and Destructers
        PresidentialPardonForm(void);
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm& src);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
        ~PresidentialPardonForm();

        //Getters and Setters
        std::string& getTarget() ;

        //Functions
};

#endif

