/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:34:30 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/17 12:11:58 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    private:
    public:
        ScavTrap();
        ScavTrap(string new_name);
        ScavTrap(const ScavTrap &cpy_scav);
        ScavTrap &operator=(const ScavTrap &eq_scav);
        void    guardGate(void);
        ~ScavTrap();
};

#endif