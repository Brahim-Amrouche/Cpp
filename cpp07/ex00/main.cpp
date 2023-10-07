/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 22:20:59 by bamrouch          #+#    #+#             */
/*   Updated: 2023/10/06 21:23:31 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"


int main()
{
    int a = 2;
    int b = 3;
    ::swap( a, b );
    cout << "a = " << a << ", b = " << b << endl;
    cout << "min( a, b ) = " << ::min( a, b ) << endl;
    cout << "max( a, b ) = " << ::max( a, b ) << endl;
    string c = "chaine1";
    string d = "chaine2";
    ::swap(c, d);
    cout << "c = " << c << ", d = " << d << endl;
    cout << "min( c, d ) = " << ::min( c, d ) << endl;
    cout << "max( c, d ) = " << ::max( c, d ) << endl;
    return 0;
}
