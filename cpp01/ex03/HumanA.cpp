/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 01:20:07 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/13 01:25:10 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string new_name, Weapon &r_weapon): name(new_name) , weapon(r_weapon){};

HumanA::HumanA(const HumanA &cpy_human): name(cpy_human.name), weapon(cpy_human.weapon)
{};

HumanA &HumanA::operator=(const HumanA &eq_human)
{
    name = eq_human.name;
}

void    HumanA::attack(void)
{
    cout << name << weapon.getType() << endl;
}

HumanA::~HumanA()
{

}