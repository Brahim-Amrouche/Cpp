/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:54:49 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/10 12:08:01 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure: public AMateria
{
    public :
        Cure();
        Cure(const Cure &cpy_cure);
        Cure &operator=(const Cure &eq_cure);
        Cure *clone() const;
        void    use(ICharacter &target);
        ~Cure();
};

