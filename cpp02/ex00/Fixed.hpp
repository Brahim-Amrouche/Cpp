/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:30:19 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/15 07:09:17 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_H
#define FIXED_H

#include "iostream"

using   std::cout;
using   std::endl;


class Fixed
{
    private:
        int              bits;
        static const int fract = 8;
    public:
        Fixed();
        Fixed(const Fixed &cpy_fixed);
        Fixed &operator=(const Fixed &eq_fixed);
        int   getRawBits(void);
        void  setRawBits(int const raw);
        ~Fixed();
};

#endif