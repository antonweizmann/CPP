#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <iostream>
# include <string>
# include <map>
# include <fstream>
# include <iterator>
# include <stdexcept>
class BitcoinExchange
{
    private:
        std::map<std::string, double> _data;
        std::multimap<std::string, double> _request;

    public:
        //Constructers and Destructers
        BitcoinExchange(void);
        BitcoinExchange(std::string input_file);
        BitcoinExchange(const BitcoinExchange& src);
        BitcoinExchange &operator=(const BitcoinExchange &src);
        ~BitcoinExchange();

        //Getters and Setters

        //Functions
        void get_price(void);
        //Execptions
};

std::map<std::string, double> parse_map(const std::string database);
std::multimap<std::string, double> parse_multi_map(const std::string &input_file);
void check_date(std::string date);
#endif

