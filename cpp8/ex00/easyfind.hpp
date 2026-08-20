#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <stdexcept>

/*
** easyfind
** Returns an iterator to the first element in 'container' equal to 'value'.
** Works for any container of integers that provides begin()/end() iterators
** (vector, list, deque, set, ...).
** Throws std::runtime_error if the value is not found.
*/
template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::runtime_error("easyfind: value not found in container");
	return it;
}

/* const overload, useful when the container is passed as const& */
template <typename T>
typename T::const_iterator easyfind(const T &container, int value)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::runtime_error("easyfind: value not found in container");
	return it;
}

#endif