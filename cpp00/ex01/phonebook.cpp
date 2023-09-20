/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:42:50 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/06 19:22:04 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook():size(0)
{
    
}

PhoneBook::~PhoneBook()
{

}

Contact *PhoneBook::get_contacts() const
{
    return ((Contact *) contacts_list);
}


PhoneBook &PhoneBook::operator=(const PhoneBook &x)
{
    int i = -1;

    while (++i < 8)
        contacts_list[i] = x.contacts_list[i];
    return *this;
}

PhoneBook::PhoneBook(const PhoneBook &x)
{
    this->operator=(x);
}

void PhoneBook::add_contact()
{
    Contact new_contact;

    new_contact = Contact(Contact::fill_contact_info());
    contacts_list[size % 8] = new_contact;
    size++;
}

void PhoneBook::display_contacts()
{
    size_t  i = 0;

    while (i < size)
    {
        contacts_list[i].print_contact(true, i + 1);
        i++;
    }
}

void PhoneBook::display_contacts(int i)
{
    if (i <= 0 || (int) size < i || i > 8)
        cout << "Out of saved contacts range" << endl;
    else
        contacts_list[i - 1].print_contact(false, i);
}
