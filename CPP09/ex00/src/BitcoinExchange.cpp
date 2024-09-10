#include "BitcoinExchange.hpp"

// Default constructor
BitcoinExchange::BitcoinExchange(void)
{
    std::cout << "BitcoinExchange Default constructor called" << std::endl;
    return ;
}

BitcoinExchange::BitcoinExchange(std::string input_file)
{
    std::cout << "BitcoinExchange contructor called" << std::endl;
    _data = parse_map("data.csv");
    _request = parse_multi_map(input_file);
}

// Copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
    std::cout << "BitcoinExchange Copy constructor called" << std::endl;
    *this = src;
    return ;
}

// Assignment operator overload
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
    std::cout << "BitcoinExchange Assignment operator called" << std::endl;
    if (this != &src)
    {

    }
    return (*this);
}

// Destructor
BitcoinExchange::~BitcoinExchange(void)
{
    std::cout << "BitcoinExchange Destructor called" << std::endl;
    return ;
}

std::map<std::string, double> parse_map(std::string database_file)
{
    std::ifstream infile(database_file.c_str());
    std::map<std::string, double> database;
    std::string line = NULL;
    std::string seperator = ",";

    if (!infile.is_open())
        throw std::runtime_error("Could no open file");
    while (std::getline(infile, line))
    {
        size_t sep_pos = line.find(seperator);
        if (sep_pos == std::string::npos || !sep_pos || sep_pos == line.size() - seperator.size())
            throw std::runtime_error("Invalid Line Format: " + line);
        std::string date = line.substr(0, sep_pos);
        check_date(date);
        double value = std::stod(line.substr(sep_pos + seperator.size()));
        if (value < 0)
            throw std::runtime_error("Invalid value: " + std::to_string(value));
        database.insert(std::make_pair(date, value));
    }
    return database;
}

std::multimap<std::string, double> parse_multi_map(std::string input_file)
{
    std::ifstream infile(input_file.c_str());
    std::multimap<std::string, double> database;
    std::string line = NULL;
    std::string seperator = " | ";

    if (!infile.is_open())
        throw std::runtime_error("Could no open file");
    while (std::getline(infile, line))
    {
        size_t sep_pos = line.find(seperator);
        if (sep_pos == std::string::npos || !sep_pos || sep_pos == line.size() - seperator.size())
            throw std::runtime_error("Invalid Line Format: " + line);
        std::string date = line.substr(0, sep_pos);
        check_date(date);
        double value = std::stod(line.substr(sep_pos + seperator.size()));
        if (value < 0)
            throw std::runtime_error("Invalid value: " + line);
        database.insert(std::make_pair(date, value));
    }
    return database;
}

    bool is_date_valid(std::string date)
    {
        int year = std::stoi(date.substr(0, 4));
        int month = std::stoi(date.substr(5, 2));
        int day = std::stoi(date.substr(8));

        if (year < 0)
            return false;

        if (month < 1 || month > 12)
            return false;

        if (day < 1 || day > 31)
            return false;

        if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
            return false;

        if (month == 2)
        {
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            {
                if (day > 29)
                    return false;
            }
            else
            {
                if (day > 28)
                    return false;
            }
        }
        return true;
    }

void check_date(std::string date)
{
    if (date.size() != 10)
        throw std::runtime_error("Invalid date size: " + date);
    if (date[4] != '-' || date[7] != '-')
        throw std::runtime_error("Invalid seperator: " + date);
    for (size_t i = 0; i < date.size(); i++)
        if (!std::isdigit(date[i]) && !(i == 4 || i == 7))
            throw std::runtime_error("Invalid non-digit character in date: " + date);
    if (!is_date_valid(date))
        throw std::runtime_error("Invalid date: " + date);
}

void BitcoinExchange::get_price(void)
{
    std::multimap<std::string, double>::iterator itr;
    for (itr = _request.begin(); itr != _request.end(); itr++)
    {
        auto day_info = _data.lower_bound(itr->first);
        if (day_info == _data.begin() && day_info->first != itr->first)
            throw std::runtime_error("No data available before: " + day_info->first);
        std::cout << itr->first << " => " << itr->second << " = " << (itr->second * day_info->second) << std::endl;
    }
}
