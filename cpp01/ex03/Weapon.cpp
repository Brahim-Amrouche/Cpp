/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 01:42:02 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/12 23:40:39 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string info)
{
    type = info;
}

Weapon::Weapon(const Weapon &cpy_weapon)
{
    type = cpy_weapon.type;
}

Weapon &Weapon::operator=(const Weapon &x)
{
    type = x.type;
}

Weapon::~Weapon()
{

}

const std::string&  Weapon::getType(void) const
{
    return type;
}

void    Weapon::setType(std::string new_type)
{
    type = new_type;
}