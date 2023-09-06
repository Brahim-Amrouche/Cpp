/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:42:25 by bamrouch          #+#    #+#             */
/*   Updated: 2023/08/29 17:02:15 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PHONE_BOOK_H
#define PHONE_BOOK_H
#include <iostream>
#include <string>
#include <iomanip>
#include "contact.hpp"

class PhoneBook {
    private :
        Contact contacts_list[8];
        size_t  size;
    public :
        PhoneBook();
        PhoneBook(const PhoneBook &x);
        ~PhoneBook();
        PhoneBook &operator=(const PhoneBook &x);
        Contact *get_contacts() const;
        void add_contact();
        void display_contacts();
        void display_contacts(int i);
};

#endif