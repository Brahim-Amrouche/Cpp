/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:34:31 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/06 19:22:24 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap():ClapTrap("_clap_name", 100, 50, 30)
{
    DiamondTrap::name = string("");
    cout << "DiamondTrap Default constructor" << endl;
}

DiamondTrap::DiamondTrap(string new_name):ClapTrap(new_name + "_clap_name", 100, 50, 30)
{
    DiamondTrap::name = new_name;
    cout << "DiamondTrap String constructor" << endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &cpy_diamond):ClapTrap(cpy_diamond), ScavTrap(cpy_diamond), FragTrap(cpy_diamond) 
{
    cout << "DiamondTrap Copy constructor" << endl;
    DiamondTrap::name = cpy_diamond.name;
    ClapTrap::operator=(cpy_diamond);
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &eq_diamond)
{
    DiamondTrap::name = eq_diamond.name;
    ClapTrap::operator=(eq_diamond);
    return (*this);
};

void DiamondTrap::whoAmI(void)
{
    cout << "DiamondTrap name is: " << DiamondTrap::name << " and it's ClapTrap name is: " << ScavTrap::name << endl;
};

DiamondTrap::~DiamondTrap()
{
    cout << "DiamondTrap Destructor" << endl;
};
