/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:15:11 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/08 20:15:14 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

AbstractAnimal::AbstractAnimal():type("evolving")
{
    cout << "an animal is Default constructing" << endl;
};

AbstractAnimal::AbstractAnimal(string new_type):type(new_type)
{
    cout << "an animal is string constructing" << endl;
};

AbstractAnimal::AbstractAnimal(const AbstractAnimal &cpy_animal):type(cpy_animal.type)
{
    cout << "an animal is being Copy constructing" << endl;
};

AbstractAnimal  &AbstractAnimal::operator=(const AbstractAnimal &eq_AbstractAnimal)
{
    type = eq_AbstractAnimal.type;
    return(*this);
}

string  AbstractAnimal::getType(void) const
{
    return type;
};

void    AbstractAnimal::setType(string new_type)
{
    type = new_type;
}

void    AbstractAnimal::makeSound() const
{
    cout << ".../*gibrish*/" << endl;
}

AbstractAnimal::~AbstractAnimal()
{
    cout << "an AbstractAnimal is destructuring" << endl;
}
