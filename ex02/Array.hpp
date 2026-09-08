#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <cstddef>

template <class T>
class Array
{
	private:
		T* array;
		unsigned int len;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& obj);
		Array &operator=(const Array& obj);
		T &operator[](unsigned int i);
		~Array();
		unsigned int	size() const;
};

#include "Array.tpp"

#endif