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

void    string_to_upper(char *str)
{
    size_t  str_len;

    str_len = std::strlen(str);
    for(size_t i = 0; i < str_len; i++)
        str[i] = std::toupper(str[i]);
}

int main(int ac, char *av[])
{
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        for (int i = 1; i < ac; i++)
        {
            string_to_upper(av[i]);
            std::cout << av[i];
        }
    }
    std::cout << std::endl;
    return (0);
} 