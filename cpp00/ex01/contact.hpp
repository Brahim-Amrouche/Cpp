/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:18:28 by bamrouch          #+#    #+#             */
/*   Updated: 2023/10/27 18:47:47 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CONTACT_H
#define CONTACT_H
#include <string>
#include <iostream>
#include <iomanip>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::left;
using std::right;
using std::setw;
using std::setfill;

class Contact {
    private :
        string first_name;
        string last_name;
        string phone_number;
        string darkest_secret;
    public :
		Contact();
		Contact(const Contact &cpy_contact);
		Contact &operator=(const Contact &eq_contact);
        static Contact fill_contact_info();
		~Contact();
        string    get_firstname();
        string    get_lastname();
        string    get_phonenumber();
        string    get_darkestsecret();
        void      set_firstname(const string &new_firstname);
        void      set_lastname(const string &new_lastname);
        void      set_phonenumber(const string &new_phonenumber);
        void      set_darkestsecret(const string &new_darkestsecret);
		void      print_contact(bool horizontal, int index);

};

#endif