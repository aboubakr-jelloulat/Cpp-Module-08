#include "Span.h"
#include <stdexcept>

template <typename T>
void Span::addRange(T first, T last)
{
    unsigned int count = std::distance(first, last);

    if (_data.size() + count > _n)
        throw std::length_error("Span is full");

    _data.insert(_data.end(), first, last);
}

