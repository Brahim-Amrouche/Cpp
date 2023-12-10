/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 07:11:11 by bamrouch          #+#    #+#             */
/*   Updated: 2023/12/10 14:29:24 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <math.h>
#include <float.h>
#include <cctype>
#include <cstdlib>
#include <exception>
#include <limits>
#include <sstream>
#include <limits.h>

using std::exception;
using std::string;
using std::cout;
using std::endl;

class PInfException : public exception
{
    public:
        const char *what() const throw();
};

class NInfException : public exception
{
    public:
        const char *what() const throw();
};

class NanException :public exception
{
    public:
        const char *what() const throw();
};

class ImpException:public exception
{
    public:
        const char *what() const throw();
};

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &cpy);
        ScalarConverter &operator=(const ScalarConverter &eq);
        ~ScalarConverter();
    public:
        static void Convert(const string str);
};