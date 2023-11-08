/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:13:58 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/08 20:14:02 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat():Animal("Cat"), brain(new Brain())
{
    cout << "Cat Default Constructor" << endl;
}

Cat::Cat(const Cat &cpy_cat):Animal(cpy_cat), brain(new Brain(*cpy_cat.brain))
{
    cout << "Cat copy constructuring" << endl;
};

Cat &Cat::operator=(const Cat &eq_cat)
{
    if (this != &eq_cat)
    {
        Animal::operator=(eq_cat);
        delete brain;
        brain = new Brain(*eq_cat.brain);
    }
    return (*this);
};

void    Cat::makeSound(void) const
{
    cout << "Meaow..." << endl;
}

Cat::~Cat()
{
    delete brain;
    cout << "Cat destructuring" << endl;
}

