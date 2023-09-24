/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:44:56 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/24 12:21:30 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat():WrongAnimal("WrongCat")
{
    cout << "WrongCat Default Constructor" << endl;
};

WrongCat::WrongCat(const WrongCat &cpy_wrong):WrongAnimal(cpy_wrong)
{
    cout << "WrongCat String Constructor" << endl;
};

WrongCat    &WrongCat::operator=(const WrongCat &eq_wrong)
{
    WrongAnimal::operator=(eq_wrong);
    return (*this);
}

void    WrongCat::makeSound(void) const
{
    cout << "pzzzzzzz...." << endl;
}

WrongCat::~WrongCat()
{
    cout << "WrongCat Destructor" << endl;
}
