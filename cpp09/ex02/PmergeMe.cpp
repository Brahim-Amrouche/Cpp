/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:30:37 by bamrouch          #+#    #+#             */
/*   Updated: 2023/12/17 21:09:05 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMeExcept::PmergeMeExcept(const PMERGE_ERR &err):err_c(err)
{
    switch (err_c)
    {
        case NO_INPUT:
            msg = "Error: no input given";
            break;
        case WRONG_INTEGER:
            msg = "Error: wrong integer value";
            break;
        default:
            msg = "Error: Unknown";   
    }
}

const char *PmergeMe::PmergeMeExcept::what() const throw()
{
    return msg.c_str();
}

PmergeMe::PmergeMeExcept::~PmergeMeExcept() throw()
{}

PmergeMe::PmergeMe()
{}

int parseInt(string &numbers)
{
    size_t i = -1;
    size_t zero_count = 0;
    bool zero_unset = false;
    while (numbers[++i])
    {
        if (numbers[i] == ' ' || numbers[i] == '\t')
            break;
        else if (!std::isdigit(numbers[i]) ||  i - zero_count >= 10)
            throw PmergeMe::PmergeMeExcept(WRONG_INTEGER);
        if (!zero_unset && numbers[i] == '0')
            ++zero_count;
        else if (numbers[i] != '0')
            zero_unset = true;
    }
    if (i == 0 || (!numbers[i] && !std::isdigit(numbers[i - 1])))
        return -1;
    string val = numbers.substr(0, i);
    long res = std::atol(val.c_str());
    if (res > INT_MAX)
        throw PmergeMe::PmergeMeExcept(WRONG_INTEGER);
    numbers = numbers.substr(i);
    return res;
}

PmergeMe::PmergeMe(int &argc,char *argv[])
{
    int i = 0;
    int value = 0;
    string arg;
    size_t space_skiper;
    while (++i < argc)
    {
        arg = argv[i];
        while (arg.size())
        {
            if ((space_skiper = arg.find_first_not_of(SPACES)) != 0 
                && space_skiper != string::npos)
                arg = arg.substr(space_skiper);
            value = parseInt(arg);
            if (value < 0)
                break;
            i_deq.push_back(value);
            i_lis.push_back(value);
        }
    }
    if (!i_deq.size())
        throw PmergeMe::PmergeMeExcept(NO_INPUT);
    sortDeque(i_deq);
    sortList(i_lis);
    cout << "i_lis size: " << i_lis.size() << endl;
    for (size_t j = 0 ; j < i_deq.size(); j++)
    {
        cout << "deq: " << i_deq[j] << endl;
        cout << "lis: " << i_lis.front() << endl;
        i_lis.pop_front();
    }
}

PmergeMe::PmergeMe(const PmergeMe &cpy_merge)
{
    (void) cpy_merge;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &eq_merge)
{
    if (this != &eq_merge)
        return *this;
    return *this;
}

template <typename T>
void   t_swap(T &t1, T &t2)
{
    T temp = t1;
    t1 = t2;
    t2 = temp;
}

void    PmergeMe::sortDeque(deque<int> &s_deq)
{
    if (s_deq.size() <= 1)
        return;
    deque<int> main_chain;
    deque<int> pending_chain;
    for (; s_deq.size() ;)
    {
        if (s_deq.size() >= 2 && s_deq[0] < s_deq[1])
            t_swap(s_deq[0], s_deq[1]);
        main_chain.push_back(s_deq[0]);
        s_deq.pop_front();
        if (s_deq.size())
        {
            pending_chain.push_back(s_deq[0]);
            s_deq.pop_front();
        }
    }
    sortDeque(main_chain);
    s_deq = main_chain;
    for (;pending_chain.size();)
    {
        deque<int>::iterator elem = std::lower_bound(s_deq.begin(), s_deq.end(), pending_chain.front());
        s_deq.insert(elem, pending_chain.front());
        pending_chain.pop_front();
    }
}

void PmergeMe::sortList(list<int> &s_lis)
{
    if (s_lis.size() <= 1)
        return;
    list<int> main_chain;
    list<int> pending_chain;
    for (; s_lis.size(); )
    {
        int first = s_lis.front();
        s_lis.pop_front();
        int second = -1;
        if (s_lis.size())
        {
            second = s_lis.front();
            s_lis.pop_front();
        }
        if ( first < second)
            t_swap(first, second);
        main_chain.push_back(first);
        if (second >= 0)
            pending_chain.push_back(second);
    }
    sortList(main_chain);
    s_lis = main_chain;
    for (; pending_chain.size(); )
    {
        list<int>::iterator elem = std::lower_bound(s_lis.begin(), s_lis.end(), pending_chain.front());
        s_lis.insert(elem, pending_chain.front());
        pending_chain.pop_front();
    }
}

PmergeMe::~PmergeMe()
{}
