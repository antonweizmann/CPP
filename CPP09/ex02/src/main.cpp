#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	if (argc < 3)
	{
		if (argc == 2)
			std::cerr << "No benchmarking is possible with only one argument.";
		else
			std::cerr << "Usage: " << *argv << " [int1] [int2] [int3] ...";
		std::cerr << std::endl;
		return (1);
	}
	std::cout << "Benchmarking deque:" << std::endl;
	PmergeMe<std::deque<int>>	deque(argv);
	deque.merge_sort(deque_ford_johnson);
	std::cout << std::endl;
	std::cout << "Benchmarking list:" << std::endl;
	PmergeMe<std::list<int>>	list(argv);
	list.merge_sort(list_ford_johnson);
	std::cout << std::endl;
	return (0);
}
