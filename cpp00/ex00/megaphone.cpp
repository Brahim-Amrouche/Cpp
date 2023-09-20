/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 14:42:32 by bamrouch          #+#    #+#             */
/*   Updated: 2023/08/27 14:43:12 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cstring>

using std::cout;
using std::endl;
using std::strlen;
using std::toupper;

void    string_to_upper(char    *str)
{
    size_t  str_len;

    str_len = strlen(str);
    for(size_t i = 0; i < str_len; i++)
        str[i] = toupper(str[i]);
}

int main(int ac, char *av[])
{
    if (ac == 1)
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        for (int i = 1; i < ac; i++)
        {
            string_to_upper(av[i]);
            cout << av[i];
        }
    }
    cout << endl;
    return (0);
} 