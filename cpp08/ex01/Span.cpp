#include "span.hpp"

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
{}

Span::Span(vector<int>::iterator begin, vector<int>::iterator end):size(0)
{
    while (begin != end)
    {
        addNumber(*(begin++));
        size++;
    }
}

Span::Span(const Span &cpy_span):size(cpy_span.size)
{
    size_t i = -1;
    while(++i < cpy_span.v_span.size())
        v_span.push_back(cpy_span.v_span[i]);
}

Span &Span::operator=(const Span &eq_span)
{
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
            temp_shortest = std::abs(v_span[i] - v_span[j]);
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
        size_t i = -1;
    size_t j;
    size_t longest = 0, temp_longest;
    while (++i < v_span.size())
    {
        j = i;
        while (++j < v_span.size())
        {
            temp_longest = std::abs(v_span[i] - v_span[j]);
            if ((i == 0 && j == 1) || temp_longest > longest)
                longest = temp_longest;
        }
    }
    return longest;
}

Span::~Span()
{}