#include "Array.hpp"

template <class T>
Array<T>::Array()
{
	array = NULL;
	len = 0;
}

template <class T>
Array<T>::Array(unsigned int n)
{
	array = new T[n];
	len = n;
	for (size_t i = 0; i < len;i++)
		array[i] = T();
}

template<class T>
Array<T>::Array(const Array &obj)
{
	array = NULL;
	*this = obj;
}

template<class T>
Array<T>& Array<T>::operator=(const Array &obj)
{
	if (this == &obj)
		return *this;
	delete[] array;
	len = obj.len;
	array = new T[len];
	for (size_t i = 0; i < len; i++)
		array[i] = obj.array[i];
	return *this;
}

template<class T>
T& Array<T>::operator[](unsigned int i)
{
	if (i >= len)
		throw std::out_of_range("Index out of bounds");
	return array[i];
}

template<class T>
Array<T>::~Array()
{
	delete[] array;
}

template <class T>
unsigned int Array<T>::size() const
{
	return len;
}
