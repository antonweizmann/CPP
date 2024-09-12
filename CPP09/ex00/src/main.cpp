#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: ./btc [File name]" << std::endl;
		return (-1);
	}
	try {

	BitcoinExchange btc(static_cast<std::string>(argv[1]));
	btc.get_price();
	}
	catch(const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}
