/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 01:01:31 by bamrouch          #+#    #+#             */
/*   Updated: 2023/10/06 21:10:12 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iostream"

using std::string;
using std::cout;
using std::endl;

template <typename T>
void swap(T &a, T &b)
{
    T temp = a;

    a = b;
    b = temp;   
};

template <typename T>
T &min(T &a, T &b)
{
    if (a >= b)
        return b;
    return a;
};

template <typename T>
T &max(T &a, T &b)
{
    if (a <= b)
        return b;
    return a;
};
