#include "iter.hpp"

template <class T>
void char_to_ascii(const T &c)
{
	std::cout << (c -48)<< std::endl;
}

int main()
{
	const char s[9] = "abcdefgh";
	iter(s, 8, char_to_ascii<char>);
}
