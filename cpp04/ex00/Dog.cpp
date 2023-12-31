/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:12:10 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/08 20:12:17 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
    cout << "Dog Default constructor" << endl;
};

Dog::Dog(const Dog &cpy_dog): Animal(cpy_dog)
{
    cout << "Dog Copy constructor" << endl;
};

Dog &Dog::operator=(const Dog &eq_dog)
{
    Animal::operator=(eq_dog);
    return (*this);
}

void    Dog::makeSound(void) const
{
    cout << "Woof..." << endl;
}

Dog::~Dog()
{
    cout << "Dog Destructuring" << endl;
}

