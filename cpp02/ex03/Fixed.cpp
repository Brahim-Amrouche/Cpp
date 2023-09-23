/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 06:48:04 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/23 11:56:56 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():bits(0)
{
    // cout << "Default constructor called" << endl;
};

Fixed::Fixed(const int i_raw)
{
    // cout << "Int constructor called" << endl;
    bits = i_raw << fract;
}

Fixed::Fixed(const float f_raw)
{
    // cout << "Float constructor called" << endl;
    bits = roundf((float) f_raw * (1 << fract));
}

Fixed::Fixed(const Fixed &cpy_fixed):bits(cpy_fixed.bits)
{
    // cout << "Copy constructor called" << endl;
};

Fixed &Fixed::operator=(const Fixed &eq_fixed)
{
    // cout << "Copy assignment operator called"  << endl; 
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
    return (float) bits / (1 << fract);   
}

ostream& operator<<(ostream& os, const Fixed& obj) 
{
    os << obj.toFloat();
    return os;
}

bool    Fixed::operator==(const Fixed &other) const
{
    return other.bits == this->bits;
}

bool    Fixed::operator!=(const Fixed &other) const
{
    return !this->operator==(other);
}

bool    Fixed::operator>(const Fixed &other) const
{
    return this->bits > other.bits;
}

bool    Fixed::operator>=(const Fixed &other) const
{
    return this->bits >= other.bits;
}

bool    Fixed::operator<(const Fixed &other) const
{
    return this->bits < other.bits;
}

bool    Fixed::operator<=(const Fixed &other) const
{
    return this->bits <= other.bits;
}

Fixed    Fixed::operator+(const Fixed &other)
{
    Fixed result;
    
    result.bits = bits + other.bits;
    return (result);
}

Fixed    Fixed::operator-(const Fixed &other)
{
    Fixed result;
    
    result.bits = bits - other.bits;
    return (result);
}

Fixed    Fixed::operator*(const Fixed &other)
{
    Fixed   result;
    long    my_bits = this->bits;
    long    other_bits = other.bits;

    result.bits = (my_bits * other_bits) >> fract;
    return (result);
}

Fixed    Fixed::operator/(const Fixed &other)
{
    Fixed   result;
    long    my_bits = this->bits << fract;
    long    other_bits = other.bits;

    result.bits = (my_bits / other_bits);
    return (result);
}

Fixed    &Fixed::operator++()
{
    bits += 1;   
    return (*this);
}

Fixed   Fixed::operator++(int)
{
    Fixed   cpy = *this;
    this->operator++();
    return (cpy);
}


Fixed &Fixed::operator--()
{
    bits -= 1;
    return (*this);
}

Fixed Fixed::operator--(int)
{
    Fixed cpy = *this;
    this->operator--();
    return cpy;
}

Fixed &Fixed::min(Fixed &first, Fixed &second)
{
    if (first <= second)
        return (first);
    else
        return (second);
}

const Fixed &Fixed::min(const Fixed &first, const Fixed &second)
{
    if (first <= second)
        return (first);
    else
        return (second);
}

Fixed &Fixed::max(Fixed &first, Fixed &second)
{
    if (first >= second)
        return (first);
    else
        return (second);
}

const Fixed &Fixed::max(const Fixed &first, const Fixed &second)
{
    if (first >= second)
        return (first);
    else 
        return (second);
}

Fixed::~Fixed()
{
    // cout << "Destructor called" << endl;
};