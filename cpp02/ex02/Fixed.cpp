/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 06:48:04 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/16 11:52:02 by bamrouch         ###   ########.fr       */
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
    return bits / (1 << fract);   
}

ostream &Fixed::operator<<(ostream &os) const
{
    os << toFloat();
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
    this->bits += other.bits;
    return (*this);
}

Fixed    Fixed::operator-(const Fixed &other)
{
    this->bits -= other.bits;
    return (*this);
}

Fixed    Fixed::operator*(const Fixed &other)
{
    long    my_bits = this->bits;
    long    other_bits = other.bits;

    this->bits = (my_bits * other_bits) >> fract;
    return (*this);
}

Fixed    Fixed::operator/(const Fixed &other)
{
    long    my_bits = this->bits << fract;
    long    other_bits = other.bits;

    this->bits = (my_bits / other_bits);
    return (*this);
}

Fixed    &Fixed::operator++()
{
    *this = *this + Fixed((float) 1.0);   
    return (*this);
}

Fixed   Fixed::operator++(int _)
{
    Fixed   cpy = *this;
    this->operator++();
    return (cpy);
}


Fixed &Fixed::operator--()
{
    *this = *this - Fixed((float) 1.0);
    return (*this);
}

Fixed Fixed::operator--(int _)
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
    cout << "Destructor called" << endl;
};