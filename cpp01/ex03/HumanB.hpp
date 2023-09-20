/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 00:51:53 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/20 11:59:49 by bamrouch         ###   ########.fr       */
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
        HumanB(): name(""), weapon(NULL){};
        HumanB(string new_name);
        HumanB(const HumanB &cpy_human);
        HumanB  &operator=(const HumanB &eq_human);
        void    setWeapon(Weapon &new_weapon);
        void    attack();
        ~HumanB();
};
