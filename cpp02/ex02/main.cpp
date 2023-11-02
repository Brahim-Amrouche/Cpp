/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:09:51 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/02 15:36:04 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main()
{
    Fixed a(20);
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    cout << "COMPARAISON" << endl;
    cout << "equals: " << (a == b) << endl;
    cout << "differs: " << (a != b) << endl;
    cout << "greater than: "  << (a > b) << endl;
    cout << "greater than equals: " << (a >= b) << endl;
    cout << "lesser than: " << (a < b) << endl;
    cout << "lesser than equals: " << (a < b) << endl;
    
    cout << "OPERATIONS" << endl;
    cout << "addition: " << a + b << endl; 
    cout << "substraction: " << a - b << endl;
    cout << "multiplication: " << a * b << endl;
    cout << "division: a / b"  << a / b << endl;

    cout << "INCREMENTS" << endl;
    a = Fixed(0.0f);
    cout << a << endl;
    cout << ++a << endl;
    cout << a << endl;
    cout << a++ << endl;
    cout << a << endl;
    cout << "decrement" << endl;
    cout << a << endl;
    cout << --a << endl;
    cout << a << endl;
    cout << a--<< endl;
    cout << a << endl;

    cout << b << endl;

    cout << "max: " << Fixed::max( a, b ) << endl;
    cout << "min :" << Fixed::min( a, b) << endl;
    return 0;
}
