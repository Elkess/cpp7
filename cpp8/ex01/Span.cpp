#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N)
{
	_numbers.reserve(N);
}

Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers)
{
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
	if (_numbers.size() >= _maxSize)
		throw Span::FullSpanException();
	_numbers.push_back(n);
}

int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw Span::NotEnoughNumbersException();

	std::vector<int> sorted(_numbers);
	std::sort(sorted.begin(), sorted.end());

	int smallest = INT_MAX;
	for (size_t i = 1; i < sorted.size(); i++)
	{
		int diff = sorted[i] - sorted[i - 1];
		if (diff < smallest)
			smallest = diff;
	}
	return smallest;
}

int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw Span::NotEnoughNumbersException();

	std::vector<int>::const_iterator minIt = std::min_element(_numbers.begin(), _numbers.end());
	std::vector<int>::const_iterator maxIt = std::max_element(_numbers.begin(), _numbers.end());

	return *maxIt - *minIt;
}

const char *Span::FullSpanException::what() const throw()
{
	return ("Span is full: cannot add more numbers");
}

const char *Span::NotEnoughNumbersException::what() const throw()
{
	return ("Not enough numbers in Span to compute a span");
}
