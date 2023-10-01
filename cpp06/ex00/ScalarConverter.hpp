/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:26:28 by bamrouch          #+#    #+#             */
/*   Updated: 2023/10/01 16:25:58 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "string"
#include "iostream"
#include "sstream"
#include "limits"
#include "float.h"
#include "cctype"
#include "iomanip"

using std::string;
using std::cout;
using std::cerr;
using std::endl;
using std::istringstream;
using std::invalid_argument;
using std::isprint;
using std::setprecision;

class ScalarConverter
{
    private :
        ScalarConverter();
    public :
        template <typename T>
        static T convert(const char *literal);
};

