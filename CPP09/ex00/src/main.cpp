#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: ./btc [File name]" << std::endl;
		return (-1);
	}
	BitcoinExchange btc(argv[1]);
	btc.get_price();
}
