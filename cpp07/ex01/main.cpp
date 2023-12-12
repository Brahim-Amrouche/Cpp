/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:40:41 by bamrouch          #+#    #+#             */
/*   Updated: 2023/12/12 11:16:03 by bamrouch         ###   ########.fr       */
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
    const string list[] = {"Brahim", "Ayoub" , "Imad", "Amine"};
    const int i_list[] = {1, 2 ,3 , 4};

    iter(i_list, 4, print_hello<const int>);
}
