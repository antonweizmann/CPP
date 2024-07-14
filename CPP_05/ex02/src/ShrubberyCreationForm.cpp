#include "ShrubberyCreationForm.hpp"

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 137, 145), _target("non existent")
{
    std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 137, 145),  _target(target)
{
    std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
    return ;
}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src)
{
    std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
    *this = src;
    return ;
}

// Assignment operator overload
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
    std::cout << "ShrubberyCreationForm Assignment operator called" << std::endl;
    if (this != &src)
    {

    }
    return (*this);
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
    return ;
}

void    ShrubberyCreationForm::action() const
{
    std::ofstream file;
    std::string   file_name;
    try
    {
        file_name = _target + "_shrubbery";
        file.open(file_name.c_str());
        if (!file.is_open())
            throw std::exception();
        file << "           /\\          \n"
            << "          /  \\         \n"
            << "         /    \\        \n"
            << "        /      \\       \n"
            << "       /        \\      \n"
            << "      /          \\     \n"
            << "     /            \\    \n"
            << "    /              \\   \n"
            << "   /________________\\  \n"
            << "         ||||||        \n"
            << "         ||||||        \n"
            << "         ||||||        \n";


    }
    catch (std::exception &e)
    {
        std::cerr << "Error creating outfile: " << file_name << std::endl;
		if (file.fail())
	        std::cerr << "Error details: " << strerror(errno) << std::endl;
    }
}

std::string& ShrubberyCreationForm::getTarget(void)
{
    return _target;
}
