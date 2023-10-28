/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 22:23:34 by bamrouch          #+#    #+#             */
/*   Updated: 2023/10/28 20:56:46 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB():name(""), weapon(NULL)
{};

HumanB::HumanB(string new_name): name(new_name), weapon(NULL)
{};

HumanB::HumanB(const HumanB &cpy_human):name(cpy_human.name), weapon(cpy_human.weapon)
{};

HumanB  &HumanB::operator=(const HumanB &eq_human)
{
    name = eq_human.name;
    weapon = eq_human.weapon;
    return (*this);
}

void    HumanB::setWeapon(Weapon &new_weapon)
{
    weapon = &new_weapon;
}

void    HumanB::attack(void)
{
    if (!weapon)
        cout << "set a weapon" << endl;
    else
        cout << name << " " << weapon->getType() << endl;
}

HumanB::~HumanB()
{}
