/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:44:17 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/24 12:53:48 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal():type("evolving")
{
    cout << "an animal is Default constructing" << endl;
};

Animal::Animal(string new_type):type(new_type)
{
    cout << "an animal is string constructing" << endl;
};

Animal::Animal(const Animal &cpy_animal):type(cpy_animal.type)
{
    cout << "an animal is being Copy constructing" << endl;
};

Animal  &Animal::operator=(const Animal &eq_animal)
{
    type = eq_animal.type;
    return(*this);
}

string  Animal::getType(void) const
{
    return type;
};

void    Animal::makeSound() const
{
    cout << ".../*gibrish*/" << endl;
}

Animal::~Animal()
{
    cout << "an animal is destructuring" << endl;
}
