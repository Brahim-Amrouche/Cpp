/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:07:41 by bamrouch          #+#    #+#             */
/*   Updated: 2023/10/27 16:17:33 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main()
{
    PhoneBook phone_book;
    bool      err = false;
    while (true)
    {
        string input("");
        cout << "please enter a command:";
        getline(cin , input);
        if (input == "ADD")
            phone_book.add_contact();
        else if (input == "SEARCH")
        {
            int i;
            phone_book.display_contacts();
            cout << "enter the index of entry to search:";
            cin >> i;
            if (cin.fail())
            {
                cin.clear();
                err = true;
            }
            else
                phone_book.display_contacts(i);
            cin.ignore();
        }
        else if (input == "EXIT")
            break;
        if (err)
            cin.ignore();
        err = false;
    }
    return (0);
}