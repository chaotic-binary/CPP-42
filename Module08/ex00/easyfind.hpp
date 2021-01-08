#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>

template<typename T>
typename T::iterator	easyfind(T &container, int n) {
	typename T::iterator found = std::find(container.begin(), container.end(), n);
	if (found == container.end())
	{
		std::cout << n << " not found\n";
		throw std::exception();
	}
	return (found);
}

#endif