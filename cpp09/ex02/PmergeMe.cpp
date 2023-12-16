/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:30:37 by bamrouch          #+#    #+#             */
/*   Updated: 2023/12/16 18:56:55 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMeExcept::PmergeMeExcept(const PMERGE_ERR &err):err_c(err)
{
    switch (err_c)
    {
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
    numbers = numbers.substr(0, numbers.find_first_not_of(SPACES));
    while (numbers[++i])
    {
        if (!zero_unset && numbers[i] == '0')
            ++zero_count;
        else if (numbers[i] != '0')
            zero_unset = true;
        if (numbers[i] == ' ' || numbers[i] == '\t')
            break;
        else if (!std::isdigit(numbers[i]) ||  i - zero_count >= 10)
            throw PmergeMe::PmergeMeExcept(WRONG_INTEGER);
    }
    if (!numbers[i] && !std::isdigit(numbers[i - 1]))
        return -1;
    string val = numbers.substr(0, i);
    long res = std::atol(val.c_str());
    if (res > INT_MAX)
        throw PmergeMe::PmergeMeExcept(WRONG_INTEGER);
    numbers = numbers.substr(i, numbers.find_first_not_of(SPACES, i));
    return res;
}

PmergeMe::PmergeMe(const int &argc, const char *argv[])
{
    int i = 0;
    int value = 0;
    string arg;
    while (++i < argc)
    {
        arg = argv[i];
        while (true)
        {
            value = parseInt(arg);
            if (value < 0)
                break;
            i_vec.push_back(value);
            i_lis.push_back(value);
        }
    }
}

PmergeMe::PmergeMe(const PmergeMe &cpy_merge)
{}

PmergeMe &PmergeMe::operator=(const PmergeMe &eq_merge)
{
    if (this != &eq_merge)
        return *this;
    return *this;
}

PmergeMe::~PmergeMe()
{}

