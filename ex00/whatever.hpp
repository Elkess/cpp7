#ifndef FUNC_TEMPLATE
#define FUNC_TEMPLATE

template <class T>
void	swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <class T>
T	min(T a, T b)
{
	if (b <= a)
		return b;
	return a;
}

template <class T>
T	max(T a, T b)
{
	if (b >= a)
		return b;
	return a;
}

#endif