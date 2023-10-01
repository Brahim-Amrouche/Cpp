/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:27:06 by bamrouch          #+#    #+#             */
/*   Updated: 2023/10/01 15:05:28 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


template int ScalarConverter::convert(const char *literal);
template float ScalarConverter::convert(const char *literal);
template double ScalarConverter::convert(const char *literal);

template <typename T>
T ScalarConverter::convert(const char *literal)
{
    istringstream stream(literal);
    T   number;
    
    if (!(stream >> number))
        throw invalid_argument("couldn't convert string into number");
    return number;
}
