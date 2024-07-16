#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <iostream>
# include <string>
# include <cstdlib>
# include "AForm.hpp"
class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
        void    action(void) const;
    public:
        //Constructers and Destructers
        RobotomyRequestForm(void);
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& src);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
        ~RobotomyRequestForm();
        //Getters and Setters
        std::string& getTarget() ;

        //Functions
};

#endif

