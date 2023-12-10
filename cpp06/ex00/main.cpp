/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 09:00:58 by bamrouch          #+#    #+#             */
/*   Updated: 2023/12/10 14:32:11 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "should be: ./convert [number]" << endl;
        return (-1);
    }
    ScalarConverter::Convert(argv[1]);
    return (0);
}