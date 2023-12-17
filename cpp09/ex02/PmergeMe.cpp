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
    for (size_t i = 0; i < s_deq.size(); i += 2)
    {
        if (i + 1 < s_deq.size() && s_deq[i] < s_deq[i + 1])
            t_swap(s_deq[i], s_deq[i + 1]);
        main_chain.push_back(s_deq[i]);
        if (i + 1 < s_deq.size())
            pending_chain.push_back(s_deq[i + 1]);
    }
    sortDeque(main_chain);
    for (size_t i = 0; pending_chain.size(); i = 0)
    {
        deque<int>::iterator elem = std::lower_bound(main_chain.begin(), main_chain.end(), pending_chain[i]);
        main_chain.insert(elem, pending_chain[i]);
        pending_chain.pop_front();
    }
    s_deq = main_chain;
}

PmergeMe::~PmergeMe()
{}
