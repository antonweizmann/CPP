#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
# include <iostream>
# include <string>

class ScalarConverter
{
    public:
        //Constructers and Destructers
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter& src);
        ScalarConverter &operator=(const ScalarConverter &src);
        ~ScalarConverter();

        //Getters and Setters

        //Functions
        static void convert(std::string input);
        //Execptions
};

#endif

