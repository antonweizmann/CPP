#include <iostream>
#include <string>

int	main(int argc, char **argv){
	int	i;

	for (i = 1; i < argc; i++)
	{
		std::string str = argv[i];
		std::transform(str.begin(), str.end(), str.begin(), ::toupper);
		if (i == argc - 1) std::cout << str << std::endl;
		else std::cout << str;
	}
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
