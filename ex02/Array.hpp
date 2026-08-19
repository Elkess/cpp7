#ifndef ARRAY_HPP
#define ARRAY_HPP

template <class T>
class Array
{
	private:
		
	public:
		Array();
		Array(const Array& obj);
		Array operator=(const Array& obj);
		~Array();
		size_t	size();
};


#endif