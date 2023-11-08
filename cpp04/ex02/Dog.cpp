/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:16:20 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/08 20:16:23 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog():AAnimal("Dog"), brain(new Brain())
{
    cout << "Dog Default constructor" << endl;
};

Dog::Dog(const Dog &cpy_dog):AAnimal(cpy_dog.type), brain(new Brain(*cpy_dog.brain))
{
    cout << "Dog Copy constructor" << endl;
};

Dog &Dog::operator=(const Dog &eq_dog)
{
    if (this != &eq_dog)
    {
        AAnimal::operator=(eq_dog);
        delete brain;
        brain = new Brain(*eq_dog.brain);
    }
    return (*this);
}

void    Dog::makeSound(void) const
{
    cout << "Woof..." << endl;
}

Dog::~Dog()
{
    delete  brain;
    cout << "Dog Destructuring" << endl;
}

