/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:31:03 by bamrouch          #+#    #+#             */
/*   Updated: 2023/12/16 18:54:36 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <limits.h>
#define SPACES "\t "

using std::cout;
using std::endl;
using std::string;
using std::list;
using std::vector;
using std::exception;

enum PMERGE_ERR
{
    WRONG_INTEGER,
};

class PmergeMe
{
    private:
        list<int> i_lis;
        vector<int> i_vec;
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
        PmergeMe(const int &argc, const char **argv);
        PmergeMe(const PmergeMe &cpy_merge);
        PmergeMe &operator=(const PmergeMe &eq_merge);
        ~PmergeMe();
};
