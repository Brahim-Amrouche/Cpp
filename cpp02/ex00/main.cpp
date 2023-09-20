/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:02:10 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/20 18:06:53 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"
int main()
{
    Fixed  x;
    Fixed  y;

    y.setRawBits(5);
    cout << "raw bits x " << x.getRawBits()  << endl;
    cout  << "and then y " << y.getRawBits() << endl;
}