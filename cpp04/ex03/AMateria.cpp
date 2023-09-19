/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamrouch <bamrouch@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:35:31 by bamrouch          #+#    #+#             */
/*   Updated: 2023/09/19 12:48:19 by bamrouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Interfaces.hpp"

AMateria::AMateria(const string &type): materia_type(type)
{};

AMateria::AMateria(const AMateria &cpy_materia): materia_type(cpy_materia.materia_type)
{};

AMateria    &AMateria::operator=(const AMateria &eq_materia)
{
    materia_type = eq_materia.materia_type;
    return (*this);
}

string const &AMateria::getType() const
{
    return (materia_type);
};

AMateria::~AMateria()
{};