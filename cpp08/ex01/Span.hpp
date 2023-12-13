#pragma once

#include <vector>
#include <iostream>
#include <exception>
#include <cstdlib>
#include <algorithm>

using std::vector;
using std::cout;
using std::endl;
using std::exception;


class Span
{
    private :
        size_t      size;
        vector<int> v_span;
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
        Span(const Span &cpy_span);
        Span &operator=(const Span &eq_span);
        void    addNumber(int number);
        void    addNumber(vector<int>::const_iterator begin, 
            vector<int>::const_iterator end);
        size_t    shortestSpan();
        size_t    longestSpan();
        ~Span();
};