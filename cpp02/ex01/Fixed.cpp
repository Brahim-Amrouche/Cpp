/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 06:48:04 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/15 17:29:21 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():bits(0)
{
    cout << "Default constructor called" << endl;
};

Fixed::Fixed(const int i_raw)
{
    cout << "Int constructor called" << endl;
    bits = i_raw << fract;
}

Fixed::Fixed(const float f_raw)
{
    cout << "Float constructor called" << endl;
    bits = roundf(f_raw * (1 << fract));
}

Fixed::Fixed(const Fixed &cpy_fixed):bits(cpy_fixed.bits)
{
    cout << "Copy constructor called" << endl;
};

Fixed &Fixed::operator=(const Fixed &eq_fixed)
{
    cout << "Copy assignment operator called"  << endl; 
    bits = eq_fixed.bits;
    return (*this);
};

int Fixed::getRawBits(void)
{
    cout << "getRawBits member function called" << endl;
    return bits;
};

void    Fixed::setRawBits(const int raw)
{
    cout << "setRawBits member function called" << endl;
    bits = raw;
};

int     Fixed::toInt(void) const
{
    return bits >> fract;
}

float   Fixed::toFloat(void) const
{
    return bits / 1 << fract;   
}

ostream &Fixed::operator<<(ostream &os) const
{
    os << toFloat();
    return os;
}


Fixed::~Fixed()
{
    cout << "Destructor called" << endl;
};