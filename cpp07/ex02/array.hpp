/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 22:38:09 by bamrouch          #+#    #+#             */
/*   Updated: 2023/12/12 09:33:38 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "string"
#include "iostream"
#include "exception"
#include <cstdlib>

using std::string;
using std::cout;
using std::endl;
using std::exception;

template <typename T>
class Array
{
    private :
        T *content;
        size_t s;
    public :
        Array():content(NULL), s(0){};
        Array(size_t i): content(new T[i]), s(i){};
        Array(const Array &cpy_array): content(new T[cpy_array.s]), s(cpy_array.s)
        {
            size_t i = -1;
            while (++i < s)
                content[i] = cpy_array[i];
        };
        Array &operator=(const Array &eq_array)
        {
            if (this == &eq_array)
                return *this;
            size_t i = -1;
            
            s = eq_array.s;
            delete[] content;
            content = new T[s];
            while (++i < s)
                content[i] = eq_array[i];
            return (*this);
        };
        T   &operator[](size_t index) const
        {
            if (s == 0 || index > s - 1)
                throw exception();
            return content[index];
        };
        size_t size() const
        {
            return s;
        };
        ~Array()
        {
            if (content)
                delete[] content;
        };
};