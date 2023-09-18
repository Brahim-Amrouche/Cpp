/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:34:31 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/18 10:23:19 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap():name(""), ClapTrap(name.append("_clap_name"), 100, 50, 30)
{
    cout << "DiamondTrap Default constructor" << endl;
}

DiamondTrap::DiamondTrap(string new_name):name(new_name), ClapTrap(new_name.append("_clap_name"), 100, 50, 30)
{
    cout << "DiamondTrap String constructor" << endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &cpy_diamond):name(cpy_diamond.name), ClapTrap(name.append("_clap_name"), 100, 50, 30)
{
    cout << "DiamondTrap Copy constructor" << endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &eq_diamond)
{
    name = eq_diamond.name;
    ClapTrap::operator=(eq_diamond);
    return (*this);
};

void DiamondTrap::whoAmI(void)
{
    cout << "DiamondTrap name is: " << name << "and it's ClapTrap name is: " << ClapTrap::name << endl;
};

DiamondTrap::~DiamondTrap()
{
    cout << "DiamondTrap Destructor" << endl;
};
