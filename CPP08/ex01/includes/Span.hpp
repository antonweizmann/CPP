#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <string>
# include <vector>
# include <algorithm>

class Span
{
    private:
        std::vector<int> _span;
        unsigned int _spanSize;
    public:
        //Constructers and Destructers
        Span(void);
        Span(int n);
        Span(const Span& src);
        Span &operator=(const Span &src);
        ~Span();

        //Getters and Setters
        void addNumber(int n);
        void addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end);
        //Functions
        int shortestSpan(void);
        int longestSpan(void);

        //Execptions
        class SpanFullException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class NoSpanFoundException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

#endif

