#include"easyfind.h"
#include <vector>
#include <cassert>

typedef std::vector<int> vi;
typedef std::vector<char> vch;


template <typename T>
void _display(T &container)
{
    typename T::iterator it;

    for (it = container.begin(); it != container.end(); ++it)
        std::cout << *it << std::endl;
    
}


void	_int()
{
	vi nums;
	nums.push_back(1337); nums.push_back(42); nums.push_back(19);
	// _display(nums); exit(0);

	assert (*easyfind(nums, 42) == 42);
	assert (*easyfind(nums, 19) == 19);
	assert (*easyfind(nums, 1337) == 1337);
	assert(*easyfind(nums, 444) == *nums.end());

	std::vector<int>::iterator itr = easyfind(nums, 888);
	std::cout << *itr << std::endl;

	*easyfind(nums, 19) = 1715;
	assert (*easyfind(nums, 1715) == 1715);


	const vi const_nums(nums);
	assert (*easyfind(const_nums, 1337) == 1337);
	// *easyfind(const_nums, 19) = 1715; // assignment of read-only location

	std::vector<int>::const_iterator it = easyfind(const_nums, 42);
	std::cout << *it << std::endl;

}

void	_char()
{
	vch str;
	str.push_back('h'); str.push_back('e'); str.push_back('j');

	for (vch::iterator it = str.begin(); it != str.end(); ++it)
	{
	    std::cout << *it << std::endl;
	}

	assert(*easyfind(str, 'h') == 'h');
	assert(*easyfind(str, 'e') == 'e');
	assert(*easyfind(str, 'j') == 'j');

}


int main(void)
{
	_int();

	_char();

	return 0;
}
