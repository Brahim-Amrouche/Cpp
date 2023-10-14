#pragma once

#include <stack>
#include <iostream>
#include <deque>
#include <list>


using std::stack;
using std::list;
using std::deque;

template <typename T, class Container = deque<T> >
class MutantStack : public stack<T, Container>
{
    public :
        typedef typename Container::iterator iterator;

        MutantStack(){};
        MutantStack(const MutantStack &cpy_mut)
        {
            *this = cpy_mut;
        };
        MutantStack &operator=(const MutantStack &eq_mut)
        {
            stack<T, Container>::operator=(eq_mut);
            return *this;
        };
        iterator begin()
        {
            return this->c.begin();
        };
        iterator end()
        {
            return this->c.end();
        };
        ~MutantStack(){};
};