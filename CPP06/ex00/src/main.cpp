#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	// ScalarConverter test;
	if (argc != 2)
		return 1;
	ScalarConverter::convert(argv[1]);

}
