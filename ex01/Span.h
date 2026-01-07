
#pragma once
#include <vector>

class Span
{
	Span();

	unsigned int _n;
	std::vector<int> _data;

public:
	Span(const unsigned int &n);
	Span(const Span &src);
	Span &operator=(const Span &src);
	virtual ~Span();

	void addNumber(const int &item);
	int shortestSpan();
	int longestSpan();
};
