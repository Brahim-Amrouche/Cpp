/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 00:37:50 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/20 12:00:08 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "string"
#include "iostream"

using   std::string;
using   std::cout;
using   std::endl;

class Weapon
{
    private:
        string type;
    public:
        Weapon():type(""){};
        Weapon(const Weapon &cpy_weapon);
        Weapon(string info);
        Weapon &operator=(const Weapon &x);
        ~Weapon();
        const string& getType(void) const;
        void    setType(string new_type);
};

