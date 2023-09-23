/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:15:34 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/17 17:40:57 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    private:
        string name;
    public:
        DiamondTrap();
        DiamondTrap(string new_name);
        DiamondTrap(const DiamondTrap &cpy_diamond);
        DiamondTrap &operator=(const DiamondTrap &eq_diamond);
        void        whoAmI(void);
        ~DiamondTrap();
};