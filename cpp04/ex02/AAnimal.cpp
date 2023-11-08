/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:14:44 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/08 20:14:47 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal():type("evolving")
{
    cout << "an animal is Default constructing" << endl;
};

AAnimal::AAnimal(string new_type):type(new_type)
{
    cout << "an animal is string constructing" << endl;
};

AAnimal::AAnimal(const AAnimal &cpy_animal):type(cpy_animal.type)
{
    cout << "an animal is being Copy constructing" << endl;
};

AAnimal  &AAnimal::operator=(const AAnimal &eq_AbstractAnimal)
{
    cout << "an animal is being Copy assignement constructing" << endl;
    if (this != &eq_AbstractAnimal)
        type = eq_AbstractAnimal.type;
    return(*this);
}

string  AAnimal::getType(void) const
{
    return type;
};

void    AAnimal::setType(string new_type)
{
    type = new_type;
}

void    AAnimal::makeSound() const
{
    cout << ".../*gibrish*/" << endl;
}

AAnimal::~AAnimal()
{
    cout << "an AAnimal is destructuring" << endl;
}
