/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 08:49:00 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/17 12:31:47 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLAPTRAP_H
#define CLAPTRAP_H
#include "iostream"
#include "string"

using std::string;
using std::cout;
using std::endl;

class ClapTrap
{
    protected:
        string name;
        int    hit_points = 10;
        int    energy = 10;
        int    damage = 0;
    public:
        ClapTrap();
        ClapTrap(string new_name);
        ClapTrap(string new_name, int new_hit, int new_energy, int damage);
        ClapTrap(const ClapTrap &cpy_claptrap);
        ClapTrap &operator=(const ClapTrap &eq_claptrap);
        void    attack(const string &target);
        void    takeDamage(unsigned int amount);
        void    beRepaired(unsigned int amount);
        ~ClapTrap();
};


#endif