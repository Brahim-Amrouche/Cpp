/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:14:33 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/08 20:17:47 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    Animal *zoo[100];
    size_t  i = -1;
    while (++i < 50)
        zoo[i] = new Cat();
    i = 49;
    while (++i < 100)
        zoo[i] = new Dog();
    i = -1;
    while (++i < 100)
        delete zoo[i];
    Cat x;
    Cat y;
    x = x;
    x = y;
}