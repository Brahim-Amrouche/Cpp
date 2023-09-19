/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:14:34 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/19 10:32:21 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(): brain(new Brain())
{
    AbstractAnimal::setType("Dog");
    cout << "Dog Default constructor" << endl;
};

Dog::Dog(const Dog &cpy_dog): brain(new Brain(*cpy_dog.brain))
{
    AbstractAnimal::setType(cpy_dog.type);
    cout << "Dog Copy constructor" << endl;
};

Dog &Dog::operator=(const Dog &eq_dog)
{
    AbstractAnimal::operator=(eq_dog);
    delete brain;
    brain = new Brain(*eq_dog.brain);
    return (*this);
}

void    Dog::makeSound(void)
{
    cout << "Woof..." << endl;
}

Dog::~Dog()
{
    delete  brain;
    cout << "Dog Destructuring" << endl;
}

