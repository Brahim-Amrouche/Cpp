/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:40:41 by bamrouch          #+#    #+#             */
/*   Updated: 2023/10/06 22:19:41 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void    print_hello(T &x)
{
    cout << "hello=====>" << x << endl;
}

int main()
{
    string list[] = {"Brahim", "Ayoub" , "Imad", "Amine"};
    
    iter(list, 4, print_hello);
}