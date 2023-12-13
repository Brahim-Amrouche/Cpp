#include "Span.hpp"

const char *Span::OutOfSpanRange::what() const throw()
{
    return "Span boundary surpassed";
}

const char *Span::UnavailableSpan::what() const throw()
{
    return "No available span";
}

Span::Span():size(0)
{}

Span::Span(unsigned int N):size(N)
{
    v_span.reserve(N);
}

Span::Span(const Span &cpy_span):size(cpy_span.size)
{
    if (this == &cpy_span)
        return ;
    v_span.reserve(size);
    size_t i = -1;
    while(++i < cpy_span.v_span.size())
        v_span.push_back(cpy_span.v_span[i]);
}

Span &Span::operator=(const Span &eq_span)
{
    if (this == &eq_span)
        return *this;
    size = eq_span.size;
    size_t i = -1;
    while (++i < eq_span.v_span.size())
        v_span.push_back(eq_span.v_span[i]);
    return (*this);
}

void    Span::addNumber(int number)
{
    if (v_span.size() < size)
        v_span.push_back(number);
    else
        throw OutOfSpanRange();
}

size_t Span::shortestSpan()
{
    if (v_span.size() <= 1)
        throw UnavailableSpan();
    size_t i = -1;
    size_t j;
    size_t shortest = 0, temp_shortest;
    while (++i < v_span.size())
    {
        j = i;
        while (++j < v_span.size())
        {
            temp_shortest = std::labs(v_span[i] - v_span[j]);
            if ((i == 0 && j == 1) || temp_shortest < shortest)
                shortest = temp_shortest;
        }
    }
    return shortest;
}

size_t Span::longestSpan()
{
    if (v_span.size() <= 1)
        throw UnavailableSpan();
    vector<int>::iterator max = std::max_element(v_span.begin(), v_span.end());
    vector<int>::iterator min = std::min_element(v_span.begin(), v_span.end());
    return *max - *min;
}

void Span::addNumber(vector<int>::const_iterator begin,
    vector<int>::const_iterator end)
{
    long dist = std::distance(begin, end);
    if (dist < 0 || static_cast<unsigned long>(dist) > (size - v_span.size()))
        throw OutOfSpanRange();
    v_span.insert(v_span.end(), begin, end);
}

Span::~Span()
{}