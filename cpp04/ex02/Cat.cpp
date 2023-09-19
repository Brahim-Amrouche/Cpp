/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 13:04:16 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/19 10:27:26 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat():brain(new Brain())
{
    AbstractAnimal::setType("Cat");
    cout << "Cat Default Constructor" << endl;
}

Cat::Cat(const Cat &cpy_cat):brain(new Brain(*cpy_cat.brain))
{
    AbstractAnimal::setType(cpy_cat.type);
    cout << "Cat copy constructuring" << endl;
};

Cat &Cat::operator=(const Cat &eq_cat)
{
    AbstractAnimal::operator=(eq_cat);
    delete brain;
    brain = new Brain(*eq_cat.brain);
    return (*this);
};

void    Cat::makeSound(void)
{
    cout << "Meaow..." << endl;
}

Cat::~Cat()
{
    delete brain;
    cout << "Cat destructuring" << endl;
}

