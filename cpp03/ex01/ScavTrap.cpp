/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 12:13:57 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/06 17:08:41 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap():ClapTrap("",100, 50, 20)
{
    cout << "ScavTrap Default constructor" << endl;
};

ScavTrap::ScavTrap(string name):ClapTrap(name, 100, 50, 20)
{
    cout << "ScavTrap String constructor" << endl;
};

ScavTrap::ScavTrap(const ScavTrap &cpy_scav):
    ClapTrap(cpy_scav.name, cpy_scav.hit_points, cpy_scav.energy, cpy_scav.damage)
{
    cout << "ScavTrap Copy constructor" << endl;
};

ScavTrap &ScavTrap::operator=(const ScavTrap &eq_scav)
{
    ClapTrap::operator=(eq_scav);
    return (*this);
}

void    ScavTrap::attack(const string &target)
{
    cout << "Scavtrap " << name;
    if (energy <= 0 || hit_points <= 0)
    {
        cout << " is unable to attack" << endl;
        return;
    }
    cout << " attacks " << target 
        << " , causing " << damage << " points of damage! " << endl;
    --energy;
}

void    ScavTrap::guardGate()
{
    cout << "ScavTrap " << name;
    if (energy <= 0 || hit_points <= 0)
    {
        cout << " is unable to guard mode" << endl;
        return;
    }
    --energy;
    cout << " is in Gate keeper mode" << endl;
}

ScavTrap::~ScavTrap()
{
    cout << "ScavTrap Destructor" << endl;
}

