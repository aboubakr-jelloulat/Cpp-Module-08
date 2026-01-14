#pragma once
#include <algorithm>
#include <iostream>
#include <stdexcept>

class NotFoundException : public std::exception 
{
public:
    virtual const char* what() const throw() 
	{
        return "Value not found in container";
    }
};

template<typename T>
typename T::iterator easyfind(T &container, int num)
{
    #ifdef DEBUG
        std::cout << "non const easy find called" << std::endl;
    #endif

    typename T::iterator it;
	
	it = std::find(container.begin(), container.end(), num);
    
    if (it == container.end()) 
        throw NotFoundException();
    
    return it;
}

template<typename T>
typename T::const_iterator easyfind(const T &container, int num)
{
    #ifdef DEBUG
        std::cout << "const easy find called" << std::endl;
    #endif

    typename T::const_iterator it;

	it = std::find(container.begin(), container.end(), num);
    
    if (it == container.end())
        throw NotFoundException();
    
    return it;
}
