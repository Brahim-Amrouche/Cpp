/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 13:39:59 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/24 14:54:14 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    AbstractAnimal *zoo[100];

    size_t  i = -1;
    while (++i < 50)
        zoo[i] = new Cat();
    i = 49;
    while (++i < 100)
        zoo[i] = new Dog();
    i = -1;
    while (++i < 100)
        delete zoo[i];
}