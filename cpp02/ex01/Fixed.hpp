/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 05:30:19 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/15 14:10:08 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef FIXED_H
#define FIXED_H

#include "iostream"
#include "cmath"

using   std::cout;
using   std::endl;
using   std::ostream;

class Fixed
{
    private:
        int              bits;
        static const int fract = 8;
    public:
        Fixed();
        Fixed(const int i_raw);
        Fixed(const float f_raw);
        Fixed(const Fixed &cpy_fixed);
        Fixed &operator=(const Fixed &eq_fixed);
        int   getRawBits(void);
        void  setRawBits(int const raw);
        float toFloat(void) const;
        int   toInt(void) const;
        ostream &operator<<(ostream &os) const;
        ~Fixed();
};

#endif