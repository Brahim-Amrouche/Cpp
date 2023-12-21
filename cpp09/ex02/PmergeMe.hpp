/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:31:03 by bamrouch          #+#    #+#             */
/*   Updated: 2023/12/17 21:07:47 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <limits.h>
#include <cstdlib>
#include <deque>
#define SPACES "\t "

using std::cout;
using std::endl;
using std::string;
using std::list;
using std::vector;
using std::deque;
using std::exception;

enum PMERGE_ERR
{
    NO_INPUT,
    WRONG_INTEGER,
};

class PmergeMe
{
    private:
        list<int> i_lis;
        deque<int> i_deq;
    public:
        class PmergeMeExcept: public exception
        {
            private:
                PMERGE_ERR err_c;
                string msg;
            public:
                PmergeMeExcept(const PMERGE_ERR &err);
                const char *what() const throw();
                ~PmergeMeExcept() throw();
        };
        PmergeMe();
        PmergeMe(int &argc,char **argv);
        PmergeMe(const PmergeMe &cpy_merge);
        PmergeMe &operator=(const PmergeMe &eq_merge);
        void sortDeque(deque<int> &s_deq);
        void sortList(list<int> &s_lis);
        ~PmergeMe();
};
