/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:40:34 by bamrouch          #+#    #+#             */
/*   Updated: 2023/12/12 11:12:37 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "string"
#include "iostream"

using std::string;
using std::cout;
using std::endl;

template <typename T, typename FUNC>
void iter(T *array, size_t length,FUNC *f)
{
    if (!array || !f)
        return;
    size_t i = -1;
    while (++i < length)
        f(array[i]);
}