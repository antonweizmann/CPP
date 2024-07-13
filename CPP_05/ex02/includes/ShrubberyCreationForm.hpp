#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP
# include <iostream>
# include <string>

class ShrubberyCreationForm
{
    public:
        ShrubberyCreationForm(void);
        ShrubberyCreationForm(const ShrubberyCreationForm& src);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
        ~ShrubberyCreationForm();
};

#endif

