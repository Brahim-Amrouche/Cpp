/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Interfaces.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:09:24 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/10 12:05:19 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once
#include "AMateria.hpp"

class ICharacter
{
    public:
        virtual ~ICharacter() {}
        virtual string const & getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;
};


