#include "Serializer.hpp"

// Default constructor
Serializer::Serializer(void)
{
    std::cout << "Serializer Default constructor called" << std::endl;
    return ;
}

// Copy constructor
Serializer::Serializer(const Serializer &src)
{
    std::cout << "Serializer Copy constructor called" << std::endl;
    *this = src;
    return ;
}

// Assignment operator overload
Serializer &Serializer::operator=(const Serializer &src)
{
    std::cout << "Serializer Assignment operator called" << std::endl;
    if (this != &src)
    {

    }
    return (*this);
}

// Destructor
Serializer::~Serializer(void)
{
    std::cout << "Serializer Destructor called" << std::endl;
    return ;
}
