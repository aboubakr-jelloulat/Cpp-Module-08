#include "Span.h"
#include <iostream>
#include <vector>
#include <cassert>


void	_42()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void	_insert()
{
	std::vector<int> nums;

	nums.push_back(42);
	nums.push_back(10);
	nums.push_back(19);
	nums.push_back(2);

	// std::cout << "distance : " << std::distance(nums.begin(), nums.end()) << std::endl;

	Span sp(8);
	sp.addNumber(1);
	sp.addNumber(1);
	sp.addNumber(1);
	sp.addNumber(1);

	// std::cout << *nums.begin() << std::endl;
	// std::cout << *(nums.end() - 1)<< std::endl;
	
	sp.addRange(nums.begin(), nums.end());

	sp.display();
}

void	_tsts()
{
	Span sp(0);

	try
	{
		sp.addNumber(1337);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Span spp(1);
	spp.addNumber(42);
	try
	{
		spp.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		spp.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	{
		Span sp(5);

		sp.addNumber(10);
		sp.addNumber(20);
		sp.addNumber(19);
		sp.addNumber(42);
		sp.addNumber(8); // 8 10 19 20 42

		std::cout << sp.shortestSpan() << std::endl; // 20 - 19 = 1
		std::cout << sp.longestSpan() << std::endl; // 42 - 8 = 34
	}
	

}

void	_one_thousand()
{
	Span span(10000); // wc -l

	for (size_t i = 0; i < 10000; i++) span.addNumber(1337);

	// span.display();
	
	assert(span.shortestSpan() == 0);
	assert(span.longestSpan() == 0);

}


int main()
{
	_42();

	_insert();

	_tsts();

	_one_thousand();


	return 0;
}
