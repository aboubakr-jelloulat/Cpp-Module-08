#include "easyfind.h"
#include <vector>
#include <cassert>
#include <iostream>


void	_int()
{
	std::vector<int> nums;
	nums.push_back(1337); nums.push_back(42); nums.push_back(19);

	assert (*easyfind(nums, 42) == 42);
	assert (*easyfind(nums, 19) == 19);
	assert (*easyfind(nums, 1337) == 1337);

	try
	{
		easyfind(nums, 444);
	} catch (const std::exception& e) 
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::vector<int>::iterator itr;
		itr = easyfind(nums, 888);

	} catch (const std::exception& e) 
	{
		std::cout << e.what() << std::endl;
	}

	// non const
	std::vector<int>::iterator it = easyfind(nums, 19);
	std::cout << "it = " << *it << std::endl;
	*it = 1715;
	std::cout << "it = " << *it << std::endl;
	assert (*easyfind(nums, 1715) == 1715);
}

void	_const()
{
	std::vector<int> nums;
	nums.push_back(1337); nums.push_back(42); nums.push_back(19);

	const std::vector<int> const_nums(nums);
	assert (*easyfind(const_nums, 1337) == 1337);

	std::vector<int>::const_iterator it = easyfind(const_nums, 42);
	std::cout << *it << std::endl;
	// *it = 444; // assignment of read-only location 

	try 
	{
		easyfind(const_nums, 999);

	} catch (const std::exception& e) 
	{
		std::cout << e.what() << std::endl;
	}

}

void	_char()
{
	std::vector<char> str;
	str.push_back('h'); str.push_back('e'); str.push_back('j');

	for (std::vector<char>::iterator it = str.begin(); it != str.end(); ++it)
	{
	    std::cout << *it << std::endl;
	}

	assert(*easyfind(str, 'h') == 'h');
	assert(*easyfind(str, 'e') == 'e');
	assert(*easyfind(str, 'j') == 'j');

	try 
	{
		easyfind(str, 'x');
	} catch (const std::exception& e) 
	{
		std::cout << e.what() << std::endl;
	}

	*easyfind(str, 'j') = 'k';
	assert(*easyfind(str, 'k') == 'k');
}

int main(void)
{
	_int();
	_const();
	_char();
	
	return 0;
}

