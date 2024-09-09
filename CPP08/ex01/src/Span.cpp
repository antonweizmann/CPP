#include "Span.hpp"

// Default constructor
Span::Span(void) : _spanSize(0)
{
    std::cout << "Span Default constructor called" << std::endl;
    return ;
}

Span::Span(int n) : _spanSize(n)
{
    std::cout << "Span constructor called" << std::endl;
    return ;
}

// Copy constructor
Span::Span(const Span &src)
{
    std::cout << "Span Copy constructor called" << std::endl;
    *this = src;
    return ;
}

// Assignment operator overload
Span &Span::operator=(const Span &src)
{
    std::cout << "Span Assignment operator called" << std::endl;
    if (this != &src)
    {

    }
    return (*this);
}

// Destructor
Span::~Span(void)
{
    std::cout << "Span Destructor called" << std::endl;
    return ;
}

void Span::addNumber(int n)
{
    if (_span.size() < _spanSize)
        _span.push_back(n);
    else
        throw SpanFullException();
}

void Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
    if (_span.size() + std::distance(start, end) <= _spanSize)
        _span.insert(_span.end(), start, end);
    else
        throw SpanFullException();
}

int Span::shortestSpan(void)
{
    int shortestSpan;
    if (_span.size() <= 1)
        throw NoSpanFoundException();
    std::vector<int> tmp = _span;
    std::sort(tmp.begin(), tmp.end());
    shortestSpan = tmp[1] - tmp[0];
    for (size_t i = 1; i < tmp.size(); i++)
    {
        int span = tmp[i ] - tmp[i - 1];
        if (span < shortestSpan)
            shortestSpan = span;
    }
    return shortestSpan;
}

int Span::longestSpan(void)
{
    std::vector<int> tmp = _span;
    std::sort(tmp.begin(), tmp.end());
    if (tmp.size() > 1)
        return (tmp[tmp.size() - 1] - tmp[0]);
    else
        throw NoSpanFoundException();
}

const char *Span::SpanFullException::what() const throw()
{
    return ("Span is full");
}

const char *Span::NoSpanFoundException::what() const throw()
{
    return ("No Span was found");
}

