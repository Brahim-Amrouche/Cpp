/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:04:04 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/19 13:09:07 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure():AMateria("cure")
{};

Cure::Cure(const Cure &cpy_cure):AMateria(cpy_cure)
{};

Cure    &Cure::operator=(const Cure &eq_cure)
{
    AMateria::operator=(eq_cure);
    return(*this);
};

Cure    *Cure::clone() const
{
    Cure *new_cure = new Cure(*this);
    return (new_cure);
};

void    Cure::use(ICharacter &target)
{
    cout << "* heals " << target.getName() << "'s wounds *" << endl;
};

Cure::~Cure()
{};
