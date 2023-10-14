#pragma once

#include <vector>
#include <iostream>
#include <exception>
#include <cstdlib>

using std::vector;
using std::cout;
using std::endl;
using std::exception;

class Span
{
    private :
        vector<int> v_span;
        size_t      size;
    public :
        class OutOfSpanRange: public exception
        {
            const char *what() const throw();
        };
        class UnavailableSpan: public exception
        {
            const char *what() const throw();
        };
        Span();
        Span(unsigned int N);
        Span(vector<int>::iterator begin, vector<int>::iterator end);
        Span(const Span &cpy_span);
        Span &operator=(const Span &eq_span);
        void    addNumber(int number);
        size_t    shortestSpan();
        size_t    longestSpan();
        ~Span();
};