/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 00:51:53 by bamrouch          #+#    #+#             */
/*   Updated: 2023/10/28 20:56:56 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"

class HumanB
{
    private:
        string name;
        Weapon      *weapon;
    public:
        HumanB();
        HumanB(string new_name);
        HumanB(const HumanB &cpy_human);
        HumanB  &operator=(const HumanB &eq_human);
        void    setWeapon(Weapon &new_weapon);
        void    attack();
        ~HumanB();
};
