/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:12:42 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/08 20:12:45 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal():type("ADN")
{
    cout << "WrongAnimal Default constructing" << endl;
};

WrongAnimal::WrongAnimal(string new_type):type(new_type)
{
    cout << "WrongAnimal string constructing" << endl;
};

WrongAnimal::WrongAnimal(const WrongAnimal &cpy_animal):type(cpy_animal.type)
{
    cout << "WrongAnimal Copy constructing" << endl;
};

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &eq_animal)
{
    type = eq_animal.type;
    return (*this);
}

string    WrongAnimal::getType(void) const
{
    return type;
}

void   WrongAnimal::makeSound() const
{
    cout << "evolving quietly..." << endl;
}

WrongAnimal::~WrongAnimal()
{
    cout << "WrongAnimal Destructuring" << endl;
}

