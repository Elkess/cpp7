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
		Array(){
			array = NULL;
			len = 0;
		}
		Array(unsigned int n){
			array = new T[n];
			len = n;
			for (size_t i = 0; i < len;i++)
				array[i] = T();
		}
		Array(const Array& obj){
			*this = obj;
		}
		Array &operator=(const Array& obj){
			if (this == &obj)
				return *this;
			delete[] array;
			len = obj.len;
			array = new T[len];
			for (size_t i = 0; i < len;i++)
				array[i] = obj.array[i];
			return *this;
		}
		T &operator[](unsigned int i){
			if (i >= len)
				throw std::out_of_range("Index out of bounds");
			return array[i];
		}
		~Array(){
			delete[] array;
		}

		unsigned int	size() const {
			return len;
		}
};

#endif