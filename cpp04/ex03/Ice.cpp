/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:47:06 by bamrouch          #+#    #+#             */
/*   Updated: 2023/11/09 20:36:41 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice():AMateria("ice")
{};

Ice::Ice(const Ice &cpy_ice):AMateria(cpy_ice)
{};

Ice &Ice::operator=(const Ice &eq_ice)
{
    if (this == &eq_ice)
        return (*this);
    AMateria::operator=(eq_ice);
    return (*this);
}

Ice *Ice::clone() const
{
    Ice *new_ice = new Ice(*this);
    return new_ice;
}

void  Ice::use(ICharacter &target)
{
    cout << "* shoots an ice bolt at " << target.getName() << " *" << endl;
};

Ice::~Ice()
{};
