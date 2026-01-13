#include <iostream>
#include <list>
#include <cassert>
#include "MutantStack.h"
#include "MutantStack.tpp"


void _42()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}


void	_42_list()
{
	std::list<int> mstack;

	mstack.push_back(5);
	mstack.push_back(17);

	std::cout << mstack.back() << std::endl;

	mstack.pop_back();

	std::cout << mstack.size() << std::endl;

	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);

	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::list<int> s(mstack);

}


void	_Why_no_OCF()
{
	MutantStack<int> *mstack = new MutantStack<int>();

	mstack->push(5);
	assert(mstack->top() == 5);

	MutantStack<int> mstack2(*mstack);
	assert(mstack2.top() == 5);

	MutantStack<int> mstack3;
	mstack3 = *mstack;
	assert(mstack3.top() == 5);

	delete mstack;
}


int main(void)
{
	// _42();

	// _42_list();

	_Why_no_OCF();

	return 0;
}
