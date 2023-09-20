/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 01:38:16 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/20 12:18:46 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

int main(int argc, char *argv[])
{
    if (argc != 4)
        cout << "wrong number of arguments" << endl;
    else
    {
        Sed sed(argv[1], string(argv[1]).append(".replace"));
        if (sed.replace_in_file(argv[2], argv[3]))
            return 0;
        return 1;
    }
}