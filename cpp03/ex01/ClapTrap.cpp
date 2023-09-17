/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 09:11:42 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/17 12:31:12 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap():name("")
{
    cout << "ClapTrap Default Constructor Called" << endl;
};

ClapTrap::ClapTrap(string new_name):name(new_name)
{
    cout << "ClapTrap String Constructor Called" << endl;
};

ClapTrap::ClapTrap(string new_name, int new_hit, int new_energy, int new_damage)
{
    name = new_name;
    hit_points = new_hit;
    energy = new_energy;
    damage = new_damage;
};

ClapTrap::ClapTrap(const ClapTrap &cpy_claptrap):name(cpy_claptrap.name),
    hit_points(cpy_claptrap.hit_points) , energy(cpy_claptrap.energy), damage(cpy_claptrap.damage)
{
    cout << "ClapTrap Copy Constructor Called" << endl;
};

ClapTrap    &ClapTrap::operator=(const ClapTrap &eq_claptrap)
{
    name = eq_claptrap.name;
    hit_points = eq_claptrap.hit_points;
    energy = eq_claptrap.energy;
    damage = eq_claptrap.damage;
    return (*this);
};

void    ClapTrap::attack(const string &target)
{
    cout << "ClapTrap" << name;
    if (energy <= 0 || hit_points <= 0)
    {
        cout << "is unable to attack" << endl;
        return;
    }
    cout << "attacks" << target 
        << ", causing" << damage << "points of damage!" << endl;
    --energy;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    cout << "ClapTrap" << name << "takes" << amount << "points of damage !" << endl;
    if (amount > hit_points)
        hit_points = 0;
    else
        hit_points -= amount;
}


void    ClapTrap::beRepaired(unsigned int amount)
{
    cout << "ClapTrap" << name;
    if (energy <= 0 || hit_points <= 0)
    {
        cout << "is unable to Repair" << endl;
        return;
    }
    --energy;
    hit_points += amount;
    cout << "repair's for" << amount
        << "of hit points" << endl;
}

ClapTrap::~ClapTrap()
{
    cout << "ClapTrap Destructor Called" << endl;
};

