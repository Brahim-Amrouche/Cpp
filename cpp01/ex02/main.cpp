/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 00:03:16 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/12 00:20:43 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"
#include "string"

int     main(void)
{
    std::string the_string = std::string("HI THIS IS BRAIN");
    std::string *p_string = &the_string;
    std::string &r_string = the_string;

    std::cout << "the string address: " << &the_string << std::endl;
    std::cout << "the string pointer adress: " << p_string << std::endl;
    std::cout << "the string reference adress: " << &r_string << std::endl;
     
    std::cout << "the value of the string variable: " << the_string << std::endl;
    std::cout << "the value of the string pointer: " << *p_string << std::endl;
    std::cout << "the value of the string reference: " << r_string << std::endl;
}