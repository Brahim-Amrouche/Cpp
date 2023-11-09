/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:16:36 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/09 21:27:35 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    AAnimal *zoo[100];

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