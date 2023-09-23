/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 16:24:17 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/18 10:15:57 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap():ClapTrap("", 100, 100, 30)
{
    cout << "FragTrap Default constructor" << endl;
};

FragTrap::FragTrap(string new_name):ClapTrap(new_name, 100, 100, 30)
{
    cout << "FragTrap String constructor" << endl;
};

FragTrap::FragTrap(const FragTrap &cpy_frag):ClapTrap(cpy_frag.name, cpy_frag.hit_points, cpy_frag.energy, cpy_frag.damage)
{
    cout << "FragTrap Copy constructor" << endl;
};

FragTrap &FragTrap::operator=(const FragTrap &eq_frag)
{
    ClapTrap::operator=(eq_frag);
    return (*this);
}

void    FragTrap::highFivesGuys(void)
{
    cout << "FragTrap " << name << " Gives You a Positive High Five" << endl;
}

FragTrap::~FragTrap(void)
{
    cout << "FragTrap Destructor" << endl;
}