/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 00:51:53 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/12 23:42:58 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon      *weapon;
    public:
        HumanB(): name(""), weapon(NULL){};
        HumanB(std::string new_name);
        HumanB(const HumanB &cpy_human);
        HumanB  &operator=(const HumanB &eq_human);
        void    setWeapon(Weapon *new_weapon);
        void    attack();
        ~HumanB();
};

#endif