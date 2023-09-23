/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 08:49:00 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/23 16:33:49 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "iostream"
#include "string"

using std::string;
using std::cout;
using std::endl;

class ClapTrap
{
    private:
        string name;
        int    hit_points;
        int    energy;
        int    damage;
    public:
        ClapTrap();
        ClapTrap(string new_name);
        ClapTrap(const ClapTrap &cpy_claptrap);
        ClapTrap &operator=(const ClapTrap &eq_claptrap);
        void    attack(const string &target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        ~ClapTrap();
};
