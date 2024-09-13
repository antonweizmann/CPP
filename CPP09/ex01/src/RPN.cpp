#include "RPN.hpp"

// Default constructor
RPN::RPN(void)
{
    std::cout << "RPN Default constructor called" << std::endl;
    return ;
}

RPN::RPN(std::string input)
{
    std::cout << "RPN input constructor called" << std::endl;
    if (input.empty())
        throw std::runtime_error("Input empty");
    _ss = std::stringstream(input);
    check_input();
    calculate();
    return ;
}

// Copy constructor
RPN::RPN(const RPN &src)
{
    std::cout << "RPN Copy constructor called" << std::endl;
    *this = src;
    return ;
}

// Assignment operator overload
RPN &RPN::operator=(const RPN &src)
{
    std::cout << "RPN Assignment operator called" << std::endl;
    if (this != &src)
    {

    }
    return (*this);
}

// Destructor
RPN::~RPN(void)
{
    std::cout << "RPN Destructor called" << std::endl;
    return ;
}

void check_input(const std::string &input)
{
    std::stringstream ss(input);
    std::string tmp;
    int count = 0;
    long i = 0;
    while (ss >> tmp)
    {
        i = std::stoi(tmp);
        if (i > INT_MAX)
            throw std::runtime_error("Input cannot be bigger than Int");
        else if (!std::isdigit(i) && !(i == '+' || i == '-' || i == '*' || i == '/'))
            throw std::runtime_error("Input should only include numbers and math operators");
        else if (!count && !std::isdigit(i))
            throw std::runtime_error("Input should start with a number");
        else if ((count % 2 && !std::isdigit(i)) || (!count % 2 && std::isdigit(i)))
            throw std::runtime_error("Input is not a inverted Polish mathematical expression");
        count++;
    }
    if (!(i == '+' || i == '-' || i == '*' || i == '/') || count < 3)
        throw std::runtime_error("Input is not a inverted Polish mathematical expression");
    
}

void RPN::calculate(void)
{
    std::string tmp;
    _ss >> tmp;
    long operand1 = INT_MAX + 1;
    long operand2 = INT_MAX + 1;
    
    

}
