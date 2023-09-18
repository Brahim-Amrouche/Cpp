/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 08:49:00 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/17 16:27:54 by bamrouch         ###   ########.fr       */
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
        int    hit_points = 10;
        int    energy = 10;
        int    damage = 0;
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
