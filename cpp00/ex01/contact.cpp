/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:45:32 by bamrouch          #+#    #+#             */
/*   Updated: 2023/10/28 14:31:24 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

Contact Contact::fill_contact_info()
{
    Contact new_contact;
    
    if (!cin.eof())
    {
        cout << "enter the contact's first name:";
        getline(cin, new_contact.first_name);
    }
    if (!cin.eof())
    {
        cout << "enter the contact's last name:";
        getline(cin, new_contact.last_name);
    }
    if (!cin.eof())
    {
        cout << "enter the contact's phone number:";
        getline(cin, new_contact.phone_number);
    }
    if (!cin.eof())
    {
        cout << "enter the contact's darkest secret:";
        getline(cin, new_contact.darkest_secret);
    }
    return new_contact;
}

Contact::Contact():first_name(""), last_name(""), phone_number(""), darkest_secret("")
{};

Contact::Contact(const Contact &cpy_contact)
{
    this->operator=(cpy_contact);
};


Contact &Contact::operator=(const Contact &eq_contact)
{
    first_name = eq_contact.first_name;
    last_name = eq_contact.last_name;
    phone_number = eq_contact.phone_number;
    darkest_secret = eq_contact.darkest_secret;    
    return *this;
}

string  trim_input(string &input)
{
    if(input.size() > 10)
    {
        string temp = input.substr(0, 9);
        temp.push_back('.');
        return temp;
    }
    return input;
}

void Contact::print_contact(bool horizontal, int index)
{
    if (horizontal)
    {
        cout << right << setfill(' ') << setw(10) << index << "|";
        cout << right << setfill(' ') << setw(10) << trim_input(first_name) << "|";
        cout << right << setfill(' ') << setw(10) << trim_input(last_name) << "|"; 
        cout << right << setfill(' ') << setw(10) << trim_input(phone_number) << "|";
        cout << right << setfill(' ') << setw(10) << trim_input(darkest_secret) << endl;
    }
    else
    {
        cout << "-Index: " << index << endl;
        cout << "-Contact first name: " << first_name << endl;
        cout << "-Contact last name: " << last_name << endl;
        cout << "-Contact phone number: " << phone_number << endl;
        cout << "-Contact darkest secret: " << darkest_secret << endl; 
    }
}

string Contact::get_firstname()
{
    return first_name;
}

string Contact::get_lastname()
{
    return last_name;
}

string Contact::get_phonenumber()
{
    return phone_number;
}

string Contact::get_darkestsecret()
{
    return darkest_secret;
}

void      Contact::set_firstname(const string &new_firstname)
{
    first_name = new_firstname;
};
void      Contact::set_lastname(const string &new_lastname)
{
    last_name = new_lastname;
};
void      Contact::set_phonenumber(const string &new_phonenumber)
{
    phone_number = new_phonenumber;
};

void      Contact::set_darkestsecret(const string &new_darkestsecret)
{
    darkest_secret = new_darkestsecret;
};

Contact::~Contact(){}