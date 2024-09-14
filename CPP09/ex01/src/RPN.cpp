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
    check_input(input);
    calculate(0);
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

bool is_operator(const std::string &str)
{
    if (str == "+" || str == "-" || str == "*" || str == "/")
        return (true);
    return (false);
}

void RPN::check_input(const std::string &input)
{
    std::stringstream ss(input);
    std::string tmp;
    int count = 0;
    long i = 0;
    while (ss >> tmp)
    {
        if (tmp.find_first_not_of("0123456789") != std::string::npos)
        {
            if (!is_operator(tmp))
                throw std::runtime_error("Input should only include numbers and math operators");
        }
        else
        {
            i = std::stoi(tmp);
            if (i > INT_MAX)
                throw std::runtime_error("Input cannot be bigger than Int");
        }
        if (!count && is_operator(tmp))
            throw std::runtime_error("Input should start with a number");
        // else if ((count % 2 && is_operator(tmp)) || (!count % 2 && !is_operator(tmp) && count != 0))
        //     throw std::runtime_error("Input is not a inverted Polish mathematical expression");
        count++;
        _stack.push(tmp);
    }
    if (!is_operator(tmp) || count < 3)
        throw std::runtime_error("Input is not a inverted Polish mathematical expression");
    
}

void RPN::calculate(int level)
{
    long operand1 = INT_MAX + 1l;
    long operand2 = INT_MAX + 1l;
    std::string operation;
    while (operand1 == INT_MAX + 1l|| operand2 == INT_MAX + 1l || operation == "")
    {
        if (is_operator(_stack.top()) && operation.empty())
        {
            operation = _stack.top();
            _stack.pop();
        }
        if (is_operator(_stack.top()))
            calculate(level + 1);
        if (operand2 == INT_MAX + 1l)
        {
            operand2 = std::stoi(_stack.top());
            _stack.pop();
        }
        else if (operand1 == INT_MAX + 1l)
        {
            operand1 = std::stoi(_stack.top());
            _stack.pop();
        }
    }
    if (operation == "+")
        _stack.push(std::to_string(operand1 + operand2));
    else if (operation == "-")
        _stack.push(std::to_string(operand1 - operand2));
    else if (operation == "*")
        _stack.push(std::to_string(operand1 * operand2));
    else if (operation == "/")
        _stack.push(std::to_string(operand1 / operand2));
    if (level == 0)
        std::cout << "Result: " << _stack.top() << std::endl;
}
