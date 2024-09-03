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
    float nb = std::stof(input);

    if (nb < 0 || nb > 127)
        std::cout << "char: impossible" << std::endl;
    else if (nb < 33 || nb == 127)
        std::cout << "char: non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(nb) << "'" << std::endl;
    if (nb < INT_MIN || nb > INT_MAX)
        std::cout << "int: impossible" << std::endl;\
    else
        std::cout << "int: " << static_cast<int>(nb) << std::endl;
    std::cout << "teeee     float: " << nb << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(nb) << std::endl;
}

static void convertDecimal(std::string input)
{
    double nb = std::stod(input);

    if (nb < 0 || nb > 127)
        std::cout << "char: impossible" << std::endl;
    else if (nb < 33 || nb == 127)
        std::cout << "char: non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(nb) << "'" << std::endl;
    if (nb < INT_MIN || nb > INT_MAX)
        std::cout << "int: impossible" << std::endl;\
    else
        std::cout << "int: " << static_cast<int>(nb) << std::endl;
    std::cout << "float: " << static_cast<float>(nb) << "f" << std::endl;
    std::cout << "double: " << nb << std::endl;
}

static void convertInt(std::string input)
{
    long int check = std::stoi(input);

    if (check < INT_MIN || check > INT_MAX)
    {
        std::cout << "Error: input is to large to be an Int." << std::endl;
        return ;
    }
    int nb = check;
    if (nb < 0 || nb > 127)
        std::cout << "char: impossible" << std::endl;
    else if (nb < 33 || nb == 127)
        std::cout << "char: non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(nb) << "'" << std::endl;
    std::cout << "int: " << nb << std::endl;
    std::cout << "float: " << static_cast<float>(nb) << ".0f" <<  std::endl;
    std::cout << "double: " << static_cast<double>(nb) << ".0"  << std::endl;
}

static void convertChar(std::string input)
{
   char c = input.at(0);

   if (c < 0 || c > 127)
        std::cout << "char: impossible" << std::endl;
    else if (c < 33 || c == 127)
        std::cout << "char: non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}

static void convertNan(std::string input)
{
    std::string pseudoLitarals[] = {"-inff", "+inff", "nanf"};

    std::cout << "char: impossible" << std::endl;
    std::cout << "int: inpossible" << std::endl;
//     for (int i = 0; i < 3; i++)
//     {
//         if (pseudoLitarals[i] == input)
//         {
//             std::cout << "float: " << input << std::endl;
//             std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
//             return ;
//         }
//     }
//     std::cout << "float: " << input << "f" << std::endl;
//     std::cout << "double: " << input << std::endl;
}

static int checkType(std::string input)
{
    std::string pseudoLitarals[] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
    bool decimal = false;

    for (int i = 0; i < 6; i++)
        if (pseudoLitarals[i].compare(input) == 0)
            return NANF;
    if (input.length() == 1 && !std::isdigit(input.at(0)))
        return CHAR;
    for (size_t j = 0 + (input.at(0) == '+' || input.at(0) == '-'); j < input.length(); j++)
    {
        if (j > 0 && input.at(j) == 'f' && std::isdigit(input.at(j - 1)) && j + 1 == input.length() && decimal)
            return FLOAT;
        else if (input.at(j) == '.' && !decimal)
            decimal = true;
        else if (input.at(j) == '.' && decimal)
            return INVALID;
        else if (!std::isdigit(input.at(j)))
            return INVALID;
        // std::cout << input.at(j - 1) << std::endl;
    }
    if (decimal)
        return DOUBLE;
    else
        return INT;
}

void ScalarConverter::convert(std::string input)
{
    int type = checkType(input);
    switch (type){
        case INT:
            convertInt(input);
            break;
        case DOUBLE:
            convertDecimal(input);
            break;
        case FLOAT:
            convertFloat(input);
            break;
        case CHAR:
            convertChar(input);
            break;
        case NANF:
            convertNan(input);
            break;
        case INVALID:
            std::cout << "This Input is invalid. Valid are either Ints, Floats, Decimals and Chars." << std::endl;
            break;
        default:
            std::cout << "Error" << std::endl;
    }

}
