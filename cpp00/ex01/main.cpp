/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:07:41 by bamrouch          #+#    #+#             */
/*   Updated: 2023/08/31 19:25:15 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main()
{
    std::string input;
    PhoneBook   phone_book;

    while (true)
    {
        cout << "please enter a command:";
        cin >> input;
        if ( input == "ADD")
            phone_book.add_contact();
        else if (input == "SEARCH")
        {
            int i;
            phone_book.display_contacts();
            cin.ignore();
            cout << "enter the index of entry to search:";
            cin >> i;
            if (cin.fail())
            {
                cout << "wrong input" << endl;
                cin.clear();
            }
            else
                phone_book.display_contacts(i);
        }
        else if (input == "EXIT")
            break;
    }
    return (0);
}