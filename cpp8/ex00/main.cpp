#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
	std::vector<int> vec;
	for (int i = 0; i < 10; i++)
		vec.push_back(i * 2); // 0 2 4 6 8 10 12 14 16 18

	std::cout << "--- vector test ---" << std::endl;
	try
	{
		std::vector<int>::iterator it = easyfind(vec, 8);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		easyfind(vec, 7); // not present -> should throw
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "--- list test ---" << std::endl;
	std::list<int> lst;
	lst.push_back(42);
	lst.push_back(21);
	lst.push_back(84);

	try
	{
		std::list<int>::iterator it = easyfind(lst, 21);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		easyfind(lst, 100); // not present -> should throw
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "--- const container test ---" << std::endl;
	const std::vector<int> cvec(vec);
	try
	{
		std::vector<int>::const_iterator it = easyfind(cvec, 16);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}