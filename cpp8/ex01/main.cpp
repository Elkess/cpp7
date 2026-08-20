#include <iostream>
#include <vector>
#include <cstdlib>
#include "Span.hpp"

int main()
{
	std::cout << "--- subject example ---" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan() << std::endl;

	std::cout << "--- addRange test ---" << std::endl;
	Span bigSpan(10000);
	std::vector<int> vec;
	for (int i = 0; i < 10000; i++)
		vec.push_back(std::rand() % 100000);

	bigSpan.addRange(vec.begin(), vec.end());
	std::cout << "Shortest span: " << bigSpan.shortestSpan() << std::endl;
	std::cout << "Longest span: " << bigSpan.longestSpan() << std::endl;

	std::cout << "--- exception tests ---" << std::endl;
	try
	{
		Span tiny(2);
		tiny.addNumber(1);
		tiny.addNumber(2);
		tiny.addNumber(3); // should throw FullSpanException
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Span empty(5);
		empty.addNumber(42);
		empty.shortestSpan(); // should throw NotEnoughNumbersException
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Span tooSmall(3);
		std::vector<int> range;
		range.push_back(1);
		range.push_back(2);
		range.push_back(3);
		range.push_back(4);
		tooSmall.addRange(range.begin(), range.end()); // should throw FullSpanException
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
