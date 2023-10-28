/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:42:25 by bamrouch          #+#    #+#             */
/*   Updated: 2023/10/28 14:15:41 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PHONE_BOOK_H
#define PHONE_BOOK_H
#include "contact.hpp"

class PhoneBook {
    private :
        Contact contacts_list[8];
        size_t  size;
    public :
        PhoneBook();
        PhoneBook(const PhoneBook &cpy_phonebook);
        PhoneBook &operator=(const PhoneBook &eq_phonebook);
        Contact *get_contacts() const;
        size_t  get_size() const;
        void add_contact();
        void display_contacts();
        void display_contacts(int i);
        ~PhoneBook();
};

#endif