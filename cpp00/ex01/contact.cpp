/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:45:32 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/06 19:27:37 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact::Contact():contact_data(){};

Contact::Contact(const Contact_data &contact):contact_data(contact){};

Contact::~Contact(){}

Contact &Contact::operator=(const Contact &x)
{
    this->contact_data = x.contact_data;
    return *this;
}

Contact_data Contact::fill_contact_info()
{
    Contact_data c_data;
    
    cin.ignore();
    cout << "enter the contact's first name: ";
    getline(cin, c_data.first_name) ;
    cout << "enter the contact's last name: ";
    getline(cin, c_data.last_name);
    cout << "enter the contact's phone number: ";
    getline(cin, c_data.phone_number);
    cout << "enter the contact's darkest secret: ";
    getline(cin, c_data.darkest_secret);
    return c_data;
}

void Contact::print_contact(bool horizontal, int index)
{
    if (horizontal)
        cout << index << " | " <<contact_data.first_name << " | " << contact_data.last_name 
            << " | " << contact_data.phone_number << " | " << contact_data.darkest_secret << endl;
    else
    {
        cout << "-Index: " << index << endl;
        cout << "-Contact first name: " << contact_data.first_name << endl;
        cout << "-Contact last name: " << contact_data.last_name << endl;
        cout << "-Contact phone number: " << contact_data.phone_number << endl;
        cout << "-Contact darkest secret: " << contact_data.darkest_secret << endl; 
    }
}
