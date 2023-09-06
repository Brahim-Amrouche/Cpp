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
        std::cout << "please enter a command:";
        std::cin >> input;
        if ( input == "ADD")
            phone_book.add_contact();
        else if (input == "SEARCH")
        {
            int i;
            phone_book.display_contacts();
            std::cout << "enter the index of entry to search:";
            std::cin >> i;
            if (std::cin.fail())
            {
                std::cout << "wrong input" << std::endl;
                std::cin.clear();
            }
            else
                phone_book.display_contacts(i);
        }
        else if (input == "EXIT")
            break;
    }
    return (0);
}