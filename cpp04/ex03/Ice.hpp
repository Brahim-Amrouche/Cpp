/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:50:40 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/19 12:21:10 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Interfaces.hpp"

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
