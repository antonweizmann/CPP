#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
# include <iostream>
# include <string>
# include "AForm.hpp"
class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;
    public:
        //Constructers and Destructers
        RobotomyRequestForm(void);
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm& src);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
        ~RobotomyRequestForm();
        //Getters and Setters
        std::string& getTarget();

        //Functions

};

#endif

