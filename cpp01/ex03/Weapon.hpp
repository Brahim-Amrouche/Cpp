/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 00:37:50 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/13 01:19:11 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_H
#define WEAPON_H

#include "string"
#include "iostream"

using   std::cout;
using   std::endl;

class Weapon
{
    private:
        std::string type;
    public:
        Weapon():type(""){};
        Weapon(const Weapon &cpy_weapon);
        Weapon(std::string info);
        Weapon &operator=(const Weapon &x);
        ~Weapon();
        const std::string& getType(void) const;
        void    setType(std::string new_type);
};

#endif
