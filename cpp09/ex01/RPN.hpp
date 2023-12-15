/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:55:10 by bamrouch          #+#    #+#             */
/*   Updated: 2023/12/15 18:22:21 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <cctype>

#define PLUS '+'
#define MINUS '-'
#define MULT '*'
#define DIV '/'

using std::string;
using std::cout;
using std::endl;
using std::stack;
using std::exception;

enum RPN_ERRORS
{
    WRONG_TOKEN,
    WRONG_SYNTAX,
};

class Rpn 
{
    private:
        void    calc_plus();
        void    calc_minus();
        void    calc_mult();
        void    calc_div();
        stack<string> rpn_stack;
    public:
        class RpnException: public exception
        {
            private:
                RPN_ERRORS err_c;
                string msg;
            public:
                RpnException(RPN_ERRORS err);
                const char *what() const throw();
                ~RpnException() throw(); 
        };
        Rpn();
        Rpn(const string &input);
        Rpn(const Rpn &cpy_rpn);
        Rpn &operator=(const Rpn &eq_rpn);
        void    calculate(char c);
        ~Rpn();
};