#pragma once
#include <algorithm>
#include <iostream>


template<typename T>
typename T::iterator easyfind(T &container, int num)
{
	#ifdef DEBUG
		std::cout << "non const easy find called" << std::endl;
	#endif

	typename T::iterator it;

	it = std::find(container.begin(), container.end(), num);

	return it;
}


template<typename T>
typename T::const_iterator easyfind(const T &container, int num)
{
	#ifdef DEBUG
		std::cout << "const easy find called" << std::endl;
	#endif

	return std::find(container.begin(), container.end(), num);
}


