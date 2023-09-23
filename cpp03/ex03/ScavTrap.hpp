/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:34:30 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/23 18:12:46 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(string new_name);
        ScavTrap(const ScavTrap &cpy_scav);
        ScavTrap &operator=(const ScavTrap &eq_scav);
        virtual void attack(const string &target);
        void    guardGate(void);
        ~ScavTrap();
};
