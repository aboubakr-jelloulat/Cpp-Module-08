#pragma once

#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
    // MutantStack();
    // MutantStack(const MutantStack &other);
    // MutantStack &operator=(const MutantStack &other);
    // ~MutantStack();

public:


	typedef typename std::deque<T>::iterator iterator;
	typedef typename std::deque<T>::const_iterator const_iterator;

	iterator begin();
	iterator end();
	const_iterator begin() const;
	const_iterator end() const;


};

#include "MutantStack.h"
