#include "easyfind.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>

int main()
{
	std::cout << "Vector Container" << std::endl;
	std::vector<int> vec_test;

	for (int i = 0; i < 50; i++)
		vec_test.push_back(i);
	try
	{
		std::cout << *easyfind(vec_test, 5) << std::endl;
		std::cout << *easyfind(vec_test, 20) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}



		std::cout << "List Container" << std::endl;
	std::list<int> list_test;

	for (int i = 0; i < 50; i++)
		list_test.push_back(i);
	try
	{
		std::cout << *easyfind(list_test, 5) << std::endl;
		std::cout << *easyfind(list_test, 20) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}


		std::cout << "Deque Container" << std::endl;
	std::deque<int> deque_test;

	for (int i = 0; i < 50; i++)
		deque_test.push_back(i);
	try
	{
		std::cout << *easyfind(deque_test, 5) << std::endl;
		std::cout << *easyfind(deque_test, 20) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
