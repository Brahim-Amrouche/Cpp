/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 00:03:16 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/20 11:59:11 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "string"

using std::string;
using std::cout;
using std::endl;

int     main(void)
{
    string the_string = string("HI THIS IS BRAIN");
    string *p_string = &the_string;
    string &r_string = the_string;

    cout << "the string address: " << &the_string << endl;
    cout << "the string pointer adress: " << p_string << endl;
    cout << "the string reference adress: " << &r_string << endl;
     
    cout << "the value of the string variable: " << the_string << endl;
    cout << "the value of the string pointer: " << *p_string << endl;
    cout << "the value of the string reference: " << r_string << endl;
}