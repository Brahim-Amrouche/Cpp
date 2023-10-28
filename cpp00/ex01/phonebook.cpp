/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:42:50 by bamrouch          #+#    #+#             */
/*   Updated: 2023/10/28 14:22:02 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook():size(0)
{}

Contact *PhoneBook::get_contacts() const
{
    return ((Contact *) contacts_list);
}

size_t PhoneBook::get_size() const
{
    return size;
}

PhoneBook &PhoneBook::operator=(const PhoneBook &eq_phonebook)
{
    size_t i = -1;

    size = eq_phonebook.size;
    while (++i < size)
        contacts_list[i] = eq_phonebook.contacts_list[i];
    return *this;
}

PhoneBook::PhoneBook(const PhoneBook &cpy_phonebook)
{
    this->operator=(cpy_phonebook);
}

void PhoneBook::add_contact()
{
    Contact new_contact(Contact::fill_contact_info());
    contacts_list[size % 8] = new_contact;
    size++;
}

void PhoneBook::display_contacts()
{
    size_t  i = -1;

    while ((size < 8 && ++i < size) || (size >= 8 && ++i < 8))
        contacts_list[i].print_contact(true, i + 1);
}

void PhoneBook::display_contacts(int i)
{
    if (i <= 0 || (int) size < i || i > 8)
        cout << "Out of saved contacts range" << endl;
    else
        contacts_list[i - 1].print_contact(false, i);
}

PhoneBook::~PhoneBook()
{}