/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:18:28 by bamrouch          #+#    #+#             */
/*   Updated: 2023/08/31 19:24:43 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CONTACT_H
#define CONTACT_H
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;

struct Contact_data
{
    string first_name;
    string last_name;
    string phone_number;
    string darkest_secret;
	Contact_data(): first_name(""),
        last_name(""), phone_number(""), darkest_secret(""){};
    Contact_data(const Contact_data &contact):first_name(contact.first_name),
        last_name(contact.last_name), phone_number(contact.phone_number),
        darkest_secret(contact.darkest_secret){}
};

class Contact {
    private :
        Contact_data contact_data;
    public :
		Contact();
		Contact(const Contact_data &contact);
		~Contact();
		Contact &operator=(const Contact &x);
		void    print_contact(bool horizontal, int index);
        static Contact_data fill_contact_info();

};

#endif