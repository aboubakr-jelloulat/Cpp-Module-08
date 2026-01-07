#include "Span.h"
#include <algorithm>
#include <stdexcept>
#include <climits>

Span::Span() {}

Span::Span(const unsigned int &n) : _n(n)
{
}

Span::Span(const Span &src) : _n(src._n), _data(src._data)
{
}

Span &Span::operator=(const Span &src)
{
	if (this == &src)
		return (*this);

	_n = src._n;
	_data = src._data;
	return (*this);
}

void Span::addNumber(const int &item)
{
	if (_data.size() >= _n)
		throw std::length_error("Span is full.");

	_data.push_back(item);
}



int Span::shortestSpan()
{
	if (_data.size() < 2)
		throw std::length_error("Span must contain at least two numbers.");

	std::sort(_data.begin(), _data.end());

	unsigned int shortest = UINT_MAX;

	for (size_t i = 0; i < _n - 1; i++)
	{
		unsigned int cur = _data[i + 1] - _data[i];
		shortest = std::min(shortest, cur);
	}

	return shortest;
}
int Span::longestSpan()
{
	if (_data.size() < 2)
		throw std::length_error("Span must contain at least two numbers.");

	std::sort(_data.begin(), _data.end());

	return (_data[_data.size() - 1] - _data[0]);
}

Span::~Span()
{
}

