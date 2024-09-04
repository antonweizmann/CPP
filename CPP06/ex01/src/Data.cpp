#include "Data.hpp"

// Default constructor
Data::Data(void)
{
    std::cout << "Data Default constructor called" << std::endl;
    return ;
}

// Copy constructor
Data::Data(const Data &src)
{
    std::cout << "Data Copy constructor called" << std::endl;
    *this = src;
    return ;
}

// Assignment operator overload
Data &Data::operator=(const Data &src)
{
    std::cout << "Data Assignment operator called" << std::endl;
    if (this != &src)
    {
        _data = src._data;
    }
    return (*this);
}

// Destructor
Data::~Data(void)
{
    std::cout << "Data Destructor called" << std::endl;
    return ;
}

