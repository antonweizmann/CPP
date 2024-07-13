#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
# include <iostream>
# include <string>

class PresidentialPardonForm
{
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(const PresidentialPardonForm& src);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
        ~PresidentialPardonForm();
};

#endif

