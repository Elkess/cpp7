#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <stdexcept>
# include <iterator>
# include <climits>

class Span
{
	public:
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void	addNumber(int n);
		int		shortestSpan() const;
		int		longestSpan() const;

		/* Template member: add a range of numbers at once from any
		** input-iterator pair (e.g. two std::vector<int> iterators). */
		template <typename Iterator>
		void addRange(Iterator begin, Iterator end)
		{
			size_t rangeSize = static_cast<size_t>(std::distance(begin, end));
			if (_numbers.size() + rangeSize > _maxSize)
				throw Span::FullSpanException();
			_numbers.insert(_numbers.end(), begin, end);
		}

		class FullSpanException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class NotEnoughNumbersException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		Span(); // no default construction: a Span must have a max size
		unsigned int		_maxSize;
		std::vector<int>	_numbers;
};

#endif
