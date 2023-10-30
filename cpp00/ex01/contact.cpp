/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:45:32 by bamrouch          #+#    #+#             */
/*   Updated: 2023/10/30 15:16:20 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

bool string_is_digit(const string &str)
{
    size_t i = -1; 
    const char    *c_str = str.c_str();
    while(c_str[++i])
    {   
        if (!isdigit(c_str[i]))
        {
            cout << "phone number must be full digits" << endl;
            return false;
        }
    }
    return true;
}

Contact Contact::fill_contact_info()
{
    Contact new_contact;
    
    while (!cin.eof() &&  new_contact.first_name.empty())
    {
        cout << "enter the contact's first name:";
        getline(cin, new_contact.first_name);
    }
    while (!cin.eof() && new_contact.last_name.empty())
    {
        cout << "enter the contact's last name:";
        getline(cin, new_contact.last_name);
    }
    while (!cin.eof() && new_contact.nickname.empty())
    {
        cout << "enter the contact's nickname:";
        getline(cin, new_contact.nickname);
    }
    while (!cin.eof() && (new_contact.phone_number.empty() || !string_is_digit(new_contact.phone_number)))
    {
        cout << "enter the contact's phone number:";
        getline(cin, new_contact.phone_number);
    }
    while (!cin.eof() && new_contact.darkest_secret.empty())
    {
        cout << "enter the contact's darkest secret:";
        getline(cin, new_contact.darkest_secret);
    }
    return new_contact;
}

Contact::Contact():first_name(""),last_name(""), nickname(""), phone_number(""), darkest_secret("")
{};

Contact::Contact(const Contact &cpy_contact)
{
    this->operator=(cpy_contact);
};


Contact &Contact::operator=(const Contact &eq_contact)
{
    first_name = eq_contact.first_name;
    last_name = eq_contact.last_name;
    nickname = eq_contact.nickname;
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
        cout << right << setfill(' ') << setw(10) << trim_input(nickname) << endl;
    }
    else
    {
        cout << "-Index: " << index << endl;
        cout << "-Contact first name: " << first_name << endl;
        cout << "-Contact last name: " << last_name << endl;
        cout << "-Contact nickname: " << nickname << endl;
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

string Contact::get_nickname()
{
    return nickname;
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

void      Contact::set_nickname(const string &new_nickname)
{
    nickname = new_nickname;
}

void      Contact::set_phonenumber(const string &new_phonenumber)
{
    phone_number = new_phonenumber;
};

void      Contact::set_darkestsecret(const string &new_darkestsecret)
{
    darkest_secret = new_darkestsecret;
};


Contact::~Contact(){}