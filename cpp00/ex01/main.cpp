/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 18:07:41 by bamrouch          #+#    #+#             */
/*   Updated: 2023/10/27 19:01:26 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void    search_contacts(PhoneBook &phone_book)
{
    string temp;
    int i = 0;
    phone_book.display_contacts();
    cout << "enter the index of entry to search:";
    getline(cin, temp);
    if (!cin.eof() && temp != "")
    {
        if (temp.size() == 1 && temp[0] >= '1' && temp[0] <= '8')
            i = temp[0] - '0';
        else
        {
            cout << "Wrong Index" << endl;
            return;
        }
    }
    else
        return ;
    phone_book.display_contacts(i);
}

int main()
{
    string input("");
    PhoneBook phone_book;
    while (input != "EXIT")
    {
        cout << "please enter a command:";
        getline(cin , input);
        if (input == "ADD")
            phone_book.add_contact();
        else if (input == "SEARCH")
            search_contacts(phone_book);
        if (cin.eof())
        {
            cout << "Interrupted" << endl;
            return 0;
        }
    }
    return (0);
}