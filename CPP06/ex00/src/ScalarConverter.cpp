#include "ScalarConverter.hpp"

// Default constructor
ScalarConverter::ScalarConverter(void)
{
    std::cout << "ScalarConverter Default constructor called" << std::endl;
    return ;
}

// Copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
    std::cout << "ScalarConverter Copy constructor called" << std::endl;
    *this = src;
    return ;
}

// Assignment operator overload
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
    std::cout << "ScalarConverter Assignment operator called" << std::endl;
    if (this != &src)
    {

    }
    return (*this);
}

// Destructor
ScalarConverter::~ScalarConverter(void)
{
    std::cout << "ScalarConverter Destructor called" << std::endl;
    return ;
}

static void convertFloat(std::string input)
{

}

static void convertDecimal(std::string input)
{

}

static void convertInt(std::string input)
{

}

static void convertChar(std::string input)
{
    
}

void ScalarConverter::convert(std::string input)
{
    convertChar(input);
    convertInt(input);
    convertFloat(input);
    convertDecimal(input);
}
