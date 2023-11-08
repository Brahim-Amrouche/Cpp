/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 20:13:04 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/08 20:13:08 by bamrouch         ###   ########.fr       */
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
