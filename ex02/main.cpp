#include "Array.hpp"
#include <iostream>

int main()
{
	Array<int> a;
	Array<int> b(10);

	for (size_t i = 0; i < b.size(); i++)
		std::cout << b[i] << " ";
	std::cout << std::endl;

	for (size_t i = 0; i < b.size(); i++)
		b[i] = i;

	for (size_t i = 0; i < b.size(); i++)
		std::cout << b[i] << " ";
	std::cout << std::endl;

	a = b;
	for (size_t i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;
}