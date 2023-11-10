/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:16:07 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/10 12:12:12 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
    public :
        Ice();
        Ice(const Ice &cpy_ice);
        Ice &operator=(const Ice &eq_ice);
        Ice  *clone() const;
        void    use(ICharacter &target);
        ~Ice();
};