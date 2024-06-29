#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

char to_upper(char c)
{
	return std::toupper(c);
}

int	main(int argc, char **argv){
	int	i;

	for (i = 1; i < argc; i++)
	{
		std::string str = argv[i];
		std::transform(str.begin(), str.end(), str.begin(), to_upper);
		if (i == argc - 1) std::cout << str << std::endl;
		else std::cout << str;
	}
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
