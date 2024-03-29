#include "Span.hpp"

Span::Span()
{

}

Span::Span(unsigned int n)
{
    this->_v.reserve(n);
}

Span::Span(Span const &src)
{
    *this = src;
}

Span::~Span()
{
    
}

Span& Span::operator=(Span const &src)
{
    this->_v = src._v;
    this->_maxSize = src._maxSize;
    return *this;
}

void Span::addNumber(int nbr)
{
    if (this->_v.size() == this->_v.capacity())
        throw std::runtime_error("Vector is full");
    this->_v.push_back(nbr);
}

void Span::addNumber(int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (this->_v.size() == this->_v.capacity())
            throw std::runtime_error("Vector is full");
        this->_v.push_back(i);
    }
}

int Span::longestSpan(void) const
{
    if (this->_v.size() < 2)
        throw std::runtime_error("Not enough items to find span");
    int min = *(std::min_element(this->_v.begin(), this->_v.end()));
    int max = *(std::max_element(this->_v.begin(), this->_v.end()));
    return static_cast<int>(abs(max - min));
}

int Span::shortestSpan(void) const
{
    if (this->_v.size() < 2)
        throw std::runtime_error("Not enough items to find span");
    std::vector<int> cpy(this->_v);

    std::sort(cpy.begin(), cpy.end());
    return static_cast<int>(abs(cpy[1] - cpy[0]));
}