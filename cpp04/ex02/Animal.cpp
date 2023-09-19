/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AbstractAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 12:44:17 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/19 10:09:33 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

AbstractAnimal  &AbstractAnimal::operator=(const AbstractAnimal &eq_AbstractAnimal)
{
    type = eq_AbstractAnimal.type;
    return(*this);
}

string  AbstractAnimal::getType(void)
{
    return type;
};

void    AbstractAnimal::setType(string new_type)
{
    type = new_type;
}

void    AbstractAnimal::makeSound()
{
    cout << ".../*gibrish*/" << endl;
}

AbstractAnimal::~AbstractAnimal()
{
    cout << "an AbstractAnimal is destructuring" << endl;
}
