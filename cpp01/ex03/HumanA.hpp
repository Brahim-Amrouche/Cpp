/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 00:52:37 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/20 11:59:41 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


#include "Weapon.hpp"

class HumanA
{
    private:
        string name;
        Weapon      &weapon;
    public:
        HumanA(string new_name, Weapon &r_weapon);
        HumanA(const HumanA &cpy_human);
        HumanA  &operator=(const HumanA &eq_human);
        void    attack(void);
        ~HumanA();
};
