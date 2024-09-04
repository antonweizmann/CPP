#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <string>
# include <limits>

# define INVALID 0
# define DOUBLE 1
# define FLOAT 2
# define CHAR 3
# define NANF 4
# define INT 5


class ScalarConverter
{
    public:
        //Constructers and Destructers
        ScalarConverter(void) = delete;
        ScalarConverter(const ScalarConverter& src);
        ScalarConverter &operator=(const ScalarConverter &src);
        ~ScalarConverter();

        //Getters and Setters

        //Functions
        static void convert(std::string input);
        //Execptions
};

#endif

