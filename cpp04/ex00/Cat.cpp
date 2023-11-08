/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:11:55 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/08 20:11:59 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat():Animal("Cat")
{
    cout << "Cat Default Constructor" << endl;
}

Cat::Cat(const Cat &cpy_cat):Animal(cpy_cat)
{
    cout << "Cat copy constructuring" << endl;
};

Cat &Cat::operator=(const Cat &eq_cat)
{
    Animal::operator=(eq_cat);
    return (*this);
};

void    Cat::makeSound(void) const
{
    cout << "Meaow..." << endl;
}

Cat::~Cat()
{
    cout << "Cat destructuring" << endl;
}

